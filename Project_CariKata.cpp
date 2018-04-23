#include<iostream>
#include<stdio.h>
using namespace std;

#define R 15
#define C 15
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool cari2D(char grid[R][C], int row, int col, string kata)
{
    if (grid[row][col] != kata[0]){
    	 return false;
	}
    int len = kata.length();
    for (int dir = 0; dir < 8; dir++)
	    {
        int k, rd = row + x[dir], cd = col + y[dir];
        for (k = 1; k < len; k++)
        {
		if (rd >= R || rd < 0 || cd >= C || cd < 0)
                break;
            if (grid[rd][cd] != kata[k])
                break;
            rd += x[dir], cd += y[dir];
        }
	    if (k == len)
            return true;
    }
    return false;
}
void patternSearch(char grid[R][C], string kata)
{
	int flag=0;
    for (int row = 0; row < R; row++)
       for (int col = 0; col < C; col++)
          if (cari2D(grid, row, col, kata))
             flag=1;
if(flag==1) cout << "Ada coeg" << endl;
    else if(flag==0) cout << "gada coeg" << endl;
}
int main()
{
