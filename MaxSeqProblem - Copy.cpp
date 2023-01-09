#include <iostream>
#include <vector>
using namespace std;

/**
 * Cubic maximum contiguous subsequence sum algorithm.
 */
int maxSubSum1(const vector<int>& a)
{
    int maxSum = 0;

    for (int i = 0; i < a.size(); ++i)
        for (int j = i; j < a.size(); ++j)
        {
            int thisSum = 0;

            for (int k = i; k <= j; ++k)
                thisSum += a[k];

            if (thisSum > maxSum)
                maxSum = thisSum;
        }

    return maxSum;
}


/**
 * Quadratic maximum contiguous subsequence sum algorithm.
 */
int maxSubSum2(const vector<int>& a)
{
    int maxSum = 0;

    for (int i = 0; i < a.size(); ++i)
    {
        int thisSum = 0;
        for (int j = i; j < a.size(); ++j)
        {
            thisSum += a[j];

            if (thisSum > maxSum)
                maxSum = thisSum;
        }
    }

    return maxSum;
}


/**
 * Linear-time maximum contiguous subsequence sum algorithm.
 */
int maxSubSum4(const vector<int>& a)
{
    int maxSum = 0, thisSum = 0;

    for (int j = 0; j < a.size(); ++j)
    {
        thisSum += a[j];

        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }

    return maxSum;
}

/**
 *  test program.
 */
int main()
{
    // vector<int> a{ 4, -3, 5, -2, -1, 2, 6, -2 };
    vector<int> a{ -2, 11, -4, 13, -5, -2 };
   
    int maxSum;

    maxSum = maxSubSum1(a);
    cout << "Max sum is " << maxSum << endl;
   

    maxSum = maxSubSum2(a);
    cout << "Max sum is " << maxSum << endl;
    

    maxSum = maxSubSum4(a);
    cout << "Max sum is " << maxSum << endl;

    return 0;
}




