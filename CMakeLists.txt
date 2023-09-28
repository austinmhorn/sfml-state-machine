cmake_minimum_required(VERSION 3.21)

set( PROJECT_NAME "sfml-state-machine" )
project( ${PROJECT_NAME} LANGUAGES CXX )
set( TARGET ${PROJECT_NAME} )

# sfml-state-machine uses C++17 features
set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin )

find_package( SFML 2.5 COMPONENTS graphics window system network audio )

if ( NOT SFML_FOUND )
    include(FetchContent)
    FetchContent_Declare(
        SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 2.6.x)
    FetchContent_MakeAvailable(SFML)

    find_package( SFML 2.5 REQUIRED COMPONENTS graphics window system network audio )
endif()

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src )

# Set source and include paths
set( SOURCE_PATH "${PROJECT_SOURCE_DIR}/src/" )
set( INCLUDE_PATH "${PROJECT_SOURCE_DIR}/include/" )

# Recursively find project files
file( GLOB_RECURSE HPPS "${SOURCE_PATH}/*.hpp" )
file( GLOB_RECURSE CPPS "${SOURCE_PATH}/*.cpp"  )

add_executable( ${TARGET} ${CPPS} ${HPPS} )

target_link_libraries( ${TARGET} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio sfml-network )
target_compile_features( ${TARGET} PRIVATE cxx_std_17 )

install( TARGETS ${TARGET} RUNTIME DESTINATION )
