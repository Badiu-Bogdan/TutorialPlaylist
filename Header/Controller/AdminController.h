#pragma once
//
// Created by badiu on 3/25/2022.
//

#ifndef LAB_5_6_PB_4_ADMINCONTROLLER_H
#define LAB_5_6_PB_4_ADMINCONTROLLER_H


#include "../Model/Repository.h"

class AdminController {
private:
    Repository<Tutorial> &repo;

public:
    explicit AdminController(Repository<Tutorial> &repository);
    int addTutorial(Tutorial& new_tutorial);
    int deleteTutorial(int &id);
    int updateTutorial(int &id, Tutorial& new_tutorial);
    //void setUpElements();
    void printAll();
};


#endif //LAB_5_6_PB_4_ADMINCONTROLLER_H
