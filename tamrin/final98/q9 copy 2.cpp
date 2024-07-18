#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

int main(){
    long long int n, m;
    cin>>n>>m;
    m--;
    // find the biggest pow of 6 which is less than the m
    long long int p = 0, temp = 1, dah = 1;
    while(temp <= m){
        temp *= 6;
        dah *= 10;
        p++;
    }    
    if(p > 0){   
        p--;
        temp /= 6;
        dah /= 10;
    }
    //cout<<dah;
    long long int fi = 0, tt;
    for(long long int i = p; i >= 0; i--){
        tt = (m / temp);
        fi += (tt + 1) * dah;
        m -= tt * temp;
        temp /= 6;
        dah /= 10;
        //cout<<fi;
    }
    p++;
    n = n - p;
    //cout<<n;
    for(long long int i = 0; i < n; i++)
        cout<<1;
    cout<<fi;
	return 0;
}
