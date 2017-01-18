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
