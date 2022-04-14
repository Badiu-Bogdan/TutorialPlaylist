#pragma once
//
// Created by badiu on 3/22/2022.
//

#ifndef LAB_5_6_PB_4_REPOSITORY_H
#define LAB_5_6_PB_4_REPOSITORY_H
#include "Tutorial.h"
#include "../../Header/Exception/TutorialValidator.h"
//typedef Tutorial TElem;

template<typename T>
class Repository {
private:
    string fileName;
    vector<T> elems;

public:
    explicit Repository(const string &new_fileName);
    Repository(const Repository<T> &copy_repository);
    ~Repository();
    void add(T entity);
    void removeElement(int &pos);
    void updateElement(int &pos, T& new_entity);
    T &operator[](int pos);
    auto vector(){return this->elems;
    }
    int getSize();

private:
    void readStartUp();
    void writeInFile(T& entity);
    void reWriteFile();

};

#include "StlRepository.tpp"

#endif //LAB_5_6_PB_4_REPOSITORY_H
