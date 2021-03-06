#include<iostream>
#include<stdio.h>
using namespace std;
//Definisi besar baris dan Kolom
#define R 15
#define C 15

//Untuk mencari kata di 8 arah
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
    if(flag==1) cout << "Ada" << endl;
    else if(flag==0) cout << "Tidak ada" << endl;
}
 
int main()
{
    char grid[R][C] = { {'t','g','b','w','w','i','n','t','e','r','w','s','e','s','n'},
			{'a','a','u','n','t','t','m','m','h','f','o','o','d','n','b'},
			{'j','l','w','c','q','l','d','z','m','p','m','v','d','m','r'},
			{'a','s','a','g','m','q','u','w','v','v','b','s','o','h','i'},
			{'b','w','p','l','o','t','a','n','a','d','t','p','g','n','c'},
			{'r','e','w','n','g','o','d','j','c','p','n','a','t','n','k'},
			{'e','e','o','t','w','o','s','b','q','h','a','r','r','s','a'},
			{'a','z','c','g','e','s','w','e','w','n','a','k','n','p','b'},
			{'d','i','n','n','e','r','q','o','d','l','w','d','c','a','r'},
			{'o','n','o','p','k','w','m','p','a','r','k','t','z','c','c'},
			{'q','b','f','r','o','g','m','a','m','w','p','w','e','e','y'},
			{'l','q','z','q','n','n','m','r','z','j','j','s','c','l','g'},
			{'m','o','s','g','z','c','z','e','t','d','b','o','o','t','o'},
			{'p','d','c','r','z','m','s','n','g','r','d','n','r','p','z'},
			{'o','h','n','k','z','w','a','t','e','r','j','g','t','r','a'}
			};
	int n;
	cin>>n;
	char kata[100];

 	for (int i=1;i<=n;i++){
 		cout<<"Masukkan Kata ke-"<<i<<" : ";cin>>kata;
		patternSearch(grid, kata);
	 }	
    return 0;
}
