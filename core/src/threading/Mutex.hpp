//
//

#ifndef CPPLIB_MUTEX_HPP
#define CPPLIB_MUTEX_HPP

namespace CppLib {

    class Mutex {
    private:

    public:
        Mutex();

        ~Mutex();


        void release();

        void waitOne();
        void waitOne(unsigned int timeoutInMilliseconds);

    };

}

#endif //CPPLIB_MUTEX_HPP
