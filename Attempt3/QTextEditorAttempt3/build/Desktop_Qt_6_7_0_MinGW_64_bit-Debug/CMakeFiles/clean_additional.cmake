# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QTextEditorAttempt3_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QTextEditorAttempt3_autogen.dir\\ParseCache.txt"
  "QTextEditorAttempt3_autogen"
  )
endif()
