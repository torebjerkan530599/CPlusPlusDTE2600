# Studieguide - repetisjon av DTE2600

Denne filen er et kart over pensum basert pa kommentarene i rot-[CMakeLists.txt](CMakeLists.txt)
(som i praksis er en oppgaveliste med stikkord for hvert tema), pluss noen
observasjoner fra a ha gatt gjennom losningene.

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
