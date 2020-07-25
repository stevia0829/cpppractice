#include<iostream>
#include<algorithm>
#include<time.h>
#include <stdlib.h>
using namespace std;


//交换
void swap(int &a, int&b) {
	int t = a;
	a = b;
	b = t;
	return;
}


// 选择排序
void Selectsort(int *h,int N)
{
	if (h == NULL) return;
	for (int i = 0; i < N-1; i++) {
		int minindex = i;
		for (int j = i + 1; j < N; j++) {
			if (h[j] < h[minindex]) minindex=j;
		}
		swap(h[i], h[minindex]);
	}
}

//插入排序
void InsertSort(int *h,int N) {
	if (h == NULL) return;
	for (int i = 1; i < N ; i++) {
		for (int j = i ; j >0; j--) {
			if (h[j] < h[j-1]) swap(h[j], h[j-1]);
		}
	}
	return;
}
//冒泡排序
void bubblesort(int *h, int N) {
	if (h == NULL) return;
	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			if (h[i] > h[j])swap(h[i], h[j]);
		}
	}
}
//希尔排序
void healsort(int *h, int N) {
	if (h == NULL) return;
	for (int div = N / 2; div >= 1; div /= 2) {
		for (int k = 0; k < div; k++) {
			for (int i = div+k; i<N; i+=div) {
				for (int j = i; j > k;j-=div) {
					if (h[j] < h[j - div])swap(h[j], h[j - div]);
				}
			}
		}
	}
}
//快速排序
//快速排序，随机选取哨兵放前面
void Quicksort(int* h, int left, int right)
{
	if (h == NULL) return;
	if (left >= right) return;

	//防止有序队列导致快速排序效率降低
	srand((unsigned)time(NULL));
	int len = right - left;
	int kindex = rand() % (len + 1) + left;
	swap(h[left], h[kindex]);

	int key = h[left], i = left, j = right;
	while (i < j)
	{
		while (h[j] >= key && i < j) --j;
		if (i < j) h[i] = h[j];
		while (h[i] < key && i < j) ++i;
		if (i < j) h[j] = h[i];
	}

	h[i] = key;

	//QuickSort(&h[left],0,i-1);
	//QuickSort(&h[j+1],0,right-j-1);

	Quicksort(h, left, i - 1);
	Quicksort(h, j + 1, right);
}

//归并排序
//归并排序
void  MergeArray(int* arr, size_t left, size_t mid, size_t right, int* temp)
{
	if (arr == NULL) return;

	size_t i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
			continue;
		}

		temp[k++] = arr[j++];
	}

	while (i <= mid)
		temp[k++] = arr[i++];

	while (j <= right)
		temp[k++] = arr[j++];

	memcpy(&arr[left], temp, k * sizeof(int));

	return;
}

void MMergeSort(int* arr, size_t left, size_t right, int* temp)
{
	if (left < right)
	{
		size_t mid = (left + right) / 2;
		MMergeSort(arr, left, mid, temp);
		MMergeSort(arr, mid + 1, right, temp);
		MergeArray(arr, left, mid, right, temp);
	}
}

void MergeSort(int* h, size_t len)
{
	if (h == NULL) return;
	if (len <= 1) return;
	int* temp = (int*)calloc(len, sizeof(int));
	MMergeSort(h, 0, len - 1, temp);

	memcpy(h, temp, sizeof(int)*len);

	free(temp);

	return;
}


//堆排序
/*
大顶堆sort之后，数组为从小到大排序
*/
//====调整=====
void AdjustHeap(int* h, int node, int len)  //----node为需要调整的结点编号，从0开始编号;len为堆长度
{
	int index = node;
	int child = 2 * index + 1; //左孩子，第一个节点编号为0
	while (child < len)
	{
		//右子树
		if (child + 1 < len && h[child] < h[child + 1])
		{
			child++;
		}
		if (h[index] >= h[child]) break;
		swap(h[index], h[child]);
		index = child;
		child = 2 * index + 1;
	}
}


//====建堆=====
void MakeHeap(int* h, int len)
{
	for (int i = len / 2; i >= 0; --i)
	{
		AdjustHeap(h, i, len);
	}
}

//====排序=====
void HeapSort(int* h, int len)
{
	MakeHeap(h, len);
	for (int i = len - 1; i >= 0; --i)
	{
		swap(h[i], h[0]);
		AdjustHeap(h, 0, i);
	}
}

/*
LSD排序
*/

int GetMaxDight(int* h, int len)
{
	if (h == NULL) return 0;
	if (len < 1) return 0;

	int max = h[0];
	for (int i = 1; i < len; ++i)
	{
		if (h[i] > max) max = h[i];
	}

	int digit = 1;
	while (max / 10 != 0)
	{
		max /= 10;
		++digit;
	}

	return digit;
}

int GetReminder(int value, int digit)
{
	int div = 1;
	for (int i = 1; i < digit; ++i)
		div *= 10;

	return value / div % 10;
}

void RadixSort_LSD(int* h, int len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int digit = GetMaxDight(h, len);
	//printf("MaxDigit:%d\n", digit);

	int count[10] = { 0 };
	int *tmp = (int*)calloc(len, sizeof(int));

	for (int d = 1; d <= digit; ++d)
	{
		memset(count, 0, sizeof(count));

		for (int i = 0; i < len; ++i)
		{
			count[GetReminder(h[i], d)]++;
		}

		//求右边界
		for (int i = 1; i < 10; ++i)
		{
			count[i] += count[i - 1];
		}

		for (int i = len - 1; i >= 0; --i)
		{
			int r = GetReminder(h[i], d);
			int index = count[r];
			tmp[index - 1] = h[i];
			count[r]--;
		}

		memcpy(h, tmp, len * sizeof(int));
	}

	free(tmp);
}

