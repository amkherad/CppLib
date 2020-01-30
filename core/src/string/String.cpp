//
//

#include "String.hpp"
#include <string>
#include <cstring>

namespace CppLib {

    String::String() {
        this->_buffer = new std::wstring(L"");
    }

    String::String(const String &str) {
        this->_buffer = new std::wstring(*str._buffer);
    }

    String::String(const wchar_t *str) {
        this->_buffer = new std::wstring(str);
    }

    String::String(const char *str) {
        const int size = strlen(str);

        this->_buffer = new std::wstring();
    }

    String::String(const unsigned int size, const char *str) {
        this->_buffer = new std::wstring();
    }

    String::String(const unsigned int size, const wchar_t *str) {
        this->_buffer = new std::wstring(str, size);
    }

    String::~String() {
        delete this->_buffer;
    }

    unsigned int String::size() {
        return this->_buffer->size();
    }

    String &String::operator=(const String &str) {
        return *new String(str);
    }

    String &String::operator=(const char *str) {
        return *(new String(str));
    }

    String &String::operator=(const wchar_t *str) {
        return *(new String(str));
    }

    const String &String::operator+(const String &str) {

    }

    String *String::append(const String &str) {

    }

    String *String::concat(const String &str1, const String &str2) {
        return nullptr;
    }

    String *String::concat(const String &str1, const String &str2, const String &str3) {
        return nullptr;
    }

    String *String::concat(const String &str1, const String &str2, const String &str3, const String &str4) {
        return nullptr;
    }

    String *
    String::concat(const String &str1, const String &str2, const String &str3, const String &str4, const String &str5) {
        return nullptr;
    }

}