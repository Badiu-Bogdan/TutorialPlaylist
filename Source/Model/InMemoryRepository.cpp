//
// Created by badiu on 4/10/2022.
//

/*
#include "../../Header/Model/Repository.h"

Repository::Repository() : size(0), capacity(20) {
    this->elems = new(std::nothrow) TElem[this->capacity];
    //if(!this->elems)
    //throw exception("Allocation of memory failed! \n");
}

Repository::~Repository() {
    if (this->elems == nullptr)
        return;
    else
        delete[] this->elems;

}

void Repository::add(TElem entity) {
    if (size == capacity)
        resize();
    else {
        this->elems[this->size] = entity;
        this->size++;
    }
}

void Repository::resize() {
    int new_capacity = this->capacity * 2;
    auto *aux = new(std::nothrow) TElem[new_capacity];
    //memcpy(aux, this->elems, sizeof(TElem)*size);
    for (int i = 0; i < size; i++)
        aux[i] = this->elems[i];
    delete[] this->elems;
    this->elems = aux;
    this->capacity = new_capacity;
}

Repository::Repository(const Repository &copy_repository) {
    this->size = copy_repository.size;
    this->capacity = copy_repository.capacity;
    this->elems = new(std::nothrow) TElem[this->capacity];
}

TElem &Repository::operator[](int pos) {
    if (pos > size)
        // throw error index out of bounds
        return this->elems[0];
    else
        return this->elems[pos];
}

int Repository::getSize() {
    return this->size;
}

void Repository::removeElement(int &pos) {
    if (pos > this->size)
        return; //Throw exception
    else {
        for (int i = pos; i < this->size - 1; i++)
            this->elems[i] = this->elems[i + 1];
        this->size--;
    }

}

void Repository::updateElement(int &pos, Tutorial &new_entity) {
    if(pos > this->size)
        return; //Throw exception
    else
    {
        this->elems[pos] = new_entity;
    }
}

*/
