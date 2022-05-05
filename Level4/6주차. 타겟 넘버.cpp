#include <string>
#include <vector>
#include <algorithm>
int answer = 0;
using namespace std;
// 주어진 numbers 순서는 고정.
void DFS(int here, vector<int> numbers, int sum, int target){
    if(sum==target && here == numbers.size()-1) {   // 모든 수를 사용해서 target을 도달하면,
        ++answer;
        return;
    }
    if(here == numbers.size()-1) return;
    DFS(here+1,numbers,sum+numbers[here+1],target);   // +
    DFS(here+1,numbers,sum-numbers[here+1],target);   // -
}
int solution(vector<int> numbers, int target) {
    DFS(-1,numbers,0,target);
    return answer;
}