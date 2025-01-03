// what a nice problem to understand the concept of recursion
// Given an array of integers, print all the possible subsequences of the array (including the empty subsequence).
// A subsequence of an array is a set of elements that can be obtained by deleting some elements possibly without changing the order of the remaining elements.
// For example, the subsequences of the array {1, 2} are {1}, {2}, and {1, 2}.  
// The empty set is also a subsequence of the array.
// The input array will not contain duplicate elements.
// The order of the subsequences in the output does not matter.
//  The solution to the problem is to use recursion. We will use a recursive function that will take the current index, the array, and the current subsequence as input.
// The function will have two recursive calls. In the first call, we will include the current element in the subsequence, and in the second call, we will not include the current element in the subsequence.
// The base case of the recursion will be when the current index is equal to the size of the array. In this case, we will print the subsequence and return.
// The time complexity of the solution is O(2^n), where n is the number of elements in the array. This is because for each element, we have two choices: either include it in the subsequence or not include it.
// The space complexity of the solution is O(n), where n is the number of elements in the array. This is because the recursion stack can have at most n elements.
// The following is the implementation of the above approach:(full implementation done by me)
#include<iostream>
#include<vector>
using namespace std;

void f(int idx, int arr[], vector<int> &ds, int n) {
    if (idx == n) {
        for (auto it : ds) {
            cout << it << " ";
        }
        if (ds.size() == 0)     
        {
            cout<<"{}"<<" "; //printing empty set 
        }
        
        cout << endl;
        return; // Return after printing the subsequence
    }
    // pick condition 
    ds.push_back(arr[idx]);
    f(idx + 1, arr, ds, n);
    ds.pop_back();
    // non-pick condition
    f(idx + 1, arr, ds, n);
}

int main() {
    int arr[] = {1, 2, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ds;
    f(0, arr, ds, n);
    return 0;
}
