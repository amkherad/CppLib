
add_executable(
        CppLibTests
        src/main.cpp
)

target_link_libraries("CppLibTests" PRIVATE "${PROJECT_NAME}")