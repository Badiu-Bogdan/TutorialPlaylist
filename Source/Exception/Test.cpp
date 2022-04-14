/*
//
// Created by badiu on 4/12/2022.
//
#include "D:\Fisiere Facultate An3\OOP\Lab 5-6 Pb.4\Header\Exception\Test.h"

void TestTutorial() {
    cout << "Starting Tutorial Test.\n";
    Tutorial entity{"Titlu", "Prezentator", 10, 11, "link"};

    //Test getter
    assert(entity.getTitle() == "Titlu");
    assert(entity.getPresenter() == "Prezentator");
    assert(entity.getMinutes() == 10);
    assert(entity.getSeconds() == 11);
    assert(entity.getLink() == "link");
    assert(entity.getLikes() == 0);

    //Test setter
    entity.setTitle("Titlu nou");
    assert(entity.getTitle() == "Titlu nou");
    entity.setPresenter("Prezentator nou");
    assert(entity.getPresenter() == "Prezentator nou");
    entity.setMinutes(20);
    assert(entity.getMinutes() == 20);
    entity.setSeconds(22);
    assert(entity.getSeconds() == 22);
    entity.setLink("link nou");
    assert(entity.getLink() == "link nou");
    entity.like();
    assert(entity.getLikes() == 1);
    entity.dislike();
    assert(entity.getLikes() == 0);

    //Test == operator
    Tutorial entity1{"Titlu", "Prezentator", 10, 11, "link"};
    Tutorial entity2{"Titlu", "Prezentator", 10, 11, "link"};
    assert(entity1 == entity2);
    entity1.setTitle("test");
    assert(entity1 != entity2);
    entity1.setTitle("Titlu");
    entity1.setPresenter("test");
    assert(entity1 != entity2);
    entity1.setPresenter("Prezentator");
    entity1.setMinutes(30);
    assert(entity1 != entity2);
    entity1.setMinutes(10);
    entity1.setSeconds(30);
    assert(entity1 != entity2);
    entity1.setSeconds(11);
    entity1.setLink("test");
    assert(entity1 != entity2);
    entity1.setLink("link");
    entity1.like();
    assert(entity1 != entity2);
    entity1.dislike();

    //Test <<
    Tutorial entity3{"<<", "<<", 10, 11, "<<"};
    std::stringstream str;
    str << entity3;
    string line_cou;
    str >> line_cou;
    assert(line_cou == "<<,<<,10,11,0,<<");

    //Test >>
    string line_cin{">>,>>,10,11,0,>>"};
    Tutorial entity4;
    Tutorial entity5{">>", ">>", 10, 11, ">>"};
    stringstream str_cin(line_cin);
    str_cin >> entity4;
    assert(entity4 == entity5);


    cout << "Done Tutorial Test.\n";
}

void TestRepository() {
    cout << "Starting Repository Test.\n";
    ofstream eraseFile("D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt");
    eraseFile.close();
    Repository<Tutorial> repo{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt"};

    //Test Constructor
    assert(repo.getSize() == 0);

    //Test Add Element
    repo.add(Tutorial{"test", "test", 10, 10, "test"});
    assert(repo.getSize() == 1);

    //Test Write To File
    ifstream readFile("D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt");
    Tutorial entity;
    readFile >> entity;
    Tutorial entity1{"test","test",10,10,"test"};
    assert(entity == entity1);

    //Test Remove Element
    int i = 0;
    repo.removeElement(i);
    assert(repo.getSize() == 0);
    string line;
    readFile >> line;
    assert(line.empty());

    //Test Update Element
    repo.add(Tutorial{"test","test", 10, 10,"test"});
    Tutorial update{"update","test", 10, 10,"test"};
    repo.updateElement(i, update);
    assert(repo[0].getTitle() == "update");

    cout << "Done Repository Test.\n";
}

void TestAdminController() {
    cout << "Starting Admin Controller testing!\n";
    ofstream eraseFile("D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt");
    eraseFile.close(); // Opening and closing the file so that existent content will be removed.

    Repository<Tutorial> adminRepo{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt"};
    AdminController controller{adminRepo};

    //Test AdminController Add
    Tutorial entity{"test","test", 10, 10,"test"};
    assert(controller.addTutorial(entity) == 1);
    assert(controller.addTutorial(entity) == 0);

    //Test Remove
    int position = 0;
    assert(controller.deleteTutorial(position) == 1);
    assert(controller.deleteTutorial(position) == 0);

    //Test Update
    Tutorial entity2{"update","test", 10, 10,"test"};
    controller.addTutorial(entity);
    assert(controller.updateTutorial(position, entity2) == 1);

    cout << "Done Admin Controller Test\n";
}

void TestUserController(){
    cout << "Starting User Controller testing!\n";

    cout << "Done User Controller Test\n";
}

*/
