#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int N, K = 0, Waas = 0;
int color[2000][2000];
int needy[2001][2001] = {0};

FILE *fin, *fout;

void get_needy(int i, int j) {
    if (i > 0) {
        if (j > 0)
            needy[i][j] += color[i-1][j-1];
        if (j < N)
            needy[i][j] += color[i-1][j];
    }
    if (i < N) {
        if (j > 0)
            needy[i][j] += color[i][j-1];
        if (j < N)
            needy[i][j] += color[i][j];
    }
    needy[i][j] &= 1;
}

void use_rect (int i, int j, int ii, int jj) {
    fprintf(fout, "%d %d %d %d\n", j+1, jj, i+1, ii);
    K++;
    needy[i][j] ^= 1;
    needy[i][jj] ^= 1;
    needy[ii][j] ^= 1;
    needy[ii][jj] ^= 1;
}

int main(int argc, char *argv[]) {
    int i, j, ii, jj, r, c;
    int ninrow, nincol;
    int inrow[2000], incol[2000];
    bool found;

    fin = fopen(argv[1], "r");
    assert(fin);
    fscanf(fin, "%d", &N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fscanf(fin, "%d", &color[i][j]);
            get_needy(i, j);
        }
        get_needy(i, N);
    }

    for (j = 0; j <= N; j++) {
        get_needy(N, j);
    }
    fclose(fin);

    fout = fopen(argv[2], "w");
    assert(fout);

    for (i = 0; i <= N; i++) {
        for (j = 0; j <= N; j++) {
            if (!needy[i][j]) continue;

            assert (i < N);
            assert (j < N);

            ninrow = 0;

            for (jj = j + 1; jj <= N; jj++) 
                if (needy[i][jj])
                    inrow[ninrow++] = jj;

            assert (ninrow & 1);

            nincol = 0;

            for (ii = i + 1; ii <= N; i++) {
                if (needy[ii][j])
                    incol[nincol++] = ii;
            }

            assert(nincol & 1);

            found = 0;
            for (c = 0; !found && c < nincol; c++) {
                for (r = 0; !found && r < ninrow; r++) {
                    if (needy[incol[c]][inrow[r]]) {
                        found = 1;
                        use_rect (i, j, incol[c], inrow[r]);
                    }
                }
            }

            if (!found) {
                Waas++;
                use_rect(i, j, incol[0], inrow[0]);
            }
        }
    }

    #ifndef NDEBUG
    for (i = 0; i <= N; i++) {
        for(j = 0; j <= N; j++) {
            assert(needy[i][j] == 0);
        }
    }
    #endif
    fclose(fout);

    printf("Number of rectangles used: %d; Number of Waas: %d; Score >= %g\n\n", K, Waas, 1 + 9 * (double) (K * 4 - Waas) / (K * 4));

    return 0;
}