#include <iostream>
using namespace std;

void swap(int *x,int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void Bubble(int a[], int n) {
	int flag = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j] > a[j + 1]) {
				swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			break;
		}
	}
}

void Insertion(int a[], int n) {
	for (int i = 1; i < n; i++) {
		int j = i - 1;
		int x = a[i];
		while (j > -1 && a[j] > x) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

void Selection(int a[], int n) {
	int i, j, k;
	int x;
	for (i = 0; i < n-1; i++) {
		j = i + 1;
		k = i;
		x = a[i];
		while (j<n) {
			if (x > a[j]) {
				x = a[j];
				k = j;
			}
			j++;
		}
		swap(&a[i], &a[k]);
	}
}

int Partition(int a[], int l, int h) {
	int pivot = a[l];
	int i = l, j = h;
	do{
		do { i++; } while (a[i] <= pivot);
		do { j--; }while(a[j] > pivot);
		if (i < j){
			swap(&a[i], &a[j]);
		}
	} while (i < j);
	swap(&a[l], &a[j]);
	return j;
}

void QuickSort(int a[], int l, int h) {
	int j;
	if (l < h) {
		j = Partition(a, l, h);
		QuickSort(a, l, j);
		QuickSort(a, j + 1, h);
	}
}
int * Merge1(int a[], int b[], int m, int n) {
	int i, j, k;
	int* p = new int[n + m];
	i = j = k = 0 ;
	while (i < m && j < n) {
		if (a[i] < b[j])
			p[k++] = a[i++];
		else
			p[k++] = b[j++];
	}
	for (; i < m; i++) { p[k++] = a[i]; }
	for (; j < n; j++) { p[k++] = b[j]; }
	return p;
}
// the two halves should be sorted in order for the algorithm to work properly
void Merge2(int a[], int l, int mid, int h) {
	int i, j, k;
	int b[100] = { 0 };
	i = l;
	j = mid+1;
	k = l;
	while (i <= mid && j <= h) {
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	for (; i <= mid; i++) { b[k++] = a[i]; }
	for (; j <= h; j++) { b[k++] = a[j]; }
	for (int i = l; i <= h; i++) {
		a[i] = b[i];
	}
}
void IMerge(int a[],int n) {
	int i, h, l, p,mid;
	for (p = 2; p < n; p=p*2) {
		for ( i = 0; i + p - 1 < n; i = i + p) {
			l = i;
			h = i + p - 1;
			mid = (l + h) / 2;
			Merge2(a, l, mid, h);
		}
	}
	if (p / 2 < n) {
		Merge2(a, 0, p / 2 - 1, n-1);
	}
}
void RMerge(int a[], int l, int h) {
	if (l < h){
		int mid = (l + h) / 2;
		RMerge(a, l, mid);
		RMerge(a, mid + 1, h);
		Merge2(a, l, mid, h);
	}
}
int findmax(int a[], int n) {
	int max = INT32_MIN;
	for (int i = 0; i < n; i++) {
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

void CountSort(int a[],int n) {
	int mx = findmax(a, n);
	int* c;
	c = new int[mx+1];
	for (int i = 0; i < mx+1; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		c[a[i]]++;
	}
	int j = 0;
	int k = 0;
	while (j < mx + 1) {
		if (c[j] > 0) {
			a[k++] = j;
			c[j]--;
		}
		else {
			j++;
		}
	}
}

int main(){
	int a[] = { 8,5,7,3,2 };
	int b[] = { 2,3,5,7,8 };
	int c[] = { 11,13,7,12,16,9,24,5,10,3,INT32_MAX };
	int d[] = {2,10,18,20,23};
	int e[] = { 4,9,19,25 };
	int f[] = { 11,13,7,12,16,9,24,5,10,3 };
	//QuickSort(c, 0,10);
	/*int* q = Merge1(d, e, 5, 4);
	for(int i=0;i<9;i++){
		cout << q[i] << " " ;
	}
	delete[] q;*/
	/*Merge2(a, 0, 2, 4);
	for (int i = 0; i <= 4; i++) {
		cout << a[i] << " ";
	}*/
	int x[] = { 11,13,7,12,16,9,24,5,10,3 };
	//RMerge(x,0, 9);
	CountSort(x, 10);
	for (int i = 0; i < 10; i++) {
		cout << x[i] << " ";
	}
	return 0;
}
