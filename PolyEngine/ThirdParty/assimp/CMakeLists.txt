add_subdirectory(contrib)


set(LIBASSIMP_SRC .)
set(LIBASSIMP_INCLUDE 
	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/contrib
	${CMAKE_CURRENT_SOURCE_DIR}/contrib/rapidjson/include
	${CMAKE_CURRENT_SOURCE_DIR}/contrib/unzip
	${CMAKE_CURRENT_SOURCE_DIR}/contrib/openddlparser/include
	)

file(GLOB_RECURSE LIBASSIMP_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} 
	${LIBASSIMP_SRC}/*.cpp 
	${LIBASSIMP_SRC}/*.c
	${LIBASSIMP_SRC}/*.hpp
	${LIBASSIMP_SRC}/*.h)
GenerateSourceGoups("${LIBASSIMP_SRCS}")

#foreach(FILE ${LIBASSIMP_SRCS})
#message(${FILE})
#endforeach()

add_library(LibAssimp SHARED ${LIBASSIMP_SRCS})
target_include_directories(LibAssimp PUBLIC ${LIBASSIMP_INCLUDE})