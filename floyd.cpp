#include <iostream>
using namespace std;

// defining the number of vertices
#define nV 4

void printMatrix(int matrix[][nV]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][nV]) 
{
  int matrix[nV][nV], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) 
  {
    for (i = 0; i < nV; i++) 
	{
      for (j = 0; j < nV; j++) 
	  {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][nV]) 
{
  for (int i = 0; i < nV; i++) 
  {
    for (int j = 0; j < nV; j++)
	 {
      if (matrix[i][j] == 999)
        cout<<"INF";
      else
        cout<<" "<<matrix[i][j];
    }
    printf("\n");
  }
}

int main() {
  int graph[nV][nV];
  int value;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
		cout<<"Enter element at ["<<i+1<<","<<j+1<<"] ?";
		cin>>value;
		graph[i][j]=value;
		}
	}
  floydWarshall(graph);
}


