#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CITIES 200001

int main(void)
{
    int n;
    scanf("%d", &n);
    
    int* path = malloc(sizeof(int) * n);
    if (path == NULL)
    {
        return 1;
    }

    int max_city_id = 0;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &path[i]);
        if (path[i] > max_city_id)
        {
            max_city_id = path[i];
        }
    }

    int num_cities = max_city_id + 1;
    int* parent = malloc(sizeof(int) * num_cities);
    bool* visited = calloc(num_cities, sizeof(bool));

    if (parent == NULL || visited == NULL)
    {
        free(path);
        free(parent);
        free(visited);
        return 1;
    }

    int root = path[0];
    parent[root] = -1;
    visited[root] = true;

    for (int i = 1; i < n; ++i)
    {
        int prev_city = path[i - 1];
        int current_city = path[i];
        if (!visited[current_city]) {
            visited[current_city] = true;
            parent[current_city] = prev_city;
        }
    }

    printf("%d\n", num_cities);
    if (num_cities > 0) {
        printf("%d", parent[0]);
        for (int i = 1; i < num_cities; ++i) {
            printf(" %d", parent[i]);
        }
    }

    printf("\n");

    free(path);
    free(parent);
    free(visited);

    return 0;
}