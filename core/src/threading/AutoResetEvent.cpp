//
//

#include "AutoResetEvent.hpp"
#include "Monitor.hpp"
#include <Mutex.hpp>

CppLib::AutoResetEvent::AutoResetEvent(bool isSet) {
    _mutex = new Mutex();
    _isSet = isSet;
}

CppLib::AutoResetEvent::~AutoResetEvent() {
    delete _mutex;
}

void CppLib::AutoResetEvent::set() {

    _mutex->waitOne();

    _isSet = true;

    Monitor::pulse();

    _mutex->release();

}

void CppLib::AutoResetEvent::reset() {

    _mutex->waitOne();

    _isSet = false;

    _mutex->release();

}

void CppLib::AutoResetEvent::wait() {

    _mutex->waitOne();

    while (!_isSet) {

        Monitor::wait();

    }

    _isSet = false;

    _mutex->release();

}

void CppLib::AutoResetEvent::wait(unsigned int timeoutInMilliseconds) {

    _mutex->waitOne();

    while (!_isSet) {

        Monitor::wait();

    }

    _isSet = false;

    _mutex->release();

}
