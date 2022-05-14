#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> dfs(int start, vector<int> graph[], vector<bool> check){
    stack<int> s;
    s.push(start);
    check[start] = true;
    while(!s.empty()){
        int current_node = s.top();
        s.pop();
        
        for (int i = 0; i < graph[current_node].size(); i++)
        {
            int next_node = graph[current_node][i];
            if(check[next_node]==false){    // 방문하지 않았다면,
                check[next_node]=true;
                s.push(current_node); s.push(next_node);
                break;
            }
        }
    }
    return check;
}
int main(){
    int n,m,count = 0;
    cin>>n>>m;
    vector<int> graph[n+1];
    vector<bool> check(n+1);
    fill(check.begin(),check.end(),false);  // 방문여부 false 초기화
    check[0] = true;

    int a,b;
    for (int i = 0; i < m; i++)
    {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }

    // 일단 첫 정점을 기준으로 dfs실행
    check = dfs(1,graph,check);
    for (int i = 0; i < n+1; i++)
    {
        if(check[i]==true) ++count;
    }
    
    cout<<count-2;  //index [0]이랑 1번 컨퓨터의 true는 뺴줘야함
    
    return 0;
}