//
//

#include "ConditionalLockTarget.hpp"

CppLib::ConditionalLockTarget::ConditionalLockTarget() {

}

void *CppLib::ConditionalLockTarget::getTargetPtr() const {
    return &this->_target;
}
