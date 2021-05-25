file(GLOB hdrs "*.h*") 
file(GLOB srcs "*.cpp")

add_library(${TreeMap} STATIC ${srcs} ${hdrs}) 


