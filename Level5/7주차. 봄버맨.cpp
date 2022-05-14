#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int r,c,n;
int map[201][201];

int main(){
    cin>>r>>c>>n;
    int tmpSec = 1;
    memset(map, -1, sizeof(map));
    for (int i = 0; i < r; i++) {
        string what; cin>>what;
        for (int j = 0; j < what.length(); j++) {
            if(what[j]=='.') map[i][j] = 0;
            else map[i][j] = 2;
        }
    }
    if(n%2==0){
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                cout<<"O";
            } cout<<endl;
        }
        return 0;
    }
    
    while(tmpSec < n){
        int max = *max_element(&map[0][0], &map[r-1][c-1]);
        if(max == 3){
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if(map[i][j] == 3){
                        map[i][j] = 0;
                        if(i-1 >= 0 && map[i-1][j] != 3) map[i-1][j] = 0;
                        if(i+1 < r && map[i+1][j] != 3) map[i+1][j] = 0;
                        if(j-1 >= 0 && map[i][j-1] != 3) map[i][j-1] = 0;
                        if(j+1 < c && map[i][j+1] != 3) map[i][j+1] = 0;
                    }
                    else if(map[i][j] != 0) ++map[i][j];
                }
            }
        }
        else{
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    ++map[i][j];
                }
            }
        }
        ++tmpSec;
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++){
            if(map[i][j] == 0) cout<<".";
            else cout<<"O";
        }
        cout<<endl;
    }
    return 0;
}