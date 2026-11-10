#include<iostream>
#include<thread>
#include<chrono>

using namespace std;

void sumArr(int a[],const int size) {
	int n = 50'000;

	for (int i = 0;i < n;i++) {
		a[i % size] += 5;
	}
}

void subArr(int a[], const int size) {
	int n = 50'000;

	for (int i = 0;i < n;i++) {
		a[i % size] -= 5;
	}
}


int main() {

	const int arrSize = 10;
	int arr[arrSize] = { 10,10,10,10,10,10,10,10,10,10 };

	//sumArr(arr, arrSize);
	//subArr(arr, arrSize);

	jthread t1(sumArr, arr, arrSize);
	jthread t2(subArr, arr, arrSize);

	this_thread::sleep_for(chrono::seconds(1));


	int sum{ 0 };
	for (int i = 0;i < arrSize;i++) {
		sum += arr[i];
	}

	cout << sum << "\n";

	return 0;
}
