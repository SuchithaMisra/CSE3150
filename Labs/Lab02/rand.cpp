#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 20; i++) {
    int randomNumber = rand () % 11; //0 - 10
    cout << randomNumber << endl;
    }
}
 