#include<bits/stdc++.h>
using namespace std;

int knapsack(int c[],int p[],int n,int R){
   int A[n+1][R+1];
   for (int j=0;j<=R;j++) A[0][j] = 0;
   for (int i=0;i<=n;i++) A[i][0] = 0; 
   for (int i=1; i<=n;i++){
       for (int j= 0;j<=R;j++){
            if (c[i] <= j)
                A[i][j] = max(p[i] + A[i-1][j-c[i]], A[i-1][j]);
           else 
                A[i][j] = A[i-1][j];
       }
   }
   return A[n][R];
}
