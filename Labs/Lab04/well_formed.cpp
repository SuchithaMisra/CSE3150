#include <iostream>
#include <vector>
#include "prefix_sum.h"
#include "gen_permutation.h" // Changed include to gen_permutation.h

using namespace std;

vector<int> generate_well_formed_sequence(const std::vector<int>& scrambledSymbols) { 
    if (scrambledSymbols.empty() || scrambledSymbols[0] == -1) {
        return vector<int>(); 
    }

    int lowest_valley_index = find_min_prefix_index(&scrambledSymbols[0], scrambledSymbols.size()); 

    vector<int> P1(scrambledSymbols.begin(), scrambledSymbols.begin() + lowest_valley_index + 1);
    vector<int> P2(scrambledSymbols.begin() + lowest_valley_index + 1, scrambledSymbols.end());

    P1.pop_back(); 

    vector<int> well_balanced_symbols;
    well_balanced_symbols.insert(well_balanced_symbols.end(), P2.begin(), P2.end());
    well_balanced_symbols.insert(well_balanced_symbols.end(), P1.begin(), P1.end());

    return well_balanced_symbols;
}
