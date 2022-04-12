#pragma once
//
// Created by badiu on 4/10/2022.
//

#ifndef LAB_5_6_PB_4_TEMPLATEREPOSITORY_H
#define LAB_5_6_PB_4_TEMPLATEREPOSITORY_H
#include "Tutorial.h"
#include <cstdlib>

//typedef Tutorial TElem;

template<typename T>
class Repository {
private:
    int size;
    int capacity;
    T* elems;

public:
    Repository();
    Repository(const Repository<T> &copy_repository);
    ~Repository();
    void add(T entity);
    void removeElement(int &pos);
    void updateElement(int &pos, T& new_entity);
    T &operator[](int pos);
    int getSize();

private:
    void resize();

};

#include "Repository.tpp"

#endif //LAB_5_6_PB_4_TEMPLATEREPOSITORY_H
