#include <iostream>
#include <cstdlib>

#include "fisher_yates.cpp"

using namespace std;

int main() {
    string n_string;
    cout << "Enter the number of open-parens: " << endl;
    cin >> n_string;

    int n;

    n = stoi(n_string);

    cout << n << endl;

    int arrayValues[2*n];

    srand(time(NULL)); //seed bc use of rand

    //how to put in the +1 =1 now
    for (int i=0; i < n; i++) {
        arrayValues[i] = 1;
    }

    for (int i=0; i < n; i++){
        arrayValues[i+n] = -1;
    }

    print_array(arrayValues, 2*n);

}