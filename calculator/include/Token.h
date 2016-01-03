//
// Created by shobhit on 1/1/16.
//

#ifndef STRINGPERMUTATION_TOKEN_H
#define STRINGPERMUTATION_TOKEN_H

#include <vector>

class Token {
// a very simple user-defined type
public:
    char kind;
    double value;
    Token(char ch)    // make a Token from a char
            :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
            :kind(ch), value(val) { }
};

#endif //STRINGPERMUTATION_TOKEN_H
