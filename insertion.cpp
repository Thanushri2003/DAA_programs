#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void insertionsrt(int arr[],int n)
{
	int i,key;
	for(int j=1;j<n;j++)
	{
		
		key=arr[j];
		i=j-1;
		while(i>=0 && arr[i]>key)
		{
			arr[i+1]=arr[i];
			i=i-1;
			
		}
		arr[i+1]=key;
	}
	
	
}

int main()
{
	
	int n;
	ofstream fout("insertsort.out");
	
	cout<<"enter the no of ele:";
	//fout<<"enter the no of ele:";
	
	cin>>n;
	fout<<"no of ele:"<<n;
	int arr[n];
	
	cout<<"before sorting:\n";
	for(int i=0;i<n;i++)
	{
		
		arr[i]=rand()%n;
		cout<<endl;
		cout<<arr[i]<<" ";
		cout<<endl;
		fout<<arr[i]<<" ";
	}
	
	insertionsrt(arr,n);
	cout<<"after sorting:\n";
		for(int i=0;i<n;i++)
	{
		
		cout<<arr[i]<<" ";
	}
	
	return 0;

	
	
	
}
