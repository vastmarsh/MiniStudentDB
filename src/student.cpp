#include "student.h"

Student::Student() : id(0), name(""), age(0), score(0.0) {}

Student::Student(int id, const std::string& name, int age, double score)
    : id(id), name(name), age(age), score(score) {}