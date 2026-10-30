cmake_minimum_required(VERSION 3.25)
project(shmbus VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SHMBUS_SANITIZE "" CACHE STRING "Sanitizer to build with: thread, address, undefined, or empty")
set_property(CACHE SHMBUS_SANITIZE PROPERTY STRINGS "" thread address undefined)

# Applied globally, before dependencies are fetched: TSan reports false
# positives if any code in the process, including the test framework, is
# uninstrumented.
if(SHMBUS_SANITIZE)
  add_compile_options(
    -fsanitize=${SHMBUS_SANITIZE}
    -fno-sanitize-recover=all
    -fno-omit-frame-pointer
    -g
  )
  add_link_options(-fsanitize=${SHMBUS_SANITIZE})
endif()

add_library(shmbus INTERFACE)
add_library(shmbus::shmbus ALIAS shmbus)
target_include_directories(shmbus INTERFACE include)

add_library(shmbus_warnings INTERFACE)
target_compile_options(shmbus_warnings INTERFACE -Wall -Wextra -Wpedantic -Werror)

include(FetchContent)

set(HDR_HISTOGRAM_CORE_ONLY ON CACHE BOOL "" FORCE)
FetchContent_Declare(
  hdr_histogram
  GIT_REPOSITORY https://github.com/HdrHistogram/HdrHistogram_c.git
  GIT_TAG 0.12.1
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(hdr_histogram)

include(CTest)
if(BUILD_TESTING)
  add_subdirectory(tests)
endif()
