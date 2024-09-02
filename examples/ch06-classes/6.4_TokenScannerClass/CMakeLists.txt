cmake_minimum_required(VERSION 3.20)

# Set project information
project(
  TokenScannerClass
  VERSION 1.0
  DESCRIPTION "The TokenScanner class"
  LANGUAGES CXX)

# Add an executable target
add_executable(${PROJECT_NAME})

# Define Cxx standard
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES CXX_STANDARD 17
             CXX_STANDARD_REQUIRED ON
             CXX_EXTENSIONS OFF)

# Add source files
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS
     ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS
     ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
file(GLOB_RECURSE RESOURCE_FILES CONFIGURE_DEPENDS
     ${CMAKE_CURRENT_SOURCE_DIR}/*.txt)
target_sources(${PROJECT_NAME} PRIVATE ${SOURCE_FILES} ${HEADER_FILES}
                                       ${RESOURCE_FILES})

# Add include directories
target_include_directories(${PROJECT_NAME} PRIVATE include)

# Add libraries
include(FetchContent)
FetchContent_Declare(
  SimpleCxxLib
  GIT_REPOSITORY https://gitee.com/stickmind/SimpleCxxLib.git
  GIT_TAG main)
FetchContent_MakeAvailable(SimpleCxxLib)
target_link_libraries(${PROJECT_NAME} PRIVATE SimpleCxxLib)

# Copy Java backend
add_custom_command(
  TARGET ${PROJECT_NAME}
  POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy ${SimpleCxxLib_BINARY_DIR}/java/spl.jar
          ${CMAKE_CURRENT_BINARY_DIR})

# Copy resource files
file(COPY ${RESOURCE_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
