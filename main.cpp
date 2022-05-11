#include "Header/View/AdminUi.h"
#include "Header/View/UserUi.h"
#include "D:\Fisiere Facultate An3\OOP\Lab 5-6 Pb.4\Header\Exception\Test.h"

int main() {
/*    cout << "Starting Tests: \n";
    TestTutorial();
    TestRepository();
    TestAdminController();
    TestUserController();
    cout << "Tests Done \n";*/
/*

    Repository<Tutorial> UserAccountRepository{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\watchListData.txt"};
    UserController UserAccountController{AdminAccountRepository, UserAccountRepository};
    UserUi UserAccount{UserAccountController};*/


    FileRepository<Tutorial> AdminAccountRepository{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\data.txt"};
    AdminController AdminAccountController{AdminAccountRepository};
    AdminUi AdminAccount{AdminAccountController};

    int choice;
    cout << "Type 1 for csv and 2 for html: ";
    cin >> choice;
    if(choice == 1)
    {
        FileRepository<Tutorial> UserAccountRepository{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\watchListData.txt"};
        UserController UserAccountController{AdminAccountRepository, UserAccountRepository};
        UserUi UserAccount{UserAccountController};

        int type;
        while(true) {
            cout << "For Admin press 1 \nFor User press 2. \n";
            cin >> type;
            if (type == 1)
                AdminAccount.menu();
            if (type == 2)
                UserAccount.menu();
            else
                break;
        }
    }
    if(choice == 2)
    {
        HtmlRepository<Tutorial> UserAccountRepository{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\webpage.html"};
        UserController UserAccountController{AdminAccountRepository, UserAccountRepository};
        UserUi UserAccount{UserAccountController};

        int type;
        while(true) {
            cout << "For Admin press 1 \nFor User press 2. \n";
            cin >> type;
            if (type == 1)
                AdminAccount.menu();
            if (type == 2)
                UserAccount.menu();
            else
                break;
        }
    }
    else
        return 0;



/*    int type;
    while(true) {
        cout << "For Admin press 1 \nFor User press 2. \n";
        cin >> type;
        if (type == 1)
            AdminAccount.menu();
        if (type == 2)
            UserAccount.menu();
        else
            break;
    }*/

    return 0;
}
