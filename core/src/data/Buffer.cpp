//
//

#include <malloc.h>
#include <cstring>
#include "Buffer.hpp"

namespace CppLib {

    Buffer::Buffer() {
        this->_size = 0;
        this->_ptr = nullptr;
    }

    Buffer::Buffer(const Buffer &copy) {
        this->_size = copy._size;
        this->_ptr = copy._ptr;
    }

    Buffer::Buffer(unsigned long size) {
        this->_size = size;
        this->_ptr = malloc(size);
    }

    Buffer::Buffer(void *ptr, unsigned long pos, unsigned long size) {
        if (size == 0) {

            this->_size = 0;
            this->_ptr = nullptr;

        } else {

            this->_size = size;
            this->_ptr = reinterpret_cast<void *>(new unsigned char[size]);

            std::memcpy(
                    this->_ptr,
                    reinterpret_cast<void *>(
                            reinterpret_cast<long>(ptr) + pos
                    ),
                    size
            );

        }
    }

    Buffer::~Buffer() {
        delete[] reinterpret_cast<unsigned char *>(this->_ptr);
    }

    unsigned long Buffer::size() {
        return this->_size;
    }


    Buffer &Buffer::empty() {
        return Buffer::_emptyBuffer;
    }

}