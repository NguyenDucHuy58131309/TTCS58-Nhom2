#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
ifstream f("InputBai5.txt", ifstream::in);
ofstream g("OutputBai5.txt", ifstream::out);
int DoLechMin = 999;
int MinDomino = 99;
struct Domino{
	bool Status;
	int Up;
	int Down;
};
Domino A[30];
int DoLech(Domino A[], int n){
	int SumUp = 0, SumDown = 0;
	for(int i = 0; i < n; i++)
		if (A[i].Status == 0){
			SumUp += A[i].Up;
			SumDown += A[i].Down;
		}
		else
		{
			SumUp += A[i].Down;
			SumDown += A[i].Up;
		}
	return abs(SumUp - SumDown);
}
int CountDomino(Domino A[], int n){
	int Count = 0;
	for(int i = 0; i < n; i++)
		if (A[i].Status == 1) Count++;
	return Count;
}
void QuayDomino(int i, int n, int &DoLechMin, int &MinDomino)
{
    for(int j = 0; j <= 1; j++)
    {
        A[i].Status = j;
        if(i == n-1){
        	if (DoLech(A, n) <= DoLechMin) 
        		if ((DoLech(A, n) == DoLechMin) && (CountDomino(A, n) < MinDomino)){
        			DoLechMin = DoLech(A, n);
        			MinDomino = CountDomino(A, n);
				}
				else
					DoLechMin = DoLech(A, n);
		}
        else QuayDomino(i+1, n, DoLechMin, MinDomino);
    }
}
int main(){
	int n;
	f >> n;
	for(int i = 0; i < n; i++){
		f >> A[i].Up;
		f >> A[i].Down;
		A[i].Status = 0;
	}
	DoLechMin = DoLech(A, n);
	QuayDomino(0, n, DoLechMin, MinDomino);
	g << DoLechMin << " " << MinDomino;
	f.close();
	g.close();
}
