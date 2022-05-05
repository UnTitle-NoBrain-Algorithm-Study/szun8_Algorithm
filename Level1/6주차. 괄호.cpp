#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
int main(){
    int input;
    cin >> input;
    
    for (int i = 0; i < input; i++)
    {
        stack<char> ps;
        string PS;
        cin >> PS;
        char left[2] = "(";
        char right[2] = ")";
        for (int j = 0; j < PS.size(); j++)
        {
            char what[2] = {PS[j], '\0'};
            if(strcmp(what,left)==0){
                ps.push(PS[j]);
            }
            else if(ps.empty()&&strcmp(what,right)==0){
                ps.push(PS[j]);
            }
            else if(!ps.empty()&&strcmp(what,right)==0){
                char front[2] = {ps.top(),'\0'};
                if(strcmp(front,left)==0){
                    ps.pop();
                }
            }
            
        }
        if(ps.empty()) cout << "YES" << endl;
        else cout<< "NO"<<endl;
        
    }
    
    return 0;
}