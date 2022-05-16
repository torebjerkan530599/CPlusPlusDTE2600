# mimimum required version 3.15: policy CMP0092
# mimimum required version 3.12: target_compile_features C++ 20
# mimimum required version 3.8:  target_compile_features C++ 17
cmake_minimum_required(VERSION 3.15)

# policy CMP0092 MSVC COMPILE FLAGS -- no warings by default
cmake_policy(SET CMP0092 NEW)

# Project name
project(dte2600_TEMPLATE_SOURCE VERSION 0.1 LANGUAGES CXX)


###########################################
# Assignment Problems
#add_subdirectory(problems/a01p01) #No input - single data point output https://stackoverflow.com/questions/3024197/what-does-int-argc-char-argv-mean
#add_subdirectory(problems/a01p02) #Single data point input - single data point output
#add_subdirectory(problems/a01p03) #Single data point input - multi-data point output , hugs and kisses, *argv[] == **argv
#add_subdirectory(problems/a01p04) #Multi data point input - multi-data point output
#add_subdirectory(problems/a01p05) #Multi data point input - storage - single or multi-data point output, ranges::transform and ranges::accumulate
#add_subdirectory(problems/a01p06) #sign. prob.1 - std::ranges::sort(data, std::ranges::greater());
#add_subdirectory(problems/a01p07) #sign. prob.2 - auto data = std::vector<int>( std::begin(p_data), std::end(p_data) );
#add_subdirectory(problems/a01p08) #sign. prob.3 - pair,  auto const data = std::pair<size_t,size_t> {5, 5};
#add_subdirectory(problems/a01p09) #sign. prob.4 - initializing and utilizing pair, td::pair<size_t,size_t> noOddEvenInRange( int lo, int hi) {} {no odd,no even}
#add_subdirectory(problems/a02p01) #Hello World!
#add_subdirectory(problems/a02p02) #Print Pi, iostream and iomanip to control stream output, std::fixed, std::showpoint 
#add_subdirectory(problems/a02p03) #sizeOf bool, char, int...
#add_subdirectory(problems/a02p04) #Functions: Length of name, compute sum, circumference and area of circle
#add_subdirectory(problems/a02p05) #Arithmetic Operators: Sum, product, division by floating point, integer and remainder of integer, using std::fmod
#add_subdirectory(problems/a02p06) #Logical Operators and expressions. Bitwise and,or,neg, xor
#add_subdirectory(problems/a02p07) #While Loop, two different ways of initializing a forward list, query iterator from forward list
#add_subdirectory(problems/a02p08) #For Loop
#add_subdirectory(problems/a02p09) #Switch Test
#add_subdirectory(problems/a02p10) #If tests, std::getline(std::cin, quote); select corret movie title from quote, "Frankly, my dear, I don't give a damn"
#add_subdirectory(problems/a02p11) obs obs! local not same as dmoj#Pointers and Arrays 01, if nullptr; return std::nullopt,  
#add_subdirectory(problems/a02p12) obs obs! local not same as dmoj#Pointers and Arrays 02, return char_array[index];
#add_subdirectory(problems/a02p13) #Pointers and Arrays 03, [1] String building test[2] Negative length test
#add_subdirectory(problems/a02p14) #Pointers and Arrays 04, Pointers support random access arithmetics, if (*char_array == c)
#add_subdirectory(problems/a02p15) #Pointers and Arrays 05,indexing into 2D array: char_tbl[row_nr * cols + col_nr];
#add_subdirectory(problems/a02p16) #Loop on input, Detect EOI/CAPS, std::getline(std::cin, line){ if (line == "EOI" && std::any_of(line.begin(), line.end(), isupper)
#add_subdirectory(problems/a03p01) #std::stringstream stream;  item.age_limit = std::max({ record1.age, record2.age, record3.age });  stream << std::fixed
#add_subdirectory(problems/a03p02) # Item* i = static_cast<Item*>(item); return i->price, int extra_years = static_cast<int>(no_years); Person* p = static_cast<Person*>(record);
#add_subdirectory(problems/a03p03) #fails the test, Member Functions of a Class
#add_subdirectory(problems/a03p04) #Unions: Any,Variant,Optional. input.substr(0, input.find(" ")); input.substr(input.find(" ") +1); ceilf, stoi, stof, max,stream << std::get<int>(num);
#add_subdirectory(problems/a03p05) #Enumeration. static_cast<Flags>(Flag::Flag1) & flags, str = str.substr(0, str.size() - 1);
#add_subdirectory(problems/a03p06) #Namespaces, m_data.size(), detail::findIndexOfFirst(m_data, c); dte2600::string::CharVec v = str.data();
#add_subdirectory(problems/a03p07) #Structured Binding, std::tie, int index = std::distance(records.begin(), itr); std::tie(name, age) = *itr;
#add_subdirectory(problems/a03p08) #Error Handling, getCharAtEx, getCharAtOpt, static_cast<int>(m_data.size(), m_data.at(index), throw
#add_subdirectory(problems/a04p01) #Concrete Classes, Weak Ordered Comparison: order by Area, then Perimiter, std::numbers::pi, return std::weak_ordering::equivalent;
#add_subdirectory(problems/a04p02) #Abstract Classes and Polymorphism, std::weak_ordering::equivalent; std::weak_ordering::less; return std::weak_ordering::greater;
#add_subdirectory(problems/a04p03) #Abstract Classes and Dynamic Casting, dynamic_cast<Triangle const&>(shape).area(); dynamic_cast<Triangle const&>(shape).perimeter();
#add_subdirectory(problems/a04p04) #RAII: Containers, new, unique_ptr ,make_unique ,shared_ptr ,make_shared, raw pointer storage: m_data = new char[m_size]; delete m_data; std::make_unique<char[]>(m_size),std::shared_ptr<char[]>(new char[m_size]);std::make_unique<char[]>(m_size);
#add_subdirectory(problems/a04p05) #Classes: Copy & Move, this->m_data.reset();this->m_data = std::move(other.m_data); return *this;m_data.reset(new char[other.m_size]);operator=
#add_subdirectory(problems/a04p06) #fails the test 1/3, Classes and the Rule of Three, Five and Zero, HeapAllocatedInt, m_int = new int(p_int); MovableHeapAllocatedInt
#add_subdirectory(problems/a04p07) #Classes and the Comparison Operators, std::bitset<8>(number); std::string k(s.rbegin(), s.rend()); std::bitset<8>reverse_set(k); num <<= 1; num |= reverse_set[i]; bitset operators,itsetInt16::operator<=>
#add_subdirectory(problems/a04p08) #Classes and Stream Operators,  std::copy(data2d.begin(), data2d.end(), back_inserter(m_data)); istream& operator>>, ostream& operator<<, mat.m_data.resize(row); stream << mat.m_data[i][j] << ' ' ;
#add_subdirectory(problems/a05p01) #Generic Functions, friend std::ostream& operator<<(std::ostream& stream, Item const& item); 
#add_subdirectory(problems/a05p02) #Generic Classes, std::weak_ordering Item::operator<=>, ints.sort(); std::cout << item because struct Item {...friend std::ostream& operator<<(std::ostream& stream, Item const& item);..}
#add_subdirectory(problems/a05p03) #Iterators, std::forward_list, std::vector, Mechanics: constructors, iteration, comparasion, element access. m_current_node = m_current_node->next; return *this; MinimalIterator::operator!=. operator*() return m_current_node->value; 
#add_subdirectory(problems/a05p04) #Iterators 2 : Generic Classes,  using ValueArray = std::array<value_type, capacity>; Node* next{ nullptr };  using NodePtr = std::unique_ptr<Node>; using NodeArray = std::array<NodePtr, capacity>;m_current_node = m_current_node->next;
#add_subdirectory(problems/a05p05) #Function Objects (Functors), operator()
#add_subdirectory(problems/a05p06) # Generic Function Objects and Lambdas, std::weak_ordering Item::operator<=> for price and name
#add_subdirectory(problems/a05p07) #Algorithms and Predicates: std::pair<int, int>(...) ... return { mean, median };Sort the people by name or year of birth in ascending or descending order std::sort(people.begin(), people.end(), pred); SortOrder::Asc, SortOrder::Dscstd::numeric_limits<int>::max()/min();
#add_subdirectory(problems/a05p08) # ---"--- std::for_each, auto pred = [&next](auto& ele), std::for_each(data.begin(), data.end(), pred);
#add_subdirectory(problems/a05p09) # ---"--- std::transform, std::back_inserter, std::transform_reduce, two predicates, one for comp and one for proj, auto const score = [](auto const& str) -> size_t, auto const pred = [score](auto const& str) -> Meta
#add_subdirectory(problems/a05p10) #Ranges and Views,  for (int e : iota(low + 1, high + 1) | filter(filter_pred)) ints.push_back(e); generateOddNumbersReversed: std::ranges::transform(iota(low, high) | filter(filter_pred) | reverse,std::back_inserter(evens), trans_pred);
#add_subdirectory(problems/a06p01) #Partial Sort, std::partial_sort(items.begin(), items.end()-middle_index, items.end(), [](const Item& lhs, const Item& rhs) {return lhs.name < rhs.name;}); for (auto const& e : std::span(items.begin(), middle_index))
#add_subdirectory(problems/a06p02) #Partial Sort: N-th Element, std::nth_element(items.begin(), items.begin()+int(ei), items.end(), comp_lesser); std::ranges::nth_element(items, items.begin() + ei, Greater());
#add_subdirectory(problems/a06p03) #Heap Sort, is_heap, make_heap, sort_heap, push_heap, pop_heap. is_max_heap vs is_min_heap, std::ranges::make_heap(items, [](const Item& lhs, const Item& rhs) {return lhs.price > rhs.price; std::ranges::push_heap(items, std::ranges::less(), &Item::price); std::ranges::pop_heap(items.begin(), items.begin() + n, std::ranges::less(), &Item::price);
#add_subdirectory(problems/a06p04) #Search and Find, if (auto p1 = sr::find_if(sr::begin(items), sr::end(items), is_category); sr::adjacent_find; p1 != items.end())std::cout << iter->category << " " + iter->name << " " << (iter + 1)->name << std::endl;stable_sort;sr::itr_low/up=lower_bound/upper_bound; sr::unique(items, [](Item& i1, Item& i2);auto i = std::distance(items.begin(), it); //get index for enumeration
#add_subdirectory(problems/a06p05) #Binary Search and Find, items and needles, sr::binary_search(items, needle, std::ranges::less(), &Item::id) 
#add_subdirectory(problems/a06p06) #Search and Find Sub-Ranges 1, search, find_end, find_first_of, auto found = sr::search(input, sub); const auto first = std::distance(input.begin(), found.begin()); const auto last = std::distance(input.begin(), found.end()); sr::find_end(input, sub);sr::find_first_of(found1 + 1, input.end(), needles.begin(), needles.end());
#add_subdirectory(problems/a06p07) #Search and Find Sub-Ranges 2, ---"--- , sr::search(items, sub, {}, &Item::id, [](const int& iValue) {return iValue; }); first and last in subrange; sr::find_end(items, sub, {}, &Item::id, [](const int& iValue) {return iValue; }); sr::find_first_of(found1 + 1, items.end(), needles.begin(), needles.end(), {}, &Item::id, [](const int& iValue) {return iValue; });
#add_subdirectory(problems/a06p08) #Minmax Element. const auto [min, max] = rng::minmax_element(items, std::ranges::greater(), &Person::year_of_birth); pos_min = rng::distance(items.begin(), min);pos_max = rng::distance(items.begin(), max);
#add_subdirectory(problems/a06p09) #Querying of Properties, operator ==, return (this->name == p.name). sr::all_of(items, pred, &Person::year_of_birth)), sr::any_of(items, pred, &Person::name),sr::none_of(items, pred),sr::equal;sr::is_permutation,sr::lexicographical_compare,sr::mismatch
#add_subdirectory(problems/a07p01) #Permutation, if (auto itr = sr::find(items, some_name, &Item::name); sr::rotate(items, itr)); if (auto itr = sr::find(items.begin() + lo, items.begin() + hi, name, &Item::name); itr != items.begin() + hi); sr::rotate(items.begin() + lo, itr, items.begin() + hi); sr::reverse(items);sr::reverse(item.name);sr::next_permutation(in_string);
#add_subdirectory(problems/a07p02) #Partitioning, sr::stable_partition(items, pred, &Item::name);  Partition the list such that all items with the unique name are stably partitioned at the front
#add_subdirectory(problems/a07p03) #Set Algorithms, sr::copy_if(items, std::back_inserter(A), pred_A); sr::set_difference(A, B, std::back_inserter(result), pred);sr::sort(result, result_order, &Item::id);sr::set_intersection(A, B, std::back_inserter(result), pred);sr::set_union(A, B, std::back_inserter(result), pred);
#add_subdirectory(problems/a07p04) #Copy. anonymize all items with an age.opy/move all items with an age in [lo, hi] to a vector, then sort the vector by id. sr::copy_if(item_list, std::back_inserter(vec), pred);
#add_subdirectory(problems/a07p05) #sr::copy_if(item_list, std::back_inserter(vec), pred);
#add_subdirectory(problems/a07p06) #Contiguous Memory Containers, toCharArray: std::fill(arr.begin() + name.length(), arr.end(), '_'); appendReversed, std::ranges::reverse_copy(str, reversed_str.begin());
#add_subdirectory(problems/a07p07) #List Containers, forward, list, reverse: out.assign(in.begin(), in.end()); out.reverse();, pyramidCopy:std::ranges::copy(in, std::front_inserter(out));std::ranges::copy(in, std::back_inserter(out));
#add_subdirectory(problems/a07p08) #Associative Containers, maps.std::hash<std::string>{}(name.m_name);myMap[name]++; myMap.insert(std::pair<Name, int>(name.toString(), 1));info.contains(name.toString()
#add_subdirectory(problems/a08p01) #auto const x = *i; auto const f = x + y;
#add_subdirectory(problems/a08p02) #calculate if two, single or complex roots
#add_subdirectory(problems/a08p03) #Accounting.using AccountMap = std::map<size_t, AccountInfo>; using PeopleMap = std::unordered_map<size_t, Person auto const& [aid, ainfo] : ainfo_map auto const& [name, balance, owner_id] = ainfo;auto const& from_account = ainfo_map.at(aid_from).name; auto const& to_account = ainfo_map.at(aid_to).name;
#add_subdirectory(problems/a08p04) # fib. std::adjacent_difference(std::begin(fib) + 1, std::prev(std::end(fib)), std::next(std::begin(fib) + 1), std::plus<>{}); printout:sr::copy(fib, std::ostream_iterator<int>(std::cout, " ")); std::cout << '\n';std::cout << "Reverse (from " << I << ") ":  sr::reverse_copy(std::cbegin(fib), std::cbegin(fib)+I+1, std::ostream_iterator<int>(std::cout, " "));
# add_subdirectory(problems/a08p05) #postponed
# add_subdirectory(problems/a08p06) #decode(std::ptrdiff_t* enc, char const** lookup):  auto const char_idx = enc[i+ 1];  char const* tbl = *(lookup+tbl_idx);
# add_subdirectory(problems/a08p07) #mail sorting,  sr::sort(mail, lvl3_comp, lvl3_proj); lvl3_comp = [](auto const& lhs, auto const& rhs) ...; auto const proj_hlpr = [];auto const lvl3_proj = [proj_hlpr, lvl3](MessageHeader const& header)
# add_subdirectory(problems/a08p08) # guarding bit shift agains overflows: if(shift >= sizeof(unsigned) * 8)
add_subdirectory(problems/a09p01)
###########################################
# Qt creator dummy target
option(DUMMY_TARGET "Dummy target..." TRUE)
if(DUMMY_TARGET)
  add_custom_target(${PROJECT_NAME}_DUMMY)
endif(DUMMY_TARGET)
