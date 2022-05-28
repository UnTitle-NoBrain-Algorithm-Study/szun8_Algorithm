#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[1001][1001];
int candy[1001][1001];

int main(){
    int n, m;
    cin>>n>>m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>candy[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int total = 0;
            total = max(map[i-1][j-1], max(map[i-1][j], map[i][j-1]));
            map[i][j] = total + candy[i][j];
        }
    }
    cout<<map[n][m];
    return 0;
}