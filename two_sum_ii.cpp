#include <vector>
#include <stdio.h>

using namespace std;

vector<int> two_sum(vector<int> &numbers, int target)
{
    int l = 0;
    int r = numbers.size() - 1;

    while(l < r)
    {
        if(numbers[l] + numbers[r] < target)
            l++;
        else if(numbers[l] + numbers[r] > target)
            r--;
        else
            return {l + 1, r + 1};
    }

    return {};
}

int main()
{
    vector<int> numbers = {1, 5, 6, 8};

    vector<int> ans = two_sum(numbers, 11);

    printf("[%d, %d]\n", ans[0], ans[1]);
}
