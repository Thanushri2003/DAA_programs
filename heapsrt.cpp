#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void exchange(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void maxheapify(int arr[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && arr[l]>arr[largest])
	{
		largest=l;
	}
	if(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		exchange(&arr[i],&arr[largest]);
		maxheapify(arr,n,largest);
	}
}

void buildmaxheap(int arr[],int n)
{
	for(int i=((n/2)-1);i>=0;i--)
	{
		maxheapify(arr,n,i);
	}
}

void heapsort(int arr[],int n)
{
	buildmaxheap(arr,n);
	for(int i=n-1;i>=0;i--)
    {
    	exchange(&arr[0],&arr[i]);
    	maxheapify(arr,i,0);
    	
    }
}
int main()
{

int n;
	ofstream fout("heapsort.out");
	
	cout<<"enter the no of ele:";
	fout<<"enter the no of ele:";
	
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
	
	heapsort(arr,n);
	cout<<"after sorting:\n";
		for(int i=0;i<n;i++)
	{
		
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
