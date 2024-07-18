#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <fstream>

// just a template to start

using namespace std;

char char_up(char ch, int n)
{
	// check if the ltter is lower case or upper
	if (ch >= 'a' && ch <= 'z')
	{
		if (ch + n > 'z')
		{
			int temp = ch + n - 'z';
			return 'a' + temp;
		}
		else
		{
			return ch + n;
		}
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		if (ch + n >= 'Z')
		{
			int temp = ch + n - 'Z';
			return 'A' + temp;
		}
		else
		{
			return ch + n;
		}
	}
	else
	{
		return ch;
	}
}

string sezar(string s, int n)
{
	for (int i = 0; i < s.length(); i++)
	{
		s[i] = char_up(s[i], n);
	}
	return s;
}

int main()
{
	string name;
	cin >> name;
	int n;
	cin >> n;
	//cout<<sezar("Dastoor midaham moteghaleban edam shavand", 3);
	ifstream in;
	in.open(name.c_str());
	name.pop_back();
	name.pop_back();
	name.pop_back();
	name.pop_back();
	name = name + "dec.txt";
	ofstream out;
	out.open(name, ios::app);
	if (in.good())
	{
		while (!in.eof())
		{
			getline(in, name);
			name = sezar(name, n);
			out<<name<<endl;
		}
	}
	out<<n;

	return 0;
}
