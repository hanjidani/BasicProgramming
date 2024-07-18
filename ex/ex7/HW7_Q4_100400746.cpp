#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;


int part(int arr[], int low, int high){
	int pivot = arr[high], i = low - 1;
	for(int j = low; j <= high; j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void QS(int arr[], int low, int high){
	if(low < high){
		int pivot = part(arr, low, high);

		QS(arr, low, pivot - 1);
		QS(arr, pivot + 1, high);
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	n--;
	QS(arr, 0, n);
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<arr[n];
	return 0;
}
