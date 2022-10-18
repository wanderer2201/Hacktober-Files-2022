#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxSum(int arr[], int n, int k) {
    if (n < k) {
        cout << "Invalid";
        return -1;
    }

    //sum of first window of size k
    int window_sum = 0;
    for (int i = 0; i < k; i++)
        window_sum += arr[i];

    int max_sum = window_sum;
    for (int i = k; i < n; i++) {
        window_sum += (arr[i] - arr[i - k]);
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main(){
    int n = 5 , k = 3;;
    int arr[] = { 20,14,91,19,13,8};
    cout << maxSum(arr, n, k);
    return 0;
}
