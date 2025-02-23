include_directories(
    inc
    tpl
)

file(GLOB lib_modules "*")
#message(STATUS "lib_modules: ${lib_modules}")

foreach (module ${lib_modules})
  if(IS_DIRECTORY ${module})
    get_filename_component(module_name ${module} NAME)
    file(GLOB module_sources "${module}/*.cpp")
    file(GLOB module_headers_templates "${module}/*.h" "${module}/*.tcc")
    list(LENGTH module_sources num_sources)
    list(LENGTH module_headers_templates num_headers_templates)
    if(num_sources GREATER 0)
      # only .cpp
      add_library(lib_${module_name} STATIC ${module_sources})
      target_include_directories(lib_${module_name} PUBLIC ${module})
    elseif(num_headers_templates)
      #only .h or only .tcc
      add_library(lib_${module_name} INTERFACE)
      target_include_directories(lib_${module_name} INTERFACE ${module})
    endif()
    list(APPEND lib_targets lib_${module_name})
  endif()
endforeach()

message(STATUS "lib: ${lib_targets}")
set(lib_targets ${lib_targets} PARENT_SCOPE)