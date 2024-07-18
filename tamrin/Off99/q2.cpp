#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

int contain(string s){
    for(int i = 0; i < s.length(); i++)
        if(s[i] == '?') return i;
    return -1;
}

bool flag = false;

bool na(string s){
    char pr = s[0];
    for(int i = 1; i < s.length(); i++){
        if(pr == s[i])  return false;
        pr = s[i];
    }
    return true;
}

void zib(string s){
    if(!flag){
        int temp = contain(s);
        if(temp == -1){
            flag = na(s);
        } else {
            //string ss = s;
            s[temp] = '1';
            zib(ss);
            s[temp] = '0';
            zib(s);
        }
    }
}

int main(){
    string s;
    cin>>s;
    zib(s);
    if(flag)    cout<<"YES";
    else        cout<<"NO";
	return 0;
}
