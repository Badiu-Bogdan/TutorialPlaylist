#pragma once
//
// Created by badiu on 3/25/2022.
//

#ifndef LAB_5_6_PB_4_USERCONTROLLER_H
#define LAB_5_6_PB_4_USERCONTROLLER_H


#include "../Model/Repository.h"
#include <list>

class UserController {
private:
    Repository<Tutorial>* database;
    Repository<Tutorial>* watchList;

public:
    UserController(Repository<Tutorial>& new_database, Repository<Tutorial>& new_watchlist);
    void printWatchList();
    void printTutorialList();
    int addTutorialToWatchList(Tutorial& entity);
    int deleteTutorialFromWatchList(Tutorial &entity);
    void likeTutorial(Tutorial& entity);
    vector<Tutorial> getTutorialsByPresenter(string &presenter);
    list<Tutorial> getWatchList();

};


#endif //LAB_5_6_PB_4_USERCONTROLLER_H
