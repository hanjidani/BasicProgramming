#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;
int ret[1000]{-1};
int an = 0;
void gen(int num, int N, int K){
    if(N==0){
        ret[an] = num;
        an++;
    } 
    else{
        if(num % 10 - K >= 0) gen(num * 10 + num % 10 - K, N - 1, K);
        if(num % 10 + K <= 9) gen(num * 10 + num % 10 + K, N - 1, K);
    }
}

int main()
{
    int n,k;
    cin>>n>>k;
    if(n == 1){
        for(int i = 0; i < 10; i++){
            cout<<i<<endl;
        }
        return 0;
    }
    for(int num = 1; num <= 9; num++){
        gen(num, n - 1, k);
    }
    for(int i = 0; i < an; i++){
        for(int j = i + 1; j < an; j++){
            if(ret[i] > ret[j])
                swap(ret[i], ret[j]);
        }
    }
    for(int i = 0; i < an; i++)
    {
        cout<<ret[i]<<endl;
    }



    return 0;
}