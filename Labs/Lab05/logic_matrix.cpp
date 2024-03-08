#include "logic_matrix.h"

void Expensive_Digraph(Matrix& D1, Matrix& D0, Matrix& Dminus1) {
    int n = D0.size(); 
    for (int l = 2; l <= 3 * n * n + 1; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (D1[i][k] + Dminus1[k][j] == 0 || D1[i][k] + Dminus1[k][j] == 0)
                        D0[i][j] = 0;
                    if (D0[i][k] + D1[k][j] == 1 || D0[i][k] + D1[k][j] == 1)
                        D1[i][j] = 1;
                    if (D0[i][k] + Dminus1[k][j] == -1 || D0[i][k] + Dminus1[k][j] == -1)
                        Dminus1[i][j] = -1;
                }
            }
        }
    }
}
