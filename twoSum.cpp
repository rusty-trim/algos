#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int i = 0;
    map<int, int> lookup;

    for(; i < nums.size(); i++)
    {
        if(lookup.find(nums[i]) != lookup.end())
            return {lookup[nums[i]], i};

        lookup[target - nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> nums = {1, 6, 2, 5, 3, 4};
    int target = 6;

    vector<int> ans = twoSum(nums, target);

    printf("{%d, %d}\n", ans[0], ans[1]);
}
