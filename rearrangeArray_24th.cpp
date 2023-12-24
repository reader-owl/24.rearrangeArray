#include <iostream>

/*
                        Q.  Rearrange array elements by sign

                    explanation -  arr[] = {3, 1, -2, -5, 2, -4}
                                    by rearranging  arr[] = {3, -2, 1, -5, 2, -4}

                                    we will always be given an array with equal nmbrs of positive and negative elements
                                    in random order
                                    means length of array is 'n' then  'n/2' positive elements and 'n/2' negative elements
                                    length of the array will always be even
                                    we have to arrange it alternate order of sign (positive, negative, positive, negative, ...)

                sol - Brute force -  we will take 2 list or array  -> pos - {}
                                                                      neg - {}
                                        then iterate through entire array, and put individual elements to their
                                        respective (positive or negative) array
                                     then put the all the elements to the main array, all positive nmbr in even indexes and
                                     negative nmbr in odd indexes

        Pseudo code
for(i=0; i<n/2; i++)
{
    arr[2*i] = pos[i]
    arr[2*i+1] = neg[i]
}

                TC - O(N) + O(N/2)
                    
                SC - O(N)


                Optimal sol -  we know all the positive elements will be in '0' & even index place  and all the negatives will 
                                be in odd index's place
                               to do this we take 1st positive element and place it in 0th index, then we take 2nd positive element
                               and place it in next available even index, then take next positive element and place in next available
                               even index and so on ...
                               then we take 1st negative element and place it in 1st index, then we take 2nd negative element
                               and place it in next available odd index, then take next negative element and place in next available
                               odd index and so on ...
                                we are doing this in new array so
                                                TC - O(N)
                                                SC - O(N)

        Actual code
vector<int> rearrangeArray(vector<int> & nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);              // size of ans
    int posIndex = 0, negIndex = 1;

    for(int i = 0; i < n; i++)
    {
        if(nums[i] < 0)                 // if num in the array is negative
        {
            ans[negIndex] = nums[i];    // 1st negative nmbr
            negIndex += 2;              // next negative nmbrs
        }
        else
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }
    return ans;
}
*/


/*
                        Q. Variety 2 -  when positives and negatives are in unequal length

                    explanation - Start the array with a positive nmbr.
                                  If any of the positive and negative nmbrs are left, add them at the end without
                                  altering the order.

                            if given array -  arr[] = {1, 2, -4, -5, 3, 6}
                                      desired array = {1, -4, 2, -5, 3, 6}

                Brute force -  given array   arr[] = {-1, 2, 3, 4, -3, 1}
                                             pos[] -> {2, 3, 4, 1}
                                             neg[] -> {-1, -3}
                                from pos and neg arrays we know for sure is that in the ams array we can feed alternate
                                 elements upto 4 indexes and then we can feed the remaining positive elements

        Pseudo code
for(i=0; i<2; i++)
{
    arr[i*2] = pos[i]
    arr[i*2 + 1] = neg[i]
}

// loop for remaining positive arrays
ind = 4
for(i=2; i<pos.size(); i++) 
{
    arr[ind] = pos[i]
    ind++;
}


        Actual code
vector<int> alternateNumbers(vector<int> &a)
{
    vector<int> pos, neg;
    int n = a.size();
    for(int i = 0; i < n; i++)
    {
        if(a[i] > 0)
        {
            pos.push_back(a[i]);
        }
        else
        {
            neg.push_back(a[i]);
        }
    }

    if(pos.size() > neg.size())
    {
        for(int i = 0; i < neg.size(); i++)
        {
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i = neg.size(); i < pos.size(); i++)
        {
            a[index] = pos[i];
            index++;
        }
    }
    else
    {
        for(int i = 0; i < pos.size(); i++)
        {
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i = pos.size(); i < neg.size(); i++)
        {
            a[index] = neg[i];
            index++;
        }
    }
    return a;
}


                TC - O(N) + O(min(pos, neg)) + O(leftovers)
                           if O(min(pos, neg)) -> O(0), then O(leftover) -> O(N)
                           if O(min(pos, neg)) -> O(N/2), then O(leftover) -> O(0)
                   - O(2N)
                SC - O(N)
*/

int main()
{
    std::cout << "Hello World!\n";
}