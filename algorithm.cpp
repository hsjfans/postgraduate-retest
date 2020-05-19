#include "./pat.h"

using namespace std;

void pat_1001()
{
    int n;
    cin >> n;
    int step = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = (3 * n + 1) / 2;
        step++;
    }

    cout << step << endl;
}

int partition(vector<int> &nums, int left, int right)
{
    int i = left, j = right, target = nums[left];
    while (i < j)
    {
        while (i < j && nums[j] >= target)
            j--;
        nums[i] = nums[j];
        while (i < j && nums[i] <= target)
            i++;
        nums[j] = nums[i];
    }
    nums[i] = target;
    return i;
}

void sort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int idx = partition(nums, left, right);
    sort(nums, left, idx - 1);
    sort(nums, idx + 1, right);
}

void merge(vector<int> &nums, int l, int mid, int r)
{
    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (nums[i] <= nums[j])
        {
            tmp.push_back(nums[i]);
            i++;
        }
        else
        {
            tmp.push_back(nums[j]);
            j++;
        }
    }

    while (i <= mid)
        tmp.push_back(nums[i++]);
    while (j <= r)
        tmp.push_back(nums[j++]);
    int idx = 0;
    while (l <= r)
        nums[l++] = tmp[idx++];
}

void merge_sort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;
    int mid = (left + right) / 2;
    merge_sort(nums, left, mid);
    merge_sort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void count(vector<int> nums, int target, int n)
{
    vector<int> dp(target + 1, n + 1);
    dp[0] = 0;
    for (int num : nums)
    {
        for (int i = target; i >= num; i--)
        {
            dp[i] = min(dp[i], dp[i - num] + 1);
        }
    }
    if (dp[target] == n + 1)
        cout << 0;
    else
        cout << dp[target];
}

int main()
{
    int n, target, tmp;
    cin >> target >> n;
    vector<int> nums(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        nums[i] = tmp;
    }
    count(nums, target, n);
    return 0;
}