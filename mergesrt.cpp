
#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;


long int count=0;

void merge(int a[],int p,int q,int r)
{
	int n1,n2;
	n1=q-p+1;
	n2=r-q;
	int l[n1+1];
	int R[n2+1];
	int i,j;
	for(i=0;i<n1;i++)
	{
		l[i]=a[p+i-1];
		
	}
	for(j=0;j<n2;j++)
	{
		R[j]=a[q+j];
	}
	l[n1+1]=-99999;
	R[n2+1]=-99999;
	i=0;
	j=0;
	
	for(int k=p;k<r;k++)
	{
		count++;
		if(l[i]<=R[j])
		{
			a[k]=l[i];
			i++;
		}
		else
		{
			a[k]=R[j];
			j++;
		}
	}
	
}


void mergesort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
	}
	mergesort(a,p,q);
	mergesort(a,q+1,r);
	merge(a,p,q,r);
}

int main()
{
	int n;
    ofstream my_out("mergesort.out");  //Generates the output file
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
    mergesort(arr, 1, n+1);
   
   
    cout << "Sorted array is : \n";
    my_out << "Sorted array is : " << endl;
   
    for(int arr_i = 0; arr_i < n; arr_i++ )
    {
        cout << arr[arr_i]<< "\t" << endl;
        my_out << arr[arr_i] << "\t" << endl;  
    }
    return 0;
}



/*void merge(int arr[],int p,int q,int r)
{
	int n1;
	int n2;
	n1=q-p+1;
	n2=r-p;
	
	int l[n1+1];
	int R[n2+1];
	
	for(int i=0;i<n1;i++)
	{
		l[i]=arr[p+i];
	}
	for(int j=0;j<n2;j++)
	{
		R[j]=arr[q+j+1];
	}
//	l[n1+1]=99999;
	//R[n2+1]=99999;
	
	int i=0;
	int j=0;
	int k=p;
	
	while(i<n1 && j<n2)
	{
		if(l[i]<R[j])
		{
			arr[k]=l[i];
			k++;
			i++;
			
		}
		else
		{
			arr[k]=arr[j];
			k++;
			j++;
		}
	}
	
	while(i<n1)
	{
		arr[k]=l[i];
			k++;
			i++;
			
		
	}
	while(j<n2)
	{
		arr[k]=R[j];
			k++;
			j++;
	}
}
void mergesort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
	}
	mergesort(a,p,q);
	mergesort(a,q+1,r);
	merge(a,p,q,r);
}

int main()
{
	

	int n;
    ofstream my_out("mergesort.out");  //Generates the output file
    cout<<"Enter the no. of elements : \n";
    my_out << "Enter the no. of elements : " << endl;
   
    cin >> n;
    my_out << n << endl;
     
    int arr[n];
   
    for(int arr_i = 0; arr_i < n; arr_i++ )
    {
    arr[arr_i]=rand()%n;
        my_out << arr[arr_i] << endl; 
		cout<<arr[arr_i]<<" "; 
    }
   
    mergesort(arr, 0, n);
   
    cout << "Sorted array is : \n";
    my_out << "Sorted array is : " << endl;
   
    for(int arr_i = 0; arr_i < n; arr_i++ )
    {
        cout << arr[arr_i]<< "\t" << endl;
        my_out << arr[arr_i] << "\t" << endl;  
    }
    return 0;
	
}*/
