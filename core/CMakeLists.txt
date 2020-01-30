
set(LIBRARY_NAME "${PROJECT_NAME}")

add_library(
        "${LIBRARY_NAME}" SHARED

        src/data/Iterable.hpp

        src/data/Buffer.hpp
        src/data/Buffer.cpp

        src/string/String.hpp
        src/string/String.cpp

        src/threading/TaskScheduler.hpp
        src/threading/TaskScheduler.cpp
        src/threading/ThreadPool.hpp
        src/threading/ThreadPool.cpp
        src/threading/AsyncTask.hpp
        src/threading/AsyncTask.cpp

)


target_include_directories(
        "${LIBRARY_NAME}" PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/data"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/string"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/threading"
)
