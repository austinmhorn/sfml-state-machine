cmake_minimum_required(VERSION 3.15...3.25.2)

project(StateMachineApplication LANGUAGES CXX)

# StateMachineApplication uses C++17 features
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
	${PROJECT_SOURCE_DIR})


# CMake options
option(STATEMACHINEAPPLICATION_STATIC_STD_LIBS "Use statically linked standard/runtime libraries? This option must match the one used for SFML." ON)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

if(NOT BUILD_SHARED_LIBS)
    set(SFML_STATIC_LIBRARIES FALSE)
endif()

# Find SFML
find_package(SFML 2.5.1 COMPONENTS audio graphics system window network REQUIRED)

if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML couldn't be located!")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# Compile target
set(SOURCE_FILES
    "src/main.cpp"
    "src/Core/ResourcePath.hpp"
    "src/Core/ResourcePath.mm"
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
add_executable(StateMachineApplication ${SOURCE_FILES})

# Static Runtime
if(STATEMACHINEAPPLICATION_STATIC_STD_LIBS)
    if(NOT SFML_STATIC_LIBRARIES)
        message("\n-> If you check STATEMACHINEAPPLICATION_STATIC_STD_LIBS, you also need to check SFML_STATIC_LIBRARIES.")
        message("-> It would lead to multiple runtime environments which results in undefined behavior.\n")
    elseif(WIN32 AND MSVC)
        set_property(TARGET StateMachineApplication PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        target_link_options(StateMachineApplication PRIVATE -static)
    endif()
endif()

# Link libraries
target_link_libraries(StateMachineApplication
    "-framework Cocoa"
    "-framework AppKit"
    "-framework CoreData"
    "-framework Foundation"
    sfml-audio
    sfml-graphics
    sfml-system
    sfml-window
    sfml-network)

# Install executable
install(TARGETS StateMachineApplication
        RUNTIME DESTINATION .)

# Install game data
install(DIRECTORY bin/
        DESTINATION .)
