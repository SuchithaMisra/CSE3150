#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "student.h"

TEST_CASE("Student") {

    SUBCASE("Edge Cases") {
        Student student; 
        CHECK(0 == student.hw_grades.size());

        Student student_1 = get_a_student();
        string name = student_1.name;
        CHECK(4 == student_1.hw_grades.size());
        CHECK(name == student_1.name);
    };

    SUBCASE("Small Cases"){
        string name = "Grace Hopper";
        vector<int> hws = {99,98,100,100};
        Student student(9999, name,100,99,hws);

        CHECK(student.name == name);

        int i=0;
        for (auto hw:student.hw_grades) {
            CHECK(hws[i++] == hw);
        }

    };
}
