# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\MyTouristManager_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MyTouristManager_autogen.dir\\ParseCache.txt"
  "MyTouristManager_autogen"
  )
endif()
