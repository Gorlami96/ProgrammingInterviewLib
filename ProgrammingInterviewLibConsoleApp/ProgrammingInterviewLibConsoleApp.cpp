// ProgrammingInterviewLibConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ProgrammingInterviewLib.h"

using namespace std;
using namespace ProgrammingInterviewLib;

int main()
{
    vector<int> arr = { 2,3,5,5,7,11,11,11,13 };
    int n = ArrayHelperMethods::RemoveDuplicatesFromSortedArray(arr);
    cout << n<<endl;

    vector<long long> stonks1 = { 1,5,7,8,-5,9,0 };
    cout<< ArrayHelperMethods::BuyAndSellStockOnce(stonks1)<<endl;

    vector<long long> stonks2 = { 12,11,13,9,12,8,14,13,15 };
    cout << ArrayHelperMethods::BuyAndSellStockTwice(stonks2)<<endl;
}
