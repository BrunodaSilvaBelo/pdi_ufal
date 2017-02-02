cmake_minimum_required( VERSION 3.3 )
project( pdi CXX )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package( OpenCV REQUIRED )

option ( ${PROJECT_NAME}_CONFIGURE_TEST
  "If ON, it will configurate to run tests" OFF )
option ( ${PROJECT_NAME}_USE_GUIDELINES_SUPPORT_LIBRARY
  "If ON, it will configurate to use the c++ standard guidelines" OFF )

if ( ${PROJECT_NAME}_CONFIGURE_TEST
    OR ${PROJECT_NAME}_USE_GUIDELINES_SUPPORT_LIBRARY )
  include(ExternalProject)
  find_package(Git REQUIRED)
endif (  ${PROJECT_NAME}_CONFIGURE_TEST
  OR ${PROJECT_NAME}_USE_GUIDELINES_SUPPORT_LIBRARY )

set( LIB_NAME ${PROJECT_NAME} )
set( LIBRARY_TYPE STATIC )

set( SOURCE ${SOURCE}
  )

set( EXTRA_DIRS ${EXTRA_DIRS}
  src
  "${OpenCV_INCLUDE_DIRS}"
  )

set( EXTRA_LIBS ${EXTRA_LIBS}
  "${OpenCV_LIBS}"
  )

# add_library ( ${LIB_NAME}
#   ${LIBRARY_TYPE}
#   ${SOURCE}
#   )
# target_compile_options( ${LIB_NAME} PRIVATE $<$<CXX_COMPILER_ID:MSVC>:/W4> )
# target_compile_options( ${LIB_NAME} PRIVATE
#   $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra -pedantic> )
# target_compile_options( ${LIB_NAME} PRIVATE
#   $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra -pedantic -Weverything
#   -Wno-c++98-compat> )

# target_include_directories( ${LIB_NAME} PUBLIC
#   $<BUILD_INTERFACE:${EXTRA_DIRS}> )
# if ( ${PROJECT_NAME}_USE_GUIDELINES_SUPPORT_LIBRARY )
#   include( gslconfig )
# endif ( ${PROJECT_NAME}_USE_GUIDELINES_SUPPORT_LIBRARY )

# target_link_libraries( ${LIB_NAME} ${EXTRA_LIBS} )

set( MAIN_EXECUTABLE ${PROJECT_NAME}_code )
add_executable( ${MAIN_EXECUTABLE} src/main.cpp )
target_link_libraries( ${MAIN_EXECUTABLE} ${EXTRA_LIBS} )

if ( ${PROJECT_NAME}_CONFIGURE_TEST )
  include( catchconfig )
endif ( ${PROJECT_NAME}_CONFIGURE_TEST )

option( ${PROJECT_NAME}_USE_GOOGLE_BENCHMARK
  "If ON, it will use the google microbenchmark" OFF )
if ( ${PROJECT_NAME}_USE_GOOGLE_BENCHMARK )
  include( microbenchconfig )
endif ( ${PROJECT_NAME}_USE_GOOGLE_BENCHMARK )

option( ${PROJECT_NAME}_USE_DOXYGEN "If ON, it will configurate for use doxygen"
  OFF )
if ( ${PROJECT_NAME}_USE_DOXYGEN )
  include( doxygenconfig )
endif ( ${PROJECT_NAME}_USE_DOXYGEN )
