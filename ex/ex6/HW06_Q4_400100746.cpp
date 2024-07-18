#include<iostream>
#include<string.h>

using namespace std;

void hello(string list[], int n, string newface){
    for(int i = n - 1; i >= 0; i--)
        cout<<newface<<": salam "<<list[i]<<"!"<<endl;
}

void bye(string list[], int n, int i){
    string oldface = list[i];
    n--;
    if(i == n)  cout<<oldface<<": khodafez bacheha!";
    else        cout<<oldface<<": khodafez bacheha!"<<endl;
    
    if(i != n){
        i++;
        for(;i < n; i++)
            cout<<list[i]<<": khodafez "<<oldface<<"!"<<endl;
        cout<<list[n]<<": khodafez "<<oldface<<"!"<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    string list[n], t;
    for(int i = 0; i < n; i++){
        cin>>t;
        list[i] = t;
        hello(list, i, t);
    }
    for(int i = 0; i < n; i++)
        bye(list, n, i);
        
    return 0;
}