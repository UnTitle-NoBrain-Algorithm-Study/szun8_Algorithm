#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <utility>
using namespace std;

int map[101][101];  // 1 = 길, 0 = 벽
int path[101][101]; // 해당칸까지의 최소이동횟수 저장
bool visited[101][101];
int n,m;

// 우, 하, 좌, 상 순으로 좌표검색 (y가 아래로, x가 오른쪽 기준)
int moveY[4] = { 0, 1, 0, -1 };
int moveX[4] = { 1, 0, -1, 0 };

void bfs(int y, int x){ // 0, 0 start
    queue<pair<int,int> > spot; //y,x
    path[y][x] = 1;
    visited[y][x] = true;
    spot.push(make_pair(y, x));
    while (!spot.empty()) {
        y = spot.front().first;
        x = spot.front().second;
        spot.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + moveY[i];
            int nx = x + moveX[i];
            if(nx >= 0 && ny >= 0 && nx < m && ny < n && visited[ny][nx]==false && map[ny][nx]==1){
                visited[ny][nx]=true;
                spot.push(make_pair(ny,nx));
                path[ny][nx] = path[y][x] + 1;
            }
        }
    }
}

int main(){
    cin>>n>>m;  // y, x
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < n; i++) {
        string way;
        cin>>way;
        for (int j = 0; j < way.size(); j++) {
            map[i][j] = way[j]-'0';
        }
    }

    bfs(0,0);
    cout<<path[n-1][m-1];
    return 0;
}