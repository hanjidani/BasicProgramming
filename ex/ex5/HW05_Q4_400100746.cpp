#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

void ommit(int a[], string s){
	if(s.compare("shanbe") == 0)			a[0] = 1;
	else if(s.compare("1shanbe") == 0)	a[1] = 1;
	else if(s.compare("2shanbe") == 0)	a[2] = 1;
	else if(s.compare("3shanbe") == 0)	a[3] = 1;
	else if(s.compare("4shanbe") == 0)	a[4] = 1;
	else if(s.compare("5shanbe") == 0)	a[5] = 1;
	else if(s.compare("jome") == 0)		a[6] = 1;
}

void print(int a[]){
	int m = 0;
	for(int i = 0; i < 7; i++){
		if(a[i] == 0)	m++;
		//cout<<a[i];
	}
	cout<<m;
}

int main(){
	int a[7] = {0,0,0,0,0,0,0};
	int s = -1;
	string str;
	for(int i = 0; i < 3; i++){
		cin>>s;
		for(int j = 0; j < s; j++){
			cin>>str;
			ommit(a, str);
		}
	}
	print(a);
	return 0;

}
