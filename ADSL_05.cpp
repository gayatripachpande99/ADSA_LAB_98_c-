/*Implement a problem of maximizing Profit by trading stocks based on given rate per day.
Statement: Given an array arr[] of N positive integers which denotes the cost of selling 
and buying stock on each of the N days. The task is to find the maximum profit that can be 
earned by buying a stock on or selling all previously bought stocks on a particular day.*/
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int arr[], int n) {
    int profit = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i-1]) {
            profit += arr[i] - arr[i-1];
        }
    }
    return profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int arr[n];
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum Profit = " << maxProfit(arr, n);
    return 0;
}
