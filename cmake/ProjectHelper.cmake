macro(add_projects dir)
    file(GLOB projects RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${dir}/[a-z]*")
    foreach( proj ${projects} )
        add_subdirectory( ${proj} build/${proj} )
    endforeach(proj ${projects})
endmacro(add_projects dir)
