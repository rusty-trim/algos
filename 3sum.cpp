#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

vector<vector<int>> three_sum(vector<int> &nums)
{
    int i = 0,
        l = 0,
        r = 0;

    int target = 0;

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        target = -nums[i];
        l = i + 1;
        r = nums.size() - 1;

        while (l < r)
        {
            if (nums[l] + nums[r] < target)
                l++;
            else if (nums[l] + nums[r] > target)
                r--;
            else
            {
                result.push_back({nums[i], nums[l], nums[r]});

                l++;
                while (l < r && nums[l] == nums[l - 1])
                    l++;

                r--;
                while (l < r && nums[r] == nums[r + 1])
                    r--;
            }
        }
    }

    return result;
}

int main()
{
    int i = 0;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = three_sum(nums);

    printf("Triplet sets that add up to equal zero are:\n");

    for (; i < result.size(); i++)
    {
        printf("{%d, %d, %d}\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}
