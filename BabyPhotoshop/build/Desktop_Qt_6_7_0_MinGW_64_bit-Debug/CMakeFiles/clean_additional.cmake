# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\photoshop_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\photoshop_autogen.dir\\ParseCache.txt"
  "Photoshop_autogen"
  )
endif()
