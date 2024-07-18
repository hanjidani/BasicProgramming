#include<iostream>
#include<string.h>

using namespace std;
bool find(char ch, string str, int len){
    bool ret = false;
    for(int i = 0; i < len; i++){
        if(ch == str[i]){
            ret = true;
            break;
        }
    }
    return ret;
}

int notr(string s){
    int len = s.length();
    string ret = "";
    int let = 0;
    for(int i = 0; i < len; i++){
        if(!find(s[i], ret, let)){
            ret += s[i];
            let++;
        }
    }
    return let;
}

int main(){
    int n;
    cin>>n;
    string s;
    int p = 0, temp;
    for(int i = 0; i < n; i++){
        cin>>s;
        temp = notr(s);
        //cout<<temp<<endl;
        if(temp > p)    p = temp;
    }
    cout<<p;
    
    return 0;
}