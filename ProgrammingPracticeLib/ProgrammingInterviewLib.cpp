// ProgrammingPracticeLib.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "ProgrammingInterviewLib.h"
#include <stdexcept>

namespace ProgrammingInterviewLib
{
	template<typename T>
	int ArrayHelperMethods::RemoveDuplicatesFromSortedArray(std::vector<T> arr)
	{
		if (arr.size() <= 1)
			return 0;
		else if (arr.empty())
			throw invalid_argument("arr cannot be null");

		int n = arr.size();

		int write_index = 1;
		for (int i = 1; i < n; ++i) {
			if (arr[write_index - 1] != arr[i])
				arr[write_index++] = arr[i];

		}
		return write_index;
	}
	template int ArrayHelperMethods::RemoveDuplicatesFromSortedArray<int>(vector<int> arr);

	long long ArrayHelperMethods::BuyAndSellStockOnce(vector<long long> arr) {

		
		if (arr.size()<=1)
			return 0;
		else if (arr.empty())
			throw invalid_argument("arr cannot be null");

		int n = arr.size();

		long long min_price = arr[0];
		long long curr_max_profit = INT64_MIN;

		for (int i = 1; i < n; i++) {
			if (min_price > arr[i])
				min_price = arr[i];
			
			curr_max_profit = std::max(curr_max_profit, arr[i] - min_price);
		}

		return (curr_max_profit > 0) ? curr_max_profit : 0;
	}

	long long ArrayHelperMethods::BuyAndSellStockTwice(vector<long long> arr)
	{
		if (arr.empty())
			throw invalid_argument("arr cannot be null");

		int n = arr.size();
		vector<long long> forward(n, 0);
		long long min_till_now = INT64_MAX;
		long long max_profit_forward = INT64_MIN;

		for (size_t i = 0; i < n; i++) {
			min_till_now = min(min_till_now, arr[i]);
			max_profit_forward = max(max_profit_forward, arr[i] - min_till_now);
			forward[i] = max_profit_forward;
		}

		vector<long long> backward(n, 0);
		long long max_till_now = INT64_MIN;
		long long max_profit_backward = INT64_MIN;

		for (size_t i = n; i-- > 0 ;)
		{
			max_till_now = max(max_till_now, arr[i]);
			max_profit_backward = max(max_profit_backward, max_till_now - arr[i]);
			backward[i] = max_profit_backward;
		}

		vector<long long> result(n, 0);
		long long max_profit = INT64_MIN;

		for (size_t i = 0; i < n; i++)
		{
			if (i == 0) 
			{
				result[0] = backward[0];
				continue;
			}
			result[i] = forward[i - 1] + backward[i];
			max_profit = max(max_profit, result[i]);
		}

		return max_profit;
	}

	vector<int> ArrayHelperMethods::GeneratePrimes(int n)
	{
		if(n<=1)
			throw invalid_argument("n is null or less than 1");
		

		vector<bool> is_prime(n+1, true);
		vector<int> primes;
		is_prime[0] = is_prime[1] = false;
		
		for (int i = 2; i < n; i++) {
			if (is_prime[i]) {
				primes.emplace_back(i);
				//sieve i's multiples. But we don't need to start from p. We can start from i^2
				//as all numbers of the form k*i where k<i have already been sieved out as they
				//are multiples of k
				for (int j = i * i; j < n; j+=i) {
					is_prime[j] = false;
				}
			}
		}

		return primes;
	}

	template<typename T>
	static void ArrayHelperMethods::PermuteArray(vector<T>* arr, vector<int>* perm)
	{
		if (arr.empty() || perm.empty)
			throw invalid_argument("cannot pass null argument");
		else if (arr.size() != perm.size())
			throw invalid_argument("size of both arr and perm should be same");

		int n = arr.size();

		for (int i = 0; i < n; i++) {
			int next = i;
			while (perm[next] >= 0) {
				swap(arr[i], arr[perm[next]]);
				int temp = perm[next];
				perm[next] -= n;
				next = temp;
			}
		}

		for each (int var in perm)
		{

		}
	}
}