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

void toArray(string arr[] ,string s){
	int con = -1, index = 0, len = s.length() - 1;
	for(int i = 0; i < len; i++){
		if(s[i] == ' '){
			arr[index] = split(s, con + 1, i - 1);
			con = i;
			index++;
		}
	}
	//cout<<strToInt(split(s, con + 1, len));
	arr[index] = split(s, con + 1, len);
}

void printArray(string arr[], int size){
	size --;
	for(int i = size; i > 0; i--)
		cout<<arr[i]<<" ";
	cout<<arr[0];
}

int main(){
	string s = "";
	getline(cin, s);
    s = ref(s);
	int size = getArraySize(s);
	string arr[size];
	toArray(arr, s);
	printArray(arr, size);
	return 0;
}
