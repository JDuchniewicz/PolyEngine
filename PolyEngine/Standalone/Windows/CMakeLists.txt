add_executable(polyrun WIN32 Src/Main.cpp)
target_link_libraries(polyrun PRIVATE polyengine)
add_dependencies(polyrun polyrenderingdevicegl) #dynamically loaded
add_custom_command(
		TARGET polyrun POST_BUILD
		COMMAND
		${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/ThirdParty/libepoxy/bin/$<${ARCH_X64}:x64>$<${ARCH_X86}:Win32>/epoxy-0.dll"
		                                      "$<TARGET_FILE_DIR:polyrun>"
		COMMAND
		${CMAKE_COMMAND} -E copy_if_different "${PROJECT_SOURCE_DIR}/ThirdParty/assimp/lib/Release/$<${ARCH_X64}:x64>$<${ARCH_X86}:Win32>/assimp-vc140-mt.dll"
		                                      "$<TARGET_FILE_DIR:polyrun>"
)

cotire(polyrun)
