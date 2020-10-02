#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define ARRAY_SIZE 10000
//quicksort, divide and conquor... conquer? conker
//hoare
int swapCount = 0;
int compCount = 0;


void swap(int myArray[], int a, int b)
{
	int temp = myArray[a];
	myArray[a] = myArray[b];
	myArray[b] = temp;
	swapCount++;

}

void printSwaps(char name[])
{
	printf("\nTEST: %s", name);
	

	printf("\nnumber of swaps: %i\nnumber of comps: %i\n\n",swapCount, compCount);
	

}

int partition(int myArray[], int start, int end)
{
	int i, j;
	int pivot = myArray[end];
	
	i = start - 1;//
	j = end ;
	
	for(;;)
	{
		do
		{
			i++;
			compCount++;
			if(i == end)
				break;
		}while(myArray[i] < pivot);
		
		do
		{
			j--;
			compCount++;
			if(j==start)
				break;
			
		}while(myArray[j] > pivot);
		
		if( i >= j)
		{
			compCount++;
			swap(myArray, i, j);
			return j;
		}
		
	}
		
	swap(myArray, i, j);
	
}

void quicksort(int*A, int low, int high)
{
	int q;
	
	if( low < high)
	{
		q = partition(A, low, high);
		quicksort(A, low, q-1);
		quicksort(A, q+1, high);
	}
}

void sortUniqueArray()
{
	srand( (unsigned)time( NULL ) );
	int i, j, random, isUnique;
	int uniqueArray[ARRAY_SIZE];
	char name[] = "Unique Array";
	
	for(i = 0; i < ARRAY_SIZE; i++) 
	{
     do 
	 {
        //assuming uniqueness
        isUnique = 1;
        random = rand() % 100000;
        //check for uniqueness
        for (j = 0; j < i && isUnique == 1; j++) 
		{
           if (uniqueArray[j] == random) 
		   {
              isUnique = 0;
           }
        }
     } while (isUnique != 1);
     uniqueArray[i] = random;
	}
	
	quicksort(uniqueArray,0,ARRAY_SIZE - 1);
	printSwaps(name);
	swapCount = 0;//reset for next one
	compCount = 0;
	
		// for(i = 0; i < 10; i++)
	// {
		// printf("%i ", uniqueArray[i]);
	// }

}
void sortRandArray()
{
	srand( (unsigned)time( NULL ) );
	int i;
	int randomArray[ARRAY_SIZE];
	char name[] = "Random Array";

	  for(i = 0; i<ARRAY_SIZE; i++)
	  {
		randomArray[i] = rand() % 100000;
	  }

	
	quicksort(randomArray,0,ARRAY_SIZE - 1);
	printSwaps(name);
	swapCount = 0;//reset for next one
	compCount = 0;
	

	// for(i = 0; i < 10; i++)
	// {
		// printf("%i ", randomArray[i]);
	// }

}

void sortUniArray()
{
	int i;
	int uniformArray[ARRAY_SIZE];
	char name[] = "Uniform Array";


	  for(i = 0; i<ARRAY_SIZE; i++)
	  {
		uniformArray[i] = 7;
	  }

	
	quicksort(uniformArray,0,ARRAY_SIZE - 1);
	printSwaps(name);
	swapCount = 0;//reset for next one
	compCount = 0;
	
		// for(i = 0; i < 10; i++)
	// {
		// printf("%i ", uniformArray[i]);
	// }
	
}

void sortSortedArray()
{
	int i;
	int sortedArray[ARRAY_SIZE];
	char name[] = "Sorted Array";


	  for(i = 0; i<ARRAY_SIZE; i++)
	  {
		sortedArray[i] = i;
	  }

	
	quicksort(sortedArray,0,ARRAY_SIZE - 1);
	printSwaps(name);
	swapCount = 0;//reset for next one
	compCount = 0;
	
	
		// for(i = 0; i < 10; i++)
	// {
		// printf("%i ", sortedArray[i]);
	// }
	
}

void sortDescendingArray()
{
	int i;
	int descArray[ARRAY_SIZE];
	char name[] = "Descending Array";


	  for(i = ARRAY_SIZE; i > 0; i--)
	  {
		descArray[i] = i ;
	  }

	
	quicksort(descArray,0,ARRAY_SIZE - 1);
	printSwaps(name);
	swapCount = 0;//reset for next one
	compCount = 0;
	
	// for(i = 0; i < 10; i++)
	// {
		// printf("%i ", descArray[i]);
	// }
	

}


int main()
{	
	sortUniqueArray();
	sortRandArray();
	sortUniArray();
	sortSortedArray();
	sortDescendingArray();
}