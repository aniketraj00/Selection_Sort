#include <iostream>
#include <ctime>

void selectionSort(int* arr, size_t length);
void printArr(int* arr, size_t length);
void swap(int* arr, size_t idx1, size_t idx2);

int randInt(int upperBound);
void shuffleArr(int* arr, int length);

static int temp{ 0 };

int main() {
	const size_t size = 1000;
	int arr[size];


	for (int i = 0; i < size; i++) {
		arr[i] = (i + 1);
	}

	shuffleArr(arr, size);

	printArr(arr, size);
	selectionSort(arr, size);
	printArr(arr, size);

	return 0;
}

void selectionSort(int* arr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		size_t smallestIdx = i;
		for (size_t j = (i + 1); j < length; j++) {
			if (arr[smallestIdx] > arr[j]) {
				smallestIdx = j;
			}
			std::cout << "\nCount = " << ++temp;
		}
		if(smallestIdx != i) swap(arr, smallestIdx, i);
	}
}

void swap(int* arr, size_t idx1, size_t idx2) {
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void printArr(int* arr, size_t length) {
	std::cout << "\n[";
	for (size_t i = 0; i < length; i++) {
		i == (length - 1) ? std::cout << arr[i] : std::cout << arr[i] << "  ";
	}
	std::cout << "]\n";
}

int randInt(int upperBound) {
	int random = std::rand() % upperBound + 1;
	return random;
}

void shuffleArr(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		swap(arr, i, randInt(length - 1));
	}
}