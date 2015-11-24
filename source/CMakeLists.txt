foreach(LIBRARY ${TESTLITE_LIBRARIES})
   add_library(${LIBRARY} ${LIBRARY}.c)
endforeach(LIBRARY)
