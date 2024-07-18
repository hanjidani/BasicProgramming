#include<iostream>
#include<string.h>

using namespace std;

int sum(int x[100][100], int y[100][100], int m, int p, int b){
    int sum = 0;
    for(int i = 0; i < b; i++){
        sum += x[m][i] * y[i][p];
    }
    return sum;
}

int main(){
    int a,b,c, ans[100][100];
    int x[100][100], y[100][100];
    
    cin>>a>>b>>c;

    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
            cin>>x[i][j];
    
    for(int i = 0; i < b; i++)
        for(int j = 0; j < c; j++)
            cin>>y[i][j];

    for(int i = 0; i < a; i++){
        for(int j = 0; j < c; j++){
            ans[i][j] = sum(x, y, i, j, b);
        }
    }
    a--;
    c--;
    for(int i = 0; i < a; i++){
        for(int j = 0; j < c; j++)
            cout<<ans[i][j]<<" ";
        cout<<ans[i][c];
        cout<<endl;
    }
    for(int i = 0; i < c; i++)
        cout<<ans[a][i]<<" ";
    cout<<ans[a][c];
    return 0;
}