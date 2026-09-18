# Studieguide - repetisjon av DTE2600

Denne filen er et kart over pensum basert pa kommentarene i rot-[CMakeLists.txt](CMakeLists.txt)
(som i praksis er en oppgaveliste med stikkord for hvert tema), pluss noen
observasjoner fra a ha gatt gjennom losningene.

## Laereplan (kronologisk)

Dette er den faktiske progresjonen gjennom kurset - hvert delkapittel bygger
pa begrepene fra det forrige. Se "Pensumkart" lenger ned for oppgave-for-
oppgave-detaljer.

### Del 1 - Grunnleggende program-I/O (a01, 9 oppgaver)
Mal: fa inn/ut-data til a fungere (argc/argv, stdin/stdout), og bli kjent
med de to oppgavearketypene som brukes resten av kurset.
- a01p01-a01p04: fra ingen input til flere datapunkter inn/ut
- a01p05: forste mote med `ranges::transform`/`ranges::accumulate` - en
  forsmak pa del 5-6
- a01p06-a01p09: introduserer signature-funksjon-arketypen (fast
  grensesnitt du implementerer mot), med `ranges::sort` og `std::pair`

### Del 2 - Sprakgrunnlag (a02, 16 oppgaver)
Mal: fundamentale C++-byggeklosser - typer, operatorer, kontrollstruktur,
pekere.
- a02p01-a02p03: Hello World, stream-formatering (`iomanip`), `sizeof`
- a02p04-a02p06: funksjoner, aritmetiske og logiske/bitvise operatorer
- a02p07-a02p10: kontrollstrukturer (while/for/switch/if) + forste mote
  med en container (`forward_list`)
- a02p11-a02p16: pekere og arrayer i okende kompleksitet, fra
  `nullptr`-sjekk til 2D-indeksering, avsluttet med lokke-basert
  input-parsing

### Del 3 - Klasser, typer og feilhandtering (a03, 8 oppgaver)
Mal: ga fra frittstaende funksjoner til a definere egne typer.
- a03p01-a03p02: `stringstream`, `static_cast`
- a03p03: medlemsfunksjoner i en klasse - forste egendefinerte klasse
- a03p04-a03p05: unions/variant/optional, enum
- a03p06-a03p07: namespaces, structured bindings
- a03p08: feilhandtering (exceptions vs. optional-returverdi) - runder av
  med hvordan en klasse svarer pa ugyldige tilstander

### Del 4 - Objektorientert programmering (a04, 8 oppgaver)
Mal: klassisk OOP - polymorfi, ressursstyring, operatoroverlasting.
- a04p01: konkrete klasser + weak ordering (`operator<=>`)
- a04p02-a04p03: abstrakte klasser, polymorfi, `dynamic_cast`
- a04p04-a04p05: RAII, smarte pekere, kopi-/move-semantikk
- a04p06: Rule of Three/Five/Zero - kjernen i ressurshandtering (kjent
  svakt punkt, se under)
- a04p07-a04p08: sammenlignings- og stream-operatorer

### Del 5 - Generisk programmering og iteratorer (a05, 10 oppgaver)
Mal: fra konkrete klasser til gjenbrukbar, generisk kode; skrive egne
iteratorer; mote de forste STL-algoritmene.
- a05p01-a05p02: generiske funksjoner og klasser
- a05p03-a05p04: egne iteratorer - en forutsetning for a forsta det meste
  av del 6-7
- a05p05-a05p06: funksjonsobjekter og lambdaer
- a05p07-a05p09: algoritmer + predikater (`sort`, `for_each`, `transform`)
- a05p10: ranges og views - broen over til del 6

### Del 6 - Sortering og sok (a06, 9 oppgaver)
Mal: STL sin sorterings- og sokefamilie i dybden.
`partial_sort` -> `nth_element` -> heap-operasjoner -> `find`-varianter ->
`binary_search` -> sok i delsekvenser (`search`/`find_end`/`find_first_of`,
med projeksjoner) -> `minmax_element` -> predikat-sporringer (`all_of`/
`any_of`/`mismatch`)

### Del 7 - Permutasjon og containere (a07, 8 oppgaver)
Mal: mer avanserte algoritmer + et bredere containerlandskap.
Permutasjon/rotasjon -> partisjonering -> mengdealgoritmer -> kopier/flytt-
monstre -> sammenhengende containere (`array`) -> liste-containere
(`list`/`forward_list`) -> assosiative containere (`map`/`unordered_map`)

### Del 8 - Blandet/avansert (a08, 4 pensumoppgaver)
Mal: sette sammen det du har lart i friere, mer virkelighetsnaere
oppgaver. a08p01-a08p04 er de reelle pensumoppgavene (uttrykk med
iteratorer, andregradsligning, et "accounting"-eksempel med maps og
structured bindings, og Fibonacci med `adjacent_difference`).
a08p05-a08p08 er ikke pensum i vanlig forstand - se "Pensumkart" under.

