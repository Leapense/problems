#include <stdio.h>
#include <stdlib.h>

enum { MAX_N = 30000, CAP = 60000 };

typedef struct {
    int data[CAP];
    int head;
    int size;
} Deck;

static void push_back(Deck *d, int v) {
    d->data[(d->head + d->size) % CAP] = v;
    d->size += 1;
}

static int pop_front(Deck *d) {
    int v = d->data[d->head];
    d->head = (d->head + 1) % CAP;
    d->size -= 1;
    return v;
}

static int top_ground(const int *g, int gs) { return gs ? g[gs - 1] : -1; }

static void move_ground(Deck *dst, int *src, int *sz) {
    for (int i = *sz - 1; i >= 0; --i) push_back(dst, src[i]);
    *sz = 0;
}

int main(void) {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2) return 0;
    Deck deck[2] = {0};
    int ground[2][CAP];
    int gsz[2] = {0};

    for (int i = 0; i < N; ++i) {
        int d, s;
        scanf("%d %d", &d, &s);
        push_back(&deck[0], d);
        push_back(&deck[1], s);
    }
    for (int i = 0; i < (int)deck[0].size / 2; ++i) {
        int j = deck[0].size - 1 - i;
        int tmp = deck[0].data[i];
        deck[0].data[i] = deck[0].data[j];
        deck[0].data[j] = tmp;
    }
    for (int i = 0; i < (int)deck[1].size / 2; ++i) {
        int j = deck[1].size - 1 - i;
        int tmp = deck[1].data[i];
        deck[1].data[i] = deck[1].data[j];
        deck[1].data[j] = tmp;
    }

    int player = 0;
    for (int turn = 0; turn < M; ++turn) {
        if (deck[player].size == 0) {
            puts(player ? "do" : "su");
            return 0;
        }
        int card = pop_front(&deck[player]);
        ground[player][gsz[player]++] = card;
        int winner = -1;
        if (card == 5) winner = 0;
        else if (gsz[0] && gsz[1] && top_ground(ground[0], gsz[0]) + top_ground(ground[1], gsz[1]) == 5) winner = 1;
        if (winner >= 0) {
            move_ground(&deck[winner], ground[1 - winner], &gsz[1 - winner]);
            move_ground(&deck[winner], ground[winner], &gsz[winner]);
        }
        player ^= 1;
    }

    if (deck[0].size > deck[1].size) puts("do");
    else if (deck[0].size < deck[1].size) puts("su");
    else puts("dosu");
    return 0;
}