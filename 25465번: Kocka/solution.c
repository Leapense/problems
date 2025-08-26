#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUBE_IDX(x, y, z, n) (((size_t)(x) * (n) + (y)) * (n) + (z))
#define GRID_IDX(r, c, n) ((size_t)(r) * (n) + (c))

void update_projections(int r, int c, int d, int n,
                        const int* cube, int* proj_front, int* proj_back,
                        int* proj_left, int* proj_right) {
    int color = 0;
    for (int k = 0; k < n; ++k) {
        if (cube[CUBE_IDX(r, c, k, n)] != 0) {
            color = cube[CUBE_IDX(r, c, k, n)];
            break;
        }
    }
    proj_front[GRID_IDX(r, c, n)] = color;

    color = 0;
    int back_view_c = (n - 1) - c;
    for (int k = 0; k < n; ++k) {
        if (cube[CUBE_IDX(r, c, (n - 1) - k, n)] != 0) {
            color = cube[CUBE_IDX(r, c, (n - 1) - k, n)];
            break;
        }
    }
    proj_back[GRID_IDX(r, back_view_c, n)] = color;

    color = 0;
    int left_view_c = (n - 1) - d;
    for (int k = 0; k < n; ++k) {
        if (cube[CUBE_IDX(r, k, d, n)] != 0) {
            color = cube[CUBE_IDX(r, k, d, n)];
            break;
        }
    }
    proj_left[GRID_IDX(r, left_view_c, n)] = color;

    color = 0;
    int right_view_c = d;
    for (int k = 0; k < n; ++k) {
        if (cube[CUBE_IDX(r, (n - 1) - k, d, n)] != 0) {
            color = cube[CUBE_IDX(r, (n - 1) - k, d, n)];
            break;
        }
    }
    proj_right[GRID_IDX(r, right_view_c, n)] = color;
}

void print_grid(const int* grid, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d", grid[GRID_IDX(i, j, n)]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    size_t cube_elements = (size_t)n * n * n;
    int* cube = (int*)calloc(cube_elements, sizeof(int));
    
    size_t grid_elements = (size_t)n * n;
    int* proj_front = (int*)calloc(grid_elements, sizeof(int));
    int* proj_back = (int*)calloc(grid_elements, sizeof(int));
    int* proj_left = (int*)calloc(grid_elements, sizeof(int));
    int* proj_right = (int*)calloc(grid_elements, sizeof(int));
    
    if (!cube || !proj_front || !proj_back || !proj_left || !proj_right) {
        return 1;
    }

    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int r, c, d, color_val;
            scanf("%d %d %d %d", &r, &c, &d, &color_val);
            r--; c--; d--;
            
            cube[CUBE_IDX(r, c, d, n)] = color_val;
            
            update_projections(r, c, d, n, cube, proj_front, proj_back, proj_left, proj_right);

        } else {
            char side[15];
            scanf("%s", side);
            if (strcmp(side, "prednja") == 0) {
                print_grid(proj_front, n);
            } else if (strcmp(side, "straznja") == 0) {
                print_grid(proj_back, n);
            } else if (strcmp(side, "lijeva") == 0) {
                print_grid(proj_left, n);
            } else if (strcmp(side, "desna") == 0) {
                print_grid(proj_right, n);
            }
        }
    }

    free(cube);
    free(proj_front);
    free(proj_back);
    free(proj_left);
    free(proj_right);

    return 0;
}