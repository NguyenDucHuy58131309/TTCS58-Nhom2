#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
ifstream f("InputBai1.txt", ifstream::in);
ofstream g("OutputBai1.txt", ifstream::out);
int Dx[4] = {0, 1, 0, -1};
int Dy[4] = {1, 0, -1, 0};
int main(){
	int A[10][10];
	int n, limit, countlimit = 1;
	f >> n;
	limit = n;
	int x = 0, y = 0, Change = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			f >> A[i][j];
	for(int i = 0; i < 2*n - 1; i++){
		for(int j = 0; j < limit; j++){
			g << A[x][y] << " ";
			x += Dx[Change];
			y += Dy[Change];
		}
		x -= Dx[Change];
		y -= Dy[Change];
		if (Change == 3) Change = 0; else Change++;
		x += Dx[Change];
		y += Dy[Change];
		if (countlimit == 1){
			countlimit = 0;
			limit--;
		} 
		else countlimit++; 
	}
	f.close();
	g.close();
}
