#include <bits/stdc++.h>
using namespace std;

struct Point{
	int x;
	int y;
};

int compareX(const void* a, const void* b){
	Point *p1=(Point *)a;
	Point *p2=(Point *)b;
	return(p1->x - p2->x);
}

int compareY(const void* a, const void* b){
	Point *p1=(Point *)a;
	Point *p2=(Point *)b;
	return (p1->y - p2->y);
}

float distancia(Point p1, Point p2){
	return sqrt(((p1.x - p2.x)*(p1.x - p2.x))+(
				(p1.y - p2.y)*(p1.y - p2.y)));
}

float min(float x, float y){
	return (x < y)?x:y;
}

float closestSplitPair(Point P[],int fin, float d){
	int medioX= P[fin/2].x;
	Point *Sy;
	Sy=&P[0];
	int k=0;
	for(int i=0;i<fin;i++){
		if(abs(P[i].x - medioX) < d){
			Sy[k]=P[i];
			k++;
		}
	}
	qsort(Sy,k,sizeof(Point),compareY);
	float menorD= d;
	for(int j=0;j < k;j++)
		for(int l= j+1;l < k&& (Sy[l].y - Sy[j].y) < menorD;l++)
			if(distancia(Sy[j], Sy[l]) < menorD)
				menorD= distancia(Sy[j], Sy[l]);
	return menorD;
}
float BruteForce(Point P[],int n){
   float minD = FLT_MAX;
   for (int i = 0; i < n; ++i)
   		for (int j = i+1; j < n; ++j)
   			if (distancia(P[i], P[j]) < minD)
				minD = distancia(P[i], P[j]);	
   return minD;
}
float closestPair(Point P[],int fin){
	if (fin<=3) return BruteForce(P,fin);
	int medio= fin/2;
	float ld= closestPair(P, medio);
	float rd= closestPair(P+medio,fin-medio);
	float delta= min(ld,rd);
	return min(delta,closestSplitPair(P,fin,delta));
}
float closest(Point P[],int end){
	qsort(P,end,sizeof(Point),compareX);
	return closestPair(P,end);
}
