//
//

#ifndef CPPLIB_AUTORESETEVENT_HPP
#define CPPLIB_AUTORESETEVENT_HPP

namespace CppLib {

    class Mutex;

    class AutoResetEvent {
    private:
        Mutex* _mutex;
        bool _isSet;

    public:
        explicit AutoResetEvent(bool isSet);

        ~AutoResetEvent();

        void set();

        void reset();

        void wait();

        void wait(unsigned int timeoutInMilliseconds);
    };

}

#endif //CPPLIB_AUTORESETEVENT_HPP
