#include<iostream>
#include<string.h>

using namespace std;

int main(){
    int arr[8];
    for(int i = 0; i < 8; i++)
        cin>>arr[i];
    for(int i = 0; i < 8; i++){
        for(int j = i + 1; j < 8; j++){
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
    for(int i = 7; i > 0; i--)
        cout<<arr[i]<<" ";
    cout<<arr[0];
    return 0;
}