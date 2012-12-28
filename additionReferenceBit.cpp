#include<iostream>
#include<math.h>
int replace(int sum[],int n)
{
	int least,j;
	least=sum[0],j=0;
	for(int i=1;i<n;i++)
	{
		if(sum[i]<least){
			least=sum[i];
			j=i; 		}
	}
	return j;
}
using namespace std;
main()
{
	int i,pages,sum1,j;
	cout<<"Enter the number of pages\n";
	cin>>pages;
	if(pages>100)
	{
		cout<<"The maximum no of pages is 100\n";
		return 0;
	}
	cout<<"No Of Reference bits used is 8\n";
	int matrix[100][8];
	int sum[100];
	//int *matrix,*sum;
	//matrix=new int[pages][8];
	//sum=new int[pages];
	for(i=0;i<pages;i++)
	{
		for(j=7;j>=0;j--)
		{
			input: cout<<"Is the "<<i+1<<"page used during"<<8-j<<" time?(1=used 0=not used)\n";
			cin>>matrix[i][j];
			if(matrix[i][j]>1)
			{
				cout<<"Enter value 1 or 0\n";
				goto input;
			}

		}
	}
	for(i=0;i<pages;i++)
	{
		sum1=0;
		for(j=0;j<8;j++)
		{
			sum1=sum1+(pow(10,j)*matrix[i][j]);
		}
		sum[i]=sum1;
	}
	cout<<"The Reference Bits for all pages are shown below:\n";
	for(i=0;i<pages;i++)
		cout<<sum[i]<<" ";
	int x= replace(sum,pages);
	cout<<endl<<" Page "<<x+1<<"is removed\n";


}
