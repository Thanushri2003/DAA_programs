///ouick sort

#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

void exchange(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int arr[],int low,int high)
{
	int pivot;
	pivot=arr[high];
	int i=low-1;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			i=i+1;
			exchange(&arr[i],&arr[j]);
			
		}
		
	}
	if(arr[high]<arr[i+1])
	{
		exchange(&arr[i+1],&arr[high]);
	}
	return i+1;
	
}

void quicksort(int arr[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=partition(arr,low,high);
		quicksort(arr,low,mid-1);
		quicksort(arr,mid+1,high);
	}
}

int main()
{
	int n;
	
    ofstream my_out("QuickSort.out");  //Generates the output file
    cout<<"Enter the no. of elements : \n";
    my_out << "Enter the no. of elements : " << endl;
   
    cin >> n;
    my_out << n << endl;
     int arr[n];
    
   
    for(int arr_i = 0; arr_i < n; arr_i++ )
    {
    arr[arr_i]=rand()%n;
        my_out << arr[arr_i] << endl;  
    }
   
    quicksort(arr, 0, n-1);
   
    cout << "Sorted array is : \n";
    my_out << "Sorted array is : " << endl;
   
    for(int arr_i = 0; arr_i < n; arr_i++ )
    {
        cout << arr[arr_i]<< "\t" << endl;
        my_out << arr[arr_i] << "\t" << endl;  
    }
    return 0;
	
	/*int i,n,arr[10];
	cout<<"enter the no elements:";
	cin>>n;
	cout<<"enter the elements:";
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		
    } 
	quicksort(arr,0,n);
	cout<<"after sorting\n";
	
	for(i=0;i<n;i++)
	{
		cout<<arr[i];
		
    }*/
	
	
}
