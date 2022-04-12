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
    Tutorial entity5{">>",">>",10,11,">>"};
    stringstream str_cin(line_cin);
    str_cin >> entity4;
    assert(entity4 == entity5);


    cout << "Done Tutorial Test.\n";
}

void TestRepository() {
    Repository<Tutorial> repo{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt"};

}

void TestAdminController() {
    Repository<Tutorial> adminRepo{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt"};
    AdminController controller{adminRepo};
}

