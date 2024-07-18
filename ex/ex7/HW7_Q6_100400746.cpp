#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>
#include<fstream>
using namespace std;
int toint(string s){
	int len = s.length();
	int ret = 0;
	for(int i = 0; i < len; i++){
		ret = ret * 10 + (s[i] - '0');
	}
	return ret;
}
string reverse(string text){
	int len = text.length();
	string ret = "";
	for(int i = len - 1; i >= 0; i--)
		ret += text[i];
	return ret;
}
string shiftl(string s, int n){
	int len = s.length();
	string ret = "";
	for(int i = 0; i < len; i++)
		ret += s[(i + n < len) ? i + n : i + n - len];
	return ret;
}
string shiftr(string s, int n){
	int len = s.length();
	string ret = "";
	for(int i = 0; i < len; i++)
		ret +=s[(i - n < 0) ? i - n + len : i - n];
	return ret;
}
string split(int st, int fi, string s){
	string ret;
	for(; st <= fi; st++)
		ret += s[st];
	return ret;
}
string extract(string &cmd){
	string ret = "", first = cmd;
	int i, len = cmd.length(); 
	for(i = 0; i < len; i++){
		if(cmd[i] != ' '){
			ret += cmd[i];
		} else	break;
	}
	i += 1;
	cmd = "";
	for(; i < len; i++){
		cmd += first[i];
	}
	return ret;
}
short command(string cmd, string &text){
	if(cmd[cmd.length() - 1] == ' ')	cmd.pop_back();
	string com = extract(cmd);
	if(com == "PRINT")	return 1;
	else if(com == "SHIFT-R"){
		int len = text.length();
		int n = toint(cmd);
		n = n % len;
		text = shiftr(text, n);
	} else if(com == "SHIFT-L"){
		int len = text.length();
		int n = toint(cmd);
		n = n % len;
		text = shiftl(text, n);
	} else if(com == "EXTEND"){
		int n = toint(cmd);
		for(int i = 0; i < n; i++)
			text += '*';
	} else if(com == "SHRINK"){
		int n = toint(cmd), len = text.length();
		n = min(n, len);
		for(int i = 0; i < n; i++)
			text.pop_back();
	} else if(com == "REVERSE")
		text = reverse(text);
	else if("PUT")
		text[toint(extract(cmd)) - 1] = cmd[0];
	else if("EXIT")	return -1;
	return 0;
}
int main(){
	string name;
	cin>>name;
	ifstream in;
	in.open(name.c_str());
	ofstream out;
	out.open("out.txt", ios::app);
	string text, cmd;
	short ret = 0;
	int line = 0;
	bool first = true;
	while (!in.eof()){
		if(in.good()){
			if(line == 0)	getline(in, text);
			else{
				getline(in, cmd);
				ret = command(cmd, text);
				if(ret == 1){
					if(first){
						out<<text;
						first = false;
					} else	out<<endl<<text;
				} else if(ret == -1)
					break;
			}
		}
		line++;
	}
	return 0;
}