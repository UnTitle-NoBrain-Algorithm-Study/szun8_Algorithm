#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<int> visited;
int cnt;
void BFS(int what, vector<int> graph[]){
    queue<int> now;
    now.push(what);
    while(!now.empty()){
        int cur = now.front();
        if(visited[cur]){
            now.pop();
            continue;
        }

        visited[cur] =  cnt++;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if(!visited[next]) now.push(next);
        }
        now.pop();
    }
}
int main(){
    int n, m, r;
    cin>>n>>m>>r;
    cnt=1;
    vector<int> graph[n+1];
    visited.resize(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i < n+1; i++) {
        sort(graph[i].begin(), graph[i].end());
    }
    BFS(r, graph);
    for (int i = 1; i < n+1; i++) {
        printf("%d\n", visited[i]);
    }
    return 0;
}