#include<bits/stdc++.h>
using namespace std;

int maxCommonSub(string X,int m,string Y,int n){
	int L[m+1][n+1];
	for (int i=0;i<m;i++)L[i][0] = 0;
	for (int j= 0;j<n;j++) L[0][j] = 0;
	for (int i=1;i<=m;i++) {
		for(int j=1;j<=n;j++){
			if (X[i-1] == Y[j-1])
				L[i][j] = L[i-1][j-1] + 1;
            else 
				L[i][j] = max(L[i-1][j], L[i][j-1]);
       }
   }
   return L[m][n];
}
