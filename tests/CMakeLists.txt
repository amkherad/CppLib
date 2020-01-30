
add_executable(
        CppLibTests
        main.cpp
)

target_link_libraries("${PROJECT_NAME}" PRIVATE "${PROJECT_NAME}")