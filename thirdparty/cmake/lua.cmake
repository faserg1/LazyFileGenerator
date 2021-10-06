find_package(Lua REQUIRED)

function(target_lua_include target)
    message(${target})
    target_include_directories(${target} PRIVATE ${LUA_INCLUDE_DIR})
endfunction()

function(target_lua_link target)
    target_link_libraries(${target} PRIVATE ${LUA_LIBRARIES})
endfunction()