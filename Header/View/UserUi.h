#pragma once
//
// Created by badiu on 3/25/2022.
//

#ifndef LAB_5_6_PB_4_USERUI_H
#define LAB_5_6_PB_4_USERUI_H


#include "../Controller/UserController.h"

class UserUi {
private:
    UserController &controller;

public:
    UserUi(UserController &controller);
    void menu();

private:
    void printTutorialsByPresenter(string& presenter);
    void editWatchList();
};


#endif //LAB_5_6_PB_4_USERUI_H
