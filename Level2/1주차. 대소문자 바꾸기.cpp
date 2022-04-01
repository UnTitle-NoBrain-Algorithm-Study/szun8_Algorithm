#include <iostream>
using namespace std;

int main(){
    string alpha;
    cin>>alpha;
    for (int i = 0; i < alpha.size(); i++)
    {
        if(alpha[i]>=65 && alpha[i]<=90){
            alpha[i]=tolower(alpha[i]);
        }
        else if(alpha[i]>=97 && alpha[i]<=122){
            alpha[i]=toupper(alpha[i]);
        }
    }
    cout<<alpha;
    return 0;
}