<#
  Oppretter en ny ovingsoppgave under practice\ basert pa malene i
  problem_templates\.

  Bruk:
    .\tools\new-problem.ps1 -Name forsok1 -Type main
    .\tools\new-problem.ps1 -Name forsok2 -Type signature

  Type "main"      -> ett main.cpp som leser/skriver stdin/stdout selv.
  Type "signature" -> header.h (grensesnitt) + handler.cpp (testdriver,
                       ferdigskrevet) + signature.cpp (der du implementerer
                       funksjonen).

  Bygg og kjor etterpa med:
    .\tools\run-problem.ps1 <Name>
#>
param(
    [Parameter(Mandatory = $true)]
    [string]$Name,

    [ValidateSet("main", "signature")]
    [string]$Type = "main"
)

$ErrorActionPreference = "Stop"
$repoRoot = Split-Path -Parent $PSScriptRoot
$destDir = Join-Path $repoRoot "practice\$Name"

if (Test-Path $destDir) {
    Write-Error "practice\$Name finnes allerede."
}
New-Item -ItemType Directory -Path $destDir | Out-Null

if ($Type -eq "signature") {
    $templateDir = Join-Path $repoRoot "problem_templates\signature_function"
    Copy-Item (Join-Path $templateDir "*") $destDir -Recurse
}
else {
    # main_function-malen inneholder for tiden et eget (ufullstendig) TTT-
    # eksperiment i main.cpp, sa her genereres en ren, minimal main.cpp i
    # stedet for a kopiere den - CMakeLists.txt fra malen er derimot ren
    # og gjenbrukes direkte.
    $templateDir = Join-Path $repoRoot "problem_templates\main_function"
    Copy-Item (Join-Path $templateDir "CMakeLists.txt") $destDir

    $mainCpp = @"
#include <iostream>

int main(int /*argc*/, char** /*argv*/)
{

    return 0;
}
"@
    Set-Content -Path (Join-Path $destDir "main.cpp") -Value $mainCpp -Encoding utf8
}

Write-Host "Opprettet practice\$Name (type: $Type)" -ForegroundColor Green
Write-Host "Bygg og kjor med:  .\tools\run-problem.ps1 $Name"
