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


add_subdirectory(src "${PROJECT_SOURCE_DIR}/objsrc")
add_subdirectory(lib "${PROJECT_SOURCE_DIR}/objlib")


# check if doxygen is even installed
find_package(Doxygen)
if (DOXYGEN_FOUND STREQUAL "NO")
    message(FATAL_ERROR "Doxygen not found. Please get a copy http://www.doxygen.org")
endif (DOXYGEN_FOUND STREQUAL "NO")

# prepare doxygen configuration file
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

# add doxygen as target
add_custom_target(doxygen ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

# cleanup $build/doxdoc on "make clean"
set_property(DIRECTORY APPEND PROPERTY ADDITIONAL_MAKE_CLEAN_FILES doxdoc)

# add doxygen as dependency to doc-target
get_target_property(DOC_TARGET doc TYPE)
if(NOT DOC_TARGET)
    add_custom_target(doc)
endif()
add_dependencies(doc doxygen)

# install HTML API documentation and manual pages
#set(DOC_PATH "share/doc/${CPACK_PACKAGE_NAME}-${VERSION}")
#install(
#    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxdoc/html
#    DESTINATION ${DOC_PATH}
#)

# install man pages into packages, scope is now project root..
#install(
#    DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/doxdoc/man/man3
#    DESTINATION share/man/man3/
#)
