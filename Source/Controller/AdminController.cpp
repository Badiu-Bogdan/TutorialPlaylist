//
// Created by badiu on 3/25/2022.
//

#include "../../Header/Controller/AdminController.h"

AdminController::AdminController(Repository<Tutorial> &repository) : repo(repository) {
}

int AdminController::addTutorial(Tutorial &new_tutorial) {
    repo.add(new_tutorial);
    return 0;
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
    for(int i = 0;i < repo.getSize();i++)
        cout << "id:" << i << ", " << repo[i];
}

int AdminController::deleteTutorial(int &id) {
    repo.removeElement(id);
    return 0;
}

int AdminController::updateTutorial(int &id, Tutorial &new_tutorial) {
    Tutorial existent = repo[id];
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

    repo.updateElement(id, existent);

}


