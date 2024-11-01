# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/brute_force_C_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/brute_force_C_autogen.dir/ParseCache.txt"
  "brute_force_C_autogen"
  )
endif()
