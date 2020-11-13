#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
using namespace std;

// hàm hoán vị 2 giá trị a và b .

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

// các thuật toán sắp xếp .

void InterchangeSort(int a[], int n)
{
	for (int i = 0; i < (n - 1); i++)
		for (int j = (i + 1); j < n; j++)
			if (a[j] < a[i])
				swap(a[i], a[j]);
}

void SelectionSort(int a[], int n)
{
	for (int i = 0; i < (n - 1); i++)
	{
		int min = i;
		for (int j = (i + 1); j < n; j++)
			if (a[j] < a[min])
				min = j;
		swap(a[i], a[min]);
	}
}

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < (n - 1); i++)
		for (int j = (n-1); j > i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

void ShakerSort(int a[], int n)
{
	int left = 0, right = n - 1;
	while (left < right)
	{
		for (int i = left; i < right; i++)
			if (a[i] > a[i + 1])
				swap(a[i], a[i + 1]);
		right--;
		for (int i = right; i > left; i--)
			if (a[i] < a[i - 1])
				swap(a[i], a[i - 1]);
		left++;
	}
}

void InsertionSort(int a[], int n)
{
	int j;
	for (int i = 1; i < n; i++)
	{
		int temp = a[i]; 
		for (j = i - 1; (a[j] > temp) && (j >= 0); j--)
			if (temp < a[j])
				a[j+1] = a[j];
		a[j+1] = temp;
	}
}

void BinaryInsertionSort(int a[], int n)
{
	int left, right, m, i;
	int key;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		left = 0;
		right = i - 1;
		while (left <= right)
		{
			m = (left + right) / 2;
			if (key < a[m])
				right = m - 1;
			else left = m + 1;
		}
		for (int j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[left] = key;
	}
}

void ShellSort(int a[], int n)
{
	int x,j;
	for (int h = n / 2; h > 0; h /= 2)
			for (int i = 1; i < n; i+=h)
			{
				x = a[i];
				for (j = i; j > 0 && a[j-h] > x; j-=h)
					a[j] = a[j-h];
				a[j] = x;
			}
}

void CreatHeap(int a[], int n)
{
	for (int l = n / 2 - 1 ; l >= 0; l--)
	{
		int i = l;
		int j = 2 * i + 1;
		int x = a[i];
		while (j <= n - 1)
		{
			if (j < n - 1)
				if (a[j] < a[j + 1])
					j++;
			if (a[j] <= x)
				break;
			else
			{
				a[i] = a[j];
				a[j] = x;
				i = j;
				j = 2 * i + 1;
				x = a[i];
			}
		}
	}
}

void HeapSort(int a[], int n)
{

	CreatHeap(a, n);
	for (int i = n - 1; i > 0;i--)
	{
		swap(a[0], a[i]);
		CreatHeap(a, i);
	}
}


int CreatQuick(int a[], int left, int right)
{
	int i = left + 1;
	int j = right;
	while (i <= j)
	{
		while (a[i] <= a[left])
			i++;
		while (a[j]>a[left])
			j--;
		if (i < j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	} 
	swap(a[left], a[j]);
	return j;
}

void QuickSort(int a[], int left, int right)
{
	if (left < right)
	{
		int k = CreatQuick(a, left, right);
		QuickSort(a, left, k - 1);
		QuickSort(a, k + 1, right);
	}
}



void CreatMerge(int a[], int left, int mid, int right)
{
	int i = left;
	int j = mid + 1;
	int k = 0;
	int n = right - left + 1;
	int *b = new int[n];
	while ((i < mid + 1) && (j < right + 1))
	{
		if (a[i] < a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}
	while (i<(mid + 1))
	{
		b[k] = a[i];
		k++;
		i++;
	}
	while (j<right + 1)
	{
		b[k] = a[j];
		k++;
		j++;
	}
	i = left;
	for (k = 0; k < n; k++)
	{
		a[i] = b[k];
		i++;
	}
	delete[] b;
}

void MergeSort(int a[], int left, int right)
{
	if (left<right)
	{
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid + 1, right);
		CreatMerge(a, left, mid, right);
	}
}


// random một số ngãu nhiên từ a->b .

int RandomNumberArr(int a, int b)
 {
	 srand(time(NULL));
	 return a + rand() % (b - a + 1);
 }

int RandomNumber(int a, int b)
{
	return a + rand() % (b - a + 1);
}

// Hàm ghi thời gian và mảng vào File.

void Arr(int a[],int k ,int j)
{
	fstream f;
	f.open("output.txt", ios::out | ios::app);
	f << endl;
	f << " mang thu "<< j + 1  <<" co cac phan tu la a[]={ ";
	for (int i = 0; i < k; i++)
	{
		f << a[i];
		if (i == (k - 1))
			f << " }";
		else
			f << ", ";
	}
	f << endl;
	f.close();
}

void File(float s,string c)
{
	fstream f;
	f.open("output.txt", ios::out | ios::app);
	f << "thoi gian do " << c << " la : "<< s <<" s" <<endl;
	f.close();
}



//-->hàm đo thời gian cho các thuật toán<--!

float TimeRunInterchangeSort(int a[],int n)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		InterchangeSort(a, n);
	clock_t end = clock();
	cout << "InterchangeSort :" <<(end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunSelectionSort(int a[], int n)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		SelectionSort(a, n);
	clock_t end = clock();
	cout << "SelectionSort :" << ((end - begin) / (float)CLOCKS_PER_SEC) <<" s"<<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunBubbleSort(int a[], int n)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		BubbleSort(a, n);
	clock_t end = clock();
	cout << "BubbleSort :" << (end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunShakerSort(int a[], int n)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		ShakerSort(a, n);
	clock_t end = clock();
	cout << "ShakerSort :" << (end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunInsertionSort(int a[], int n)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		InsertionSort(a, n);
	clock_t end = clock();
	cout << "InsertionSort :" << (end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunBinaryInsertionSort(int a[], int n)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		BinaryInsertionSort(a, n);
	clock_t end = clock();
  cout << "BinaryInsertionSort :" << (end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunShellSort(int a[], int n)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		ShellSort(a, n);
	clock_t end = clock();
	cout << "ShellSort :" << (end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunHeapSort(int a[], int n)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		HeapSort(a, n);
	clock_t end = clock();
	cout << "HeapSort :" << (end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunQuickSort(int a[], int left,int right)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		QuickSort(a,left,right);
	clock_t end = clock();
	cout << "QuickSort :" << (end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

float TimeRunMergeSort(int a[], int left, int right)
{
	clock_t begin = clock();
	for (int i = 0; i < 1000000; i++)
		MergeSort(a, left, right);
	clock_t end = clock();
  cout << "MergeSort :" << (end - begin) / (float)CLOCKS_PER_SEC << " s" <<endl;
	return (end - begin) / (float)CLOCKS_PER_SEC;
}

int main()
{
	int *a = nullptr;
	for (int j = 0; j < 10; j++)
	{
		int k = RandomNumberArr(3, 20);
		a = new int[k];
		for (int i = 0; i < k; i++)
		{
			a[i] = RandomNumber(5, 100);
		}
		for (int i = 0; i < k; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;

		Arr(a, k, j);

		float s = TimeRunSelectionSort(a, k);
		File(s, "selection sort");
		s = TimeRunBubbleSort(a, k);
		File(s, "BubbleSort");
		s = TimeRunInsertionSort(a, k);
		File(s, "InsertionSort");
		s = TimeRunBinaryInsertionSort(a, k);
		File(s, "BinaryInsertionSort");
		s = TimeRunInterchangeSort(a, k);
		File(s, "InterchangeSort");
		s = TimeRunShakerSort(a, k);
		File(s, "ShakerSort");
		s = TimeRunShellSort(a, k);
		File(s, "ShellSort");
		s = TimeRunHeapSort(a, k);
		File(s, "HeapSort");
		s = TimeRunQuickSort(a, 0, k - 1);
		File(s, "QuickSort");
		s = TimeRunMergeSort(a, 0 ,k-1);
		File(s, "MergeSort");
		if (j == 9)
		{
			cout << endl << " ghi file thanh cong !!! "<<endl;
		}
		else
			cout << endl;
	}
	system("pause");
	delete[] a;
	return 0;
	
}

