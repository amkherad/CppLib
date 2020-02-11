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

        T get(unsigned int i) const;
        void set(const T &item);

        void prepend(const T &item);

        void append(const T &item);

        T pop() const;

        void push(const T &item);

        unsigned int count();


    }

}

#endif //CPPLIB_LINKEDLIST_HPP