### Etter pensum - a09 (ufullfort)
Et mer apent, avsluttende prosjekt (meldingsklient / rom-domenemodell) som
aldri ble ferdigstilt. Naturlig neste steg etter du har repetert a01-a08,
om du vil prove deg pa noe storre og mer selvstendig.

## To oppgavetyper

- **main.cpp** (`problem_templates/main_function`): ett program som leser
  input fra stdin og skriver til stdout. Brukt i a01, og gjennomgaende i a02
  og enkelte senere oppgaver.
- **header.h + handler.cpp + signature.cpp** (`problem_templates/signature_function`):
  du implementerer kun `signature.cpp` mot et gitt grensesnitt i `header.h`.
  `handler.cpp` er en ferdigskrevet testdriver med hardkodede parametre som
  kaller funksjonen og skriver ut resultatet - kjor og les output manuelt.

Kun de seks forste oppgavene (a01p01-a01p06) har `dat/example_data.in` +
`dat/example_data.out` liggende lokalt. Resten ble apenbart rettet mot en
ekstern judge, sa det finnes ikke fasit i repoet for de fleste oppgavene -
`run-problem.ps1` kjorer dem uansett og viser deg output, men kan bare
autoverifisere de seks forste.

## Verktoy

- **Visual Studio**: apne en enkelt oppgavemappe direkte som mappe
  (`File > Open > Folder...`, velg f.eks. `problems\a04p01`). VS sin
  CMake-integrasjon fungerer pa enhver mappe med en CMakeLists.txt, ikke
  bare rotmappen - du far full IntelliSense, bygg og debugger uten a matte
  endre noe i repoet.
- **Terminal**: `.\tools\run-problem.ps1 <id>` konfigurerer, bygger og
  kjorer en oppgave (og sammenligner mot fasit nar den finnes).
