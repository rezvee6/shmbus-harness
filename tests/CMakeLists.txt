FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.8.1
  GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(Catch)

add_executable(shmbus_tests smoke_test.cpp histogram_test.cpp)
target_link_libraries(shmbus_tests PRIVATE
  shmbus::shmbus
  shmbus_warnings
  hdr_histogram::hdr_histogram_core_static
  Catch2::Catch2WithMain
)

catch_discover_tests(shmbus_tests)
