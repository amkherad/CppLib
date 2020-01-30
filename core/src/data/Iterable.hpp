//
//

#ifndef CPPLIB_ITERABLE_HPP
#define CPPLIB_ITERABLE_HPP

/**
 * An abstract class to provide iteration over an array-like data structure.
 * @tparam T
 */
template <typename T>
class Iterable {

public:

   T current() = 0;

   bool next() = 0;

   void dispose() = 0;

};

//#define foreach(item, iterable) for(auto item = iterable->current(); iterable->next(); iterable->)

#endif //CPPLIB_ITERABLE_HPP
