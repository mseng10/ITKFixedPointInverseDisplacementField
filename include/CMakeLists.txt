# This is the root ITK CMakeLists file.
cmake_minimum_required(VERSION 2.4)
if(COMMAND CMAKE_POLICY)
  cmake_policy(SET CMP0003 NEW)
endif()

project(ITKUtils)

# Find ITK.
find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_executable(InvertDeformationField InvertDeformationField.cxx )

target_link_libraries(InvertDeformationField ${ITK_LIBRARIES})

set(INSTALL_RUNTIME_DESTINATION bin CACHE STRING "Install destination")

install(TARGETS InvertDeformationField DESTINATION ${INSTALL_RUNTIME_DESTINATION})

