# Source files
file(GLOB_RECURSE SRC_FILES *.cpp *.hpp)
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${SRC_FILES})
set(LFG_SOURCE ${SRC_FILES})
#Executable
add_executable(lfg ${LFG_SOURCE})
#Compiler dirs
target_include_directories(lfg PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_thirdparty_include(lfg)
#Compile options
target_arch_compile_options(lfg)
#Linking
target_thirdparty_link(lfg)
#