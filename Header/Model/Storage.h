#pragma once
//
// Created by badiu on 4/14/2022.
//

#ifndef LAB_5_6_PB_4_STORAGE_H
#define LAB_5_6_PB_4_STORAGE_H
#include "../Model/Tutorial.h"

class Storage {
public:
    virtual void print() = 0;
    virtual void readStartUp() = 0;
    virtual void writeInFile() = 0;
    virtual void reWriteFile() = 0;

};

class File:public Storage{
private:
    string filename;
public:
    void print() override
    {

    }

};

class Html:public Storage{
private:
    string filename;
public:
    void print() override
    {

    }
};


#endif //LAB_5_6_PB_4_STORAGE_H
