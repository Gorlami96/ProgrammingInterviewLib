#pragma once

#include <vector>

using namespace std;

namespace ProgrammingInterviewLib
{
	
	class ArrayHelperMethods
	{
	public:

		
		template<typename T>
		/// <summary>
		/// Removes duplicates from a sorted array. The remaining elements after the returned
		/// index should be ignored.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="arr"></param>
		/// <returns>The index of last unique element after shifting</returns>
		static int RemoveDuplicatesFromSortedArray(vector<T> arr);

		/// <summary>
		/// If the given array describes price of a single stock on various days, then
		/// maximum profit that can be made by trading a single unit of stock is returned
		/// </summary>
		/// <param name="arr">Array of stock price on different days</param>
		/// <returns>max profit made by buying and selling a single unit of stock</returns>
		static long long BuyAndSellStockOnce(vector<long long> arr);

		/// <summary>
		/// If the given array describes price of a single stock on various days, then
		/// maximum profit that can be made by trading a single unit of stock twice is returned.
		/// Second buy must always be after the first sale. Might have a generalized version in
		/// later iterations.
		/// </summary>
		/// <param name="arr">Array of stock price on different days</param>
		/// <returns>max profit made by buying and selling a single unit of stock twice</returns>
		static long long BuyAndSellStockTwice(vector<long long> arr);

		/// <summary>
		/// Returns a sorted vector of all primes till integer "n".
		/// </summary>
		/// <param name="n">positive integer >=1 </param>
		/// <returns>sorted vector of all primes till "n"</returns>
		static vector<int> GeneratePrimes(int n);

		/// <summary>
		/// Applies permutation to given vector. Permutation itself is a vector that is the is same size
		/// as arr and is of the form [m1,m2,m3....mn]. This means place element at index 0 at index m1,
		/// element at index 2 at index m2 and so on.
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="arr">vector that needs to be permuted</param>
		/// <param name="perm">permutation of vector as defined above</param>
		template<typename T>
		static void PermuteArray(vector<T>* arr, vector<int>* perm);
	};
}