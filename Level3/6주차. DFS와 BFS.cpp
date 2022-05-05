#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m,v;
bool visited[1001];

void dfs(vector<int> graph[], int start){
    stack<int> s;
    s.push(start);
    visited[start] = true;
    cout<<start<<" ";
    while (!s.empty()) {
        int now = s.top();
        s.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if(visited[next]==false){
                s.push(now);
                s.push(next);
                visited[next]=true;
                cout<<next<<" ";
                break;
            }
        }
    }
}

void bfs(vector<int> graph[], int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    //cout<<start<<" ";
    while(!q.empty()){
        int now = q.front();
        cout<<now<<" ";
        q.pop();
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i];
            if(visited[next]==false){
                q.push(next);
                visited[next]=true;
            }
        }
    }
}

int main(){
    cin>>n>>m>>v;
    vector<int> graph[n+1];
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i <= n; i++) {
        sort(graph[i].begin(),graph[i].end());
    }
    
    memset(visited, false, sizeof(visited));
    dfs(graph, v);
    cout<<"\n";
    memset(visited, false, sizeof(visited));
    bfs(graph, v);
    
    return 0;
}