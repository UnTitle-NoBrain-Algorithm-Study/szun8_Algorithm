#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    string s, newS;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        string word;
        if(s[i]!=' ' && s[i]!='<' && s[i]!= '>'){
            for (int j = 0; ; j++) {
                if(s[i+j]!=' ' && s[i+j]!='<' && s[i+j]!='\0') word+=s[i+j];
                else{
                    i+=(j-1);
                    break;
                }
            }
            reverse(word.begin(), word.end());
            newS.append(word);
        }
        else if(s[i]=='<'){
            while(s[i]!='>'){
                word+=s[i++];
            }
            word+='>';
            newS.append(word);
        }
        else{
            newS+=s[i];
        }
    }
    cout<<newS;
    return 0;
}