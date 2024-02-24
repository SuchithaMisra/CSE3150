#include <iostream>
#include <fstream>
#include "student.h"

using namespace std;

Student::Student() {};
Student::Student(int id, string name, int midterm, int final_exam, vector<int> & hw_grades) 
: id(id), name(name), midterm(midterm), final_exam(final_exam), hw_grades(hw_grades){
};

Student get_a_student(){
    Student student;

    student.name = "Jonny von Neumann";
    student.final_exam = 90;
    student.midterm = 99;
    student.id = 9999;
    student.hw_grades.push_back(89);
    student.hw_grades.push_back(100);
    student.hw_grades.push_back(98);
    student.hw_grades.push_back(100);

    return student;
}

void print_student(Student student) {
    cout <<"ID: "
         << student.id 
         << " Name: " 
         << student.name << endl;
    cout << "Midterm: "
         <<student.midterm 
         << endl;
    cout << "Final: "
         <<student.final_exam << endl;
    cout << "Homeworks:" << endl;

    for (auto hw: student.hw_grades) {
        cout << hw << " ";
    }
    cout << endl;
}