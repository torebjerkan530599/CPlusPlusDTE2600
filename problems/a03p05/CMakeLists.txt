get_filename_component(FNAME ${CMAKE_CURRENT_LIST_DIR} NAME)
project(${FNAME})

add_executable( ${PROJECT_NAME} )

# C++ standard feature set
target_compile_features( ${PROJECT_NAME}
  PUBLIC $<$<CXX_COMPILER_ID:Clang>:cxx_std_20>
  PUBLIC $<$<CXX_COMPILER_ID:GNU>:cxx_std_20>
  PUBLIC $<$<CXX_COMPILER_ID:MSVC>:cxx_std_20>
  )

# Compile definitions
target_compile_definitions( ${PROJECT_NAME}
  PUBLIC $<$<CXX_COMPILER_ID:MSVC>: _USE_MATH_DEFINES>
  )

target_sources( ${PROJECT_NAME} PRIVATE
  header.h handler.cpp
  signature.cpp )


