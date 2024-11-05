#include<bits/stdc++.h>
using namespace std;

int knapsack(int indx, int maxWeight, vector<int> weight, vector<int> value, vector<vector<int>> &dp){

    if(indx==0){
        if(weight[indx]<=maxWeight){
            return value[indx];
        }
        return 0;
    }

    if(dp[indx][maxWeight]!=-1){
        return dp[indx][maxWeight];
    }

    int notPick = knapsack(indx-1, maxWeight, weight, value, dp);
    int pick = INT_MIN;
    if(weight[indx]<=maxWeight){
        pick = value[indx] + knapsack(indx-1, maxWeight-weight[indx], weight, value, dp);
    }

    return dp[indx][maxWeight] = max(pick, notPick);

}

int main(){

    int n = 4;
    int W = 7; 

    vector<int> weight = {2, 3, 4, 5};
    vector<int> value = {40, 50, 70, 80};

    vector<vector<int>> dp(1000, vector<int>(1000, -1));

    int maxProfit = knapsack(n-1, W, weight, value, dp);

    cout << "Maximum profit using DP with Memoization: " << maxProfit << endl;

    return 0;
}