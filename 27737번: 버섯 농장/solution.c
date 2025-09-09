#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 105

int N;
long long M, K;
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int qx[MAXN*MAXN], qy[MAXN*MAXN];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(void)
{
    if (scanf("%d %lld %lld", &N, &M, &K) != 3) return 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (scanf("%d", &a[i][j]) != 1) return 0;
        }
    }

    long long totalZero = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (a[i][j] == 0) totalZero++;
        }
    }

    if (totalZero == 0)
    {
        puts("IMPOSSIBLE");
        return 0;
    }

    long long R = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (a[i][j] == 0 && !vis[i][j])
            {
                int head = 0, tail = 0;
                vis[i][j] = true;
                qx[tail] = i; qy[tail] = j; tail++;
                long long S = 0;
                while (head < tail)
                {
                    int x = qx[head], y = qy[head]; head++;
                    S++;
                    for (int d = 0; d < 4; ++d)
                    {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (!vis[nx][ny] && a[nx][ny] == 0)
                        {
                            vis[nx][ny] = true;
                            qx[tail] = nx; qy[tail] = ny; tail++;
                        }
                    }
                }

                long long need = (K == 0 ? S : (S + K - 1) / K);
                R += need;
            }
        }
    }

    if (M >= R && R >= 1)
    {
        puts("POSSIBLE");
        printf("%lld\n", M - R);
    }
    else 
    {
        puts("IMPOSSIBLE");
    }

    return 0;
}