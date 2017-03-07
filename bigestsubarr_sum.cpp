#include <iostream>

using namespace std;

void main() {
	int size = 16;
	float Array[16];
	int low = 0 , high = size-1;
	float *maxV = new float(3);
	float *Find_MAX_SUBARRAY(float *, int, int);
	float *Find_MAX_CROSS_SUBARRAY(float *, int, int, int);
	for (int i = 0; i < size; i++)
	{
		cin >> Array[i];
	}
	maxV = Find_MAX_SUBARRAY(Array,low,high);
	cout << maxV[0] << maxV[1] << maxV[2] << endl;
	getchar();
	getchar();
}

float *Find_MAX_SUBARRAY(float *A, int low, int high) {
	float *left = new float(3), *right = new float(3), *cross = new float(3);
	float *max_1k = new float(3);
	int mid;
	float *Find_MAX_CROSS_SUBARRAY(float *, int, int, int);
	if (low == high)
	{
		max_1k[0] = low;
		max_1k[1] = high;
		max_1k[2] = A[low];
		return  max_1k;
	}
	else
	{
		mid = (low + high) / 2;
		left = Find_MAX_SUBARRAY(A, low, mid);
		right = Find_MAX_SUBARRAY(A, mid+1, high);
		cross = Find_MAX_CROSS_SUBARRAY(A, low, mid, high);
		if ((*(left+2)>=*(right+2))&&((*left+2)>=*(cross+2)))
		{
			return left;
		}
		else if ((*(right + 2) >= *(left + 2)) && ((*right + 2) >= *(cross + 2)))
		{
			return right;
		}
		else
		{
			return cross;
		}
	}

}

float *Find_MAX_CROSS_SUBARRAY(float *A, int low, int mid, int high) {
	float left_sum = -10000000.00;
	float right_sum = -10000000.00;
	float sum = 0;
	float *max_cross = new float(3);
	for (int i = mid; i >= low; i--)
	{
		sum = sum + A[i];
		if (sum>left_sum)
		{
			left_sum = sum;
			max_cross[0] = i;
		}
	}
	sum = 0;
	for (int j = mid+1; j <= high ; j++)
	{
		sum = sum + A[j];
		if (sum>right_sum)
		{
			right_sum = sum;
			max_cross[1] = j;
		}
	}
	max_cross[2] = left_sum + right_sum;
	return max_cross;
}