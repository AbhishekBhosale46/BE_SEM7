#include<bits/stdc++.h>
using namespace std;

/*
Time Complexity : O(n)
Space Complexity : O(1)
*/
int fiboIterative(int n){
    if(n<=1){
        return n;
    }
    int prev1=0, prev2=1, result=0;
    for(int i=2; i<=n; i++){
        result = prev1+prev2;
        prev1 = prev2;
        prev2 = result;
    }
    return result;
}

/*
Time Complexity : O(2^n)
Space Complexity : O(n)
*/
int fiboRecursive(int n){
    if(n<=1){
        return n;
    }
    return fiboRecursive(n-1) + fiboRecursive(n-2);
}

int main(){

    int num;
    cout<<"Enter a number : ";
    cin>>num;

    cout<<"Fibonacci (Iterative) of "<<num<<" : "<<fiboIterative(num)<<endl;
    cout<<"Fibonacci (Recursive) of "<<num<<" : "<<fiboRecursive(num)<<endl;

    return 0;
}