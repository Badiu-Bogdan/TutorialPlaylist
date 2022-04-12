//
// Created by badiu on 3/25/2022.
//

#include "../../Header/View/AdminUi.h"

void print_menu() {
    cout << "\n";
    cout << "Menu: \n";
    cout << "Press 1 to print all tutorials. \n";
    cout << "Press 2 to add a new tutorial. \n";
    cout << "Press 3 to delete a tutorial. \n";
    cout << "Press 4 to update a tutorial. \n";
}

Tutorial read_tutorial() {
    string new_title;
    string new_presenter;
    int new_minutes;
    int new_seconds;
    string new_link;

    //cin.clear();
    //fflush(stdin);
    cout << "Insert the title: \n";
    cin.get();
    getline(cin, new_title);
    cout << "Insert the presenter: \n";
    getline(cin, new_presenter);
    cout << "Insert duration minutes: \n";
    cin >> new_minutes;
    cout << "Insert duration seconds: \n";
    cin >> new_seconds;
    cout << "Insert link: \n";
    cin.get();
    getline(cin, new_link);

    Tutorial new_tutorial{new_title, new_presenter, new_minutes, new_seconds, new_link};
    return new_tutorial;

}

void AdminUi::menu() {
    int choice;
    int id;
    while (true) {
        print_menu();
        cout << "Please enter a value: ";
        cin >> choice;
        cin.get();
        if (choice == 0)
            return;

        if (choice == 1) {
            controller.printAll();
        }

        if (choice == 2) {
            try{
                Tutorial new_tutorial = read_tutorial();
                TutorialValidator::Validate(new_tutorial);
                controller.addTutorial(new_tutorial);
            }
            catch(InvaludArgument &error)
            {
                cout << error.what();
            }
        }

        if(choice == 3)
        {
            cout << "Insert id: ";
            cin >> id;
            if(id < 0)
                cout << "Id cannot be negative! \n";
            else
                controller.deleteTutorial(id);
        }

        if(choice == 4)
        {
            cout << "Insert id: ";
            cin >> id;
            Tutorial new_tutorial = read_tutorial();
            controller.updateTutorial(id, new_tutorial);
        }

    }
}
