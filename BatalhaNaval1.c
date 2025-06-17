#include <stdio.h>

int main() {
    int n = 10;
    int navSize = 3;
    int grid[10][10];

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            grid[x][y] = 0;
        }
    }

    int shipH[3] = {3, 3, 3};
    int rowH = 2;
    int colH = 4;

    for (int i = 0; i < navSize; i++) {
        grid[rowH][colH + i] = shipH[i];
    }

    int shipV[3] = {3, 3, 3};
    int rowV = 5;
    int colV = 7;

    for (int i = 0; i < navSize; i++) {
        grid[rowV + i][colV] = shipV[i];
    }

    int shipD1[3] = {3, 3, 3};
    int rowD1 = 4;
    int colD1 = 3;

    for (int i = 0; i < navSize; i++) {
        grid[rowD1 + i][colD1 - i] = shipD1[i];
    }

    int shipD2[3] = {3, 3, 3};
    int rowD2 = 7;
    int colD2 = 3;

    for (int i = 0; i < navSize; i++) {
        grid[rowD2 + i][colD2 + i] = shipD2[i];
    }

    int cone[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {5, 5, 5, 5, 5}
    };
    int coneRow = 0;
    int coneCol = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int val = cone[i][j];
            if (val != 0) {
                int r = coneRow + i;
                int c = coneCol + j - 2;
                if (r >= 0 && r < n && c >= 0 && c < n) {
                    grid[r][c] = val;
                }
            }
        }
    }

    int octa[3][5] = {
        {0, 0, 5, 0, 0},
        {0, 5, 5, 5, 0},
        {0, 0, 5, 0, 0}
    };
    int octaRow = 6;
    int octaCol = 2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int val = octa[i][j];
            if (val != 0) {
                int r = octaRow + i;
                int c = octaCol + j;
                if (r >= 0 && r < n && c >= 0 && c < n) {
                    grid[r][c] = val;
                }
            }
        }
    }

    int cross[3][5] = {
        {0, 0, 5, 0, 0},
        {5, 5, 5, 5, 5},
        {0, 0, 5, 0, 0}
    };
    int crossRow = 0;
    int crossCol = 7;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int val = cross[i][j];
            if (val != 0) {
                int r = crossRow + i;
                int c = crossCol + j - 2;
                if (r >= 0 && r < n && c >= 0 && c < n) {
                    grid[r][c] = val;
                }
            }
        }
    }

    printf("Tabuleiro Batalha Naval:\n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}
