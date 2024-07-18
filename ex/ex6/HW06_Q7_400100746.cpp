#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;
int a[100][100];
void maxRow(int n, int ma[], int mi[]){
    for(int i = 0; i < n; i ++){
        int max = a[i][0];
        int min = a[i][0];
        for(int j = 1; j < n; j++){
            if(a[i][j] > max)  max = a[i][j];
            else if(a[i][j] < min)  min = a[i][j];
        }
        ma[i] = max;
        mi[i] = min;
    }
}

void minCol(int n, int ma[], int mi[]){
    for(int j = 0; j < n; j ++){
        int max = a[0][j];
        int min = a[0][j];
        for(int i = 1; i < n; i++){
            if(a[i][j] < min)  min = a[i][j];
            else if(a[i][j] > max)  max = a[i][j];
        }
        ma[j] = max;
        mi[j] = min;
    }
}

int main(){
	int n, max = 0, min = 0;
	cin>>n;
	for(int i  = 0; i < n; i ++){
		for(int j = 0; j < n; j ++){
			cin>>a[i][j];
		}
	}
    int mincol[n], maxrow[n], minrow[n], maxcol[n];
    minCol(n, maxcol, mincol);
    maxRow(n, maxrow, minrow);
	bool print = false;	
	for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j++){
            if((maxrow[i] == a[i][j] && mincol[j] == a[i][j]) || (minrow[i] == a[i][j] && maxcol[j] == a[i][j])){
                print = true;
                cout<<i + 1<<" "<<j + 1<<endl;
            }
        }
	}
	if(!print)	cout<<-1;
	return 0;
}