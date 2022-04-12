#pragma once
//
// Created by badiu on 4/12/2022.
//
#include <exception>
#include <string>

#ifndef LAB_5_6_PB_4_CUSTOMEXCEPTION_H
#define LAB_5_6_PB_4_CUSTOMEXCEPTION_H

class CustomException:public std::exception
{
private :
    std::string error;
public:
    explicit CustomException(std::string new_error){this->error = std::move(new_error);};
    virtual const char* what() const throw()
    {
        return this->error.c_str();
    };

};

class InvalidArgument:public std::exception
{
private:
    std::string error;
public:
    explicit InvalidArgument(std::string new_error){this->error = std::move(new_error);};
    virtual const char* what() const throw()
    {
        return this->error.c_str();
    };
};

#endif //LAB_5_6_PB_4_CUSTOMEXCEPTION_H
