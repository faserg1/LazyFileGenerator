find_package(range-v3 CONFIG REQUIRED)

function(target_rangev3_link target)
    target_link_libraries(${target} PRIVATE range-v3 range-v3-meta range-v3::meta range-v3-concepts)
endfunction()