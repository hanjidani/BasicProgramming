#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

// just a template to start

using namespace std;

int minInArray(int a[], int n){
    int min = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] < min)  min = a[i];
    return min;
}

int maxInArray(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > max)  max = a[i];
    return max;
}

void bubbleSort(int a[], int n){
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}

string split(int st, int fi, string s){
    string ret;
    fi = min(fi, s.length() - 1);
    for(int i = st; i <= fi; i++)
        ret += s[i];
    return ret;
}

bool isprime(int a){
	bool flag = false;
	if(a >= 2){
		flag = true;
		int x = sqrt(a);
		for(int i = 2; i <= x; i++){
			if(a % i == 0){
				flag = false;
				break;
			}
		}
	}
	return flag;
}

char toLowerCase(char i){
    if(i >= 'A' && i <= 'Z')
        return i + 32;
    else return i;
}

char toUpperCase(char i){
    if(i >= 'a' && i <= 'z')
        return i - 32;
    else return i;
}

string toUpper(string s){
    int len = s.length();
    for(int i = 0; i < len; i++)
        s[i] = toUpperCase(s[i]);
    return s;
}

void hanoi(int n, char a, char b, char c){
	if(n > 0){
		hanoi(n - 1, a, c, b);
		cout<<a<<" --> "<<c<<endl;
		hanoi(n - 1, b, a, c);
	}
}

string toLower(string s){
    int len = s.length();
    for(int i = 0; i < len; i++)
        s[i] = toLowerCase(s[i]);
    return s;
}



int main(){

	return 0;
}
