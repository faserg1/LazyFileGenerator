find_package(nlohmann_json CONFIG REQUIRED)

function(target_json_link target)
    target_link_libraries(${target} PRIVATE nlohmann_json nlohmann_json::nlohmann_json)
endfunction()