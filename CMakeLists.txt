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
#add_subdirectory(problems/a02p11) #Pointers and Arrays 01
#add_subdirectory(problems/a02p12)
#add_subdirectory(problems/a02p13)
#add_subdirectory(problems/a02p14)
#add_subdirectory(problems/a02p15)
#add_subdirectory(problems/a02p16)
#add_subdirectory(problems/a03p01)
#add_subdirectory(problems/a03p02)
#add_subdirectory(problems/a03p03) #fails the test
#add_subdirectory(problems/a03p04)
#add_subdirectory(problems/a03p05)
#add_subdirectory(problems/a03p06)
#add_subdirectory(problems/a03p07)
#add_subdirectory(problems/a03p08)
#add_subdirectory(problems/a04p01)
#add_subdirectory(problems/a04p02)
#add_subdirectory(problems/a04p03)
#add_subdirectory(problems/a04p04)
#add_subdirectory(problems/a04p05)
#add_subdirectory(problems/a04p06) #fails the test
#add_subdirectory(problems/a04p07)
#add_subdirectory(problems/a04p08)
#add_subdirectory(problems/a05p01)
#add_subdirectory(problems/a05p02)
#add_subdirectory(problems/a05p03)
#add_subdirectory(problems/a05p04)
#add_subdirectory(problems/a05p05)
#add_subdirectory(problems/a05p06)
#add_subdirectory(problems/a05p07)
#add_subdirectory(problems/a05p08)
#add_subdirectory(problems/a05p09)
#add_subdirectory(problems/a05p10)
#add_subdirectory(problems/a06p01)
#add_subdirectory(problems/a06p02)
#add_subdirectory(problems/a06p03)
#add_subdirectory(problems/a06p04)
#add_subdirectory(problems/a06p05)
#add_subdirectory(problems/a06p06)
#add_subdirectory(problems/a06p07)
#add_subdirectory(problems/a06p08)
#add_subdirectory(problems/a06p09)
#add_subdirectory(problems/a07p01)
#add_subdirectory(problems/a07p02)
#add_subdirectory(problems/a07p03)
#add_subdirectory(problems/a07p04)
#add_subdirectory(problems/a07p05)
#add_subdirectory(problems/a07p06)
#add_subdirectory(problems/a07p07)
#add_subdirectory(problems/a07p08)
#add_subdirectory(problems/a08p01)
#add_subdirectory(problems/a08p02)
#add_subdirectory(problems/a08p03)
#add_subdirectory(problems/a08p04)
# add_subdirectory(problems/a08p05) #postponed
# add_subdirectory(problems/a08p06)
# add_subdirectory(problems/a08p07)
# add_subdirectory(problems/a08p08)
add_subdirectory(problems/a09p01)
###########################################
# Qt creator dummy target
option(DUMMY_TARGET "Dummy target..." TRUE)
if(DUMMY_TARGET)
  add_custom_target(${PROJECT_NAME}_DUMMY)
endif(DUMMY_TARGET)
