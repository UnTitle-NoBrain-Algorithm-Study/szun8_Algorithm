#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    queue<int> num;
    queue<int> out;
    for(int i=1;i<=n;i++){
        num.push(i);
    }
    while(!num.empty()){ 
        if(num.size()==1) {
            out.push(num.front());
            num.pop();
            break;
        }
        int count=0;
        int f = num.front();
        while(count<k-1){
            num.push(f);
            num.pop();
            f=num.front();
            count++;
        }
        out.push(num.front());
        num.pop();
    }
    cout<<"<";
    while(!out.empty()){
        if(out.size()==1) {
            cout<<out.front()<<">";
            break;
        }
        cout<<out.front()<<", ";
        out.pop();
    }
    return 0;
}