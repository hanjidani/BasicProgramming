#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;
string rem(string s, int c){
	string ret = "";
	int len = s.length();
	for(int i = c; i < len; i++){
		ret += s[i];
	}
	return ret;
}
string search(string &main, char ch){
	int len = main.length();
	int num = 0;
	int i = 0;
	for(i = 0; i < len; i++){
		if(main[i] == ch){
			num++;
		} else {
			break;
		}
	}
	string ret = "";
	main = rem(main, i);
	while(num >= 16){
		num -= 15;
		ret += ch;
		ret += 'f';
	}
	if(num > 0){
		if(num <= 9){
				ret += ch; 
				ret += to_string(num);
		}
		else{			
			ret += ch;
			ret += 'a' + num - 10;
		}
	}
	return ret;
}

string rev(string s){
	int len = s.length();
	string ret = "";
	for(int i = s.length() - 1; i >= 0; i--)
		ret += s[i];
	return ret;
}

int main(){
	string s;
	getline(cin, s);
	int len = s.length();
	string ret = "";
	while(len != 0){
		ret += search(s, s[0]);
		len = s.length();
	}
	cout<<rev(ret);
	return 0;
}
