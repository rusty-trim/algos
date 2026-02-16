#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
    vector<vector<int>> result;
    vector<int> quad;

  private:
    void kSum(vector<int> &nums, int k, int start, long long target)
    {
        if (nums.size() - start < k)
            return;

        if (k == 2)
        {
            int l = start;
            int r = nums.size() - 1;

            while (l < r)
            {
                long long sum = (long long)nums[l] + nums[r];

                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else
                {
                    vector<int> temp = quad;
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    result.push_back(temp);

                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1])
                        l++;
                    while (l < r && nums[r] == nums[r + 1])
                        r--;
                }
            }
        }
        else
        {
            for (int i = start; i <= nums.size() - k; i++)
            {
                if (i > start && nums[i] == nums[i - 1])
                    continue;

                quad.push_back(nums[i]);
                kSum(nums, k - 1, i + 1, target - nums[i]);
                quad.pop_back();
            }
        }
    }

  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        kSum(nums, 4, 0, target);
        return result;
    }
};

int main()
{
    auto vecToStr = [](const vector<int> &v) -> string {
        string s = "[";
        for (size_t i = 0; i < v.size(); i++)
        {
            s += to_string(v[i]);
            if (i + 1 < v.size())
                s += ", ";
        }
        s += "]";
        return s;
    };

    auto quadsToStr = [&](vector<vector<int>> quads) -> string {
        // Sort quads and each quad for stable printing/comparison
        for (auto &q : quads)
            sort(q.begin(), q.end());
        sort(quads.begin(), quads.end());

        string s = "[";
        for (size_t i = 0; i < quads.size(); i++)
        {
            s += vecToStr(quads[i]);
            if (i + 1 < quads.size())
                s += ", ";
        }
        s += "]";
        return s;
    };

    auto runTest = [&](int testNum, vector<int> nums, int target, const string &label) {
        cout << "=============================\n";
        cout << "Test " << testNum << ": " << label << "\n";
        cout << "Input nums   = " << vecToStr(nums) << "\n";
        cout << "Target       = " << target << "\n";

        vector<int> numsCopy = nums; // preserve original view in case you want it later
        Solution sol;
        auto ans = sol.fourSum(numsCopy, target);

        cout << "Output count = " << ans.size() << "\n";
        cout << "Quadruplets  = " << quadsToStr(ans) << "\n";
        cout << "Note         = (quadruplets sorted for display)\n";
    };

    int t = 1;

    // 1) Classic example (LeetCode 18)
    runTest(t++, {1, 0, -1, 0, -2, 2}, 0, "Classic example with duplicates");

    // 2) Empty input
    runTest(t++, {}, 0, "Empty array");

    // 3) Fewer than 4 elements
    runTest(t++, {1, 2, 3}, 6, "Array size < 4 (no solutions)");

    // 4) Exactly 4 elements - single solution
    runTest(t++, {2, 2, 2, 2}, 8, "Exactly 4 elements, all same, one solution");

    // 5) Exactly 4 elements - no solution
    runTest(t++, {2, 2, 2, 2}, 7, "Exactly 4 elements, all same, no solution");

    // 6) Many duplicates -> should return unique quadruplets
    runTest(t++, {0, 0, 0, 0, 0, 0, 0}, 0, "All zeros, many duplicates (unique result expected)");

    // 7) Negative-heavy + duplicates
    runTest(t++, {-3, -1, -1, 0, 1, 2, 2, 3}, 0, "Mix of negatives/positives with duplicates");

    // 8) Large magnitude values to exercise long long sums (avoid overflow)
    runTest(t++, {1000000000, 1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000, -1000000000},
            0, "Large magnitude values (checks overflow safety)");

    // 9) No possible solutions (sorted + two-pointer should quickly fail)
    runTest(t++, {5, 5, 5, 5, 5, 5}, 1, "No solutions with all positives and small target");

    // 10) Mixed values, multiple solutions
    runTest(t++, {-2, -1, -1, 1, 1, 2, 2}, 0, "Multiple solutions possible, duplicates present");

    cout << "=============================\n";
    cout << "Done.\n";
    return 0;
}
