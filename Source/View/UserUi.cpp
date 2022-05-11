//
// Created by badiu on 3/25/2022.
//

#include "../../Header/View/UserUi.h"

UserUi::UserUi(UserController &controller) : controller(controller) {

}

void printMenu() {
    cout << "User-Menu: \n";
    cout << "Press 0 to exit. \n";
    cout << "Press 1 to see tutorials having a given presenter. \n";
    cout << "Press 2 to see watch list. \n";
    cout << "Press 3 to edit watch list. \n";
}

void UserUi::menu() {
    int choice;
    while (true) {
        printMenu();
        cout << "Insert choice: ";
        cin >> choice;
        cin.get();
        if (choice == 0)
            return;

        if (choice == 1) {
            string presenter;
            cout << "Insert Presenter name: \n";
            getline(cin, presenter);
            printTutorialsByPresenter(presenter);

        }

        if (choice == 2) {
            controller.printWatchList();
        }

        if(choice == 3)
        {
            editWatchList();
        }
    }

}

void UserUi::printTutorialsByPresenter(string &presenter) {
    //First if to print in case of a empty presenter i will print the list with all elements at once
    if (presenter.empty()) {
        controller.printTutorialList();
        return;
    }

    vector<Tutorial> tutorial_list = controller.getTutorialsByPresenter(
            presenter); //Iau lista sortata sau intreaga din controller


    int choice;
    for (int i = 0; i < tutorial_list.size(); i++) {
        cout << tutorial_list[i];
        cout << "Open in browser(Press 1) or next(Press 2) or addToWatchList(Press3) or exit(Press 0): ";
        cin >> choice;
        if (choice == 1) { //Creating a char to execute the open command
            string command = "<Chrome> " + tutorial_list[i].getLink();
            char *str = &command[0];
            system(str);
        }

        if (choice == 2 && (i + 1) == tutorial_list.size()) //Daca am ajuns la ultimul element o iau de la capat
            i = -1;

        if(choice == 3)
            this->controller.addTutorialToWatchList(tutorial_list[i]);

        if (choice == 0)
            break;
    }
    cout << "Done! \n";
}

void UserUi::editWatchList() {
    list<Tutorial> watchList = controller.getWatchList();
    int choice;
    for(auto & it : watchList) {
        cout << it;
        cout << "Press 1 to like and delete or 2 for delete only or any key to skip. ";
        cin >> choice;
        if (choice == 1)
        {
            controller.likeTutorial(it);
            controller.deleteTutorialFromWatchList(it);
        }
        if(choice == 2)
        {
            controller.deleteTutorialFromWatchList(it);
        }

    }
}
