#include <iostream>
#include <vector>
#include "well_formed.h" // Changed include to well_formed.h
#include "gen_permutation.h"

using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n ;
    cout << endl;

    for (int trial = 0; trial < 10; ++trial) {
        cout << "Trial " << (trial + 1) << ":" << endl;

        vector<int> symbols(2 * n + 1);

        for (int i = 0; i < n; ++i) symbols[i] = 1;

        for (int i = n; i < 2 * n + 1; ++i) symbols[i] = -1;
        cout << "Original list: ";
        for (int symbol : symbols) {
            cout << symbol << " ";
        }
        cout << endl;

        generate_permutation(&symbols[0], symbols.size()); // Corrected function call

        cout << "Scrambled list: ";
        for (int symbol : symbols) {
            cout << symbol << " ";
        }
        cout << endl;

        if (symbols[0] == -1) {
            cout << "Skip sequence -> starts with -1" << endl;
            cout << endl;
            continue; 
        }

        vector<int> wellFormedSymbols = generateWellFormedSequence(symbols); // Corrected function name

        cout << "Well formed sequence: ";
        for (int symbol : wellFormedSymbols) {
            cout << symbol << " ";
        }
        cout << endl;
        cout << endl;
    }
    
    return 0;
}
