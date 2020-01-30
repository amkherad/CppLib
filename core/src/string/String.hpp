//
//

#ifndef CPPLIB_STRING_HPP
#define CPPLIB_STRING_HPP

#include <string>


namespace CppLib {
/**
 * Represents a string of characters.
 */
    class String {
    private:
        std::wstring *_buffer;

    public:
        String();

        String(const String &str);

        String(const char *str);

        String(const wchar_t *str);

        String(unsigned int size, const char *str);

        String(unsigned int size, const wchar_t *str);

        ~String();


        /**
         * @return The size of the string.
         */
        unsigned int size();

        String *append(const String &str);


        String &operator=(const String &str);

        String &operator=(const char *str);

        String &operator=(const wchar_t *str);

        const String &operator+(const String &str);


        static String *concat(const String &str1, const String &str2);

        static String *concat(const String &str1, const String &str2, const String &str3);

        static String *concat(const String &str1, const String &str2, const String &str3, const String &str4);

        static String *
        concat(const String &str1, const String &str2, const String &str3, const String &str4, const String &str5);

    };

}

#endif //CPPLIB_STRING_HPP
