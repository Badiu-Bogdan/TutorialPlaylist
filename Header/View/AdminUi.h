#pragma once
//
// Created by badiu on 3/25/2022.
//

#ifndef LAB_5_6_PB_4_ADMINUI_H
#define LAB_5_6_PB_4_ADMINUI_H


#include "../Controller/AdminController.h"

class AdminUi {
private:
    AdminController &controller;

public:
    AdminUi(AdminController &controller):controller(controller){};
    void menu();

};


#endif //LAB_5_6_PB_4_ADMINUI_H
