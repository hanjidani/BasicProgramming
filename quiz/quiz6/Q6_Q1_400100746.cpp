#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int v(int a, int b){
	if(a > b)
		return 1;
	else if(a < b)
		return 2;
	else return 3;

}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	n--;
	int c = 0;
	int pr = v(a[0], a[1]);
	for(int i = 1; i < n; i++){
		if(c == 0){
			    int t = v(a[i], a[i + 1]);
				if(pr == 3)	pr = t;
				if(pr != t && t != 3){	
					c++;
					pr = v(a[i], a[i + 1]);			
				}
			}
		else {
			if(pr != v(a[i], a[i + 1])){
				c++;
				pr = v(a[i], a[i + 1]);	
			}
		}
		//cout<<a[i]<<" "<<a[i + 1]<<" "<<c<<endl;
	}
	if(c > 1)	cout<<"No";
	else 		cout<<"Yes";
	return 0;
}
