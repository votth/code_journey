// you can use includes, for example:
// // #include <algorithm>
//
// // you can write to stdout for debugging purposes, e.g.
// // cout << "this is a debug message" << endl;

/*
   This is a demo task.

   Write a function:
       int solution(vector<int> &A);
	   that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

	   For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
	   Given A = [1, 2, 3], the function should return 4.
	   Given A = [−1, −3], the function should return 1.
	   Write an efficient algorithm for the following assumptions:
	           N is an integer within the range [1..100,000];
			           each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

#include <iostream>
#include <bits/stdc++.h>

int main() {
	std::vector<int> A = {2, 2, 1, 0, 4};
	std::sort(A.begin(), A.end());

	int size = A.size();
	int result = 0;
	int i {};

	for (i = 0; i < size; ++i) {
		if (A[i] < 0) continue;
		if (result == A[i]) continue;
		result++;
		if (result != A[i]) break;
	}
	if (i == size) result++;

	std::cout << result;

	return 0;
}

/*
int firstMissingPositive(vector<int>& nums) {
	cin.tie(nullptr)->sync_with_stdio(false);

	size_t n = nums.size();
	bool cnt[nums.size()+3];

	memset(cnt, false, sizeof cnt);

	for(int i:nums){
		if(i>0 && i<=n) cnt[i] = true;
	}

	for(int i=1; i<=n+1; ++i){
		if(!cnt[i]) return i; 
	}

	return n+1;
}
*/
