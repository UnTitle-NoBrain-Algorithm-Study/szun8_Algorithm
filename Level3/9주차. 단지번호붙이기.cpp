#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;      // 정사각형의 크기
int area;   // 넓이 카운팅
char map[26][26];

// 1) 우, 상, 좌, 하 순으로 좌표검색 (y가 위로, x가 오른쪽 기준)
// 2) 우, 하, 좌, 상 순으로 좌표검색 (y가 아래로, x가 오른쪽 기준)
int moveY[4] = { 0, 1, 0, -1 };
int moveX[4] = { 1, 0, -1, 0 };

void DFS(int a, int b) {
	//[y][x]
    map[a][b] = '0'; // visited
    ++area;
    for (int l = 0; l < 4; ++l) {
        int y = moveY[l] + a;
        int x = moveX[l] + b;
        if (x >= 0 && y >= 0 && x < n && y < n && map[y][x] == '1') DFS(y, x);
    }
}
 
int main() {
    vector<int> answer;
    memset(map, 0, sizeof(map));
 
	cin >> n;
    for (int i = 0; i < n; i++) // y
    {
        string onefloor;
        cin>>onefloor;
        for (int j = 0; j < n; j++) // x
        {
            map[i][j] = onefloor[j];
        }   
    }
    
	for (int i = 0; i < n; ++i) {   // y
		for (int j = 0; j < n; ++j) {   // x
			if (map[i][j] == '1') {
				area = 0;
				DFS(i, j);      // (y, x) = [y][x]
				answer.push_back(area);
			}
		}
	}
	sort(answer.begin(),answer.end());  // 오름차순
	cout << answer.size() << "\n";
 
	for (int i = 0; i < answer.size(); ++i) cout << answer[i] << "\n";
 
	return 0;
}