#include <iostream>
using namespace std;
// DP
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num;
    cin>>num;
    long long int fibo[91];
    fibo[0]=0, fibo[1]=1;
    for (int i = 2; i <= num; i++) {
        fibo[i]=fibo[i-1]+fibo[i-2];
    }
    printf("%lld", fibo[num]);
    return 0;
}