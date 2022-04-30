#include <iostream>
#include <stack>
using namespace std;

int main(){
    int input;
    cin >> input;
    stack<int> ans;
    for(int i =0;i<input;++i){
        string order;
        int num;
        cin >> order;
        if(order=="push") {
            cin >> num;
            ans.push(num);
        }
        else if(order=="top"){
            if(ans.empty()){
                cout<<"-1"<<endl;
            }
            else{
                cout<<ans.top()<<endl;
            }
        }
        else if(order=="size"){
            cout<<ans.size()<<endl;
        }
        else if(order=="empty"){
            cout<<ans.empty()<<endl;
        }
        else if(order=="pop"){
            if(ans.empty()){
                cout<<"-1"<<endl;
            }
            else{
                int popnum = ans.top();
                ans.pop();
                cout<<popnum<<endl;
            }
            
        }
    }
    return 0;
}