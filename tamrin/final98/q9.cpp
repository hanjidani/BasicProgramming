#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int tabe(int n){
    if(n == 1)  return 1;
    int x = n;
    int ret = 1;
    for(int i = 2; i < x; i++){
        int s = 0;
        if(n % i == 0){
            s++;
            n = n / i;
            while(n % i == 0){
                n = n / i;
                s++;
            }
            ret *= (s + 1);
            //cout<<n<<endl;
        }
    }
    if(ret == 1)  return 2;
    return ret;
} 
int tabe2(int n){
    int ret = 1;
    for(int i = 2; i <= n; i++){
        if(n % i == 0)  ret++;
    }
    return ret;
}
int main(){
    /*//cout<<tabe(6);
    for(int i = 1; i <= 100; i++)
        cout<<i<<"\t"<<tabe(i)<<"\t"<<tabe2(i)<<endl;*/
    int n, x, index;
    cin>>n;
    int arr[n];
    int ret[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>x;
    cout<<x;
    int j = 0, k = n - 1;
    for(int i = 0; i < n; i++){
        if(arr[i] <= x){
            ret[j] = arr[i];
            j++;
        } else if(arr[i] > x){
            ret[k] = arr[i];
            k--;
        }
    }
    for(int i = 0; i < n; i++)
        cout<<ret[i]<<' ';
	return 0;
}
