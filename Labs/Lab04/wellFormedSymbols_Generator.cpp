#include <iostream>
#include <vector>
#include "prefix_sum.h"
#include "gen_permutation.h"

using namespace std;

vector<int> generateWellFormedSymbols(const std::vector<int>& scrambledSymbols) {
    if (scrambledSymbols.empty() || scrambledSymbols[0] == -1) {
        return vector<int>(); 
    }

    int lowestValleyIndex = index_of_lowest_prefix_sum_element(&scrambledSymbols[0], scrambledSymbols.size());

    vector<int> P1(scrambledSymbols.begin(), scrambledSymbols.begin() + lowestValleyIndex + 1);
    vector<int> P2(scrambledSymbols.begin() + lowestValleyIndex + 1, scrambledSymbols.end());

    P1.pop_back(); 

    vector<int> wellBalancedSymbols;
    wellBalancedSymbols.insert(wellBalancedSymbols.end(), P2.begin(), P2.end());
    wellBalancedSymbols.insert(wellBalancedSymbols.end(), P1.begin(), P1.end());

    return wellBalancedSymbols;
}
