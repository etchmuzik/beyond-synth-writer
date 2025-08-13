cmake_minimum_required(VERSION 3.15)

# The project name and version. Feel free to change the name later.
project(BeyondSynthWriter VERSION 0.1.0 LANGUAGES C CXX)

# JUCE expects C++17 by default. Enforce it here.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add JUCE as a subdirectory. When the repository is cloned with
# `git submodule update --init --recursive`, the JUCE source will live
# at juce/ inside this repository. If JUCE is not found, builds will
# fail until the submodule is initialised.
add_subdirectory(juce)

# Create the plugin target. juce_add_plugin generates a CMake
# target with the specified parameters. The target will be built
# for VST3 and AU formats on macOS and Windows by default.
juce_add_plugin(BeyondSynthWriterPlugin
    COMPANY_NAME "Beyond"
    COMPANY_ID "com.beyond"
    PLUGIN_MANUFACTURER_CODE BEYN
    PLUGIN_CODE SYNW
    FORMATS VST3 AU
    PRODUCT_NAME "Beyond Synth Writer"
)

# Add our source files to the plugin target. These files live in
# the Source directory.
target_sources(BeyondSynthWriterPlugin PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
)

# Enable a few JUCE features and disable others to keep the build
# minimal. These flags can be customised later.
target_compile_definitions(BeyondSynthWriterPlugin PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)
