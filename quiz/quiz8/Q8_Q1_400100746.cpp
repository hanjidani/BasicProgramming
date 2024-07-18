#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;
int arr[20000], n;
int mx = 0;
void find(int i){
    if(i < n){
        if(arr[i] > arr[mx]){
            mx = i;
            find(i + 1);
        }
    }
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    //mx = 0;
    find(1);
    cout<<mx + 1;
    return 0;
}