#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;
 
int tabe2(int n){
    int ret = 1;
    for(int i = 2; i < n; i++){
        if(n % i == 0)  ret += i;
    }
    return ret;
}
int main(){
    int x, y;
    cin>>x>>y;
    int arr[x][y];
    for(int i = 0; i < x; i++)
        for(int j = 0; j < y; j++)
            cin>>arr[i][j];
    int ret[y][x];
    for(int i = 0; i < y; i++)
        for(int j = 0; j < x; j++)
            ret[i][j] = arr[j][i];
    for(int i = 0; i < y; i++){
        for(int j = 0; j < x; j++)
            cout<<ret[i][j]<<" ";
        cout<<endl;
    }
    
     
	return 0;
}
