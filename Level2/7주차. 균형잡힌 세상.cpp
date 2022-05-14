#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<int> out;
    while(true){
        string world;
        stack<int> check;
        getline(cin, world);
        if(world.size()==1 && world[0] == 46) break;

        for(int i = 0;i<world.size();++i) {
            if(world[i]==40){
                check.push(40);
            }
            else if(world[i] ==91){
                check.push(91);
            }
            else if(world[i] == 93){
                if(!check.empty() && check.top() == 91) check.pop();
                else check.push(93);
            }
            else if(world[i] == 41){
                if(!check.empty() && check.top() == 40) check.pop();
                else check.push(41);
            }
        }

        if(check.empty()) out.push_back(1);
        else out.push_back(0);
    }

    for(int i =0;i<out.size();++i){
        if(out[i]==1) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}