void RadixSort_LSD_Reverse(int* h, int len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int digit = GetMaxDight(h, len);
	//printf("MaxDigit:%d\n", digit);

	int count[10] = { 0 };

	int *tmp = (int*)calloc(len, sizeof(int));

	for (int d = 1; d <= digit; ++d)
	{
		memset(count, 0, sizeof(count));

		for (int i = 0; i < len; ++i)
		{
			count[GetReminder(h[i], d)]++;
		}

		//printf("haha\n");

		//求右边界
		for (int i = 8; i >= 0; --i)
		{
			count[i] += count[i + 1];
		}



		for (int i = len - 1; i >= 0; --i)
		{
			int r = GetReminder(h[i], d);
			int index = count[r];
			tmp[index - 1] = h[i];
			count[r]--;
		}

		memcpy(h, tmp, len * sizeof(int));
	}

	free(tmp);
}


// MSD排序


int GetMaxDight(int* h, int len)
{
	if (h == NULL) return 0;
	if (len < 1) return 0;

	int max = h[0];
	for (int i = 1; i < len; ++i)
	{
		if (h[i] > max) max = h[i];
	}

	int digit = 1;
	while (max / 10 != 0)
	{
		max /= 10;
		++digit;
	}

	return digit;
}

int GetReminder(int value, int digit)
{
	int div = 1;
	for (int i = 1; i < digit; ++i)
		div *= 10;

	return value / div % 10;
}

void RRadixSort_MSD(int* h, int begin, int end, int digit)
{
	if (h == NULL) return;
	if (begin >= end) return;
	if (digit < 1) return;

	int start[10];
	int count[10] = { 0 };
	int *tmp = (int*)calloc(end - begin + 1, sizeof(int));

	for (int i = begin; i <= end; ++i)
	{
		count[GetReminder(h[i], digit)]++;
	}

	memcpy(start, count, sizeof(start));

	//求右边界
	for (int i = 1; i < 10; ++i)
	{
		start[i] += start[i - 1];
	}

	for (int i = end; i >= begin; --i)
	{
		int r = GetReminder(h[i], digit);
		int index = start[r];
		tmp[index - 1] = h[i];
		start[r]--;
	}

	/*
	for(int i=0;i<10;++i)
	{
		printf("%d ",start[i]);
	}

	printf("\n");
	*/

	memcpy(&h[begin], tmp, (end - begin + 1) * sizeof(int));

	for (int i = 0; i < 10; ++i)
	{
		if (count[i] > 1)
		{
			RRadixSort_MSD(h, start[i], start[i] + count[i] - 1, digit - 1);
		}
	}
}

void RadixSort_MSD(int* h, int len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int digit = GetMaxDight(h, len);

	//printf("MaxDigit:%d\n",digit);

	RRadixSort_MSD(h, 0, len - 1, digit);
}

void RRadixSort_MSD_Reverse(int* h, int begin, int end, int digit)
{
	if (h == NULL) return;
	if (begin >= end) return;
	if (digit < 1) return;

	int start[10];
	int count[10] = { 0 };
	int *tmp = (int*)calloc(end - begin + 1, sizeof(int));

	for (int i = begin; i <= end; ++i)
	{
		count[GetReminder(h[i], digit)]++;
	}

	memcpy(start, count, sizeof(start));

	//求右边界
	for (int i = 8; i >= 0; --i)
	{
		start[i] += start[i + 1];
	}

	for (int i = end; i >= begin; --i)
	{
		int r = GetReminder(h[i], digit);
		int index = start[r];
		tmp[index - 1] = h[i];
		start[r]--;
	}

	/*
	for(int i=0;i<10;++i)
	{
		printf("%d ",start[i]);
	}

	printf("\n");
	*/

	memcpy(&h[begin], tmp, (end - begin + 1) * sizeof(int));

	for (int i = 0; i < 10; ++i)
	{
		if (count[i] > 1)
		{
			RRadixSort_MSD_Reverse(h, start[i], start[i] + count[i] - 1, digit - 1);
		}
	}
}

void RadixSort_MSD_Reverse(int* h, int len)
{
	if (h == NULL) return;
	if (len <= 1) return;

	int digit = GetMaxDight(h, len);

	//printf("MaxDigit:%d\n",digit);

	RRadixSort_MSD_Reverse(h, 0, len - 1, digit);
}


int main() {
	int A[10] = { 0 };//初始化一个数组
	srand((unsigned)time(NULL));//随机数
	int length = sizeof(A) / sizeof(A[0]);
	cout << "generate rand numbers:" << endl;
	for (int i = 0; i < 10; i++) {
		A[i] = rand() % 100;
		printf("%d ", A[i]);
	}
	cout << "\n" << endl;
	//Selectsort(A,length);
	//InsertSort(A,length);
	//bubblesort(A, length);
	//healsort(A, length);
	Quicksort(A,0,9);
	cout << "after sort algorithm:" << endl;
	for (int i = 0; i < 10; i++) {
		printf("%d ", A[i]);
	}
	system("pause");
	return 0;
}