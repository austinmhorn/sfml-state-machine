cmake_minimum_required(VERSION 3.21)
project(sfml-state-machine LANGUAGES CXX)

# sfml-state-machine uses C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compile target
set(SOURCE_FILES
    "src/main.cpp"
    "src/Core/Resources.hpp"
    "src/Core/Resources.cpp"
    "src/Core/Application.hpp"
    "src/Core/Application.cpp"
    "src/State/Base/State.hpp"
    "src/State/Base/State.cpp"
    "src/State/Base/StateMachine.hpp"
    "src/State/Base/StateMachine.cpp"
    "src/State/PlayState.hpp"
    "src/State/PlayState.cpp"
    "src/State/OptionsState.hpp"
    "src/State/OptionsState.cpp"
    "src/State/IntroState.hpp"
    "src/State/IntroState.cpp")
add_executable(sfml-state-machine ${SOURCE_FILES})
target_link_libraries(sfml-state-machine PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
target_compile_features(sfml-state-machine PRIVATE cxx_std_17)
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET sfml-state-machine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:sfml-state-machine> $<TARGET_FILE_DIR:sfml-state-machine> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS sfml-state-machine)
