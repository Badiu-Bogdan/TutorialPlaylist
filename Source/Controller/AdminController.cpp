//
// Created by badiu on 3/25/2022.
//

#include "../../Header/Controller/AdminController.h"

AdminController::AdminController(Repository<Tutorial> &repository) : repo(&repository) {
}

/*
 * This function will add a new tutorial in the repository.
 * The element will not be added 2 times.
 * If the function is in the repo addTutorial will return 0.
 * Otherwise will return 1.
 * Param: Tutorial new_tutorial.
 * return: 1 for success, otherwise 0.
 */
int AdminController::addTutorial(Tutorial &new_tutorial) {
    if(checkExistance(new_tutorial))
        return 0;
    repo->add(new_tutorial);
    return 1;
}

/*void AdminController::setUpElements() {
    repo.add(Tutorial{"video1", "presenter1", 10, 11, "link1"});
    repo.add(Tutorial{"video2", "presenter2", 20, 22, "link2"});
    repo.add(Tutorial{"video3", "presenter3", 30, 33, "link3"});
    repo.add(Tutorial{"video4", "presenter4", 40, 44, "link4"});
    repo.add(Tutorial{"video5", "presenter5", 50, 55, "link5"});
    repo.add(Tutorial{"video6", "presenter6", 60, 66, "link6"});
    repo.add(Tutorial{"video7", "presenter7", 70, 77, "link7"});
    repo.add(Tutorial{"video8", "presenter8", 80, 88, "link8"});
    repo.add(Tutorial{"video9", "presenter9", 90, 99, "link9"});
    repo.add(Tutorial{"video10", "presenter10", 55, 55, "link10"});
    repo.add(Tutorial{"video11", "presenter1", 12, 21, "link1"});
    repo.add(Tutorial{"video12", "presenter1", 23, 32, "link1"});
    repo.add(Tutorial{"video13", "presenter1", 34, 43, "link1"});
    repo.add(Tutorial{"video14", "presenter1", 45, 54, "link1"});
}*/

void AdminController::printAll() {
/*    for(int i = 0;i < repo.getSize();i++)
        cout << "id:" << i << ", " << repo[i];*/
    for(auto&i:repo->vector())
        cout << i;
}


/*
 * This function will delete a tutorial from position id in the repository.
 * Param: int position.
 * return: 1 for success, otherwise 0.
 */
int AdminController::deleteTutorial(int &id) {
    if(repo->getSize() == 0 || repo->getSize() < id || id < 0)
        return 0;
    repo->removeElement(id);
    return 1;
}


/*
 * This function will update a tutorial from position id in the repository.
 * Only the params of the new_tutorial that are defined will be changed in the old Tutorial from the
 * position id.
 * It can receive a tutorial only with the title set and will update just the title in the
 * old one.
 * Param: int position, Tutorial new_tutorial.
 * return: 1 for success, otherwise 0.
 */
int AdminController::updateTutorial(int &id, Tutorial &new_tutorial) {
    if(repo->getSize() == 0 || repo->getSize() < id || id < 0)
        return 0;
    Tutorial existent = (repo)->operator[](id);
    if(!new_tutorial.getTitle().empty())
        existent.setTitle(new_tutorial.getTitle());
    if(!new_tutorial.getPresenter().empty())
        existent.setPresenter(new_tutorial.getPresenter());
    if(new_tutorial.getMinutes() > 0)
        existent.setMinutes(new_tutorial.getMinutes());
    if(new_tutorial.getSeconds() > 0)
        existent.setSeconds(new_tutorial.getSeconds());
    if(!new_tutorial.getLink().empty())
        existent.setLink(new_tutorial.getLink());

    repo->updateElement(id, existent);
    return 1;

}

bool AdminController::checkExistance(Tutorial &entity) {
    bool result = false;
    for(auto &i:repo->vector())
        if(i == entity)
            result = true;

    return result;
}


