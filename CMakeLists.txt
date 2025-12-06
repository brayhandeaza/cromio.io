cmake_minimum_required(VERSION 3.10) # Using 3.10 as requested

project(cromio VERSION 0.0.1 LANGUAGES C CXX)

# ============================================================
#                  MACOS & LLVM SETUP
# ============================================================

# 1. FIXED: Set the deployment target to the valid version for macOS Tahoe (26.0).
set(CMAKE_OSX_DEPLOYMENT_TARGET "26.0")

# 2. LLVM: Explicitly tell CMake where Homebrew installed LLVM on Apple Silicon.
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/llvm")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Path Definitions ----
set(GENERATED_DIR "${CMAKE_SOURCE_DIR}/src/lexer/antlr")
set(SOURCES_DIR "${CMAKE_SOURCE_DIR}/src")

# ---- ANTLR4 runtime include and lib paths ----
set(ANTLR4_RUNTIME_INCLUDE "/usr/local/include/antlr4-runtime")
set(ANTLR4_RUNTIME_LIB "${CMAKE_SOURCE_DIR}/antlr4/runtime/Cpp/build/runtime")


# ============================================================
#                     LLVM INTEGRATION
# ============================================================
cmake_policy(SET CMP0075 NEW)
find_package(LLVM REQUIRED CONFIG)

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

# Map all LLVM components your project uses
llvm_map_components_to_libnames(llvm_libs
        core
        support
        native
        irreader
        linker        # <--- needed for llvm::Linker
        bitreader     # <--- needed for llvm::parseBitcodeFile
        bitwriter     # <--- needed if you plan to write bitcode
)

add_definitions(${LLVM_DEFINITIONS})


# ============================================================
#                 Collect Sources & Executable
# ============================================================

# Collect all source files including those that use LLVM.
# NOTE: file(GLOB) is generally discouraged but kept here as per your original file.
file(GLOB ALL_SOURCES
        "${SOURCES_DIR}/cromio.cpp"
        "${GENERATED_DIR}/*.cpp"
        "${ALL_SOURCES}"
        "${SOURCES_DIR}/*.cpp"
        "${SOURCES_DIR}/utils/*.cpp"
        "${SOURCES_DIR}/visitor/*.cpp"
        "${SOURCES_DIR}/optimizer/*.cpp"
        "${SOURCES_DIR}/backend/*.cpp"
        "${SOURCES_DIR}/lowering/*.cpp"
        "${SOURCES_DIR}/semantic/*.cpp"
        "${SOURCES_DIR}/modules/*.cpp"
)

# Add executable using the unified list of source files.
add_executable(${PROJECT_NAME} ${ALL_SOURCES})


# ============================================================
#                     Target Setup
# ============================================================
# Includes
target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}
        ${SOURCES_DIR}
        ${ANTLR4_RUNTIME_INCLUDE}
        ${GENERATED_DIR}
)

# LLVM Includes (SYSTEM suppresses warnings from LLVM headers)
target_include_directories(${PROJECT_NAME} SYSTEM PUBLIC
        ${LLVM_INCLUDE_DIRS}
)

# Link Directories (Added to find ANTLR dynamic library)
target_link_directories(${PROJECT_NAME} PUBLIC
        ${ANTLR4_RUNTIME_LIB}
)

# Suppress duplicate library warnings (common with LLVM static libs)
target_link_options(${PROJECT_NAME} PRIVATE "LINKER:-no_warn_duplicate_libraries")

# Final Linking: Link ANTLR, the specific ANTLR dylib (for robustness), and all LLVM libs.
target_link_libraries(${PROJECT_NAME}
        antlr4-runtime
        "${ANTLR4_RUNTIME_LIB}/libantlr4-runtime.4.13.2.dylib"
        ${llvm_libs}
)

# ============================================================
#                   Custom "make run"
# ============================================================
# Set the path for the input file relative to the project source directory.
set(DEFAULT_FILE "${CMAKE_SOURCE_DIR}/test.io")

add_custom_target(run
        COMMAND ${PROJECT_NAME} ${DEFAULT_FILE}
        DEPENDS ${PROJECT_NAME}
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)