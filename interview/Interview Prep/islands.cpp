#include <iostream>
#define N 4
#define M 4

int num_islands(int a[N][M]);
void bfs(int a[N][M], int x, int y, bool visited[N][M]);
bool on_grid(int x, int y);

int main(){
    int a[N][M] = {{1, 1, 1, 1},
                 {0, 0, 1, 0},
                 {0, 0, 0, 0},
                 {1, 0, 0, 0}};
    std::cout << num_islands(a) << std::endl;
    return 0;
}

bool on_grid(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}

void bfs(int a[N][M], int x, int y, bool visited[N][M]){
    visited[x][y] = true;
    for(int i = -1; i >= 1; i++){
        for(int j = -1; j >= 1; j++){
            if(on_grid(x + i, y + j) && !visited[x + i][y + j] && a[x + i][y + j] == 1)
                bfs(a, x + i, y + j, visited);
        }
    }
}

int num_islands(int a[N][M]){
    int n = 0;
    bool visited[N][M];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(a[i][j] && !visited[i][j]){
                n++;
                bfs(a, i, j, visited);
            }
        }
    }
    return n;
}
