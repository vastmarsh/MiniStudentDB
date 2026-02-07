#include <iostream>
using namespace std;

// 显示菜单
void showMenu() {
    cout << "===== Student DB =====" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Update Student" << endl;
    cout << "4. List Students" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    int choice;

    while(true){
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Bye!" << endl;
            break;
        }

        cout << "You selected: " << choice << endl;
    }
    return 0;
}