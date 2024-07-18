#include<iostream>
#include<string.h>

using namespace std;
// atl : all to lower
char atl(char i){
    if(i >= 'A' && i <= 'Z')
        return i + 32;
    else return i;
}
void print(string s[], int n){
    n--;
    for(int i = n; i > 0; i--){
        cout<<s[i]<<" ";
    }
    cout<<s[0];
}
// 0 if i > j 1 if i < j

short int chcomp(char i, char j){
    if(atl(i) > atl(j))             return 1;
    else if(atl(i) < atl(j))        return 0;
    else{
        if(i >= 'A' && i <= 'Z')    return 0;
        else                        return 1;
    }
}

short int strcomp(string a, string b){
    int len = min(a.length(), b.length());
    len = min(len, 5);
    if(a == b)  return -1;
    int ret = 2;
    for(int i  = 0; i < len; i++){
        if(a[i] != b[i]){
            short int t = chcomp(a[i], b[i]);
            if(t == 0)         ret = 0;
            else if(t == 1)    ret = 1;
            break;
        }
    }
    if(len >= 5 && ret == 2)            return 0;
    if(ret == 2){
        if(a.length() <= b.length())    return 0;
        else                            return 1;
    }
    return ret;
}

void sort(string arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            short int t = strcomp(arr[i], arr[j]);
            if(t == 0 || t == 2)
                swap(arr[i], arr[j]);
        }
    }
}



int main(){
    //cout<<strcomp("Sara","sahari");
    int n;
    cin>>n;
    string s[n];

    for(int i = 0; i < n; i ++)
        cin>>s[i];
    sort(s, n);
    print(s, n);
}