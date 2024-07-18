#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

void hanoi(int n, char a, char b, char c){
	if(n > 0){
		hanoi(n - 1, a, c, b);
		cout<<a<<" --> "<<c<<endl;
		hanoi(n - 1, b, a, c);
	}
}

int main(){
	int n;
	cin>>n;
	hanoi(n, 'A', 'B', 'C');
	return 0;
}
