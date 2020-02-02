//
//

#ifndef CPPLIB_LINKEDLIST_HPP
#define CPPLIB_LINKEDLIST_HPP

namespace CppLib {

    template<typename T>
    class LinkedList {

    private:

    public:
        LinkedList();

        ~LinkedList();


        void prepend(const T &item);

        void append(const T &item);

        unsigned int count();


    }

}

#endif //CPPLIB_LINKEDLIST_HPP
