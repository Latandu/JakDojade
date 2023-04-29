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

void String::AddChar(char newChar){
    char* newStr;
    size_t len = getSize();
    if(len + 2 > reservedSize){
        reservedSize += 10;
        newStr = string;
        string = new char[reservedSize];
        strcpy(string, newStr);
        delete[] newStr;
        strncat(string, &newChar, 1);
        size = strlen(string);

    }
    else{
        strncat(string, &newChar, 1);
        size = strlen(string);
    }
}
void String::CopyString(String* other){
    if (other) {
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

char * String::c_str() const {
    return string;
}

