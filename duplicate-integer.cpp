#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

bool hasDuplicate(vector<int> &nums)
{
    int i = 0;
    unordered_map<int, int> hash;
    
    for(i = 0; i < nums.size(); i++)
    {
        if(hash.find(nums[i]) != hash.end())
            return true;

        hash[nums[i]] = i;
    }

    return false;
}

int main()
{
    int i = 0;
    vector<int> nums;

    srand(time(NULL));

    for(i = 0; i < 5; i++)
    {
        nums.push_back(rand() % 10);
    }

    printf("Checking duplicate for numbers: {%d, %d, %d, %d, %d}\n", nums[0], nums[1], nums[2], nums[3], nums[4]);
    printf("Duplicate %s\n", hasDuplicate(nums) ? "found" : "not found");
}
