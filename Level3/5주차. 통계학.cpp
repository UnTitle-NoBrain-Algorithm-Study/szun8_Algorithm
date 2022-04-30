#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
#include <map>
using namespace std;
int main(){
    int n,maxcnt=0,three;
    scanf("%d", &n);
    vector<int> N(n);
    for (int i = 0; i < n; i++) scanf("%d", &N[i]);
    sort(N.begin(),N.end());    // 오름차순 정렬
    int sum = accumulate(N.begin(),N.end(),0);
    int one = round((float)sum/n);  // 1. 산술평균
    int two = N[N.size()/2];    // 2. 중앙값

    int max = *max_element(N.begin(),N.end());
    int min = *min_element(N.begin(),N.end());
    int four = max-min;     // 4. 범위
 
    map<int,int> how;
    for (int i = 0; i < N.size(); i++) {
        map<int,int>::iterator iter = how.find(N[i]);
        if(iter!=how.end()) iter->second++;
        else how.insert(pair<int,int>(N[i],1));
    }
    N.clear();
    for (map<int,int>::iterator iter = how.begin(); iter != how.end(); iter++) {
        if(iter->second>maxcnt) maxcnt=iter->second;
    }
    for (map<int,int>::iterator iter = how.begin(); iter != how.end(); iter++) {
        if(iter->second==maxcnt)  N.push_back(iter->first);
    }
    sort(N.begin(),N.end());
    N.size()>1 ? three=N[1] : three=N[0];   // 3. 최빈값
    cout<<one<<"\n"<<two<<"\n"<<three<<"\n"<<four;
    
    return 0;
}