//
// Created by Latandu on 25/04/2023.
//

#include "String.h"
#include <cstring>
#include <cstdlib>

String::String() {
    string = new char[1];
    string[0] = '\0';
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
bool String::CompareStrings(const String& other){
    if(strcmp(this->string, other.string) == 0) return true;
    return false;
}
String::~String(){
    delete[] string;
}

size_t String::getSize() const {
    return size;
}

void String::AddChar(char newChar) {
    if (size + 1 >= reservedSize) {
        reservedSize += 10;
        char* newString = new char[reservedSize];
        memcpy(newString, string, size);
        delete[] string;
        string = newString;
    }
    string[size++] = newChar;
    string[size] = '\0';
}
void String::CopyString(String* other){
    if (other && other != this) {
        size_t otherSize = other->getSize();
        if (otherSize > 0) {
            reservedSize = otherSize + 10;
            delete[] string;
            string = new char[reservedSize];
            size = otherSize;
            strcpy(string, other->string);
        } else {
            size = 0;
            reservedSize = 1;
            delete[] string;
            string = new char[reservedSize];
            string[0] = '\0';
        }
    } else {
        size = 0;
        reservedSize = 1;
        delete[] string;
        string = new char[reservedSize];
        string[0] = '\0';
    }
}

int String::StringToIntConversion(){
    char* pEnd;
    return strtol(this->string, &pEnd, 10);
}
String& String::operator=(const String& other) {
    if (this != &other) {
        char* new_string = new char[other.size + 1];
        strcpy(new_string, other.string);
        if (other.string == nullptr) return *this;
        delete[] string;
        string = new_string;
        size = other.size;
        reservedSize = other.reservedSize;

    }
    return *this;
}
char * String::c_str() const {
    return string;
}

