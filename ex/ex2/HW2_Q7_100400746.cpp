#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

bool isprime(int a){
        bool flag = false;
        if(a >= 2){
                flag = true;
                int x = sqrt(a);
                for(int i = 2; i <= x; i++){
                        if(a % i == 0){
                                flag = false;
                                break;
                        }
                }
        }
        return flag;
}

int main(){
	int n, c = 0;
	cin>>n;
	for(int i = 2; i <= n; i++){
		if(isprime(i)){
			c = 0;
			while(n % i == 0){
				n /= i;
				c++;
			}
			if(c != 0)	cout<<i<<"\t"<<c<<endl;
		}
	}
	return 0;
}
