#include<iostream>
#include<string.h>

using namespace std;
int a[8][8];

short int rthreats(int x, int y){
    short int ret = 0;
    for(int j = 0; j < 8; j++){
        if(j != y && a[x][j] != 0)
            ret++;
    }
    for(int i = 0; i < 8; i++){
        if(i != x && a[i][y] != 0)
            ret++;
    }
    return ret;
}

int vthreats(int x,int y){
    short int ret = 0;
    for(int j = 0; j < 8; j++){
        if(j != y && a[x][j] != 0)
            ret++;
    }
    for(int i = 0; i < 8; i++){
        if(i != x && a[i][y] != 0)
            ret++;
    }
    int i = x - 1,j = y - 1;
    while(i >= 0 && j >= 0){
        if(a[i][j] != 0)
            ret++;
        i--;
        j--;
    }
    i = x + 1,j = y + 1;
    while(i < 8 && j < 8){
        if(a[i][j] != 0)
            ret++;
        i++;
        j++;
    }
    i = x + 1,j = y - 1;
    while(i < 8 && j >= 0){
        if(a[i][j] != 0)
            ret++;
        i++;
        j--;
    }
    i = x - 1, j = y + 1;
    while(i >= 0 && j < 8){
        if(a[i][j] != 0)
            ret++;
        i--;
        j++;
    }
    return ret;
}
int main(){
    // input
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            cin>>a[i][j];
    int c = 0;    
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            if(a[i][j] == 1)
                c += vthreats(i , j);
            else if(a[i][j] == 2)
                c += rthreats(i, j);
    cout<<c;
    return 0;
}