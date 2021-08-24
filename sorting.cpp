#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

//function prototypes
vector<int> generator(int);
void swap(int&, int&);
void insertionSort(vector<int>&);
void mergeSort(vector<int>&, int, int);
void merge(vector<int>&, int, int, int);
void buildHeap(vector<int>&, int);
void heapSort(vector<int>&, int);
void heapify(vector<int>&, int, int);
void quickSort(vector<int>&, int, int);
int partition(vector<int>&, int, int);
void quickSortRand(vector<int>&, int, int);
int randPartition(vector<int>&, int, int);
void radixSort(vector<int>&);


int main()
{
	//generating 36 arrays for sorting purpose;
	srand(time(0));
	int nums[6] = { 10, 100, 1000, 10000, 100000, 1000000 };
	vector<vector<vector<int>>> randomNums(6, vector<vector<int>>(6));
	for (int i = 0; i < 6; ++i)
	{
		vector<int> temp = generator(nums[i]);
		for (int j = 0; j < 6; ++j)
			randomNums[i][j] = temp;
	}

	//this vector holds the time used by all the sorting algorithms
	vector<vector<int>> timeUsed(5, vector<int>(6));
	vector<double> timeUsed_1M;

	//testing insertion sort
	cout << "Testing insertion sort: \nNano seconds" << endl;
	for (int i = 0; i < 4; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		insertionSort(randomNums[i][0]);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<int, nano> dur_ns = (end - start);
		timeUsed[i][0] = dur_ns.count();
		cout << timeUsed[i][0] << endl;
	}
	auto start1 = chrono::high_resolution_clock::now();
	insertionSort(randomNums[4][0]);
	auto end1 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> dur_mi1 = (end1 - start1);
	timeUsed_1M.push_back(dur_mi1.count());
	cout << "Milli seconds: " << dur_mi1.count() << endl << endl;

	//testing merge sort
	cout << "Testing merge sort: \nNano seconds" << endl;
	for (int i = 0; i < 5; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		mergeSort(randomNums[i][1], 0, nums[i] - 1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<int, nano> dur_ns = (end - start);
		timeUsed[i][1] = dur_ns.count();
		cout << timeUsed[i][1] << endl;
	}
	auto start2 = chrono::high_resolution_clock::now();
	mergeSort(randomNums[5][1], 0, nums[5] - 1);
	auto end2 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> dur_mi2 = (end2 - start2);
	timeUsed_1M.push_back(dur_mi2.count());
	cout << "Milli seconds: " << dur_mi2.count() << endl << endl;

	//testing heap sort
	cout << "Testing heap sort: \nNano seconds" << endl;
	for (int i = 0; i < 5; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		buildHeap(randomNums[i][2], nums[i]);
		heapSort(randomNums[i][2], nums[i]);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<int, nano> dur_ns = (end - start);
		timeUsed[i][2] = dur_ns.count();
		cout << timeUsed[i][2] << endl;
	}
	auto start3 = chrono::high_resolution_clock::now();
	buildHeap(randomNums[5][2], nums[5]);
	heapSort(randomNums[5][2], nums[5]);
	auto end3 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> dur_mi3 = (end3 - start3);
	timeUsed_1M.push_back(dur_mi3.count());
	cout << "Milli seconds: " << dur_mi3.count() << endl << endl;

	//testing quick sort with right val as pivot point
	cout << "Testing quick sort: \nNano seconds" << endl;
	for (int i = 0; i < 5; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		quickSort(randomNums[i][3], 0, nums[i]-1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<int, nano> dur_ns = (end - start);
		timeUsed[i][3] = dur_ns.count();
		cout << timeUsed[i][3] << endl;
	}
	auto start4 = chrono::high_resolution_clock::now();
	quickSort(randomNums[5][3], 0, nums[5] - 1);
	auto end4= chrono::high_resolution_clock::now();
	chrono::duration<double, milli> dur_mi4 = (end4 - start4);
	timeUsed_1M.push_back(dur_mi4.count());
	cout << "Milli seconds: " << dur_mi4.count() << endl << endl;


	//testing quick sort with random pivot point
	cout << "Testing quick sort(rand): \nNano seconds" << endl;
	for (int i = 0; i < 5; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		quickSortRand(randomNums[i][4], 0, nums[i] - 1);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<int, nano> dur_ns = (end - start);
		timeUsed[i][4] = dur_ns.count();
		cout << timeUsed[i][4] << endl;
	}
	auto start5 = chrono::high_resolution_clock::now();
	quickSortRand(randomNums[5][4], 0, nums[4] - 1);
	auto end5 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> dur_mi5 = (end5 - start5);
	timeUsed_1M.push_back(dur_mi5.count());
	cout << "Milli seconds: " << dur_mi5.count() << endl << endl;

	//testing radix sort
	cout << "Testing radix sort: \nNano seconds" << endl;
	for (int i = 0; i < 5; ++i)
	{
		auto start = chrono::high_resolution_clock::now();
		radixSort(randomNums[i][5]);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<int, nano> dur_ns = (end - start);
		timeUsed[i][5] = dur_ns.count();
		cout << timeUsed[i][5] << endl;
	}
	auto start6 = chrono::high_resolution_clock::now();
	radixSort(randomNums[5][5]);
	auto end6 = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> dur_mi6 = (end6 - start6);
	timeUsed_1M.push_back(dur_mi6.count());
	cout << "Milli seconds: " << dur_mi6.count() << endl << endl;

	//printing the time chart
	cout << "--------------------------------------------------Time chart---------------------------------------------" << endl;
	cout << setw(18) << left << "N" << setw(20) << "Insertion sort" << setw(13) << "Merge Sort" << setw(12) << "Heap Sort";
	cout << setw(13) << "Quick sort" << setw(19) << "Quick Sort(Rand)" << setw(10) << "Radix Sort" << endl;
	for (int i = 0; i < 5; ++i)
	{
		if (i == 4)
		{
			cout << setw(18) << to_string(nums[i]) + "(nano)" << setw(20) << to_string(timeUsed_1M[0]) + "(milli)" << setw(13) << timeUsed[i][1] << setw(12) << timeUsed[i][2];
			cout << setw(13) << timeUsed[i][3] << setw(19) << timeUsed[i][4] << setw(10) << timeUsed[i][5] << endl;
		}
		else
		{
			cout << setw(18) << to_string(nums[i]) + "(nano)" << setw(20) << timeUsed[i][0] << setw(13) << timeUsed[i][1] << setw(12) << timeUsed[i][2];
			cout << setw(13) << timeUsed[i][3] << setw(19) << timeUsed[i][4] << setw(10) << timeUsed[i][5] << endl;
		}
	}
	cout << setw(18) << "1000000(milli)" << setw(20) << "Unknown" << setw(13) << timeUsed_1M[1] << setw(12) << timeUsed_1M[2];
	cout << setw(13) << timeUsed_1M[3] << setw(19) << timeUsed_1M[4] << setw(10) << timeUsed_1M[5] << endl;

	return 0;
}

//this generator will generate a vector of num of size (n)
vector<int> generator(int n)
{
	vector<int> vec;
	for (int i = 0; i < n; ++i)
		vec.push_back(rand() % 1001);
	return vec;
}

//swap function, swap the value of x and y
void swap(int& x, int& y)
{
	int temp = y;
	y = x;
	x = temp;
}

//insertion sort implementation
void insertionSort(vector<int>& nums)
{
	int n = nums.size();
	for (int i = 1; i < n; ++i)
	{
		int cur = nums[i];
		for (int j = i - 1; j >= 0; --j)
		{
			if (nums[j] > cur)
			{
				nums[j + 1] = nums[j];
			}
			else
			{
				nums[j + 1] = cur;
				break;
			}
		}
	}
}

//merge sort implementation
void mergeSort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) >> 1;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

//merge the two subarrays A1[left, mid]. A2[mid+1, right]
void merge(vector<int>& nums, int left, int mid, int right)
{
	int n = right - left + 1;
	vector<int> temp(n);
	int i = left, j = mid + 1;
	for (int k = 0; k < n; ++k)
	{
		if (i > mid) temp[k] = nums[j++];
		else if (j > right) temp[k] = nums[i++];
		else if (nums[i] <= nums[j]) temp[k] = nums[i++];
		else temp[k] = nums[j++];
	}
	for (int k = 0; k < n; ++k)
		nums[left + k] = temp[k];
}

//this function will build the vector nums to a heap
void buildHeap(vector<int>& nums, int n)
{
	for (int i = n/2; i >= 0; --i)
		heapify(nums, i, n);
}

//heap sort implementation
void heapSort(vector<int>& nums, int n)
{
	for (int i = n - 1; i > 0; --i)
	{
		swap(nums[0], nums[i]);
		heapify(nums, 0, i);
	}
}

void heapify(vector<int>& nums, int i, int n)
{
	int maxI = i, childL = i * 2 + 1, childR = i * 2 + 2;
	if (childL < n && nums[maxI] < nums[childL])
		maxI = childL;
	if (childR < n && nums[maxI] < nums[childR])
		maxI = childR;
	if (i != maxI)
	{
		swap(nums[i], nums[maxI]);
		heapify(nums, maxI, n);
	}
}

//quick sort implementation using right val as pivot point
void quickSort(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int p = partition(nums, left, right);
		quickSort(nums, left, p - 1);
		quickSort(nums, p + 1, right);
	}
}

