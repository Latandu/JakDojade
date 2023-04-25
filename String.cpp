//
// Created by Latandu on 25/04/2023.
//

#include "String.h"
#include <cstring>
#define BUFFER 50

String::String() {
    string = new char[1];
    string[0] = '\0';
    size = 1;
}

String::String(const char *s) {
    if(s){
        size = strlen(s);
        string = new char [size + 1];
        strcpy(string, s);
    } else String();
}

String::String(const String& other) {
   size = strlen(other.string);
    string = new char[size + 1];
    std::strcpy(string, other.string);
}

String::~String(){
    delete[] string;
}

size_t String::getSize() const {
    return strlen(string);
}

void String::AddChar(char newChar){
    char* newStr;
    size_t len = getSize();
    if(len + 2 > reservedSize){
        reservedSize += 50;
        newStr = string;
        string = new char[reservedSize];
        strcpy(string, newStr);
        delete[] newStr;
        strncat(string, &newChar, 1);

    }
    else{
        strncat(string, &newChar, 1);
    }
}
char * String::c_str() const {
    return string;
}

