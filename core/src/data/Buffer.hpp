//
//

#ifndef CPPLIB_BUFFER_HPP
#define CPPLIB_BUFFER_HPP

namespace CppLib {

/**
 * A utility class to manage a buffer.
 */
    class Buffer {

    private:
        static Buffer &_emptyBuffer;

        unsigned long _size;
        void *_ptr;

        Buffer();

    public:

        Buffer(const Buffer &copy);

        Buffer(unsigned long size);

        Buffer(void *ptr, unsigned long pos, unsigned long size);

        ~Buffer();


        /**
         * @return The size of the buffer in bytes.
         */
        unsigned long size();

        /**
         * @param ptr pointer to the target data location.
         * @param start The start index which copy starts from.
         * @param size The size of the buffer which should be copied to the target data, pass -1 to copy remaining bytes.
         */
        void copy(void *ptr, unsigned long start, long size);

        static Buffer &empty();
    };

}

#endif //CPPLIB_BUFFER_HPP
