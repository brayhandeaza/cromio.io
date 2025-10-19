cmake_minimum_required(VERSION 3.10)

project(cromio VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Path to ANTLR-generated sources ----
set(GENERATED_DIR "${CMAKE_SOURCE_DIR}/grammar/antlr")
set(INCLUDES_DIR "${CMAKE_SOURCE_DIR}/includes")


# ---- Collect all generated .cpp files ----
file(GLOB GENERATED_SOURCES
        "${GENERATED_DIR}/*.cpp"
        "${INCLUDES_DIR}/*.cpp"
)

# ---- ANTLR4 runtime include and lib paths ----
set(ANTLR4_RUNTIME_INCLUDE "/usr/local/include/antlr4-runtime")
set(ANTLR4_RUNTIME_LIB "${CMAKE_SOURCE_DIR}/antlr4/runtime/Cpp/build/runtime")


add_executable(${PROJECT_NAME}
        main.cpp
        ${GENERATED_SOURCES}
        ${CMAKE_SOURCE_DIR}/visitor/Visitor.h
)

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
        ${ANTLR4_RUNTIME_INCLUDE}
        ${GENERATED_DIR}
        ${INCLUDES_DIR}/libs
        ${INCLUDES_DIR}/
        ${CMAKE_SOURCE_DIR}/visitor
)

# Link ANTLR runtime
target_link_directories(${PROJECT_NAME} PUBLIC
        ${ANTLR4_RUNTIME_LIB}
)

target_link_libraries(${PROJECT_NAME}
        antlr4-runtime
)

# ✅ CUSTOM "make run" TARGET (dinámico)
# Permite: make run FILE=../main.io
set(DEFAULT_FILE "../test.io")

add_custom_target(run
        COMMAND ${PROJECT_NAME} ${FILE}
        DEPENDS ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
