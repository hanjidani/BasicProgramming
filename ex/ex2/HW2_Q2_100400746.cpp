#include<iostream>
#include<cmath>

using namespace std;

bool isprime(int a);

int main(){
	int flag = -1,a,b,temp;
	cin>>a>>b;
	if(a > b){
		temp = b;
		b = a;
		a = temp;
	}
	a++;
	while(flag == -1 && a < b){
		if(isprime(a)){
			flag = a;
		}
		//cout<<a<<isprime(a)<<endl;
		a++;
	}
	cout<<flag<<endl;
	return 0;
}


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
