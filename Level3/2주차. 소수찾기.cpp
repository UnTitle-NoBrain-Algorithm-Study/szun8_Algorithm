#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int n, cnt=0;
    cin >> n;
    vector<int> sosuNumber(n, 0);
    for (int i = 0; i < n; i++){
        cin>>sosuNumber[i];
    }
    int max = *max_element(sosuNumber.begin(),sosuNumber.end());
    vector<int> sosus(max+1);
    for (int i = 2; i < sosus.size(); i++) {    // 2부터 원소초기화
        sosus[i]=i;
    }
    for (int i = 2; i <= sqrt(max); i++) {
        if (sosus[i] == 0)  // 이미 0인 값은 소수가 아님이 판정났으므로 pass
            continue;
        for (int j = i * i; j <= max; j += i)
            sosus[j] = 0;
    }

    for (int i = 0; i < sosuNumber.size(); i++) {
        if(sosus[sosuNumber[i]]!=0) ++cnt;
    }
    cout<<cnt;
    return 0;
}