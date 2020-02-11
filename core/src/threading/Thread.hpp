//
//

#ifndef CPPLIB_THREAD_HPP
#define CPPLIB_THREAD_HPP

namespace CppLib {

    typedef void ThreadCallback();
    typedef void ThreadCallbackWithState(void* state);

    class Thread {

    public:
        explicit Thread(ThreadCallback* callback);
        explicit Thread(ThreadCallbackWithState* callback, void* state);

        void join();

        static void yield();

        static void sleep(unsigned int milliseconds);

        static void ensureInitialized(void ** ptr, void *(*initilizer)());

    };

}

#endif //CPPLIB_THREAD_HPP
