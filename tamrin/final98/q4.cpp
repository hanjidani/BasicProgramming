#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

bool check(int city[500][500], int i, int j, int a){
    int sick = 0, healthy = 0;
    // left cell
    if(i != 0)  (city[i - 1][j] == 1) ? sick++ : healthy++;
    // right cell
    if(i != a - 1)  (city[i + 1][j] == 1) ? sick++ : healthy++;
    // up cell
    if(j != 0)  (city[i][j - 1] == 1) ? sick++ : healthy++;
    // down cell
    if(j != a - 1)  (city[i][j + 1] == 1) ? sick++ : healthy++;
    // up-left cell
    if(j != 0 && i != 0)  (city[i - 1][j - 1] == 1) ? sick++ : healthy++;
    // up-right cell
    if(j != 0 && i != a - 1)  (city[i + 1][j - 1] == 1) ? sick++ : healthy++;
    // down-left cell
    if(j != a - 1 && i != 0)  (city[i - 1][j + 1] == 1) ? sick++ : healthy++;
    // down-right cell
    if(j != a - 1 && i != a - 1)  (city[i + 1][j + 1] == 1) ? sick++ : healthy++;
    if(sick > healthy)  return true;
    else if(sick < healthy) return false;
    else return (bool) city[i][j];
}

void checkAll(int city[500][500], int a){
    int temp[500][500];
    for(int i = 0; i < a; i++)
        for(int j = 0; j < a; j++)
            temp[i][j] = check(city, i, j, a);
    for(int i = 0; i < a; i++)
        for(int j = 0; j < a; j++)
            city[i][j] = temp[i][j];
}

int main(){
    int city[500][500], a, k;
    cin>>a>>k;
    for(int i = 0; i < a; i++)
        for(int j = 0; j < a; j++)
            cin>>city[i][j];
    for(int i = 0; i < k; i++)
        checkAll(city, a);
    for(int i = 0; i < a; i++){
        for(int j = 0; j < a; j++)
            cout<<city[i][j]<<' ';
        cout<<endl;
    }
    
    //cout<<check(city, 0, 0, a)<<endl;
	return 0;
}
