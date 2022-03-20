cmake_minimum_required (VERSION 3.12)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

project ("PrimeReciprocals")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS include/*.hpp)

add_executable (PrimeReciprocals ${SOURCES} ${HEADERS})
target_include_directories(PrimeReciprocals PRIVATE include)
target_include_directories(PrimeReciprocals PRIVATE src)

target_compile_features(PrimeReciprocals PUBLIC cxx_std_20)

