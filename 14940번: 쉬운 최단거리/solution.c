#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Coordinate structure
typedef struct {
    int row;
    int col;
} Point;

// A simple queue implementation using a circular array
typedef struct {
    Point* data;
    int front;
    int rear;
    int size;
    int capacity;
} Queue;

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (!q) return NULL;
    q->capacity = capacity;
    q->front = q->size = 0;
    q->rear = capacity - 1;
    q->data = (Point*)malloc(q->capacity * sizeof(Point));
    if (!q->data) {
        free(q);
        return NULL;
    }
    return q;
}

bool isQueueEmpty(Queue* q) { return (q->size == 0); }
bool isQueueFull(Queue* q) { return (q->size == q->capacity); }

void enqueue(Queue* q, Point item) {
    if (isQueueFull(q)) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
    q->size = q->size + 1;
}

Point dequeue(Queue* q) {
    Point item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size = q->size - 1;
    return item;
}

void freeQueue(Queue* q) {
    if (q) {
        free(q->data);
        free(q);
    }
}

int** create2DArray(int rows, int cols) {
    // Allocate space for row pointers and the actual data in one go.
    int** arr = malloc(rows * sizeof(int*) + (size_t)rows * cols * sizeof(int));
    if (!arr) {
        return NULL;
    }

    // The data block starts right after the array of row pointers.
    int* data_block = (int*)(arr + rows);

    // Set each row pointer to the correct starting position in the data block.
    for (int i = 0; i < rows; i++) {
        arr[i] = data_block + (size_t)i * cols;
    }
    return arr;
}

void free2DArray(int** arr) {
    free(arr);
}

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** map = create2DArray(n, m);
    int** distances = create2DArray(n, m);

    // A single, robust check for allocation failure.
    if (!map || !distances) {
        perror("Failed to allocate memory");
        free2DArray(map);
        free2DArray(distances);
        return;
    }

    Point start_node = {-1, -1};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &map[i][j]);
            distances[i][j] = -1;
            if (map[i][j] == 2) {
                start_node = (Point){i, j};
            } else if (map[i][j] == 0) {
                distances[i][j] = 0;
            }
        }
    }

    Queue* q = createQueue(n * m);
    if (!q) {
        perror("Failed to create queue");
        free2DArray(map);
        free2DArray(distances);
        return;
    }

    if (start_node.row != -1) {
        distances[start_node.row][start_node.col] = 0;
        enqueue(q, start_node);
    }

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!isQueueEmpty(q)) {
        Point current = dequeue(q);
        for (int i = 0; i < 4; ++i) {
            int next_row = current.row + dr[i];
            int next_col = current.col + dc[i];

            if (next_row >= 0 && next_row < n && next_col >= 0 && next_col < m &&
                map[next_row][next_col] == 1 && distances[next_row][next_col] == -1)
            {
                distances[next_row][next_col] = distances[current.row][current.col] + 1;
                enqueue(q, (Point){next_row, next_col});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", distances[i][j]);
        }
        printf("\n");
    }

    // Cleanup
    free2DArray(map);
    free2DArray(distances);
    freeQueue(q);
}

int main() {
    solve();
    return 0;
}