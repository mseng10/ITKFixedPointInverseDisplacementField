
set(${kit}_SRC
    InvertDeformationField.cxx
)

if(BUILD_TESTING)
  add_library(${kit}Lib ${ITK_LIBRARY_BUILD_TYPE} ${${kit}_SRC})
  set_target_properties(${kit}Lib PROPERTIES COMPILE_FLAGS "-Dmain=${kit}EntryPoint")
endif()

get_target_property(LINK_LIBRARIES_invertDeformationFieldLib ${kit}Lib LIBRARY_OUTPUT_DIRECTORY)

add_executable(InvertDeformationField ${${kit}_SRC} )

target_link_libraries(InvertDeformationField ${ITK_LIBRARIES})

set(INSTALL_RUNTIME_DESTINATION bin CACHE STRING "Install destination")

install(TARGETS InvertDeformationField DESTINATION ${INSTALL_RUNTIME_DESTINATION})
