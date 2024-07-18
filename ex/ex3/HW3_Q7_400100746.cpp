#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int main(){
	int a, hsp = 1, vsp = 1, x = 0, y = 0;
	cin>>a;
	
	for(int i = 1; i < a; i++){
		if(i % 4 == 1){
			x += hsp;
			hsp ++;
		} else if(i % 4 == 2){
			y += vsp;
			vsp ++;
		} else if(i % 4 == 3){
			x -= hsp;
			hsp ++;
		} else if(i % 4 == 0){
			y -= vsp;
			vsp ++;
		}
	}	
	cout<<x<<' '<<y;
	return 0;
}
