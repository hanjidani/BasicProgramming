#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
	double a, b, c, d, temp, det;
	cin>>a>>b>>c>>d;
	det = (a * d) - (b * c);
	if(det == 0){
		cout<<"0";
		return 0;
	}
	temp = a;
	a = d / det;
	d = temp / det;
	b = -b / det;
	c = -c / det;
	cout<<fixed<<setprecision(2)<<a<<"\t"<<b<<endl<<c<<"\t"<<d<<endl;
	return 0;
}
