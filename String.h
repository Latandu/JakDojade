//
// Created by Latandu on 25/04/2023.
//

#ifndef JAKDOJADE_STRING_H
#define JAKDOJADE_STRING_H


#include <cstring>

class String {
private:
    char* string;
    int size;
    int reservedSize = 0;
public:
    String();
    String(const char* s);
    String(const String& other);
    size_t getSize() const;
    void AddChar(char newChar);
    ~String();
    char* c_str() const;
};


#endif //JAKDOJADE_STRING_H
