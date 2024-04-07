#include<iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
//...........................................................
void merge(int a[],int low,int mid, int hight)
{
	int i,j,k;
	int n1 = mid - low +1;
	int n2 = hight - mid;
	
	int L[n1],R[n2];
	
	for(i=0 ; i<n1 ; i++)
		L[i]= a[low+i];
	
	for (j=0 ; j<n2 ; j++)
		R[j]= a[mid +1+j];
		
	i=0;
	j=0;
	k=low;
	
	while ( i<n1 && j<n2)
	{
		if (L[i]<=R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k]= R[j];
			j++;
		}
		k++;
	}
	
	while ( i<n1)
	{
		a[k]= L[i];
		i++;
		k++;
	}
	
	while ( i<n2 )
	{
		a[k] = R[j];
		j++;
		k++;
	}
}
//...........................................................
void mergesort(int a[], int low, int hight)
{
	int mid;
	if (low < hight)
	{
		mid = ( low+hight)/2;
		mergesort(a , low , mid);
		mergesort(a , mid + 1 , hight);
		merge(a , low ,mid, hight);
	}
}
//...........................................................
void selectionSort(int a[], int n) 
{  
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) 
	{   
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		temp = a[i];
    	a[i] = a[min];
    	a[min] = temp;
   }
}
//......................................................................

int main() {
   int a[20];
   int n = sizeof(a)/ sizeof(a[0]);
   int max = 100, min = 0,x;
   srand(time(0));
   for(int i=0 ; i<20 ; i++)
    	a[i]=(rand()%(max-min))+min;
	
   cout<<"Your array is:"<<endl;
   for (int i = 0; i < n; i++)  
		cout<< a[i] <<" ";
	cout<<endl<<endl<<"1(selectionSort) or 2(mergesort)"<<endl;
	cin>>x;
	
	if(x==1)
		selectionSort(a, n);
	else if(x==2)
		mergesort(a,0,n-1);
	
	
	printf("\nYour array after sorting: \n");
	
	for (int i = 0; i < n; i++)
		cout<< a[i] <<" ";
	return 0;
}
