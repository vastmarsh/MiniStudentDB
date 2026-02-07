#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
    public:
        int id;
        std::string name;
        int age;
        double score;

        Student();
        Student(int id, const std::string& name, int age, double score);
};

#endif