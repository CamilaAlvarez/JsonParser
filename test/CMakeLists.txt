find_package(Threads REQUIRED)

#Modulo para incluir proyectos externos
include(ExternalProject)

#Agregar proyecto externo
ExternalProject_Add(
        gtest #Nombre del proyecto externo
        URL https://googletest.googlecode.com/files/gtest-1.7.0.zip
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest #directorio raiz del proyecto
        CMAKE_ARGS CMAKE_CXX_FLAGS -std=c++11 -stdlib=libc++
        INSTALL_COMMAND "" #deshabilitar instalacion
)

#imported dice que es una libreria externa, global que es visible por todos
add_library(libgtest IMPORTED STATIC GLOBAL)
#agrega dependencia a libgtest de manera que gtest sea buildeada primero
add_dependencies(libgtest gtest)

#se extraen propiedades del proyecto externo
ExternalProject_Get_Property(gtest source_dir binary_dir)
set_target_properties(libgtest PROPERTIES
        "IMPORTED_LOCATION" "${binary_dir}/libgtest.a"
        "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
        )

#de aqui para abajo todos podran ocupar este include, con target solo uno puede utilizarlos
include_directories("${source_dir}/include")
add_subdirectory(jsonTest)