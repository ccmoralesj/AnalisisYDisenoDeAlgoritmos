



// Calse Vector y con posiciones de memoria (ver más abajo este código)

vector<int> merge(vector<int>X1,vector<int> X2,int m){
   int i=0, j=0, k=0;
   bool paso=false;
   vector<int> Z;
   while (k< m) {
		if (i >= m/2){
		  	Z.push_back(X2[j]);
			j++;
		}else if (j >= ((m%2==0)?m/2:(m/2)+1)){
		  	Z.push_back(X1[i]);
		 	i++;
		}else if (X1[i] < X2[j]){
		  	Z.push_back(X1[i]);
		 	i++;
		}else{
		  	Z.push_back(X2[j]);
		 	j++;
		}	
   		k++;
   }
   return Z;
}
vector<int> divideAndMerge(vector<int> X,int m){
   if (m > 1){
		if(m % 2 == 0){
	   		vector<int> X1(X.begin(),X.end()-(X.size()/2));
	   		vector<int> X2(X.begin()+(X.size()/2),X.end());
	    	return merge(divideAndMerge(X1, m/2), divideAndMerge(X2, m/2), m);
	   	}else{
	   		vector<int> X1(X.begin(),X.begin()+(X.size()/2));
	   		vector<int> X2(X.begin()+(X.size()/2),X.end());
	    	return merge(divideAndMerge(X1, m/2), divideAndMerge(X2,(m/2)+1), m);
	   	}
   }else return X;
}
vector<int> mergeSort(vector<int> X,int n){
   return divideAndMerge(X, n);
}

// Con posiciones de memoria y con CONTADOR DE INVERSIONES!!!!
#include <bits/stdc++.h>
using namespace std;

long long inversion=0; //variable para contar las inversiones del arreglo
long order[100001];
long auxorder[100001];

void merge(int inii,int mitad,int finj){
   int i=inii, j= mitad + 1, k=0;
   int funcionaYAAA= finj - inii + 1;
   while (k < funcionaYAAA) {
		if (j > finj){
		  	auxorder[k]=order[i];
		 	i++;
		}else if (i > mitad){
		  	auxorder[k]=order[j];
			j++;
		}else if (order[j] < order[i]){
		  	auxorder[k]=order[j];
		  	inversion+= mitad - i + 1;
		 	j++;
		}else{
		  	auxorder[k]=order[i];
		 	i++;
		}
   		k++;
   }
   for(int f=0; f<funcionaYAAA;order[inii++]=auxorder[f++]);
}
void divideAndMerge(int ini,int fin){
   if (ini<fin){
   		int medio= (ini + fin)/2;
	    divideAndMerge(ini, medio);
	    divideAndMerge(medio+1,fin);
	    merge(ini,medio,fin);
   }else return;
}
void mergeSort(int begin,int end){
   divideAndMerge(begin,end-1);
}
