#pragma once
//
// Created by badiu on 4/10/2022.
//

#ifndef LAB_5_6_PB_4_STLREPOSITORY_TPP
#define LAB_5_6_PB_4_STLREPOSITORY_TPP

#include "Repository.h"

template<typename T>
Repository<T>::Repository(const string &new_fileName):fileName(new_fileName) {
    readStartUp();
}

template<typename T>
void Repository<T>::readStartUp() {
    ifstream readFile(this->fileName);
    if (!readFile) {
        //File not opened correctly
    } else {
        //File opened correctly
    }
    while (!readFile.eof()) {
        Tutorial entity;
        readFile >> entity;
        try {
            TutorialValidator::Validate(entity);
            this->elems.push_back(entity);
        }
        catch (InvaludArgument &error) {
            cout << "1 element not added. Read from file error. \n";
            cout << entity;
        }
    }

    readFile.close();
}

template<typename T>
Repository<T>::Repository(const Repository<T> &copy_repository) {
    for (auto &i: copy_repository) {
        this->elems.push_back(i);
    }
}

template<typename T>
Repository<T>::~Repository() {

}

template<typename T>
void Repository<T>::add(T entity) {
    this->elems.push_back(entity);
    writeInFile(entity);

}

template<typename T>
void Repository<T>::removeElement(int &pos) {
    this->elems.erase(this->elems.begin() + pos);
    reWriteFile();
}

template<typename T>
void Repository<T>::updateElement(int &pos, T &new_entity) {
    this->elems[pos] = new_entity;
    reWriteFile();

}

template<typename T>
T &Repository<T>::operator[](int pos) {
    return this->elems[pos];
}

template<typename T>
int Repository<T>::getSize() {
    return this->elems.size();
}

template<typename T>
void Repository<T>::writeInFile(T &entity) {
    ofstream file(this->fileName, ios_base::app);
    if (!file) {
        //file not opened
    } else {
        //file opened
        file << entity;
    }

}

template<typename T>
void Repository<T>::reWriteFile() {
    ofstream file(this->fileName);
    if (!file) {
        //file not opened
    } else {
        for (auto &i: this->elems)
            file << i;
    }

}

#endif //LAB_5_6_PB_4_STLREPOSITORY_TPP
