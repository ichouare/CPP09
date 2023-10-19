#ifndef RPN_H
#define RPN_H
#include <iostream>
#include <sstream>
#include <stack>
#include <exception>
#include <ctype.h>



void push_stack(std::string  str);
void printerror();
int is_operator(std::string str, int& op);
int reverse_polishNotation(std::stack<float> *st, std::string op);

#endif