#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;
void printMyArray(int a[]){
    for(int i = 0; i < 12; i ++)    cout<<a[i]<<"\t";
    cout<<endl;
}
int findMax(int a[]){
    int m = -1;
    for(int i = 0; i < 12; i ++){
        if(a[i] > m)    m = a[i];
    }
    return m;
}

int main(){
    srand(time(NULL));
    int a[12];
    for(int i = 0; i < 12; i ++)    a[i] = rand() % 15;
    printMyArray(a);
    int m = findMax(a);
    for(int j = m; j > 0; j--){
        for(int i = 0; i < 12; i ++){
            if(a[i] >= j)   cout<<'*';
            else            cout<<' ';
        }
        cout<<endl;
    }
	return 0;
}
