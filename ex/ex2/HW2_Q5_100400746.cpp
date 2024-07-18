#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	int n,m,x,temp;
	cin>>n>>m>>x;
	if(x == 0)	return 0;
	if(m > n){
		temp = n;
		n = m;
		m= temp;
	}
	for(;n >= m; n--){
		if(n % x == 0)	cout<<n<<endl;
	}
	return 0;
}
