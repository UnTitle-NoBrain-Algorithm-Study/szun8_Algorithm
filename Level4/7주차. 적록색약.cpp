#include <iostream>
#include <cstring>
using namespace std;
int n;
char map[101][101];
bool RGBvisited[101][101];
bool RBvisited[101][101];

// 우 하 좌 상
int moveX[4]={1,0,-1,0};
int moveY[4]={0,1,0,-1};

// dfs
void RGB(int y, int x){
    RGBvisited[y][x]=true;
    for (int i = 0; i < 4; i++) {
        int ny = y + moveY[i];
        int nx = x + moveX[i];
        if(nx>=0 && ny>=0 && nx<n && ny<n && RGBvisited[ny][nx]==false && map[ny][nx]== map[y][x]){
            RGB(ny,nx);
        }
    }
}

void RG(int y, int x){
    RBvisited[y][x]=true;
    for (int i = 0; i < 4; i++) {
        int ny = y + moveY[i];
        int nx = x + moveX[i];
        if(nx>=0 && ny>=0 && nx<n && ny<n && RBvisited[ny][nx]==false){
            if(map[ny][nx]=='R' || map[ny][nx]=='G'){
                RG(ny,nx);
            }
        }
    }
}

void B(int y, int x){
    RBvisited[y][x]=true;
    for (int i = 0; i < 4; i++) {
        int ny = y + moveY[i];
        int nx = x + moveX[i];
        if(nx>=0 && ny>=0 && nx<n && ny<n && RBvisited[ny][nx]==false && map[ny][nx]== map[y][x]) B(ny,nx);
    }
}

int main(){
    int rgb=0, rb=0;
    memset(RGBvisited,false,sizeof(RGBvisited));
    memset(RBvisited,false,sizeof(RBvisited));
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];
        }      
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(RGBvisited[i][j]==false){
                RGB(i,j);
                ++rgb;
            }
            if(RBvisited[i][j]==false){
                map[i][j]=='B' ? B(i,j) : RG(i,j);
                ++rb;
            }
        }      
    }
    
    cout<<rgb<<" "<<rb;
    return 0;
}