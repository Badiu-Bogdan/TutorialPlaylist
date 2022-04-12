/*
#pragma once
//
// Created by badiu on 3/29/2022.
//

#ifndef LAB_5_6_PB_4_REPOSITORY_TPP
#define LAB_5_6_PB_4_REPOSITORY_TPP

template<typename T>
Repository<T>::Repository() : size(0), capacity(20) {
    this->elems = new(std::nothrow) T[this->capacity];
    //if(!this->elems)
    //throw exception("Allocation of memory failed! \n");
}

template<typename T>
Repository<T>::~Repository() {
    if (this->elems == nullptr)
        return;
    else
        delete[] this->elems;

}

template<typename T>
void Repository<T>::add(T entity) {
    if (size == capacity)
        resize();
    else {
        this->elems[this->size] = entity;
        this->size++;
    }
}

template<typename T>
void Repository<T>::resize() {
    int new_capacity = this->capacity * 2;
    auto *aux = new(std::nothrow) T[new_capacity];
    //memcpy(aux, this->elems, sizeof(TElem)*size);
    for (int i = 0; i < size; i++)
        aux[i] = this->elems[i];
    delete[] this->elems;
    this->elems = aux;
    this->capacity = new_capacity;
}

template<typename T>
Repository<T>::Repository(const Repository<T> &copy_repository) {
    this->size = copy_repository.size;
    this->capacity = copy_repository.capacity;
    this->elems = new(std::nothrow) T[this->capacity];
    for(int i =0;i<this->size;i++)
    {
        elems[i] = copy_repository.elems[i];
    }
    cout << "Repository copied \n";
}

template<typename T>
T &Repository<T>::operator[](int pos) {
    if (pos > size)
        // throw error index out of bounds
        return this->elems[0];
    else
        return this->elems[pos];
}

template<typename T>
int Repository<T>::getSize() {
    return this->size;
}

template<typename T>
void Repository<T>::removeElement(int &pos) {
    if (pos > this->size)
        return; //Throw exception
    else {
        for (int i = pos; i < this->size - 1; i++)
            this->elems[i] = this->elems[i + 1];
        this->size--;
    }

}

template<typename T>
void Repository<T>::updateElement(int &pos, T &new_entity) {
    if(pos > this->size)
        return; //Throw exception
    else
    {
        this->elems[pos] = new_entity;
    }
}

#endif //LAB_5_6_PB_4_REPOSITORY_TPP

*/
