include(FetchContent)
FetchContent_Declare(
    catch2
    URL https://github.com/catchorg/Catch2/archive/refs/tags/v3.5.2.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(catch2)

enable_testing()

add_executable(tests run_tests.cpp test_solver.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
target_link_libraries(tests PRIVATE core)
target_include_directories(tests PRIVATE ${catch2_SOURCE_DIR}/single_include)

include(Catch)
catch_discover_tests(tests)