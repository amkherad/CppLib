//
//

#ifndef CPPLIB_THREAD_HPP
#define CPPLIB_THREAD_HPP

namespace CppLib {

    class Thread {

    public:


        static void yield();

        static void sleep(unsigned int milliseconds);

        static void ensureInitialized(void ** ptr, void *(*initilizer)());

    };

}

#endif //CPPLIB_THREAD_HPP