//partition function using right val as pivot
int partition(vector<int>& nums, int left, int right)
{
	int x = nums[right];
	int p = left;
	for (int i = left; i < right; ++i)
		if (nums[i] < x)
			swap(nums[p++], nums[i]);
	swap(nums[p], nums[right]);
	return p;
}

//quick sort implementation with random index pivot
void quickSortRand(vector<int>& nums, int left, int right)
{
	if (left < right)
	{
		int p = randPartition(nums, left, right);
		quickSort(nums, left, p - 1);
		quickSort(nums, p + 1, right);
	}
}

//random parition function using random value as pivot
int randPartition(vector<int>& nums, int left, int right)
{
	//chosing random index then swap it with the right val
	int randI = rand() % (right - left + 1) + left;
	swap(nums[randI], nums[right]);
	//paritioning
	int x = nums[right];
	int p = left;
	for (int i = left; i < right; ++i)
		if (nums[i] < x)
			swap(nums[p++], nums[i]);
	swap(nums[p], nums[right]);
	return p;
}

//radix sort implementation
void radixSort(vector<int>& nums)
{
	int n = nums.size();
	vector<int> buffer(n);
	int bitPos = 1, maxVal = *max_element(nums.begin(), nums.end());
	while (maxVal >= bitPos)
	{
		vector<int> count(10);
		//counting raidx numbers
		for (int x : nums)
			++count[(x / bitPos) % 10];
		//count positions
		for (int i = 1; i < 10; ++i)
			count[i] += count[i - 1];
		//sorting accordingly to radix
		for (int i = n - 1; i >= 0; --i)
		{
			int idx = count[(nums[i] / bitPos) % 10] - 1;
			buffer[idx] = nums[i];
			--count[(nums[i] / bitPos) % 10];
		}
		//copy the buffer to the original array
		for (int i = 0; i < n; ++i) nums[i] = buffer[i];

		bitPos *= 10;
	}
}