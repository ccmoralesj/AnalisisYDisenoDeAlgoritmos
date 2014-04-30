#include<bits/stdc++.h>
using namespace std;
int n= 5;
void printMCP(int S[][10000],int i,int j){
	if (i == j) printf("A%i",i);
	else{
      printf("(");
      printMCP(S, i, S[i][j]);
      printf(" x ");
      printMCP(S, S[i][j]+1, j);
      printf(")");
	}
}

long MCP(int p[],int n){
	int j,q;
	long M[n+1][n+1];
	int  S[n+1][10000];
	for (int i=1;i<=n;i++) M[i][i] = 0;
	for (int t=2;t<=n;t++){
	   for (int i= 1; i <= n-t+1 ; i++){
			j = i+t-1;
			M[i][j] = LONG_MAX;
			for (int k= i; k <= j-1 ;k++){
				q = M[i][k] + M[k+1][j] + p[i-1]*p[k]*p[j];
				if (q < M[i][j]){
					M[i][j] = q;
					S[i][j] = k;
				}
			}
	   }
	}
	
	/*for(int i=0;i<=n;i++){
		for(int o=0;o<=n;o++){
			if(M[i][o]>=0)cout<<M[i][o]<<"\t";
			else cout<<"n\t";
		}
		cout<<endl;
	}
	cout<<endl;*/
	/*for(int i=0;i<=n;i++){
		for(int o=0;o<=n;o++){
			if(S[i][o]>=0)cout<<S[i][o]<<"\t";
			else cout<<"n\t";
		}
		cout<<endl;
	}*/
	printMCP(S,1,n);
	return M[1][n-1];
}
