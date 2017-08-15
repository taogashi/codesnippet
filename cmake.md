```cmake
macro(debug_fatal opt) 
	if ("${opt}" MATCHES "ON")
		foreach(arg ${ARGN})
			message(STATUS "YS DEBUG: ${arg}")
		endforeach()
		message(FATAL_ERROR "YS DEBUG: end")
	endif()
endmacro()
```

```cmake
## Extract version numbers from version string
function (version_numbers version major minor patch)
	string(REGEX REPLACE "([0-9]+).[0-9]+.[0-9]+" "\\1"
		_major ${version})
	string(REGEX REPLACE "[0-9]+.([0-9]+).[0-9]+" "\\1"
		_minor ${version})
	string(REGEX REPLACE "[0-9]+.[0-9]+.([0-9]+)" "\\1"
		_patch ${version})

	if ("${_major}" STREQUAL "")
		set (_major 0)
	endif ()

	if ("${_minor}" STREQUAL "")
		set (_minor 0)
	endif ()

	if ("${_patch}" STREQUAL "")
		set (_patch 0)
	endif ()

	set ("${major}" "${_major}" PARENT_SCOPE)
	set ("${minor}" "${_minor}" PARENT_SCOPE)
	set ("${patch}" "${_patch}" PARENT_SCOPE)
endfunction ()
```
```cmake
ExternalProject_Add(project_libgp
	PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/external
	GIT_REPOSITORY https://github.com/taogashi/libgp.git
	CMAKE_ARGS -DBUILD_TESTS=OFF -DBUILD_EXAMPLES=ON -DCMAKE_INSTALL_PREFIX:PATH=<INSTALL_DIR>)

ExternalProject_Get_Property(project_libgp install_dir)
add_library(gp STATIC IMPORTED)
set_target_properties(gp PROPERTIES
	IMPORTED_LOCATION ${install_dir}/lib/libgp.a
	INTERFACE_INCLUDE_DIRECTORIES ${install_dir}/include/gp)
add_dependencies(gp project_libgp)
```
