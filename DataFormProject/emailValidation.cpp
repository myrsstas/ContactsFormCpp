//Application development in popular integrated development environments � 2023 by Myrsini Stasinou is licensed under CC-BY-4.0 
#include <iostream>
#include <string>
#include <regex>
#include "msclr\marshal_cppstd.h"

using namespace System;

bool isEmailValid1(std::string email)
{

    // Regular expression definition
    const std::regex pattern(
        "(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    // Match the string pattern
    // with regular expression
    return regex_match(email, pattern);

}
