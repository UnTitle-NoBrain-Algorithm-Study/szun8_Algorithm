#include <iostream>
using namespace std;

int main(){
    string score;
    cin>>score;
    if(score[0]=='A'){
        if(score[1]=='+') cout<<"4.3";
        else if(score[1]=='0') cout<<"4.0";
        else if(score[1]=='-') cout<<"3.7";
    }
    else if(score[0]=='B'){
        if(score[1]=='+') cout<<"3.3";
        else if(score[1]=='0') cout<<"3.0";
        else if(score[1]=='-') cout<<"2.7";
    }
    else if(score[0]=='C'){
        if(score[1]=='+') cout<<"2.3";
        else if(score[1]=='0') cout<<"2.0";
        else if(score[1]=='-') cout<<"1.7";
    }
    else if(score[0]=='D'){
        if(score[1]=='+') cout<<"1.3";
        else if(score[1]=='0') cout<<"1.0";
        else if(score[1]=='-') cout<<"0.7";
    }
    else cout<<"0.0";
    return 0;
}