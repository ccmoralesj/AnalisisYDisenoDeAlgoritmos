#include<bits/stdc++.h>
using namespace std;

int cutRod(int p[],int n){
   int R[n+1];
   R[0] = 0;
	for (int j=1;j<=n;j++){
		R[j] = 0;
		for(int i=1;i<=j;i++) R[j] = max(R[j], p[i-1]+R[j-i]);
	}
   return R[n]
}
