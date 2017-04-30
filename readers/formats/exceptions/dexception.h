#ifndef DEXCEPTION_H
#define DEXCEPTION_H

#include <exception>

class Dexception : public std::exception {
public:

    Dexception(const char* msg)
        : message_{msg} { }

    const char* what() const noexcept {
        return message_;
    }

private:
    const char* message_;
};

#endif // DEXCEPTION_H
