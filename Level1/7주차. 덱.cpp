#include <iostream>
#include <deque>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    deque<int> de;
    for (int i = 0; i < n; i++)
    {
        string what;
        cin>>what;

        int num;
        if (what=="push_front")
        {
            cin>>num;
            de.push_front(num);
        }
        else if (what=="push_back")
        {
            cin>>num;
            de.push_back(num);
        }
        else if (what=="pop_front")
        {
            if(de.empty()) cout<<"-1\n";

            else{
                cout<<de.front()<<"\n";
                de.pop_front();
            }
        }
        else if (what=="pop_back")
        {
            if(de.empty()) cout<<"-1\n";
            else{
                cout<<de.back()<<"\n";
                de.pop_back();
            }
        }
        else if (what=="size")
        {
            cout<<de.size()<<"\n";
        }
        else if (what=="empty")
        {
            if(de.empty()) cout<<"1\n";
            else cout<<"0\n";
        }
        else if (what=="front")
        {
            if(de.empty()) cout<<"-1\n";

            else{
                cout<<de.front()<<"\n";
            }
        }
        else if (what=="back")
        {
            if(de.empty()) cout<<"-1\n";
            else{
                cout<<de.back()<<"\n";
            }
        }
    }
    return 0;
}