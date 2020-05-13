/*
Combinations
Problem Description
Given two integers A and B, return all possible combinations of B numbers out of 1 2 3 ... A . Make sure the combinations are sorted. To elaborate,
Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING COMBINATIONS.   


Problem Constraints
1 <= A, B <= 10


Input Format
First argument is an integer A.
Second argument is an integer B.


Output Format
Return a 2-D vector denoting all possible combinations.


Example Input
A = 4
B = 2


Example Output
[
[1, 2],
[1, 3],
[1, 4],
[2, 3],
[2, 4],
[3, 4],
]


Example Explanation
All the possible combinations of size 2 in sorted order.

Intuition:
This problem as same as the finding all the subsets from a given array with just added two condition 1. Elements will be from 1 to A and size of each subset will be B. 
In subset problem we have two to choices to for each element. They are we can add to subset or not add to subset. We start first element and we can add or we ignore and we keep doing it until our subset size matches with B or we left with no elements. 

Initial Step - Create one array of size A with elements in increasing order till A. Like A = 4 then [1,2,3,4] as array.

Added Base Condition - subset.size()==B 
*/
void getCombination(vector<int>& numbers,int index,int B,vector<int> subset,vector<vector<int>> &result)
{
    if(subset.size()==B)
    {
        result.push_back(subset);
        return;
    }
    if(index==numbers.size())
    {
        return;
    }
    subset.push_back(numbers[index]);
    getCombination(numbers,index+1,B,subset,result);
    subset.pop_back();
    getCombination(numbers,index+1,B,subset,result);
}

vector<vector<int> > Solution::combine(int A, int B) {
    vector<int> numbers(A,0);
    for(int i=1;i<=A;i++)
    {
        numbers[i-1] = i;
    }
    vector<vector<int> >  result;
    getCombination(numbers,0,B,{},result);
    return result;
    
}
