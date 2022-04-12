//
// Created by badiu on 4/12/2022.
//
#include "D:\Fisiere Facultate An3\OOP\Lab 5-6 Pb.4\Header\Exception\Test.h"

void TestTutorial()
{
    Tutorial entity{"Titlu","Prezentator", 10, 11, "link"};

    //Test getter
    assert(entity.getTitle() == "Titlu");
    assert(entity.getPresenter() == "Prezentator");
    assert(entity.getMinutes() == 10);
    assert(entity.getSeconds() == 11);
    assert(entity.getLink() == "link");

    //Test setter

}
void TestRepository()
{
    Repository<Tutorial> repo{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt"};

}

void TestAdminController()
{
    Repository<Tutorial> adminRepo{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\testData.txt"};
    AdminController controller{adminRepo};
}

