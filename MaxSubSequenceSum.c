/*
** 最大子序列和问题的解
** 三种不同时间复杂度的算法
*/

#include <stdio.h>

/*
//O(N*N)
int MaxSubsequenceSum(const int A[], int N) {
	int ThisSum, MaxSum, i, j;

	MaxSum = 0;
	for(i = 0; i < N; i++) {
		ThisSum = 0;
		for(j = i; j < N; j++) {
			ThisSum += A[j];

			if(ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}
*/

/*
//O(N*logN)，采用递归和分治策略
static int Max3(int i, int j, int k) {
	return (i >= j) ? (i >= k ? i : k) : (j >= k ? j : k);
}

static int MaxSubSum(const int A[], int Left, int Right) {
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
	int center, i;

	if(Left == Right) //Base case
		if(A[Left] > 0)
			return A[Left];
		else 
			return 0;

		Center = (Left + Right) / 2;
		MaxLeftSum = MaxSubSum(A, Left, Center);
		MaxRightSum = MaxSubSum(A, Center + 1, Right);

		MaxLeftBorderSum = 0;
		LeftBorderSum = 0;
		for(i = Center; i >= Left; i--) {
			LeftBorderSum += A[i];
			if(LeftBorderSum > MaxLeftBorderSum)
				MaxLeftBorderSum = LeftBorderSum;	
		}

		for(i = Center + 1; i <= Right; i++) {
			RightBorderSum += A[i];
			if(RightBorderSum > MaxRightBorderSum)
				MaxRightBorderSum = RightBorderSum;
		}

		return Max3(MaxLeftSum, MaxRightSum， MaxLeftBorderSum + MaxRightBorderSum);
}

int MaxSubsequenceSum(const int A[], int N) {
	return MaxSubSum(A, 0, N - 1);
}
*/

//O(N)，仅需要常量空间并以线性时间允许的联机算法几乎是完美的算法
int MaxSubsequenceSum(const int A[], int N) {
	int ThisSum, MaxSum, j;

	ThisSum = MaxSum = 0;
	for (j = 0; j < N; j++) {
		ThisSum += A[j];
		if(ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if(ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}

int main(void) {
	int array[] = {2, 4, 6, 3, 5, 1, 8, 7, 9, 0};
	int MaxSubSum = 0;
	MaxSubSum = MaxSubsequenceSum(array, 10);

	printf("The max subsequence sum is: %d\n", MaxSubSum);

	return 0;
}
