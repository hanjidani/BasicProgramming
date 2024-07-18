#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start
// Hosein Anjidani 

using namespace std;

int meat, pot, nokhod;
char ch1, ch2, ch3;


void chef(char sefaresh);
void monshi(char sefaresh);
void waiter(int money, char sefaresh);

int main(){
	int money = 0, n = 0;
	char sefaresh;
	cin>>nokhod>>pot>>meat;
	cin>>ch1>>ch2>>ch3;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>money>>sefaresh;
		waiter(money, sefaresh);
	}
	return 0;
}

void waiter(int money, char sefaresh){
	if (sefaresh == 'f'){
		if(money >= 6000)	monshi(sefaresh);
		else 			cout<<"No enough money"<<endl;
	} else if(sefaresh == 's'){
		if(money >= 18000)	monshi(sefaresh);
		else 			cout<<"No enough money"<<endl;
	} else if(sefaresh == 'd'){
		if(money >= 30000)	monshi(sefaresh);
		else			cout<<"No enough money"<<endl;

	}
}

void monshi(char sefaresh){
	if(sefaresh == 'f'){
		if(ch1 == 'p')	chef(sefaresh);
		else if(ch1 == 'a') 		cout<<"Not a chef"<<endl;
	} else if(sefaresh == 's'){
		if(ch2 == 'p')	chef(sefaresh);
		else if(ch2 == 'a')		cout<<"Not a chef"<<endl;
	} else if(sefaresh == 'd'){
		if(ch3 == 'p')	chef(sefaresh);
		else if(ch3 == 'a')		cout<<"Not a chef"<<endl;
	}
}

void chef(char sefaresh){
	if(sefaresh == 'f'){
		if(nokhod >= 0){
			cout<<"Food is ready"<<endl;
			nokhod -= 1;
		} else {
			cout<<"Material is not enough"<<endl;
		}
	} else if(sefaresh == 's'){
		if(pot >= 0){
			cout<<"Food is ready"<<endl;
			pot -= 1;
		} else{
			cout<<"Material is not enough"<<endl;
		}
	} else if(sefaresh == 'd'){
		if(meat >= 0){
			cout<<"Food is ready"<<endl;
			meat -= 1;	
		} else{
				cout<<"Material is not enough"<<endl;
		}
	}
}

