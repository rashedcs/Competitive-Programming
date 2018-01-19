#include <bits/stdc++.h>
using namespace std;
 
int n;
int arr[10]; 
 
int check(int row, int col)
{
    for (int i=0; i<row; i++) 
    {
        if (arr[i] == col || abs(row - i) == abs(col -arr[i]))  return false;
    }
    return true;
}
 
 
void print()
{
       for(int row=0; row<n; row++) 
        {
            for(int col=0; col<n; col++) 
            {
                if(arr[row] == col) cout<<"1 ";
                else                cout<<"0 ";
            }
            cout<<endl;
        }
}
 
 
bool nqueen(int row) 
{
    if (row==n) 
    {
        print();
        return true;
    }
    
    for (int col=0; col<n; col++) 
    {
        if(arr[n-1]>0) //For one solution .... Otherwise gets many solution
        {
            break;
        }
        else if(check(row,col)) 
        {
            arr[row] = col;
            nqueen(row + 1);
        }
    }
    return false; 
}
 
 
int main()
{
    cin>>n;
    if (n==1) cout<<"1\n";
    else if(n>1 && n<4) cout<<"Not possible\n";
    else                nqueen(0);
    return 0;
}
