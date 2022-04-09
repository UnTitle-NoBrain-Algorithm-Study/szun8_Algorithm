#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,num;;
    cin >> n;
    vector<int> numvec;

    for(int i=0;i<n;++i){
        cin>>num;
        numvec.push_back(num);
    }
    sort(numvec.begin(),numvec.end());
    for(int i =0;i<numvec.size();++i){
        cout<<numvec[i]<<"\n";
    }
    return 0;
}