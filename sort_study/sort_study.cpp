#include <iostream>

using namespace std;

//冒泡排序
void bubble_sorting(int array[],int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int buf = array[j];
				array[j] = array[j + 1];
				array[j + 1] = buf;
			}
		}
	}
}

//选择排序
void select_sorting(int array[], int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (array[i] > array[j])
			{
				int buf = array[j];
				array[j] = array[i];
				array[i] = buf;
			}
		}
	}
}

//插入排序
void insert_sorting(int array[], int num)
{
	for (int i = 1; i < num; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (array[j - 1] > array[j])
			{
				int buf = array[j - 1];
				array[j - 1] = array[j];
				array[j] = buf;
			}
			else
				break;
		}
	}
}

void display_array(int array[], int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
}

//希尔排序
void shell_sorting(int array[], int num)
{
	for (int gap = 3; gap > 0; gap--)
	{
		for (int i = gap; i < num; i += gap)
		{
			for (int j = i; j > 0; j -= gap)
			{
				if (array[j - gap] > array[j])
				{
					int buf = array[j - gap];
					array[j - gap] = array[j];
					array[j] = buf;
				}
			}
		}

	}
}

void swap(int array[], int i, int j)
{
	int temp = array[i];

	array[i] = array[j];

	array[j] = temp;
}

int find_middle(int array[], int i, int j)
{
	int buf = array[i];
	while (i < j)//结束条件
	{
		while (buf <= array[j] && i < j)//不能少了 等于 的条件
		{
			j--;
		}
		swap(array,i,j);
		while (array[i] <= buf && i < j)
		{
			i++;
		}
		swap(array, i, j);
	}
	return i;
}


//快速排序
void quick_sorting(int array[],int i,int j)//递归调用自己一定要有不再调用自己的条件
{
	if (i >= j)return;
	int middle = find_middle(array, i, j);
	quick_sorting(array, i, middle - 1);
	quick_sorting(array, middle + 1, j);
}

void myprintf(int array[], int low, int high)
{
	int num = high - low + 1;
	for (int i = low; i < num; i++)
	{
		cout << array[i] << ' ';
	}
	cout << "---" <<endl;
}

void merge_array(int array[], int low, int high)
{
	int meddle = (low + high) / 2;
	int num = high - low + 1;
	int i = low;
	int j = meddle + 1;
	int k = 0;
	int* array_buf = NULL;
	array_buf = new int[num];
	while (i <= meddle && j <= high)
	{
		if (array[i] < array[j])
		{
			array_buf[k++] = array[i++];
		}
		else
		{
			array_buf[k++] = array[j++];
		}
	}
	while (i <= meddle)
	{
		array_buf[k++] = array[i++];
	}
	while (j <= high)
	{
		array_buf[k++] = array[j++];
	}
	memcpy(array+low, array_buf, num * sizeof(int));
	delete  [] array_buf;
}



//归并排序
void merge_sorting(int array[], int low,int high)
{
	if (low == high)
		return;
	int meddle = (low + high) / 2;
	merge_sorting(array,low,meddle);
	merge_sorting(array, meddle + 1, high);
	merge_array(array,low,high);
}


int main()
{
	int array[] = {5,2,-1,0,2,5,-7,-1,3,5};
	int num = sizeof(array) / sizeof(*array);
	cout << "before sort:" << endl;
	display_array(array, num);
	merge_sorting(array,0,num-1);
	cout << "after sort:" << endl;
	display_array(array, num);
}
