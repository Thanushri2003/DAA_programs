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

int countsort(int arr[],int n,int place)
{
	
	int count[n];
	int output[n+1];
	
	for(int i=0;i<n;i++)
	{
		count[i]=0;
	}
	
	for(int i=0;i<n;i++)
	{
		count[(arr[i]/place)%n]++;
	}
	for(int i=0;i<n;i++)
	{
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		output[count[(arr[i]/place)%n]-1]=arr[i];
		count[(arr[i]/place)%n]--;
	}
	
	for(int i=0;i<n;i++)
	{
		arr[i]=output[i];
	}
}

void radixsort(int arr[],int n)
{
	int max=getmax(arr,n);
	for(int place=1;max/place>0;place*=n)
	countsort(arr,n,place);
}
int main()
{
	int i,n;

	fstream fout("radixsort.out");
	cout<<"enter no the ele:"<<endl;
	cin>>n;
	
	int arr[n];
	fout<<"elements:"<<endl;
	for(int i=0;i<n;i++)
	{
		arr[i]=rand()%n;
		fout<<arr[i];
	}
	
	radixsort(arr,n);
	cout<<"after sorting:"<<endl;
	for(int i=0;i<n;i++)
	{
		
		cout<<arr[i];
	}
	
}
