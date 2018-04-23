#include<iostream>
#include<stdio.h>
using namespace std;

#define R 15
#define C 15
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
bool cari2D(char grid[R][C], int row, int col, string kata)
