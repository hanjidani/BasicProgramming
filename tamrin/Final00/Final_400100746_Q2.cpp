#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

char toLowerCase(char i){
    if(i >= 'A' && i <= 'Z')
        return i + 32;
    else return i;
}

string toLower(string s){
    int len = s.length();
    for(int i = 0; i < len; i++)
        s[i] = toLowerCase(s[i]);
    return s;
}

int main(){
	string s;
	getline(cin, s);
	int len = s.length();
	bool ch[26];
	for(int i = 0; i < 26; i++)
		ch[i] = false;
	s = toLower(s);
	//cout<<s;
	for(int i = 0; i < len; i++){
		if(s[i] <= 'z' && s[i] >= 'a')
			ch[int(s[i] - 'a')]  = true;
	}
	for(int i  = 0; i < 26; i++)
		if(!ch[i]){
			cout<<"NO";
			return 0;
		}
	cout<<"YES";
	return 0;
}
