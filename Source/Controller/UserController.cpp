//
// Created by badiu on 3/25/2022.
//

#include "../../Header/Controller/UserController.h"

UserController::UserController(Repository<Tutorial> &new_database, Repository<Tutorial> &new_watchlist) : database(new_database),
                                                                                      watchList(new_watchlist) {

}

void UserController::printWatchList() {
/*    for(int i = 0; i < watchList.getSize();i++)
        cout << watchList[i];
    cout << "Done. \n";*/
    for(auto&i:watchList.vector())
        cout << i;
    cout << "Done. \n";
}


Repository<struct Tutorial> UserController::getTutorialsByPresenter(string &presenter) {
/*    Repository<Tutorial> aux{};
    for(int i = 0; i < this->database.getSize();i++)
        if(database[i].getPresenter() == presenter)
            aux.add(this->database[i]);


    return aux;*/
}

void UserController::printTutorialList() {
/*    for(int i = 0; i < database.getSize();i++)
        cout << database[i];*/
    for(auto&i:database.vector())
        cout << i;

    cout << "Done. \n";
}

int UserController::addTutorialToWatchList(Tutorial &entity) {
    this->watchList.add(entity);
}

int UserController::deleteTutorialFromWatchList(Tutorial& entity) {
    for(int i = 0; i < watchList.getSize();i++)
        if(watchList[i] == entity)
        {
            watchList.removeElement(i);
            return 1;
        }
    return 0;
}

void UserController::likeTutorial(Tutorial &entity) {
    for(int i =0;i < database.getSize();i++)
        if(database[i] == entity)
        {
            database[i].like();
            return;
        }
}

list<Tutorial> UserController::getWatchList() {
    list<Tutorial> aux;
/*    for(int i=0;i<watchList.getSize();i++)
        aux.push_back(watchList[i]);*/
    for(auto&i:watchList.vector())
        aux.push_back(i);
    return aux;
}
