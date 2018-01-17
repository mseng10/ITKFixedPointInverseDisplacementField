cmake_minimum_required(VERSION 3.9.5)
set(module InvertDisplacementField)
project(${module})

find_package(ITK REQUIRED COMPONENTS FixedPointInverseDisplacementField)
include(${ITK_USE_FILE})

set(${module}_SRC
    InvertDisplacementField.cxx
)

add_executable(${module} ${${module}_SRC} )
target_link_libraries(${module} ${ITK_LIBRARIES})

set(INSTALL_RUNTIME_DESTINATION bin CACHE STRING "Install destination")

install(TARGETS ${module} DESTINATION ${INSTALL_RUNTIME_DESTINATION})
