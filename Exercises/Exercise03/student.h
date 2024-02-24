#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>

class Student {
public:
    int id;
    std::string name;
    int final_exam;
    int midterm;
    std::vector<int> hw_grades;

    double class_total_score() const;
    void printInfo() const;
};

#endif 