- **Nye oppgaver**: `.\tools\new-problem.ps1 -Name <navn> -Type main|signature`
  oppretter en ny ovingsoppgave under `practice\` fra malene.

Rot-CMakeLists.txt star urort med alle `add_subdirectory`-linjene
kommentert ut (slik den apenbart var etterlatt) - den fungerer fint som et
lesbart register over alle oppgavene selv om den ikke lenger trengs for a
bygge.

## Pensumkart

### a01 - Input/output og forste signature-oppgaver
| Oppgave | Tema |
|---|---|
| a01p01 | Ingen input, enkelt datapunkt ut (`argc`/`argv`) |
| a01p02 | Ett datapunkt inn -> ett ut |
| a01p03 | Ett datapunkt inn -> flere ut (`*argv[]` vs `**argv`) |
| a01p04 | Flere datapunkt inn -> flere ut |
| a01p05 | Flere datapunkt inn, lagring, `ranges::transform`/`ranges::accumulate` |
| a01p06 | Signature-oppgave: `std::ranges::sort(data, std::ranges::greater())` |
| a01p07 | Signature-oppgave: bygge `std::vector` fra iteratorer |
| a01p08 | Signature-oppgave: `std::pair` |
| a01p09 | Signature-oppgave: initialisere/bruke `std::pair` |

### a02 - Sprakgrunnlag
| Oppgave | Tema |
|---|---|
| a02p01 | Hello World |
| a02p02 | `iostream`/`iomanip`, `std::fixed`, `std::showpoint` |
| a02p03 | `sizeof` pa `bool`/`char`/`int`... |
| a02p04 | Funksjoner: navnelengde, sum, omkrets/areal av sirkel |
| a02p05 | Aritmetiske operatorer, `std::fmod` |
| a02p06 | Logiske/bitvise operatorer (and/or/neg/xor) |
| a02p07 | While-lokke, `std::forward_list` init + iterator |
| a02p08 | For-lokke |
| a02p09 | Switch |
| a02p10 | If-tester, `std::getline` |
| a02p11 | Pekere og arrayer 1 - `nullptr`, `std::nullopt` |
| a02p12 | Pekere og arrayer 2 - indeksering |
| a02p13 | Pekere og arrayer 3 - strengbygging, negativ lengde |
| a02p14 | Pekere og arrayer 4 - pointer-aritmetikk |
| a02p15 | Pekere og arrayer 5 - indeksering i 2D-array |
| a02p16 | Lokke pa input - detektere EOI/CAPS |

### a03 - Klasser, typer og feilhandtering
| Oppgave | Tema |
|---|---|
| a03p01 | `std::stringstream`, `std::max({...})` |
| a03p02 | `static_cast` mellom base/avledet peker |
| a03p03 | Medlemsfunksjoner i en klasse *(se "Kjente svake punkter" under)* |
| a03p04 | Unions: Any/Variant/Optional |
| a03p05 | Enum, bitvise flagg-operasjoner |
| a03p06 | Namespaces |
| a03p07 | Structured bindings, `std::tie` |
| a03p08 | Feilhandtering - exceptions vs. optional-returverdi |

### a04 - Objektorientert programmering
| Oppgave | Tema |
|---|---|
| a04p01 | Konkrete klasser, `operator<=>` (weak ordering) |
| a04p02 | Abstrakte klasser og polymorfi |
| a04p03 | Abstrakte klasser og `dynamic_cast` |
| a04p04 | RAII - `unique_ptr`/`shared_ptr` vs. rå `new`/`delete` |
| a04p05 | Kopi- og move-semantikk |
| a04p06 | Rule of Three/Five/Zero *(se "Kjente svake punkter" under)* |
| a04p07 | Sammenligningsoperatorer, `std::bitset` |
| a04p08 | Stream-operatorer (`operator<<`/`operator>>`) |

### a05 - Generisk programmering, iteratorer, algoritmer
| Oppgave | Tema |
|---|---|
| a05p01 | Generiske funksjoner, `friend operator<<` |
| a05p02 | Generiske klasser, `operator<=>` |
| a05p03 | Egen iterator over `forward_list`/`vector` |
| a05p04 | Iteratorer 2 - generisk klasse med array-baserte noder |
| a05p05 | Funksjonsobjekter (functors) |
| a05p06 | Generiske funksjonsobjekter og lambdaer |
| a05p07 | Algoritmer og predikater, sortering pa flere kriterier |
| a05p08 | `std::for_each` |
| a05p09 | `std::transform`, `transform_reduce`, projeksjoner |
| a05p10 | Ranges og views - `iota`, `filter`, `reverse` |

### a06 - Sortering og soking (ranges-algoritmer)
| Oppgave | Tema |
|---|---|
| a06p01 | Partial sort |
| a06p02 | Nth element |
| a06p03 | Heap sort (`make_heap`/`push_heap`/`pop_heap`/`sort_heap`) |
| a06p04 | Sok og finn (`find_if`, `adjacent_find`, `stable_sort`, `unique`) |
| a06p05 | Binærsøk |
| a06p06 | Sok i delsekvenser 1 (`search`, `find_end`, `find_first_of`) |
| a06p07 | Sok i delsekvenser 2 (med projeksjoner) |
| a06p08 | `minmax_element` |
| a06p09 | Egenskaper pa ranges (`all_of`/`any_of`/`none_of`, `equal`, `is_permutation`, `mismatch`) |

### a07 - Permutasjon, partisjonering og containere
| Oppgave | Tema |
|---|---|
| a07p01 | Permutasjon - `rotate`, `reverse`, `next_permutation` |
| a07p02 | Partisjonering (`stable_partition`) |
| a07p03 | Mengdealgoritmer (`set_difference`/`set_intersection`/`set_union`) |
| a07p04 | Kopiere/flytte delmengde av data til ny container, sortere |
| a07p05 | Som a07p04, variant |
| a07p06 | Sammenhengende minne-containere (`array`, `fill`, `reverse_copy`) |
| a07p07 | List-containere (`forward_list`/`list`, front/back-inserter) |
| a07p08 | Assosiative containere (`map`/`unordered_map`, hashing) |

### a08 - Blandet/avansert
| Oppgave | Tema |
|---|---|
| a08p01 | Uttrykk med iteratorer (`auto x = *i; auto f = x + y;`) |
| a08p02 | Beregne om en andregradsligning har to, en eller komplekse rotter |
| a08p03 | "Accounting"-eksempel: `map`/`unordered_map` av structs, structured bindings |
| a08p04 | `std::adjacent_difference`, `std::ostream_iterator`, Fibonacci |
| a08p05 | *Ikke en pensumoppgave* - eget uferdig Tic-Tac-Toe-eksperiment (star fortsatt aktiv i CMakeLists.txt, merket "postponed") |
| a08p06 | (kommentert ut) Dekoding via oppslagstabell med pekere |
| a08p07 | (kommentert ut) E-postsortering med flernivas komparator/projeksjon |
| a08p08 | (kommentert ut) Beskytte bit-shift mot overflow |

### a09 - Ikke fullfort
a09p01 (meldingsklient med `chrono`-datoer/kriteriematching) og a09p02
(rom/material-domenemodell) star med betydelig utkommentert kode og
"not working!"-notater - dette ser ut som et avsluttende, egendefinert
prosjekt som ikke ble ferdigstilt. Fin kandidat hvis du vil ta et friere,
storre oppgave-lignende prosjekt etter a ha repetert a01-a08.

## Kjente svake punkter

Disse to er verdt a ta forst i repetisjonen, siden losningen fra forrige
gjennomgang selv er merket som feilende i rot-CMakeLists.txt:

- **a03p03** (Medlemsfunksjoner i en klasse) - kommentaren sier rett ut
  "fails the test".
- **a04p06** (Rule of Three/Five/Zero, `HeapAllocatedInt`) - kommentaren
  sier "fails the test 1/3". Ved en rask titt i `signature.cpp` er
  kopikonstruktoren mistenkelig: den kaller `delete m_int` for
  `m_int` i det hele tatt er satt (udefinert oppforsel), og kopierer sa
  bare pekeren (`m_int = other.m_int`) i stedet for a allokere en ny
  `int` - to objekter ender opp med a eie samme heap-minne, som er
  akkurat det "Rule of Three" skal unnga. Bra case a løse pa nytt fra
  bunnen av.
