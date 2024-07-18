#include<iostream>
#include<string.h>

using namespace std;

char lower(char x){
    if(x >= 'A' && x <= 'Z')
        return x + 32;
    else return x;
}

bool chcomp(char a, char b){
    if(lower(a) == lower(b))    return true;
    else                        return false;
}

bool comp(string main, string check, int st, int en){
    bool ret = true;
    for(int i = 0; st < en; st++){
        if(!chcomp(main[st],check[i])){
            ret = false;   
            break;
        }
        i++;
    }
    return ret;
}

int exists(string main, string check){
    int clen = check.length();
    int len = main.length() - clen;
    int c = 0;
    for(int i = 0; i <= len; i++){
        if(comp(main, check, i, i + clen))  c++;
        //cout<<comp(main, check, i, i + clen)<<endl;
    }
    return c;
}

int main(){
    //cout<<exists("EXamMple", "ple");
    string list[1000], temp, check;
    int n = 0;
    while(true){
        cin>>temp;
        if(temp != "end"){
            list[n] = temp;
            n++;
        } else  break;
    }
    cin>>check;
    int c = 0;
    for(int i = 0; i < n; i++)
        c += exists(list[i], check);
    cout<<c;
    return 0;
}