#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

int getmax(int arr[],int n)
{
	int max=arr[0];
	for(int i=0;i<n;i++)
	{
		if(arr[i]>max)
		{
			max=arr[i];
		}
	}
	return max;
}

int countsrt(int arr[],int n,int *op)
{
	int max=getmax(arr,n);
	int count[max+1];
	int output[n];
	
	for(int i=0;i<max+1;i++)
	{
		count[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		count[arr[i]]++;
	}
	for(int i=1;i<max+1;i++)
	{
		count[i]+=count[i-1];
		
	}
	for(int i=0;i<n;i++)
	{
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
		
	}
		for(int i=0;i<n;i++)
	{
		arr[i]=output[i];
		
	}

}

int main()
{
	int i,n;
	ofstream fout("countsort.out");
	cout<<"enter the no of ele: ";
	cin>>n;
	
	int arr[n];
	int *op;
	cout<<"eles: ";
	fout<<"eles: ";
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%n;
		fout<<arr[i];
		
	
	}
	
	countsrt(arr,n,op);
	for(int i=0;i<n;i++)
	{
		//arr[i]=rand()%n;
		cout<<arr[i];
		
	
	}
	
}
