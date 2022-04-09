#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    if(a.size()>b.size()){
        for (int i = 0; i < b.size(); i++){
            if(a[i]==b[i]) continue;
            else return a[i]>b[i];
        }
    }
    else{
        for (int i = 0; i < a.size(); i++){
            if(a[i]==b[i]) continue;
            else return a[i]>b[i];
        }
    }
    string ab = a+b, ba = b+a;
    int abnum = stoi(ab), banum = stoi(ba);
    return abnum > banum;
}
string solution(vector<int> numbers) {
    string answer = "";
    if(count(numbers.begin(),numbers.end(),0)==numbers.size()) {
        return answer="0";
    }
    vector<string> strNums;
    for (int i = 0; i < numbers.size(); i++){
        string str = to_string(numbers[i]);
        strNums.push_back(str);
    }
    sort(strNums.begin(),strNums.end(),cmp);
    for (int i = 0; i < strNums.size(); i++){
        answer+=strNums[i];
    }
    
    return answer;
}