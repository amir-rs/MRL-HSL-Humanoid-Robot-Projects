#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
 
const int m = 100;
/////////////////////////////////////////////////////////////////////
void findElement2(int (*arr)[m], int n,int key) 
{
	int i , j , position = -1;
	
	cout<<"[i][j] i=?"<<endl;
	cin>>i;
	//if (i==1234)
	//	break;
	cout<<"[i][j] j=?"<<endl;
	cin>>j;
	if (arr[i][j] == key)
	{
		position = 1;
		//break;
		cout << "Element Found at Position: ["<<i<<"] ["<<j<<"]" ; 
	}
	if (position == - 1) 
        cout << "Element not found";  
} 
///////////////////////////////////////////////////////////////////
void findElement1(int (*arr)[m], int n,int key) 
{ 
    int i , j , position = -1;
    for (i = 0; i < n; i++)
    {
    	for (j = 0; j < n; j++) 
        	if (arr[i][j] == key)
			{
				position = 1;
				break;
			}
		if (arr[i][j] == key)
			break;	 	
	}
    	
            	
	if (position == - 1) 
        cout << "Element not found"; 
    else
        cout << "Element Found at Position: ["<<i<<"] ["<<j<<"]" ;  
} 
//////////////////////////////////////////////////////////////////////////////
void addarr(int (*arr)[m],int n)
{
	int g1 , g2;
	for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		arr[i][j] = 0;
    		
    srand(time(0));
    g1=rand() % 100;
    g2=rand() % 100;
    cout<<g1<<endl<<g2<<endl;
	arr[g1][g2] = 1;
}
/////////////////////////////////////////////////////////////////////////////
int main() 
{ 
    int arr[100][100],x,key; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    key = 1;
	
	addarr(arr,n);
    cout<<"1 or 2"<<endl;
    cin>>x;
    
	if (x==1)
    	findElement1(arr, n, key);
    else if (x==2)
    	findElement2(arr, n, key);
 
     
 
}
