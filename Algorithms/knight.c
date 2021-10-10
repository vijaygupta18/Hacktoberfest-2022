#include <stdio.h>
#include <stdbool.h>
int row[] = {2, 1, -1, -2, -2, -1, 1, 2};
int col[] = {1, 2, 2, 1, -1, -2, -2, -1};
int n = 5;
int flag = 0;
bool Valid(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return false;
    else
        return true;
}
void kTour(int visited[n][n], int x, int y, int pos)
{
    visited[x][y] = pos;
    if (pos == n * n)
    {
        flag++;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%d,", visited[i][j]);
            printf("\n");
        }
        printf("\n");
        visited[x][y] = 0;
    }
    else
    {
        int nx, ny;
        for (int k = 0; k < 8; k++)
        {
            nx = x + row[k];
            ny = y + col[k];
            if (Valid(nx, ny) && visited[nx][ny] == 0)
                kTour(visited, nx, ny, pos + 1);
        }
        visited[x][y] = 0;
    }
}
int main()
{
    int pos = 1;
    //scanf("%d", &n);
    int visited[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }
    kTour(visited, 0, 0, pos);
    if (flag == 0)
        printf("Solution doesn't exist");
    return 0;
}
