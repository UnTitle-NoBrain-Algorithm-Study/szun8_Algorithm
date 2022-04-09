#include <iostream>
using namespace std;
int main(){
    int n;
    cin>> n;
    if(n==1) cout<<2;
    else if(n==2) cout<<4;
    else if(n==3) cout<<8;
    else if(n==4) cout<<16;
    else if(n==5) cout<<32;
    return 0;
}