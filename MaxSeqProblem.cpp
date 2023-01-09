#include<chrono>
#include <iostream>
#include <vector>
#include<cstdlib>
#include<ctime>
using namespace std;
using namespace std::chrono;



int maxSubSum1(vector<int> a)
{
    int maxSum = 0, thisSum = 0;

    for (int j = 0; j < a.size(); ++j)  // Complextion O(N)  One Loop.
    {
        thisSum = thisSum + a[j];

        if (thisSum > maxSum) {
            maxSum = thisSum;
        }
        

    }

    return maxSum;
}
int maxSubSum2(const vector<int>& a) {
    int maxSum = 0;
    int temp;

    for (int i = 0; i < a.size(); i++) {
        int thisSum = 0;
        for (int j = 0; j <= i; j++) {              // complextion O(N^2) Two Loops
            thisSum = thisSum + a[j];

            if (thisSum > maxSum)
                maxSum = thisSum;
            else {
                temp = thisSum;
            }
            


        }
    }
    return maxSum;

}
int maxSubSum3(const vector<int>& a)
{
    int maxSum = 0;


    for (int i = 0; i < a.size(); ++i)

    {


        for (int j = i; j < a.size(); ++j)
        {
            int thisSum = 0;

            //{ -2, 11, -4, 13, -5, -2 }
            for (int k = i; k <= j; ++k)
            {
                thisSum += a[k];
            }
            if (thisSum > maxSum)
                maxSum = thisSum;

        }
    }
    return maxSum;
}


int main() {
    srand((unsigned)time(NULL));
    int max;
    cout << "Enter how many number you want to genarate: ";
    cin >> max;
    vector<int>a{};
    for (int i = 0; i < max; i++)
        a.push_back(rand());

    cout << "First few random "<<max<<" elements: " << endl;;
    for (int i = 0; i < max; i++)
        cout << a[i] << " ";
    cout << endl;

    int sum;
    auto start = chrono::high_resolution_clock::now();
    sum = maxSubSum1(a);
    auto stop = chrono::high_resolution_clock::now();
    cout << "\nMax sum is " << sum << endl;
    duration<double>duration = (stop - start);

    cout << "Time taken by function with complextion O(N): "
        << duration.count() << " seconds" << endl;


    int sum1;
    start = chrono::high_resolution_clock::now();
    sum1 = maxSubSum2(a);
    stop = chrono::high_resolution_clock::now();
    cout << "\nMax sum is " << sum1 << endl;
    duration = (stop - start);

    cout << "Time taken by function with complextion O(N^2): "
        << duration.count() << " seconds" << endl;

    int sum2;
    start = chrono::high_resolution_clock::now();
    sum2 = maxSubSum3(a);
    stop = chrono::high_resolution_clock::now();
    cout << "\nMax sum is " << sum2 << endl;
    duration = (stop - start);

    cout << "Time taken by function  with complextion O(N^3): "
        << duration.count() << " seconds" << endl;

}