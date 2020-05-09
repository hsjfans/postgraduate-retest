#include "pat.h"
#include <cmath>
using namespace std;

// 复旦上机题

void exec_a()
{
    int a[5], sum = 0, i = 0;
    while (i < 5)
    {
        cin >> a[i];
        sum += a[i];
        i++;
    }

    int leave = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            leave = a[i] + a[j];
            if ((sum - leave) % 10 == 0)
            {
                cout << leave % 10 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

// 斗牛
void fudan_a()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        exec_a();
    }
}

void dadishu()
{
    int n, d;
    cin >> n >> d;
    int nums[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // 排序
    sort(nums, nums + n);

    // dp 问题
    // 代表以 nums[i] 结尾的最大上升序列
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    // 动态规划
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] - nums[j] >= d)
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    cout << dp[n - 1] << endl;
}

// void e_seq(){
//     int n;
//     cin >> n;
//     int nums[n];
//     for(int i=0;i<n;i++) cin >> nums[i];
//     if(n == 1) {
//         cout << 0 << endl;
//         return;
//     }
//     int weight = 0;
//     int nx,nx_1,idx = n-1;
//     for(int i=9; i>=0 && 2*i-nums[n-1] >=0; i--){
//         nx = i,nx_1 = 2*nx-nums[idx];
//         weight = abs(nx-nums[idx]) + abs(nx_1-nums[idx-1]) + pow((nx-nx_1),2);
//         idx--;
//     }

// }
int mergeStones(vector<int> &stones, int K)
{
    // 哈夫曼树
    int n = stones.size();
    if ((n - 1) % (K - 1) != 0)
        return -1;
    int ans = 0;
    while (stones.size() >= K)
    {
        int idx = K - 1, sum = 0, cur = 0;
        for (int i = 0; i < stones.size(); i++)
        {
            if (i < K)
            {
                sum += stones[i];
                cur = sum;
            }
            else
            {
                sum += (stones[i] - stones[i - K]);
                if (cur > sum)
                {
                    cur = sum;
                    idx = i;
                }
            }
        }
        ans += sum;
        stones[idx] = cur;
        stones.erase(stones.begin() + idx - K + 1, stones.begin() + idx);
    }
    return ans;
}
int main()
{
    // fudan_a();
    // e_seq();
    vector<int> ans{3,5,1,2,6};
    cout << mergeStones(ans, 3);
    return 0;
}