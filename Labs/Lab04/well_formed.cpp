#include <iostream>
#include <vector>
#include "prefix_sum.h"
#include "well_formed.h"

using namespace std;

vector<int> permuteWellFormed(const std::vector<int>& scrambledSymbols) { // Changed function name
    if (scrambledSymbols.empty() || scrambledSymbols[0] == -1) {
        return vector<int>(); 
    }

    int lowestValleyIndex = min_prefix_index(&scrambledSymbols[0], scrambledSymbols.size()); // Changed function name

    vector<int> P1(scrambledSymbols.begin(), scrambledSymbols.begin() + lowestValleyIndex + 1);
    vector<int> P2(scrambledSymbols.begin() + lowestValleyIndex + 1, scrambledSymbols.end());

    P1.pop_back(); 

    vector<int> wellBalancedSymbols;
    wellBalancedSymbols.insert(wellBalancedSymbols.end(), P2.begin(), P2.end());
    wellBalancedSymbols.insert(wellBalancedSymbols.end(), P1.begin(), P1.end());

    return wellBalancedSymbols;
}
