//Amir Mohammad Parvizi - Task7
#include <iostream>

using namespace std;
 
const int m = 8; 
//////////////////////////////////////////////////////////////////////////////
void addarr(int (*arr)[m],int n,int *g1,int *g2)
{
	for (int i = 0; i < n; i++)
    	for (int j = 0; j < n; j++)
    		arr[i][j] = 0;
    		
	arr[*g1][*g2] = 1;
}
/////////////////////////////////////////////////////////////////////////////
void showarr(int (*arr)[m],int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
    		cout<<"["<<i<<"] ["<<j<<"]= "<<arr[i][j]<<'\t';
    	cout<<endl<<endl;
	}
}
/////////////////////////////////////////////////////////////////////////////
void move_u(int (*arr)[m],int n,int *g1,int *g2)
{
	int x;
	cout<<"How many moves?"<<endl;
	cin>>x;
	if (x>*g1)
		cout<<"Can not move!!"<<endl<<endl;
	else
	{
		arr[*g1][*g2] = 0;
		*g1-=x;
		arr[*g1][*g2] = 1;
		showarr(arr,n);	
	}
}
////////////////////////////////////////////////////////////////////////////////
void move_d(int (*arr)[m],int n,int *g1,int *g2)
{
	int x;
	cout<<"How many moves?"<<endl;
	cin>>x;
	if (x + *g1 > 7)
		cout<<"Can not move!!"<<endl<<endl;
	else
	{
		arr[*g1][*g2] = 0;
		*g1+=x;
		arr[*g1][*g2] = 1;
		showarr(arr,n);	
	}
}
////////////////////////////////////////////////////////////////////////////////
void move_l(int (*arr)[m],int n,int *g1,int *g2)
{
	int x;
	cout<<"How many moves?"<<endl;
	cin>>x;
	if (x>*g2)
		cout<<"Can not move!!"<<endl<<endl;
	else
	{
		arr[*g1][*g2] = 0;
		*g2-=x;
		arr[*g1][*g2] = 1;
		showarr(arr,n);	
	}
}
////////////////////////////////////////////////////////////////////////////////
void move_r(int (*arr)[m],int n,int *g1,int *g2)
{
	int x;
	cout<<"How many moves?"<<endl;
	cin>>x;
	if (x + *g2 > 7)
		cout<<"Can not move!!"<<endl<<endl;
	else
	{
		arr[*g1][*g2] = 0;
		*g2+=x;
		arr[*g1][*g2] = 1;
		showarr(arr,n);	
	}
}
////////////////////////////////////////////////////////////////////////////////
int main() 
{ 
    int arr[8][8], g1=7 , g2=0; 
    int n = sizeof(arr) / sizeof(arr[0]); 
	char x;
	
	addarr(arr,n,&g1,&g2);
	showarr(arr,n);
	for (;;)
	{
		cout<<"U or D or L or R or UL=i or UR=o or DL=p or DR=k (exit = E)"<<endl;
	    cin>>x;
	    switch(x)
	    {
			case 'U':
			case 'u':
				move_u(arr,n,&g1,&g2);
				break;
		
			case 'D':
			case 'd':
				move_d(arr,n,&g1,&g2);
				break;
		
		    case 'L':
			case 'l':
				move_l(arr,n,&g1,&g2);
				break;
				
			case 'R':
			case 'r':
				move_r(arr,n,&g1,&g2);
				break;
				
			case 'O':
			case 'o':
				//move_ur();
				break;
		
			case 'i':
			case 'I':
				//move_ul();
				break;
		
		    case 'K':
			case 'k':
				//move_dr();
				break;
				
			case 'p':
			case 'P':
				//move_dl();
				break;

			case 'E':
			case 'e':
				exit(0);
				break;
		
			default:
				cout<<endl<<"U or D or L or R or UL=i or UR=o or DL=p or DR=k (exit = E)"<<endl<<endl;
				break;
	   }
	}
     
}
