#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

int main(){
    long long int n, first;
    cin>>n;
    first = n * n - n + 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<first - j * (n)<<' ';
        cout<<endl;
        first++;
    }
    
	return 0;
}
