#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define ll long long

void merge(int a[], int start, int mid, int end) {

	int p = start;
	int q = mid + 1;
	int k = 0;
	int arr[end - start + 1];

	for (int i = start; i <= end; i++) {

		if (p > mid)
			arr[k++] = a[q++];
		else if (q > end)
			arr[k++] = a[p++];

		else if (a[p] < a[q])
			arr[k++] = a[p++];
		else
			arr[k++] = a[q++];

	}

	for (int i = start; i <= end; i++)
		a[i] = arr[i - start];
}


void merge_sort(int a[], int start, int end) {

	if (start < end) {
		int mid = (start + end) / 2;

		merge_sort(a, start, mid);
		merge_sort(a, mid + 1, end);

		merge(a, start, mid, end);
	}

}


int main() {

    //Using text files for input output
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int a[5];
    for (int i = 0; i < 5; i++)
    	scanf("%d", &a[i]);

    merge_sort(a, 0, 4);
    for (int i = 0; i < 5; i++)
    	printf("%d ", a[i]);

	



    return 0;
}
