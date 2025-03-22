cmake_minimum_required(VERSION 3.10)
project(CubeGUI_JSON_Plugin)

# Find Qt6 (make sure it's installed and in PATH)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Optional: if Cube provides a CMake config file, you can use find_package(Cube)
# If not, you can manually set include and lib paths later.

# Add your plugin source files
add_library(jsonplugin SHARED json_plugin.cpp)

# Link Qt libraries
target_link_libraries(jsonplugin Qt6::Core Qt6::Widgets)

# Optional: add include directories if needed
# target_include_directories(jsonplugin PRIVATE /path/to/cube/include)
# target_link_libraries(jsonplugin /path/to/cube/lib/libcubepluginapi.so)
