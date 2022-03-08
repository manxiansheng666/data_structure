#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void print_array(int array[],int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\r\n");
}

void swap(int* a, int* b)
{
	int buf = *a;
	*a = *b;
	*b = buf;
}


void insert_sort(int array[],int num)
{
	for (int i = 1; i < num; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (array[j - 1] > array[j])
			{
				swap(&array[j  -1],&array[j]);
			}
		}
	}
}

int binary_search(int array[],int low,int high,int key)
{
	int ret = -1;
	if (low >= high)
		return ret;
	int middle = (low + high) / 2;
	if (array[middle] == key)
		ret = middle;
	else if (key < array[middle])
		ret = binary_search(array, low, middle - 1, key);
	else
		ret = binary_search(array, middle + 1, high, key);
	return ret;
}

int binary_search_ex(int array[], int low, int high, int key)
{
	int ret = -1;
	int middle;
	while (low <= high)
	{
		middle = (low + high) / 2;
		if (array[middle] == key)
		{
			ret = middle;
			break;
		}
		else if (key < array[middle])
		{
			high = middle - 1;
		}
		else
		{
			low = middle + 1;
		}
	}
	return ret;
}




int main()
{
	int array[SIZE];
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++)
	{
		array[i] = rand() % 100;
	}
	printf("before sort:\r\n");
	print_array(array,SIZE);
	insert_sort(array,SIZE);
	printf("after sort:\r\n");
	print_array(array, SIZE);
#define KEY 1
	int ret = binary_search_ex(array, 0, SIZE - 1, KEY);
	if (ret != -1)
	{
		printf("find key %d succeed,it is at address%d\r\n",KEY,ret);
	}
	else
	{
		printf("find key is failed!\r\n");
	}
	return 0;
}