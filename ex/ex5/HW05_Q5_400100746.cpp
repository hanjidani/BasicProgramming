#include<iostream>
#include<cmath>

// just a template to start

using namespace std;

string split(string s, int i, int f){
	string ret = "";
	for(;i <= f; i++)
		ret += s[i];
	return ret;
}

string ref(string str){
    //str = split(str,0, str.length() - 2);
    if(str[str.length() - 1] == ' ')
        str = split(str,0, str.length() - 2);
    //cout<<str<<endl;
    return str;
}

int getArraySize(string s){
	int m = 1, len = s.length() - 1;
	for(int i = 0; i < len; i++)
		if(s[i] == ' ')
			m++;
	return m;
}

int strToInt(string s){
	int ret = 0;
    if(s[0] == '-'){
        for(int i = 1; i < s.length(); i++){
		    ret *= 10;
		    ret += (int)(s[i] - '0');
	    }
        ret = -ret;
    } else {
        for(int i = 0; i < s.length(); i++){
		    ret *= 10;
		    ret += (int)(s[i] - '0');
	    }
    }
	return ret;
}

void toArray(int arr[] ,string s){
	int con = -1, index = 0, len = s.length() - 1;
	for(int i = 0; i < len; i++){
		if(s[i] == ' '){
			arr[index] = strToInt(split(s, con + 1, i - 1));
			con = i;
			index++;
		}
	}
	//cout<<strToInt(split(s, con + 1, len));
	arr[index] = strToInt(split(s, con + 1, len));
}

void printArray(int arr[], int size){
	size --;
	for(int i = 0; i < size; i++)
		cout<<arr[i]<<" ";
	cout<<arr[size];
}
 
void merge(int arr[], int st, int mid, int end){
    int i = 0, j = 0, k = st;
    int size1 = mid - st + 1;
    int size2 =  end - mid;
    int L[size1], R[size2];
    for (; i < size1; i++)
        L[i] = arr[st + i];
    for (; j < size2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    while (i < size1 && j < size2){
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < size1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < size2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size){ 
	size--;
	for (int i = 1; i <= size; i = 2 * i){
        for (int j = 0; j < size; j += 2 * i){
           int mid = min(j + i - 1, size);
           int rend = min(j + 2 * i - 1, size);
           merge(arr, j, mid, rend);
       }
   }
}

int main(){
	string s = "";
	getline(cin, s);
    s = ref(s);
	int size = getArraySize(s);
	int arr[size];
	toArray(arr, s);
	mergeSort(arr, size);
	printArray(arr, size);
	return 0;
}
