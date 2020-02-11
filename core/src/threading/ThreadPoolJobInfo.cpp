//
//

#include "ThreadPoolJobInfo.hpp"

namespace CppLib {

    ThreadPoolJobInfo::ThreadPoolJobInfo(ThreadPoolCallback *callback) {

        this->_voidCallback = callback;
        this->_stateCallback = nullptr;
        this->_state = nullptr;
        this->_isWithState = false;

    }

    ThreadPoolJobInfo::ThreadPoolJobInfo(ThreadPoolCallbackWithState *callback, void *state) {

        this->_voidCallback = nullptr;
        this->_stateCallback = callback;
        this->_state = state;
        this->_isWithState = true;

    }


    void ThreadPoolJobInfo::execute() {

        if (this->_isWithState) {

            this->_stateCallback(this->_state);

        } else {

            this->_voidCallback();

        }

    }

}