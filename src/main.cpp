/*
 * main.cpp
 * MiniStudentDB 主程序入口
 * 实现菜单展示与用户输入处理，并调用 Database 执行 CRUD 操作
 */

#include <iostream>
#include <string>
#include "database.h"
using namespace std;

// 显示菜单
void showMenu() {
    cout << "===== Student DB =====" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Delete student" << endl;
    cout << "3. Update student" << endl;
    cout << "4. List students" << endl;
    cout << "0. Exit" << endl;
}

int main() {
    Database db("data/student.db");  // 连接数据库
    int choice;

    while (true) {
        showMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Bye!" << endl;
            break;
        }

        // 添加学生
        if (choice == 1) {
            string name;
            int age;
            double score;

            cout << "Name: ";
            cin >> name;
            cout << "Age: ";
            cin >> age;
            cout << "Score: ";
            cin >> score;

            string sql = "INSERT INTO student (name, age, score) VALUES ('" +
                         name + "', " + to_string(age) + ", " + to_string(score) + ");";

            db.execute(sql);
        }

        // 删除学生
        else if (choice == 2) {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;

            string sql = "DELETE FROM student WHERE id=" + to_string(id) + ";";
            db.execute(sql);
        }

        // 更新学生
        else if (choice == 3) {
            int id, age;
            string name;
            double score;

            cout << "ID: ";
            cin >> id;
            cout << "New name: ";
            cin >> name;
            cout << "New age: ";
            cin >> age;
            cout << "New score: ";
            cin >> score;

            string sql = "UPDATE student SET name='" + name +
                         "', age=" + to_string(age) +
                         ", score=" + to_string(score) +
                         " WHERE id=" + to_string(id) + ";";

            db.execute(sql);
        }

        // 列出学生
        else if (choice == 4) {
            string sql = "SELECT * FROM student;";
            db.execute(sql);
            cout << "(Note: SELECT results appear in terminal automatically)" << endl;
        }
    }

    return 0;
}