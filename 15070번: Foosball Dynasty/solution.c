#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 32
#define MAX_SCORE_LEN 1001

typedef struct {
    char player1[MAX_NAME_LEN];
    char player2[MAX_NAME_LEN];
} Team;

typedef struct {
    char white_offense[MAX_NAME_LEN];
    char white_defense[MAX_NAME_LEN];
    char black_offense[MAX_NAME_LEN];
    char black_defense[MAX_NAME_LEN];
    Team white_team;
    Team black_team;
    char queue_players[MAX_PLAYERS][MAX_NAME_LEN];
    int queue_front;
    int queue_rear;
    int queue_size;
} GameState;

void enqueue(GameState* state, const char* name) {
    strcpy(state->queue_players[state->queue_rear], name);
    state->queue_rear = (state->queue_rear + 1) % MAX_PLAYERS;
    state->queue_size++;
}

void dequeue(GameState* state, char* name_buffer) {
    strcpy(name_buffer, state->queue_players[state->queue_front]);
    state->queue_front = (state->queue_front + 1) % MAX_PLAYERS;
    state->queue_size--;
}

void update_dynasty(int current_length, Team team, int* max_length, Team** longest_teams, int* count, int* capacity) {
    if (current_length > *max_length) {
        *max_length = current_length;
        *count = 0;
        *count = 1;
        (*longest_teams)[0] = team;
    } else if (current_length == *max_length && *max_length > 0) {
        if (*count == *capacity) {
            *capacity *= 2;
            *longest_teams = realloc(*longest_teams, *capacity * sizeof(Team));
        }
        (*longest_teams)[*count] = team;
        (*count)++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char players[MAX_PLAYERS][MAX_NAME_LEN];
    for (int i = 0; i < n; ++i) {
        scanf("%s", players[i]);
    }

    GameState state = {0};
    strcpy(state.white_offense, players[0]);
    strcpy(state.black_offense, players[1]);
    strcpy(state.white_defense, players[2]);
    strcpy(state.black_defense, players[3]);

    strcpy(state.white_team.player1, players[0]);
    strcpy(state.white_team.player2, players[2]);
    strcpy(state.black_team.player1, players[1]);
    strcpy(state.black_team.player2, players[3]);

    for (int i = 4; i < n; ++i) {
        enqueue(&state, players[i]);
    }

    char scores[MAX_SCORE_LEN];
    scanf("%s", scores);

    int max_dynasty_length = 0;
    int dynasty_teams_count = 0;
    int dynasty_teams_capacity = 10;
    Team* longest_dynasty_teams = malloc(dynasty_teams_capacity * sizeof(Team));

    int current_dynasty_length = 0;
    char current_dynasty_scorer = '\0';
    Team last_winning_team;

    for (int i = 0; scores[i] != '\0'; ++i) {
        char scorer = scores[i];
        if (scorer != current_dynasty_scorer && current_dynasty_scorer != '\0') {
            update_dynasty(current_dynasty_length, last_winning_team, &max_dynasty_length, &longest_dynasty_teams, &dynasty_teams_count, &dynasty_teams_capacity);
            current_dynasty_length = 1;
        } else {
            current_dynasty_length++;
        }
        current_dynasty_scorer = scorer;

        char temp[MAX_NAME_LEN];
        if (scorer == 'W') {
            last_winning_team = state.white_team;
            strcpy(temp, state.white_offense);
            strcpy(state.white_offense, state.white_defense);
            strcpy(state.white_defense, temp);

            enqueue(&state, state.black_defense);
            strcpy(state.black_defense, state.black_offense);
            dequeue(&state, state.black_offense);
            strcpy(state.black_team.player1, state.black_defense);
            strcpy(state.black_team.player2, state.black_offense);
        } else {
            last_winning_team = state.black_team;
            strcpy(temp, state.black_offense);
            strcpy(state.black_offense, state.black_defense);
            strcpy(state.black_defense, temp);

            enqueue(&state, state.white_defense);
            strcpy(state.white_defense, state.white_offense);
            dequeue(&state, state.white_offense);
            strcpy(state.white_team.player1, state.white_defense);
            strcpy(state.white_team.player2, state.white_offense);
        }
    }
    
    update_dynasty(current_dynasty_length, last_winning_team, &max_dynasty_length, &longest_dynasty_teams, &dynasty_teams_count, &dynasty_teams_capacity);

    for (int i = 0; i < dynasty_teams_count; ++i) {
        printf("%s %s\n", longest_dynasty_teams[i].player1, longest_dynasty_teams[i].player2);
    }
    
    free(longest_dynasty_teams);

    return 0;
}