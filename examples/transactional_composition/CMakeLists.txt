
# add a min accumulator plugin
add_xplugin(plugin_min ${CMAKE_CURRENT_SOURCE_DIR}/plugin_calculate_feature_min.cpp)
target_include_directories(plugin_min PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add a max accumulator plugin
add_xplugin(plugin_max ${CMAKE_CURRENT_SOURCE_DIR}/plugin_calculate_feature_max.cpp)
target_include_directories(plugin_max PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add a max accumulator plugin
add_xplugin(plugin_validate ${CMAKE_CURRENT_SOURCE_DIR}/plugin_validate.cpp)
target_include_directories(plugin_validate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add a max accumulator plugin
add_xplugin(plugin_transform ${CMAKE_CURRENT_SOURCE_DIR}/plugin_transform.cpp)
target_include_directories(plugin_transform PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add a max accumulator plugin
add_xplugin(plugin_model ${CMAKE_CURRENT_SOURCE_DIR}/plugin_apply_secret_model.cpp)
target_include_directories(plugin_model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# add  main executable using the plugins
add_executable(transactional_composition ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_include_directories(transactional_composition PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(transactional_composition PUBLIC xplugin_host)
target_compile_features(transactional_composition PRIVATE cxx_std_17)
set_target_properties(transactional_composition PROPERTIES POSITION_INDEPENDENT_CODE ON)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/transactional_composition.ini ${CMAKE_CURRENT_BINARY_DIR}/transactional_composition.ini COPYONLY)

xplugin_add_emscripten_main_module_flags(transactional_composition)

