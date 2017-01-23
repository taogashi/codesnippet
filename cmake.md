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
