/*
Delete one
Problem Description
Given an integer array A of size N. You have to delete one element such that the GCD(Greatest common divisor) of the remaining array is maximum.

Find the maximum value of GCD.


Problem Constraints
2 <= N <= 105
1 <= A[i] <= 109


Input Format
First argument is an integer array A.


Output Format
Return an integer denoting the maximum value of GCD.


Example Input
Input 1:
 A = [12, 15, 18]
Input 2:
 A = [5, 15, 30]
 


Example Output
Output 1:
 6
Output 2:
 15
 


Example Explanation
Explanation 1:
 
 If you delete 12, gcd will be 3.
 If you delete 15, gcd will be 6.
 If you delete 18, gcd will 3.
 Maximum vallue of gcd is 6.
Explanation 2:
 If you delete 5, gcd will be 15.
 If you delete 15, gcd will be 5.
 If you delete 30, gcd will be 5.
*/

typedef long long int ll;
int Solution::solve(vector<int> &A) {
    ll* gcdleft = new ll[A.size()];
    ll* gcdright = new ll[A.size()];
    ll len = A.size();
    gcdleft[0] = A[0];
    gcdright[len-1] = A[len-1];
    for(ll i=1,j=len-2;i<len;i++,j--)
    {
        gcdleft[i] = __gcd(gcdleft[i-1],(ll)A[i]);
        gcdright[j] = __gcd(gcdright[j+1],(ll)A[j]);
    }
    ll maxgcd = INT_MIN;
    for(int i=0;i<len;i++)
    {
       if(i==0) maxgcd = max(maxgcd,gcdright[i+1]);
       else if(i==len-1) maxgcd = max(maxgcd,gcdleft[i-1]);
       else
       {
           ll gcdleftright = __gcd(gcdleft[i-1],gcdright[i+1]);
           maxgcd = max(maxgcd,gcdleftright);
       }
    }
    return maxgcd;
}

