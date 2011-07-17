cmake_minimum_required (VERSION 2.6)
project (IPRANGE)

# our software library version
set (LIB_VERSION_MAJOR 0)
set (LIB_VERSION_MINOR 1)
 
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
      "${PROJECT_SOURCE_DIR}/lib/libconfig.h.in"
      "${PROJECT_BINARY_DIR}/libconfig.h"
      )
       
# add the binary tree to the search path for include files
# so that we will find generated *.h files
include_directories("${PROJECT_BINARY_DIR}")

# add the software library source dir for blahblah.h
include_directories("${PROJECT_SOURCE_DIR}/lib")


add_subdirectory(src "${PROJECT_SOURCE_DIR}/obj")
add_subdirectory(lib "${PROJECT_SOURCE_DIR}/obj")
