find_package(toml11 CONFIG REQUIRED)

function(target_toml_link target)
    target_link_libraries(${target} PRIVATE toml11::toml11)
endfunction()