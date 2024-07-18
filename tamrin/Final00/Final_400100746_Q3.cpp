#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;

void mulaNum(short int a[],short x){
    int i = 0;
    while(a[i] != -1) {
        a[i] *= x;
        i++;
    }
    i=0;
    while(a[i + 1] != -1){
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
        i++;
    }
    if(a[i] > 9){
        a[i + 1]=a[i] / 10;
        a[i] %= 10;
        a[i + 2] = -1;
    }
}
short int tool(short int a[])
{
    int len = 0;
    while(a[len] != -1)
        len++;
    return len;
}
void jam(short int a[],short int b[],short int c[])
{
    int i = 0;
    while((a[i] != -1) && (b[i] != -1)){
        c[i]=a[i]+b[i];
        i++;
    }
    if(a[i] != -1){
        while(a[i] != -1){
            c[i] = a[i];
            i++;
        }
    }
    else if(b[i] != -1){
        while(b[i] != -1){
            c[i] = b[i];
            i++;
        }
    }
    c[i] = -1;
    i = 0;
    while(c[i + 1] != -1){
        c[i+1]+=c[i]/10;
        c[i]%=10;
        i++;
    }
    if(c[i] > 9){
        c[i + 1]=c[i] / 10;
        c[i] %= 10;
        c[i + 2] = -1;
    }
}
void rev(short int a[]){
    int l = tool(a);
    for(int i = 0; i < l / 2; i++)
        swap(a[i], a[l - i - 1]);
}

void mv(short int a[],short int b[], short i){
    int j = 0;
    while(j < i){
        b[j] = 0;
        j++;
    }
    while(a[j-i] != -1) {
        b[j] = a[j - i];
        j++;
    }
    b[j] = -1;
}

void zarb(short int a[],short int b[],short int c[]){
    short int temp[1000];
	short len = tool(a);
    c[0] = 0;
    c[1] = -1;
    rev(a);
    rev(b);
    for(int i = 0; i < len; i++){
        mv(b,temp,i);
        mulaNum(temp,a[i]);
        jam(c,temp,c);
    }

    rev(a);
    rev(b);
    rev(c);
}


int main(){
	short int a[500], b[500], c[1000];
	char ch = 0;
	int i = 0;
	while(true){
		cin>>ch;
		if(ch != '#' && ch >= '0' && ch <= '9'){
			a[i] = ch -'0';
			i++;
		} else if(ch == '#'){
			a[i] = -1;
			break;
		}
	}
	i = 0;
	while(true){
		cin>>ch;
		if(ch != '#' && ch >= '0' && ch <= '9'){
			b[i] = ch -'0';
			i++;
		} else if(ch == '#'){
			b[i] = -1;
			break;
		}
	}
	zarb(a, b, c);
	i = 0;
	while(c[i] != -1)
		cout<<c[i++];
	return 0;
}
