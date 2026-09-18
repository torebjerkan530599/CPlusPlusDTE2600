<#
  Konfigurerer, bygger og kjorer en enkelt DTE2600-oppgave med MSVC + Ninja
  (samme verktoykjede som CMakeSettings.json opprinnelig var satt opp for).

  Bruk:
    .\tools\run-problem.ps1 a01p01
    .\tools\run-problem.ps1 a04p01 -Config Release

  Oppgaven kan ligge under problems\<id> (original pensum) eller
  practice\<id> (nye ovingsoppgaver laget med new-problem.ps1).

  Hvis oppgaven har dat\example_data.in, sendes den som stdin. Hvis den
  ogsa har dat\example_data.out, sammenlignes output automatisk (PASS/FAIL).
  Har oppgaven ingen dat\-mappe, kjores den bare og output skrives ut for
  manuell sjekk (typisk for signature/handler-oppgaver).
#>
param(
    [Parameter(Mandatory = $true, Position = 0)]
    [string]$Id,

    [string]$Config = "Debug"
)

$ErrorActionPreference = "Stop"
$repoRoot = Split-Path -Parent $PSScriptRoot

$srcDir = Join-Path $repoRoot "problems\$Id"
if (-not (Test-Path $srcDir)) { $srcDir = Join-Path $repoRoot "practice\$Id" }
if (-not (Test-Path $srcDir)) {
    Write-Error "Fant ingen oppgave '$Id' under problems\ eller practice\"
}

# Finn Visual Studio og importer utviklermiljoet, slik at cl.exe/cmake/ninja
# havner riktig konfigurert pa PATH i denne prosessen.
$vswhere = "C:\Program Files (x86)\Microsoft Visual Studio\Installer\vswhere.exe"
if (-not (Test-Path $vswhere)) {
    Write-Error "Fant ikke vswhere.exe - er Visual Studio installert?"
}
$vsPath = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if (-not $vsPath) {
    Write-Error "Fant ingen Visual Studio-installasjon med C++-verktoy (Desktop development with C++). Se STUDIEGUIDE.md."
}

# Launch-VsDevShell.ps1 kaller internt vswhere.exe uten full sti, sa den ma
# vare pa PATH forst for a unnga en (ufarlig) "not recognized"-feilmelding.
$env:PATH = "C:\Program Files (x86)\Microsoft Visual Studio\Installer;$env:PATH"

$devShell = Join-Path $vsPath "Common7\Tools\Launch-VsDevShell.ps1"
& $devShell -Arch amd64 -HostArch amd64 -SkipAutomaticLocation *> $null

$buildDir = Join-Path $repoRoot "out\build\$Id"

Write-Host "==> Konfigurerer $Id ($Config) ..." -ForegroundColor Cyan
& cmake -S $srcDir -B $buildDir -G Ninja "-DCMAKE_BUILD_TYPE=$Config"
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

Write-Host "==> Bygger $Id ..." -ForegroundColor Cyan
& cmake --build $buildDir
if ($LASTEXITCODE -ne 0) { exit $LASTEXITCODE }

$exe = Join-Path $buildDir "$Id.exe"
if (-not (Test-Path $exe)) {
    $found = Get-ChildItem $buildDir -Filter "*.exe" -File -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($found) { $exe = $found.FullName }
}
if (-not (Test-Path $exe)) {
    Write-Error "Fant ingen .exe i $buildDir"
}

$inFile = Join-Path $srcDir "dat\example_data.in"
$outFile = Join-Path $srcDir "dat\example_data.out"

Write-Host "==> Kjorer $Id ..." -ForegroundColor Cyan
# Ekte fil-omdirigering via cmd /c, ikke PowerShell-pipe - PowerShell sin
# "streng | native.exe"-pipe skriver om stdin-encodingen og kan odelegge
# std::cin-parsing (f.eks. tall) selv om filinnholdet er helt greit.
if (Test-Path $inFile) {
    $actual = (cmd /c "`"$exe`" < `"$inFile`"") | Out-String
}
else {
    $actual = (cmd /c "`"$exe`" < NUL") | Out-String
}
Write-Host $actual

if (Test-Path $outFile) {
    $expected = Get-Content $outFile -Raw
    if ($actual.Trim() -eq $expected.Trim()) {
        Write-Host "PASS - output matcher dat\example_data.out" -ForegroundColor Green
    }
    else {
        Write-Host "FAIL - output matcher IKKE dat\example_data.out" -ForegroundColor Red
        Write-Host "--- forventet ---"
        Write-Host $expected
        Write-Host "--- fikk ---"
        Write-Host $actual
    }
}
