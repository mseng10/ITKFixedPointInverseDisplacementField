cmake_minimum_required(VERSION 2.8.9)

SET(kit FixedPointInverseDeformationField)
project(${kit})

if(NOT ITK_SOURCE_DIR)
  find_package(ITK 4.9 REQUIRED)
  include(${ITK_USE_FILE})
  list(APPEND CMAKE_MODULE_PATH ${ITK_CMAKE_DIR})
  include(ITKModuleExternal)
else()
  itk_module_impl()
endif()

add_subdirectory( examples )

