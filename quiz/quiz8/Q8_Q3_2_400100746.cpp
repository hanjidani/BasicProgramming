#include<iostream>
#include<cmath>
#include<iomanip>
#include<string.h>

using namespace std;
int n,m, gpl=1;

void path(int * h, bool * travelled, int length, int i, int j);

int main()
{
    cin>>m>>n;
    int heights[n][m];
    bool travelled[n][m];

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin>>heights[i][j];
            travelled[i][j]=false;
        }
    }

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            path(&heights[0][0],&travelled[0][0],1,i,j);

    cout<<gpl;

    return 0;
}

void path(int * h, bool * travelled, int length, int i, int j)
{
    *(travelled+i*m+j)=true;

    if (length>gpl)
        gpl=length;

    //go up
    if (i>0 && abs(*(h+i*m+j)-*(h+(i-1)*m+j))==1 && !*(travelled+(i-1)*m+j))
        path(h, travelled,length+1,i-1,j);

    //go down
    if (i<n-1 && abs(*(h+i*m+j)-*(h+(i+1)*m+j))==1 && !*(travelled+(i+1)*m+j))
        path(h, travelled,length+1,i+1,j);

    //go left
    if (j>0 && abs(*(h+i*m+j)-*(h+i*m+j-1))==1 && !*(travelled+i*m+j-1))
        path(h, travelled,length+1,i,j-1);

    //go right
    if (j<m-1 && abs(*(h+i*m+j)-*(h+i*m+j+1))==1 && !*(travelled+i*m+j+1))
        path(h, travelled,length+1,i,j+1);


    *(travelled+i*m+j)=false;
}
