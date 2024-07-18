#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;
void selectionSort(int a[], int n){
    int index;
    for(int i = n - 1; i > 0; i--){
        index = 0;
        for(int j = 0; j < i; j++){
            if(a[j] > a[index]){
                index = j;
            }
        }
        swap(a[i], a[index]);
    }
}
int main(){
    int a[100], n, m1 = 0, m2 = -1;
    cin>>n;
    for(int i = 0; i < n; i++)  cin>>a[i];
    //selectionSort(a,n);
    for(int i = 0; i < n; i++){
        if(a[i] > m1){
            m2 = m1;
            m1 = a[i];
        }
    }
    cout<<m2<<endl;
    //for(int i = 0; i < n; i++)  cout<<a[i];
	return 0;
}
