#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    int n; cin>>n;
    queue<int> card;
    for (int i = 1; i <= n; i++) {
        card.push(i);
    }
    vector<int> tmp;
    while (card.size()>1) {
        tmp.push_back(card.front());
        card.pop();
        card.push(card.front());
        card.pop();
    }
    for (int i = 0; i < tmp.size(); i++) {
        cout<<tmp[i]<<" ";
    }
    cout<<card.front();
    
    return 0;
}