#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> visited;
int cnt;
void DFS(int what, vector<int> graph[]){
    visited[what] = cnt++;
    for (int i = 0; i < graph[what].size(); i++) {
        int next = graph[what][i];
        if(!visited[next]){
            DFS(graph[what][i], graph);
        }
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
    
    DFS(r, graph);
    for (int i = 1; i < n+1; i++) {
        printf("%d\n", visited[i]);
    }
    
    return 0;
}