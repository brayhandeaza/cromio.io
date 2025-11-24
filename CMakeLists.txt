cmake_minimum_required(VERSION 3.10)

project(cromio VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Path to ANTLR-generated sources ----
set(GENERATED_DIR "${CMAKE_SOURCE_DIR}/grammar/antlr")
set(INCLUDES_DIR "${CMAKE_SOURCE_DIR}/includes")
set(SOURCES_DIR "${CMAKE_SOURCE_DIR}/src")
set(LIBS_DIR "${CMAKE_SOURCE_DIR}/libs")

# ---- Collect all generated .cpp files ----
file(GLOB GENERATED_SOURCES
        "${GENERATED_DIR}/*.cpp"
        "${SOURCES_DIR}/*.cpp"
)

# ---- ANTLR4 runtime include and lib paths ----
set(ANTLR4_RUNTIME_INCLUDE "/usr/local/include/antlr4-runtime")
set(ANTLR4_RUNTIME_LIB "${CMAKE_SOURCE_DIR}/antlr4/runtime/Cpp/build/runtime")


# ---- Add executable ----
add_executable(${PROJECT_NAME}
        "${SOURCES_DIR}/main.cpp"
        ${GENERATED_SOURCES}
)

# Include directories
target_include_directories(${PROJECT_NAME} PUBLIC
        ${ANTLR4_RUNTIME_INCLUDE}
        ${GENERATED_DIR}
        ${INCLUDES_DIR}
        ${LIBS_DIR}
        ${GENERATED_SOURCES}
)

# Link ANTLR runtime
target_link_directories(${PROJECT_NAME} PUBLIC
        ${ANTLR4_RUNTIME_LIB}
        ${INCLUDES_DIR}
)

target_link_libraries(${PROJECT_NAME}
        antlr4-runtime
)

# ---- Custom "make run" target ----
set(DEFAULT_FILE "../test.io")

# Add a custom target to run the program
add_custom_target(run
        COMMAND ${PROJECT_NAME} ${FILE}
        DEPENDS ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
