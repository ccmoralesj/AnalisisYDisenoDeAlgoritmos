#include <bits/stdc++.h>
using namespace std;

float mini(float x, float y){
	return (x < y)? x : y;
}

float seqAlign(string X,int m,string Y,int n,float a,float b){
	float P[m+1][n+1];
	for (int i=0;i<=m;i++)	P[i][0] = i*a;
 	for (int j=0;j<=n;j++)	P[0][j] = j*a;
	float MIN,term;
	for (int i= 1; i<=m ; i++){
		for (int j= 1; j<=n ; j++){
			if(X[i-1] != Y[j-1]) term = P[i-1][j-1] + b;
			else term = P[i-1][j-1];
			MIN= mini(term,P[i][j-1] + a);
			MIN= mini(MIN,P[i-1][j] + a);                    
			P[i][j] = MIN;                      
		}
	}
   return P[m][n];
}
