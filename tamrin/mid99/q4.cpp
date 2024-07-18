#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;
int a[100][100];
int maxRow(int n, int row){
	int tmp = a[row][0], index = 0;
	for(int i = 1; i < n; i ++){
		if(a[row][i] > tmp){
			tmp = a[row][i];
			index = i;
		}
	}
	return index;
}

int minCol(int n, int col){
        int tmp = a[0][col], index = 0;
        for(int i = 1; i < n; i ++){
                if(a[i][col] < tmp){
                        tmp = a[i][col];
                        index = i;
                }
        }
        return index;
}

int main(){
	int n, max = 0, min = 0;
	cin>>n;
	for(int i  = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			cin>>a[i][j];
		}
	}
	bool print = false;	
	for(int i = 0; i < n; i ++){
		max = maxRow(n, i);
		min = minCol(n, max);
		if(min == i){
			cout<<min<<" "<<max<<endl;
			print = true;
		}
	}
	if(!print)	cout<<"NO";
	return 0;
}
