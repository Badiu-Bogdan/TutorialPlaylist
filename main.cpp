#include "Header/View/AdminUi.h"
#include "Header/View/UserUi.h"
#include "D:\Fisiere Facultate An3\OOP\Lab 5-6 Pb.4\Header\Exception\Test.h"

int main() {
    cout << "Starting Tests: \n";
    TestTutorial();
    cout << "Test Done \n";
    Repository<Tutorial> AdminAccountRepository{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\data.txt"};
    AdminController AdminAccountController{AdminAccountRepository};
    AdminUi AdminAccount{AdminAccountController};

    Repository<Tutorial> UserAccountRepository{"D:\\Fisiere Facultate An3\\OOP\\Lab 5-6 Pb.4\\Database\\watchListData.txt"};
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

    return 0;
}
