cmake_minimum_required(VERSION 3.10)
project(GalGameEngine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Cocos2d-x
find_package(cocos2d REQUIRED)

# Source files
set(SOURCES
    src/main.cpp
    src/GalGameScene.cpp
    src/script/ScriptEngine.cpp
    src/script/DialogueManager.cpp
    src/script/ScriptInterpreter.cpp
    src/character/CharacterManager.cpp
    src/background/BackgroundManager.cpp
    src/ui/DialogueBox.cpp
    src/ui/ChoiceBox.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE cocos2d)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)