/*
Number of Digit One
Problem Description
Given an integer A, find and return the total number of digit 1 appearing in all non-negative integers less than or equal to A.


Problem Constraints
0 <= A <= 109


Input Format
The only argument given is the integer A.


Output Format
Return the total number of digit 1 appearing in all non-negative integers less than or equal to A.


Example Input
Input 1:
 A = 10
Input 2:
 A = 11


Example Output
Output 1:
 2
Output 2:
 4


Example Explanation
Explanation 1:
Digit 1 appears in 1 and 10 only and appears one time in each. So the answer is 2.
Explanation 2:
Digit 1 appears in 1(1 time) , 10(1 time) and 11(2 times) only. So the answer is 4.

Intuition:
Unit Place: 
For n = 10 it is 1
For n = 20 it is 2
For n = 30 it is 3
For n = 40 it is 4
For n = 50 it is 5
For n = 60 it is 6
For n = 63 it is 7 
For n = 70 it is 7 
We get for unit place by n/10 + (n%10!=0) 
so for 63 it is 63/10 + (63%10!=0) = 6 + 1 = 7
10th Place:
For n = 100 it is 10
For n = 200 it is 20
For n = 300 it is 30
.
.
.
.
For n = 1600 it is 160
For n = 1610 it is 161
For n = 161x it is 161+x (x is at unit place count of 1's)
We get for 10th place by (N/100)*10 + min(max(N%10-10+1,0),10) here 10 indicates 10th places

From above equation we can get for 100,1000,10000 and so. 
*/
int Solution::solve(int A) {
    long long int ans  = 0;
    for(int i=1;i<=A;i*=10)
    {
        int divider = i*10;
        ans += (A/divider)*i + min(max(A%divider-i+1,0),i);
    }
    return ans;
}

