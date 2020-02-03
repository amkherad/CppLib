//
//

#ifndef CPPLIB_MANUALRESETEVENT_HPP
#define CPPLIB_MANUALRESETEVENT_HPP

namespace CppLib {

    class ManualResetEvent {
    private:

    public:
        explicit ManualResetEvent(bool isSet);

        ~ManualResetEvent();

        void set();

        void reset();

        void wait();

        void wait(unsigned int timeoutInMilliseconds);
    };

}

#endif //CPPLIB_MANUALRESETEVENT_HPP
