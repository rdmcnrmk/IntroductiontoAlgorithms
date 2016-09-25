#include "insertionsort.h"

int main() {
    int arr[] = { -11, -3, 9, 17, 42, 54, 54, 602, 999 };
    InsertionSort *insertionSort = new InsertionSort();
	insertionSort->Print(insertionSort->Run(arr, 9), 9);
	
	return 0;
}