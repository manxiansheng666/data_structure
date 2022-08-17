#include <stdio.h>
#include <string.h>

void swap(int *a,int *b)
{
	int buf = *a;
	*a = *b;
	*b = buf;
}


//√∞≈›≈≈–Ú
void buble_sorting(int *array,int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
				swap(array+j,array+j + 1);
		}

	}
}

//≤Â»Î≈≈–Ú
void insert_sorting(int *array,int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j > 0; j--)
		{
			if (array[j - 1] > array[j])
				swap(array + j - 1, array + j);
			else
				break;
		}
	}
}

int find_meddle(int* array, int i, int j)
{
	int buf = array[i];
	while (i < j)
	{
		while (buf <= array[j] && i < j)
			j--;
		swap(array+i,array+j);
		while (buf >= array[i] && i < j)
			i++;
		swap(array + i, array + j);
	}
	return i;
}

void recursion_quick_sorting(int* array, int i, int j)
{
	if (i >= j)return;
	int meddle = find_meddle(array,i,j);
	recursion_quick_sorting(array,i,meddle);
	recursion_quick_sorting(array,meddle+1,j);
}


void quick_sortint(int* array, int num)
{
	recursion_quick_sorting(array,0, num - 1);
}

//—°‘Ò≈≈–Ú
void select_sorting(int *array,int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (array[j] < array[i])
				swap(array+j,array+i);
		}
	}
}

//œ£∂˚≈≈–Ú
void shell_sroting(vector<int>& array)
{
	int gap = len;
    do
    {
        gap = gap / 3 + 1;
        for (int i = 0; i < len - gap; i++)
        {
            for (int j = i + gap; j > gap - 1; j -= gap)
            {
                if (array[j] > array[j - gap])
                    swap(array + j, array + j - gap);
                else
                    break;
            }
        }
    } while (gap > 1);
}


//πÈ≤¢≈≈–Ú
void merge_two_array(int* array,int i,int meddle,int j)
{
	int len = j - i + 1;
	int* array_buf = (int*)malloc(sizeof(int) * len);
	int dst = 0;
	int x = i;
	int y = meddle + 1;
	while (x <= meddle && y <= j)
	{
		if (array[x] < array[y])
		{
			array_buf[dst++] = array[x++];
		}
		else
			array_buf[dst++] = array[y++];
	}
	while (x <= meddle)
	{
		array_buf[dst++] = array[x++];
	}
	while (y <= j)
	{
		array_buf[dst++] = array[y++];
	}
	memcpy(array + i,array_buf,sizeof(int) * len);
	free(array_buf);
}

void recursion_merge_sorting(int* array, int i, int j)
{
	if (i >= j)return;
	int meddle = (i + j) / 2;
	recursion_merge_sorting(array,i,meddle);
	recursion_merge_sorting(array,meddle+1,j);
	merge_two_array(array,i,meddle,j);
		

}


void merge_sorting(int *array,int num)
{
	recursion_merge_sorting(array,0,num-1);
}

void array_print(int* array, int num)
{
	for (int i = 0;i< num;i++)
	{
		printf("%d ",array[i]);
	}
}

int main()
{
	int array[] = {4,8,-3,6,2,9,0,5,7,1,2,3};
	int num = sizeof(array) / sizeof(int);

	merge_sorting(array,num);
	array_print(array,num);
	return 0;
}


