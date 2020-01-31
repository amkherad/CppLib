
set(LIBRARY_NAME CppLib)

add_library(
        "${LIBRARY_NAME}" SHARED

        src/data/Iterable.hpp

        src/data/Buffer.hpp
        src/data/Buffer.cpp

        src/string/String.hpp
        src/string/String.cpp

        src/data/LinkedList.hpp
        src/data/LinkedList.cpp

        src/threading/TaskScheduler.hpp
        src/threading/TaskScheduler.cpp
        src/threading/ThreadPool.hpp
        src/threading/ThreadPool.cpp
        src/threading/AsyncTask.hpp
        src/threading/AsyncTask.cpp
        src/threading/Thread.hpp
        src/threading/Thread.cpp
        src/threading/Semaphore.hpp
        src/threading/Semaphore.cpp
        src/threading/Mutex.hpp
        src/threading/Mutex.cpp
        src/threading/ManualResetEvent.hpp
        src/threading/ManualResetEvent.cpp
        src/threading/AutoResetEvent.hpp
        src/threading/AutoResetEvent.cpp

)


target_include_directories(
        "${LIBRARY_NAME}" PUBLIC
        "${CMAKE_CURRENT_SOURCE_DIR}/src"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/data"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/string"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/threading"
)
