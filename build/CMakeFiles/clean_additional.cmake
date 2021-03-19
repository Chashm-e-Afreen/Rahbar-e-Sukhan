# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Rahbar-e-Sukhan_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Rahbar-e-Sukhan_autogen.dir/ParseCache.txt"
  "Rahbar-e-Sukhan_autogen"
  )
endif()
