#include "pat.h"
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int maps[m][n];
    fill(maps[0], maps[0] + m * n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                maps[i][j] = 0;
            else
            {
                if (i == 0 && j == 0)
                    maps[i][j] = 1;
                else if (i == 0)
                    maps[i][j] = maps[i][j - 1];
                else if (j == 0)
                    maps[i][j] = maps[i - 1][j];
                else
                    maps[i][j] = maps[i - 1][j] + maps[i][j - 1];
            }
        }
    }
    return maps[m - 1][n - 1];
}

int uniquePaths(int m, int n)
{
    int maps[m + 1][n + 1];
    fill(maps[0], maps[0] + (m + 1) * (n + 1), 0);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || j == 1)
                maps[i][j] = 1;
            else
            {
                maps[i][j] = maps[i - 1][j] + maps[i][j - 1];
            }
        }
    }
    return maps[m][n];
}

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else if (i == 0)
                grid[i][j] += grid[i][j - 1];
            else if (j == 0)
                grid[i][j] += grid[i - 1][j];
            else
                grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
        }
    }
    return grid[m - 1][n - 1];
}

int minDistance(string word1, string word2)
{

    int m = word1.size(), n = word2.size();
    if (m * n == 0)
        return m + n;
    int d[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
        d[i][0] = i;
    for (int j = 0; j < n + 1; j++)
        d[0][j] = j;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            int left = d[i - 1][j] + 1;
            int down = d[i][j - 1] + 1;
            int left_down = d[i - 1][j - 1];
            if (word1.at(i - 1) != word2.at(j - 1))
            {
                left_down += 1;
            }
            d[i][j] = 1 + min(left_down, min(left, down));
        }
    }
    return d[m][n];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n <= 1)
        return 0;
    int first = 0, next = 0, res = 0, less = prices[0];
    int dp[n][2];
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(prices[i] - less, dp[i - 1][0]);
        less = min(less, prices[i]);
        if (prices[i] >= prices[i - 1])
            res += (prices[i] - prices[i - 1]);
        else
        {
            if (res >= first)
            {
                next = first;
                first = res;
            }
            else if (res > next)
                next = res;
            res = 0;
        }
        dp[i][1] = next + first;
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}

struct trie
{
    vector<int> index;
    int value;
    struct trie *next[256];
};

trie *build()
{
    trie *node = new trie();
    node->value = -1;
    for (int i = 0; i < 256; i++)
        node->next[i] = nullptr;
    return node;
}

// search the index of word1
vector<int> search(trie *root, string word1)
{
    int len = word1.size();
    trie *p = root;
    for (int i = 0; i < len; i++)
    {
        p = p->next[word1[i] - 'A'];
    }
    return p->index;
}

// insert
void insert(trie *root, string word1, int index)
{
    int len = word1.size();
    trie *p = root;
    for (int i = 0; i < len; i++)
    {
        if (p->next[word1[i] - 'A'] == nullptr)
        {
            trie *node = build();
            node->value = word1[i] - 'A';
            p->next[word1[i] - 'A'] = node;
        }
        p = p->next[word1[i] - 'A'];
    }
    p->index.push_back(index);
}

int findClosest(vector<string> &words, string word1, string word2)
{

    // 主要是字符串匹配的开销，这里可以采用 字典树 来优化
    trie *root = build();

    int len = words.size();
    for (int i = 0; i < len; i++)
    {
        insert(root, words[i], i);
    }

    vector<int> index1 = search(root, word1);
    vector<int> index2 = search(root, word2);
    int res = 0x7fffffff;

    int len1 = index1.size(), len2 = index2.size();
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {

        if (index1[i] > index2[j])
        {
            res = min(res, abs(index1[i] - index2[j]));
            j++;
        }
        else
        {
            res = min(res, abs(index1[i] - index2[j]));
            i++;
        }
    }
    return res;
}

class Node
{
public:
    char c;
    map<char, Node> next;
    int end;
    Node(char c)
    {
        this->c = c;
        this->end = 0;
    }
    Node(){};
};

class Trie
{
public:
    Node root;

    /** Initialize your data structure here. */
    Trie()
    {
        root = Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *p = &root;
        for (char c : word)
        {
            if (p->next.find(c) == p->next.end())
            {
                p->next[c] = Node(c);
            }
            p = &(p->next[c]);
        }
        p->end = 1;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *p = &root;
        for (char c : word)
        {
            if (p->next.find(c) == p->next.end())
                return false;
            p = &(p->next[c]);
        }
        return p->end == 1;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *p = &root;
        for (char c : prefix)
        {
            if (p->next.find(c) == p->next.end())
                return false;
            p = &(p->next[c]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

static bool cmp(string a, string b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    else
        return a < b;
}

bool isCombine(map<string, int> &maps, string str, int less, bool origin)
{
    if (str.size() < less)
        return false;
    if (maps.count(str) > 0 && !origin)
        return true;
    for (int i = less; i <= str.size() - less; i++)
    {
        if (maps.count(str.substr(0, i)) > 0 && isCombine(maps, str.substr(i, str.size() - i), less, false))
            return true;
    }
    return false;
}

string longestWord(vector<string> &words)
{
    if (words.size() < 2)
        return "";
    map<string, int> maps;
    int len = words.size();
    for (int i = 0; i < len; i++)
        maps[words[i]] = 1;
    sort(words.begin(), words.end(), cmp);
    int less = words[len - 1].size();
    for (int i = 0; i < len - 1; i++)
    {
        string word = words[i];
        if (word.size() < less * 2)
            return "";
        if (isCombine(maps, word, less, true))
        {
            return word;
        }
    }
    return "";
}

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBST(TreeNode *root)
{
    TreeNode *p = root;
    stack<TreeNode *> s;
    TreeNode *prev = NULL, *next = NULL;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            p = p->left;
        }

        p = s.top();
        s.pop();
        prev = next;
        next = p;
        if (prev && next && (prev->val > next->val))
        {
            return false;
        }
        p = p->right;
    }
    return true;
}

void recoverTree(TreeNode *root)
{
    TreeNode *p = root;
    stack<TreeNode *> s;
    TreeNode *first = NULL, *prev = NULL, *second = NULL;
    bool invalid = false;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        if (prev && (prev->val >= p->val))
        {
            if (first == NULL)
                first = prev;
        }
        else if (prev && (prev->val < p->val) && first)
        {
            second = prev;
            break;
        }
        prev = p;
        p = p->right;
    }
    if (second == NULL)
        second = prev;
    int tmp = second->val;
    second->val = first->val;
    first->val = tmp;
}

int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
{
    if (reservedSeats.size() == 0)
        return 2 * n;
    map<string, int> maps;
    int res = 0, len = reservedSeats.size();
    for (int i = 0; i < len; i++)
    {
        maps[to_string(reservedSeats[i][0]) + "_" + to_string(reservedSeats[i][1])] = 1;
    }
    int nums[3] = {2, 4, 6};
    for (int i = 1; i <= n; i++)
    {
        int t1 = 0, t2 = 0;
        for (int j = 0; j < 3; j++)
        {
            int sum = 0;
            for (int k = 0; k < 4; k++)
            {
                if (maps.count(to_string(i) + "_" + to_string(j)) > 0)
                {
                    sum++;
                    break;
                }
            }
            if (sum == 0)
            {
                if (j == 0 || j == 2)
                    t2++;
                else
                    t1++;
            }
        }
        res += max(t1, t2);
    }
    return res;
}

bool solve(vector<double> nums)
{
    if (nums.size() == 0)
        return false;
    if (nums.size() == 1)
        return abs(nums[0] - 24) < 1e-6;

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
            {
                vector<double> nums2;
                for (int k = 0; k < nums.size(); k++)
                    if (k != i && k != j)
                    {
                        nums2.push_back(nums[k]);
                    }
                for (int k = 0; k < 4; k++)
                {
                    if (k < 2 && j > i)
                        continue;
                    if (k == 0)
                        nums2.push_back(nums[i] + nums[j]);
                    if (k == 1)
                        nums2.push_back(nums[i] * nums[j]);
                    if (k == 2)
                        nums2.push_back(nums[i] - nums[j]);
                    if (k == 3)
                    {
                        if (nums[j] != 0)
                        {
                            nums2.push_back(nums[i] / nums[j]);
                        }
                        else
                        {
                            continue;
                        }
                    }
                    if (solve(nums2))
                        return true;
                    nums2.erase(nums2.end() - 1);
                }
            }
        }
    }
    return false;
}

bool judgePoint24(vector<int> &nums)
{
    vector<double> nums2;
    for (int i = 0; i < nums.size(); i++)
        nums2.push_back((double)nums[i]);
    return solve(nums2);
}

int consecutiveNumbersSum(int N)
{

    int i = 2, num = 1;
    int sum = 0, a;

    while (i * i + i <= 2 * N)
    {
        if (N % i == 0 && i % 2 != 0)
            num++;
        else
        {
            a = N / i;
            sum = i * (a - (i - 1) / 2) + (i - 1) * i / 2;
            if (sum == N)
                num++;
        }
        i++;
    }
    return num;
}

int numTeams(vector<int> &rating)
{
    if (rating.size() <= 2)
        return 0;
    int res = 0, m, n;
    for (int i = 1; i < rating.size() - 1; i++)
    {
        m = n = 0;
        for (int j = 2; j < rating.size(); j++)
        {
            if (rating[j] > rating[i])
            {
                m++;
            }
        }
        for (int k = 0; k < i; k++)
        {
            if (rating[k] < rating[i])
            {
                n++;
            }
        }
        res += m * n + (rating.size() - i - 1 - m) * (i - n);
    }
    return res;
}

int distance(string a, string b, int n)
{
    int sum = b[0] - a[0];
    for (int i = 1; i < n; i++)
    {
        sum = sum * 26 + b[i] - a[i];
    }
    return sum;
}

int findGoodStrings(int n, string s1, string s2, string evil)
{
    int sum = distance(s1, s2, n);

    // 减去 前缀为 evil 的数量
    for (int i = 0; i + evil.size() <= n; i++)
    {
        if (evil < s1.substr(i, evil.size()) || evil > s2.substr(i, evil.size()))
        {
            continue;
        }
        else
        {
            sum -= distance(s1.substr(i, evil.size()), evil, evil.size()) * pow(26, (n - evil.size()));
            // sum  -= distance(evil,s2.substr(i,evil.size()),evil.size())*pow(26,(n-evil.size()));
        }
    }

    return sum;
}

string add(string a, string b)
{
    string res;
    int next = 0, l1 = a.size(), l2 = b.size(), len = l2, c;
    if (l2 > l1)
    {
        len = l1;
        l1 = l2;
        l2 = len;
        res = a;
        a = b;
        b = res;
        res = "";
    }
    while (len > 0)
    {
        c = a[l1 - 1] - '0' + b[len - 1] - '0' + next;
        res = to_string(c % 10) + res;
        next = c / 10;
        l1--;
        len--;
    }
    while (l1 > 0)
    {
        c = a[l1 - 1] - '0' + next;
        res = to_string(c % 10) + res;
        next = c / 10;
        l1--;
    }
    if (next > 0)
        res = to_string(next) + res;
    return res;
}

bool isAdditiveNumber(string num)
{
    int len = num.size();
    if (len < 3)
        return false;
    int n = (len - 1) / 2;
    string a, b;
    int k, flag = 0;
    string res;
    for (int i = 1; i <= n; i++)
    {
        if (i > 1 && num[0] == '0')
            return false;
        for (int j = 1; j <= n; j++)
        {
            if (j > 1 && num[i] == '0')
                break;
            flag = 1;
            a = num.substr(0, i);
            b = num.substr(i, j);
            k = i + j;
            if (k >= len)
                flag = 0;
            while (k < len)
            {
                res = add(a, b);
                if ((res.size() > 1 && num[k] == '0') || res.size() > len - k || res != num.substr(k, res.size()))
                {
                    flag = 0;
                    break;
                }
                a = b;
                b = res;
                k += res.size();
            }
            if (flag)
                return true;
        }
    }
    return false;
}

bool isMatch(string s, string p)
{
    if (p == ".*")
        return true;
    int l1 = s.size(), l2 = p.size();
    int i = 0, j = 0;
    char a, b, prev = '0';
    while (i < l1 && j < l2)
    {
        a = s[i];
        b = p[j];
        if (a == b || b == '.')
        {
            i++;
            j++;
            prev = b;
        }
        else if (b != '*')
        {
            prev = b;
            b = p[++j];
            if (b == '*')
                j++;
            else
                return false;
        }
        else
        {
            if (prev != a)
                j++;
            else
                i++;
        }
    }
    if (i == l1 && j < l2)
        return isMatch(s.substr(l1 - 1, 1), p.substr(j + 1, l2 - j - 1));
    return i == l1 && j == l2;
}

int minDepth(TreeNode *root)
{
    stack<TreeNode *> s;
    int res = 0;
    TreeNode *tmp = nullptr;
    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if (root->right && tmp != root->right)
        {
            root = root->right;
            s.push(root);
            root = root->left;
        }
        else
        {
            s.pop();
            tmp = root;
            if (!root->left && !root->right)
            {
                if (res == 0 || res > s.size())
                    res = s.size();
            }
            root = root->right;
        }
    }
    return res;
}

void flatten(TreeNode *root)
{
    TreeNode *prev = root, *p = root;
    stack<TreeNode *> s;
    vector<TreeNode *> nodes;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            nodes.push_back(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        p = p->right;
    }

    for (int i = 1; i < nodes.size(); i++)
    {
        p = nodes[i];
        prev->left = nullptr;
        prev->right = p;
        prev = p;
    }
    p->left = nullptr;
    return;
}

int lengthOfLongestSubstring(string s)
{
    int dict[256];
    fill(dict, dict + 256, -1);
    int res = 0, len = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (dict[s[i]] > len)
        {
            len = i;
        }
        res = max(res, i - len);
        dict[s[i]] = i;
    }
    return res;
}

int sumNumbers(TreeNode *root)
{
    if (!root)
        return 0;
    stack<TreeNode *> s;
    int res = 0, sum = 0;
    TreeNode *r = NULL;
    while (root || !s.empty())
    {
        while (root)
        {
            sum = sum * 10 + root->val;
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if (root->right && root->right != r)
        {
            root = root->right;
        }
        else
        {
            if (!root->left && !root->right)
            {
                res += sum;
            }
            s.pop();
            r = root;
            sum = (sum - root->val) / 10;
            root = NULL;
        }
    }
    return res;
}

typedef struct trieNode
{
    int count;
    map<char, trieNode> next;
} TrieNode;

void insert(TrieNode *root, string str)
{
    TrieNode *p = root;
    for (int i = 0; i < str.size(); i++)
    {
        if (p->next.count(str[i]) == 0)
        {
            p->next[str[i]] = trieNode();
        }
        p->next[str[i]].count++;
        p = &(p->next[str[i]]);
    }
}

string longestCommonPrefix(vector<string> &strs)
{
    TrieNode *root = new trieNode();
    for (auto str : strs)
    {
        root->count++;
        if (str.size() == 0)
            return "";
        insert(root, str);
    }
    string res;
    char key;
    while (root->next.size() == 1)
    {
        for (auto &p : root->next)
        {
            key = p.first;
        }
        if (root->next[key].count == strs.size())
            res = res + key;
        else
            return res;
        root = &(root->next[key]);
    }
    return res;
}

// bool canFinish(int numCourses, vector<vector<int> >& prerequisites) {
//     vector<int> d(numCourses,0);
//     vector<int> v[numCourses];
//     int x,y;
//     for(int i=0;i<prerequisites.size();i++){
//        x = prerequisites[i][0], y = prerequisites[i][1];
//        d[y] ++;
//        v[x].push_back(y);
//     }
//     int point = -1,k = numCourses,ds = 0;
//     while(k > 0){
//         point = -1;
//         // 找到 拓扑排序的起点
//         for(int i = 0;i<numCourses;i++){
//             if(d[i] == 0){
//                 ds ++;
//                 point = i;
//                 d[i] = -1;
//                 break;
//             }
//         }
//         if(point == -1 && k > 1 ) return false;
//         // 去掉 顶点 point
//         for(int i=0;i < v[point].size();i++){
//             y = v[point][i];
//             d[y]--;
//         }
//         v[point].clear();
//         k--;
//     }
//     return ds == numCourses;
// }

// bfs
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{

    vector<int> v[numCourses];
    vector<int> d(numCourses, 0);
    vector<int> k(numCourses, 0);
    int x, y;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        x = prerequisites[i][0], y = prerequisites[i][1];
        v[x].push_back(y);
        d[y]++;
    }
    int flag = 0;
    for (int i = 0; i < numCourses; i++)
    {
        if (d[i] == 0)
        {
            stack<int> s;
            vector<int> visited(numCourses, 0);
            s.push(i);
            visited[i] = 1;
            while (!s.empty())
            {
                int t = s.top();
                flag = 0;
                for (int j = k[t]; j < v[t].size(); j++)
                {
                    if (visited[v[t][j]] == 0)
                    {
                        s.push(v[t][j]);
                        visited[v[t][j]] = 1;
                        flag = 1;
                        k[t]++;
                        break;
                    }
                    else
                        return false;
                }
                if (!flag)
                    s.pop();
            }
        }
    }
    return true;
}

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    int res = -1, city = 0;
    int curCity = 0;
    int visited[n], t, w, cur, num, p, min_id;
    // fill(v[0],v[0]+n*n,0);
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < edges.size(); i++)
    {
        v[edges[i][0]][edges[i][1]] = edges[i][2];
        v[edges[i][1]][edges[i][0]] = edges[i][2];
    }

    // dijkstra
    for (int i = 0; i < n; i++)
    {
        curCity = 0;
        vector<int> dis(n, 0x7fffffff);
        fill(visited, visited + n, 0);
        cur = i;
        visited[cur] = 1;
        dis[cur] = 0;
        num = 0;
        while (num < n)
        {
            p = 0x7fffffff;
            min_id = -1;
            for (int j = 0; j < n; j++)
            {
                if (!visited[j] && v[cur][j] > 0)
                {
                    w = dis[cur] + v[cur][j];
                    dis[j] = min(w, dis[j]);
                    // if(dis[j] < distanceThreshold)
                    //     curCity ++;
                }
                if (!visited[j] && dis[j] < p)
                {
                    p = dis[j];
                    min_id = j;
                }
            }
            if (min_id != -1)
            {
                num++;
                cur = min_id;
                visited[cur] = 1;
            }
            else
                break;
        }
        for (int j = 0; j < n; j++)
        {
            if (j != i && dis[j] <= distanceThreshold)
                curCity++;
        }
        if (res == -1 || curCity <= city)
        {
            city = curCity, res = i;
        }
    }
    return res;
}

bool isPalindrome(string str)
{
    if (str.size() == 0)
        return false;
    int i = 0, j = str.size() - 1;
    while (i <= j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool canConstruct(string s, int k)
{
    if (k == 1)
        return isPalindrome(s);
    for (int i = 1; i < s.size(); i++)
    {
        if (k >= 2 && isPalindrome(s.substr(0, i)) && canConstruct(s.substr(i, s.size() - i), k - 1))
            return true;
    }
    return false;
}

int maxSatisfaction(vector<int> &satisfaction)
{
    int cur = 0, res = 0, i = 0, step = 0;
    sort(satisfaction.begin(), satisfaction.end());
    for (; i < satisfaction.size() && satisfaction[i] < 0; i++)
    {
    };
    for (int k = i; k < satisfaction.size(); k++)
    {
        cur += (k - i + 1) * satisfaction[k];
        step += satisfaction[k];
    }
    res = cur;
    for (int k = i - 1; k >= 0; k--)
    {
        step += satisfaction[k];
        cur = step + cur;
        if (res < cur)
            res = cur;
        else
            break;
    }
    return res;
}

string add_1(string s)
{
    int next = 1, len = s.size();
    string res = "0";
    for (int i = len - 2; i >= 0; i--)
    {
        res = to_string((s[i] - '0' + next) % 2) + res;
        next = (s[i] - '0' + next) / 2;
    }
    if (next != 0)
        res = to_string(next) + res;
    return res;
}

int numSteps(string s)
{
    int len;
    int step = 0;
    while (s != "1")
    {
        len = s.size();
        if (s[len - 1] == '0')
        {
            s = s.substr(0, len - 1);
        }
        else
        {
            s = add_1(s);
        }
        step++;
    }

    return step;
}

string stoneGameIII(vector<int> &stoneValue)
{
    int sum_a = 0, sum_b = 0;

    int i = 0, len = stoneValue.size();
    int cur_a, k, res_a, j;
    while (i < len)
    {
        cur_a = 0, res_a = stoneValue[i];
        for (j = i; j < len && j < i + 3; j++)
        {
            cur_a += stoneValue[j];
            if (cur_a >= res_a)
            {
                res_a = cur_a;
                k = j;
            }
        }
        sum_a += res_a;
        i = k + 1;
        if (i < len)
        {
            cur_a = 0, res_a = stoneValue[i];
            for (j = i; j < len && j < i + 3; j++)
            {
                cur_a += stoneValue[j];
                if (cur_a >= res_a)
                {
                    res_a = cur_a;
                    k = j;
                }
            }
            sum_b += res_a;
            i = k + 1;
        }
    }

    if (sum_a > sum_b)
        return "Alice";
    else if (sum_a == sum_b)
        return "Tie";
    else
        return "Bob";
}

string generate(int a, int b, int c, char aa, char bb, char cc)
{
    if (a < b)
    {
        return generate(b, a, c, bb, aa, cc);
    }
    if (a < c)
    {
        return generate(c, b, a, cc, bb, aa);
    }
    if (b < c)
    {
        return generate(a, c, b, aa, cc, bb);
    }

    if (b == 0)
    {
        string res;
        res.append(min(2, a), aa);
        return res;
    }
    string left, right;
    int use_a = min(2, a);
    int use_b = a - use_a >= b ? 1 : 0;
    left.append(use_a, aa);
    right.append(use_b, bb);
    return left + right + generate(a - use_a, b - use_b, c, aa, bb, cc);
}

string longestDiverseString(int a, int b, int c)
{
    return generate(a, b, c, 'a', 'b', 'c');
}
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int x = n / 2, p;
    for (int i = 0; i < x; i++)
    {
        for (int j = i; j < n - i - 1; j++)
        {
            p = matrix[i][j];
            matrix[i][j] = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
            matrix[j][n - 1 - i] = p;
        }
    }
    return;
}

int numDistinct(string s, string t)
{

    if (s.size() < t.size())
        return 0;
    else if (s.size() == t.size())
        return s == t ? 1 : 0;
    int l1 = s.size(), l2 = t.size();
    int size, idx, c, res = 0;
    for (int i = 0; i <= l1 - l2; i++)
    {
        // bfs
        if (s[i] == t[0])
        {
            queue<int> q;
            q.push(i);
            idx = 0;
            while (!q.empty() && idx < l2)
            {
                size = q.size();
                if (idx == l2 - 1)
                {
                    res += size;
                    break;
                }
                idx++;
                for (int j = 0; j < size; j++)
                {
                    c = q.front();
                    q.pop();
                    for (int k = c + 1; k < l1; k++)
                    {
                        if (s[k] == t[idx])
                        {
                            q.push(k);
                        }
                    }
                }
            }
        }
    }
    return res;
}

// dfs
int dfs(vector<vector<int>> &matrix, vector<vector<int>> &visited, int x, int y, int m, int n)
{
    //  if(x < 0 || x >= m || y < 0 || y >= n) return;
    visited[x][y] = 1;
    int dx[4] = {-1, 1, 0, 0}, x1, y1;
    for (int k = 0; k < 4; k++)
    {
        x1 = dx[k] + x;
        y1 = dx[(k + 2) % 4] + y;
        if (x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && !visited[x1][y1] && matrix[x][y] < matrix[x1][y1])
        {
            return dfs(matrix, visited, x1, y1, m, n) + 1;
        }
    }
    return 1;
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int len = matrix.size();
    if (len == 0)
        return 0;
    int n = matrix[0].size();
    vector<vector<int>> visited(len, vector<int>(n, 0));
    // dfs
    int res = 0;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < n; j++)
            res = max(res, dfs(matrix, visited, i, j, len, n));
    return res;
}

int superEggDrop(int K, int N)
{
    int step = 0;
    while (K > 1)
    {
        step++;
        K--;
        N = (N - 1) / 2;
    }
    return step + N;
}

vector<string> getValidT9Words(string num, vector<string> &words)
{
    map<char, int> maps;
    int step = 2, i, j;
    for (i = 0; i < 25; i += 3)
    {
        for (j = 0; j < 3; j++)
        {
            maps[i + j + 'a'] = step;
        }
        if (step == 7 || step == 9)
        {
            maps[i + j + 'a'] = step;
            i++;
        }
        step++;
    }
    int flag = 1;
    vector<string> res;
    for (i = 0; i < words.size(); i++)
    {
        flag = 1;
        for (j = 0; j < words[i].size(); j++)
        {
            // cout << maps[words[i][j]] << " " << (num[i] - '0') << endl;
            if (maps[words[i][j]] != (num[i] - '0'))
                flag = 0;
        }
        if (flag)
            res.push_back(words[i]);
    }
    return res;
}

bool robot(string command, vector<vector<int>> &obstacles, int x, int y)
{
    int m = obstacles.size(), a, b;
    vector<int> t1{0, 1};
    vector<int> t2{1, 0};
    map<char, vector<int>> maps;
    maps['U'] = t1, maps['R'] = t2;
    int oa = 0, ob = 0;
    for (int i = 0; i < command.size(); i++)
    {
        oa += maps[command[i]][0];
        ob += maps[command[i]][1];
    }
    map<int, map<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        a = obstacles[i][0] / oa, b = obstacles[i][1] / ob;
        if (a == b)
            v[a * oa][b * ob] = 1;
    }
    a = b = 0;
    while (a + oa <= x && b + ob <= y)
    {
        a += oa;
        b += ob;
        // 是否存在障碍
        if (v[a][b] == 1)
            return false;
    }
    if (a + oa == x && b + ob == y)
        return true;
    else
    {
        for (int i = 0; i < command.size(); i++)
        {
            a += maps[command[i]][0];
            b += maps[command[i]][1];
            if (v[a][b] == 1)
                return false;
            else if (a == x && y == b)
                return true;
        }
        return false;
    }
}

int sumRootToLeaf(TreeNode *root)
{
    stack<TreeNode *> s;
    TreeNode *prev = NULL;
    int num = 0, cur = 0;
    while (root || !s.empty())
    {
        while (root)
        {
            s.push(root);
            cur = (cur << 1) + root->val;
            root = root->left;
        }
        root = s.top();
        if (root->right && root->right != prev)
            root = root->right;
        else
        {
            num += cur;
            s.pop();
            cur = cur >> 1;
            prev = root;
            root = NULL;
        }
    }
    return num;
}

struct Point
{
    int idx, left, right;
};

int videoStitching(vector<vector<int>> &clips, int T)
{
    int n = clips.size();
    // 先排序
    sort(clips.begin(), clips.end());

    if (clips[0][0] != 0)
        return -1;

    // bfs
    queue<Point> q;
    q.push(Point{-1, 101, 0});
    int size, res = 0, r, l;
    while (!q.empty())
    {
        size = q.size();
        for (int i = 0; i < size; i++)
        {
            Point p = q.front();
            q.pop();
            if (p.left == 0 && p.right >= T)
                return res;
            for (int j = p.idx + 1; j < n; j++)
            {
                if (p.right >= clips[j][0])
                {
                    l = min(p.left, clips[j][0]);
                    r = max(p.right, clips[j][1]);
                    if (l <= 0)
                        q.push(Point{j, l, r});
                }
            }
        }
        res++;
    }
    return -1;
}
struct Point1
{
    int idx;
    vector<int> re;
};

static bool cmp_get(Point1 p1, Point1 p2)
{
    if (p1.re[0] != p2.re[0])
        return p1.re[0] < p2.re[0];
    else if (p1.re[1] != p2.re[1])
        return p1.re[1] < p2.re[1];
    else
        return p1.re[2] < p2.re[2];
}

vector<int> getTriggerTime(vector<vector<int>> &increase, vector<vector<int>> &requirements)
{
    // 每一步更新即可
    vector<int> steps(3, 0);
    int n = requirements.size();
    Point1 p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].idx = i;
        p[i].re = requirements[i];
    }
    // 难在如何比较
    vector<int> res(n, -1);
    sort(p, p + n, cmp_get);
    int cur = 0, tmp = 0;
    for (int i = 0; i <= increase.size(); i++)
    {
        if (i != 0)
        {
            for (int j = 0; j < 3; j++)
                steps[j] += increase[i - 1][j];
        }
        tmp = cur;
        for (int k = cur; k < n; k++)
        {
            if (steps[0] >= p[k].re[0] && steps[1] >= p[k].re[1] && steps[2] >= p[k].re[2])
            {
                res[p[k].idx] = i;
                tmp = k + 1;
            }
        }
        cur = tmp;
    }

    return res;
}

int merge(vector<int> &nums, int l1, int r1, int l2, int r2)
{
    vector<int> tmp;
    int ans = 0;
    int i = l1, j = l2;
    while (i <= r1 && j <= r2)
    {
        if (nums[i] > nums[j])
        {
            tmp.push_back(nums[j++]);
            ans += (r1 - i + 1);
        }
        else
            tmp.push_back(nums[i++]);
    }
    while (i <= r1)
        tmp.push_back(nums[i++]);
    while (j <= r2)
        tmp.push_back(nums[j++]);
    for (i = l1; i <= r1; i++)
        nums[i] = tmp[i - l1];
    for (i = l2; i <= r2; i++)
        nums[i] = tmp[r1 - l1 + i - l2 + 1];
    return ans;
}

int merge_sort(vector<int> &nums, int left, int right)
{
    if (left >= right)
        return 0;
    int mid = (left + right) / 2;
    int l = merge_sort(nums, left, mid);
    int r = merge_sort(nums, mid + 1, right);
    return l + r + merge(nums, left, mid, mid + 1, right);
}

int reversePairs(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return 0;
    int res = 0;
    return merge_sort(nums, 0, n - 1);
}

struct Item
{
    int start, end, val, m;
    int g;
};

int minTime(vector<int> &time, int m)
{
    int n = time.size();
    if (n <= m)
        return 0;
    queue<Item> q;
    int val = 0, t = time[0];
    for (int i = 0; i < n; i++)
    {
        if (t < time[i])
            t = time[i];
        val += time[i];
        q.push(Item{0, i, val - t, 1, val - t});
    }
    int res = 0x7fffffff, size = 0;

    while (!q.empty())
    {
        size = q.size();
        for (int j = 0; j < size; j++)
        {
            Item it = q.front();
            q.pop();
            if (it.end == n - 1 && it.m <= m)
            {
                res = min(res, it.g);
            }
            else if (it.val > res || it.m >= m)
                continue;
            t = 0;
            val = 0;
            for (int i = it.end + 1; i < n; i++)
            {
                t = max(t, time[i]);
                val += time[i];
                q.push(Item{it.end + 1, i, val - t, it.m + 1, max(val - t, it.val)});
            }
        }
    }
    return res == 0x7fffffff ? 0 : res;
}

int maxSumDivThree(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(3, 0));
    // dp[0][0] = dp[0][1] = dp[0][2] = 0;
    int p = nums[0] % 3;
    dp[0][p] = nums[0];
    for (int i = 1; i < n; i++)
    {
        p = nums[i] % 3;
        if (p == 0)
        {
            dp[i][0] = dp[i - 1][0] + nums[i];
            if (dp[i][1] > 0)
                if (dp[i][2] > 0)
                    dp[i][2] += nums[i];
        }
        else if (p == 1)
        {
            dp[i][0] = dp[i - 1][2] > 0 ? max(dp[i - 1][0], dp[i - 1][2] + nums[i]) : dp[i - 1][0];
            dp[i][1] = max(dp[i - 1][0] + nums[i], dp[i - 1][1]);
            dp[i][2] = dp[i - 1][1] > 0 ? max(dp[i - 1][2], dp[i - 1][1] + nums[i]) : dp[i - 1][2];
        }
        else
        {
            dp[i][0] = dp[i - 1][1] > 0 ? max(dp[i - 1][0], dp[i - 1][1] + nums[i]) : dp[i - 1][0];
            dp[i][1] = dp[i - 1][2] > 0 ? max(dp[i - 1][1], dp[i - 1][2] + nums[i]) : dp[i - 1][1];
            dp[i][2] = max(dp[i - 1][0] + nums[i], dp[i - 1][2]);
        }
    }

    return dp[n - 1][0];
}

string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    // 连通分量或者并查集
    vector<map<int, char>> v;
    int flag = 0;
    for (int i = 0; i < pairs.size(); i++)
    {
        flag = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].count(pairs[i][0]) == 1 || v[j].count(pairs[i][1]) == 1)
            {
                v[j][pairs[i][0]] = s[pairs[i][0]];
                v[j][pairs[i][1]] = s[pairs[i][1]];
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            map<int, char> maps;
            maps[pairs[i][0]] = s[pairs[i][0]];
            maps[pairs[i][1]] = s[pairs[i][1]];
            v.push_back(maps);
        }
    }

    for (int i = 0; i < v.size(); i++)
    {
        vector<char> cs;
        for (auto &p : v[i])
        {
            cs.push_back(p.second);
        }
        sort(cs.begin(), cs.end());
        int j = 0;
        for (auto &p : v[i])
        {
            s[p.first] = cs[j++];
        }
    }

    return s;
}

class MountainArray
{
public:
    vector<int> data;

    MountainArray(vector<int> &data)
    {
        this->data = data;
    }
    int get(int index)
    {
        return this->data[index];
    }
    int length()
    {
        return this->data.size();
    }
};

int findInMountain(int target, int left, int right, MountainArray &mountainArr)
{
    if (left > right)
        return -1;
    else if (left == right)
        return mountainArr.get(left) == target ? left : right;
    else
    {
        int mid = (left + right) / 2;
        if (mountainArr.get(mid) == target)
            return mid;
        else if (mountainArr.get(mid) > target)
        {
            int l = findInMountain(target, left, mid - 1, mountainArr);
            if (l != -1)
                return l;
            else
                return findInMountain(target, mid + 1, right, mountainArr);
        }
        else
        {
            if (mid - 1 >= left && mountainArr.get(mid - 1) > mountainArr.get(mid))
            {
                return findInMountain(target, left, mid - 1, mountainArr);
            }
            else if (mid + 1 <= right && mountainArr.get(mid + 1) > mountainArr.get(mid))
            {
                return findInMountain(target, mid + 1, right, mountainArr);
            }
            else if (mountainArr.get(left) == target)
                return left;
            else if (mountainArr.get(right) == target)
                return right;
            else
                return -1;
        }
    }
}

int findInMountainArray(int target, MountainArray &mountainArr)
{
    return findInMountain(target, 0, mountainArr.length() - 1, mountainArr);
}
string minWindow(string s, string t)
{
    unordered_map<char, int> need, windows;
    for (char c : t)
        need[c]++;
    int left = 0, right = 0, start = 0, n = s.size();
    int cur = n + 1;
    char c;
    int match = 0;
    while (right < n)
    {
        c = s[right];
        if (need.count(c))
        {
            windows[c]++;
            if (windows[c] == need[c])
                match++;
        }
        right++;
        while (match == need.size())
        {
            if (right - left < cur)
            {
                cur = right - left;
                start = left;
            }
            c = s[left];
            if (need.count(c))
            {
                windows[c]--;
                if (windows[c] < need[c])
                    match--;
            }
            left++;
        }
    }

    return cur == n + 1 ? "" : s.substr(start, cur);
}

bool isMatch(string s, int left, int right, string t)
{

    int m = t.size(), i = 0;
    while (left <= right && i < m)
    {
        if (s[left] == t[i])
            i++;
        left++;
    }

    return i == m;
}

/**
     * @param S: a string
     * @param T: a string
     * @return: the minimum substring of S
     */
string minWindow2(string s, string t)
{
    // Write your code here
    int left = 0, right = 0, start = 0, n = s.size(), cur = n + 1, m = t.size();
    while (right < n)
    {

        if (!isMatch(s, left, right, t))
            right++;
        else
        {
            if (right - left + 1 > cur)
            {
                cur = right - left + 1;
                start = left;
            }
            left++;
        }
    }

    return cur == n + 1 ? "" : s.substr(start, cur);
}

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 1)
        return n;
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    int ans = 1, res = n;
    int step = 0, cur = 0;
    for (int i = 1; i < n; i++)
    {
        step = 0;
        cur = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                if (dp[i] > cur)
                {
                    cur = dp[i];
                    step = 1;
                }
                else if (dp[i] = cur)
                    step++;
            }
        }
        if (cur == ans)
            res += step;
        else if (cur > ans)
        {
            ans = dp[i];
            res = step;
        }
    }

    return res;
}

int numberOfArithmeticSlices(vector<int> &A)
{
    int n = A.size();
    unordered_map<int, int> dp[n];
    int ans = 0, k;
    // for(int i=0;i<n;i++) dp[0][A[i]-A[0]] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            k = A[j] - A[i];
            dp[j][k] = (i == 0 ? dp[i][k] : 1) + 1;
            if (dp[j][k] >= 3)
                ans++;
        }
    }
    return ans;
}

string reverseVowels(string s)
{
    map<char, int> maps = {{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};
    int prev = -1;
    char c;
    for (int i = 0; i < s.size(); i++)
    {
        c = s[i];
        if (maps.count(c))
        {
            if (prev != -1)
            {
                s[i] = s[prev];
                s[prev] = c;
                prev = -1;
            }
            else
                prev = i;
        }
    }
    return s;
}

bool isBipartite(vector<vector<int>> &graph)
{

    // 着色 (color+1 )% 2
    int color = 0;
    int n = graph.size();
    // 初识化无颜色
    vector<int> colors(n, -1);
    // 这里采用 bfs 方案
    for (int i = 0; i < n; i++)
    {
        // 可能存在多个连通分量
        if (colors[i] == -1)
        {
            queue<int> q;
            // 初始着色为 0
            q.push(i);
            colors[i] = 0;
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                for (int j = 0; j < graph[t].size(); j++)
                {
                    // 还没有着色
                    if (colors[graph[t][j]] == -1)
                    {
                        colors[graph[t][j]] = (colors[t] + 1) % 2;
                        q.push(graph[t][j]);
                    }
                    // 以及着色而且与
                    else if (colors[graph[t][j]] == colors[t])
                        return false;
                }
            }
        }
    }

    return true;
}
bool hasCycle(vector<vector<int>> &v, int idx, vector<int> &localvisited)
{
    // 缓存
    // if(visited[idx]) return false;
    localvisited[idx] = 1;
    for (int i = 0; i < v[idx].size(); i++)
    {
        if (localvisited[v[idx][i]])
            return true;
        else if (hasCycle(v, v[idx][i], localvisited))
            return true;
    }
    // visited[idx] = 1;
    return false;
}

bool canFinish2(int numCourses, vector<vector<int>> &prerequisites)
{

    // 拓扑排序
    // 采用邻接表表示有向图
    vector<vector<int>> v;
    for (int i = 0; i < numCourses; i++)
        v.push_back({});

    for (int i = 0; i < prerequisites.size(); i++)
        v[prerequisites[i][0]].push_back(prerequisites[i][1]);
    // 是否访问过
    // vector<int> visited(numCourses, 0);
    for (int i = 0; i < numCourses; i++)
    {
        vector<int> localvisited(numCourses, 0);
        if (hasCycle(v, i, localvisited))
            return false;
    }
    return true;
}

// dp 0-1 背包问题
void package(vector<int> &nums)
{
    int n = nums.size(), sum = 0;
    for (int num : nums)
        sum += num;
    int target = sum / 2;
    // 不能重复时
    vector<bool> dp(target + 1, 0);
    dp[0] = true;
    for (int num : nums)
    {
        for (int i = num; i <= target; i++)
        {
            dp[i] = dp[i] || dp[i - num];
        }
    }
    int b = 0;
    for (int i = target; i >= 0; i--)
    {
        if (dp[i])
        {
            b = i;
            break;
        }
    }
    printf("%d %d\n", b, sum - b);
}

int countTriplets(vector<int> &arr)
{

    int ans = 0, sum = arr[0];
    int n = arr.size();
    if (n < 3)
        return 0;
    vector<int> sums;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            sum = sum ^ arr[i];
        sums.push_back(sum);
    }
    int a, b;
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                a = (i == 0) ? sums[j - 1] : sums[i - 1] ^ sums[j - 1];
                b = sums[k] ^ sums[j - 1];
                // 2 3 1 6 7. i = 0  j =1 2
                // 0,1,2), (0,2,2), (2,3,4) 以及 (2,4,4)
                if (a == b)
                    ans++;
            }
        }
    }

    return ans;
}

int dis(map<int, vector<int>> &v, int node, vector<int> &visited, vector<bool> &hasApple)
{

    visited[node] = 1;
    int ans = 0, res = 0, flag = 0;
    for (int i = 0; i < v[node].size(); i++)
    {
        if (!visited[v[node][i]])
        {
            ans = dis(v, v[node][i], visited, hasApple);
            if (ans != -1)
            {
                res += ans + 2;
                flag = 1;
            }
        }
    }
    if (hasApple[node] && !flag)
        return 0;
    else if (!flag)
        return -1;
    else
        return res;
}

int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{

    map<int, vector<int>> v;
    for (vector<int> edge : edges)
    {
        v[edge[0]].push_back(edge[1]);
        v[edge[1]].push_back(edge[0]);
    }
    vector<int> visited(n, 0);
    int ans = dis(v, 0, visited, hasApple);
    return ans == -1 ? 0 : ans;
}

vector<string> printVertically(string s)
{

    vector<string> words;
    vector<string> ans;
    int prev = 0, len = 0;
    string tmp;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            tmp = s.substr(prev, i - prev);
            prev = i + 1;
            words.push_back(tmp);
        }
        else if (i + 1 == s.size())
        {
            tmp = s.substr(prev, i - prev + 1);
            words.push_back(tmp);
        }
        len = max((int)(tmp.size()), len);
    }

    for (int i = 0; i < len; i++)
    {
        string word;
        for (int j = 0; j < words.size(); j++)
        {
            if (words[j].size() <= i && word.size() > 0)
                word += ' ';
            else
                word += words[j][i];
        }
        int j = word.size() - 1;
        for (; j >= 0 && word[j] == ' '; j--)
        {
        }
        ans.push_back(word.substr(0, j + 1));
    }

    return ans;
}

int totalFruit(vector<int> &tree)
{

    int ans = 0, left = 0, right = -1, num1 = 1, num2 = 0;
    for (int i = 1; i < tree.size(); i++)
    {
        if (tree[i] == tree[left])
        {
            left = i;
            num1++;
        }
        else if (right == -1 || tree[i] == tree[right])
        {
            right = i;
            num2++;
        }
        else
        {
            ans = max(ans, num1 + num2);
            if (left < right)
            {
                num1 = right - left;
                left = right;
                right = i;
                num2 = 1;
            }
            else
            {
                num1 = 1;
                right = i;
                num2 = 1;
            }
        }
    }

    return ans = max(ans, num1 + num2);
}

int main()
{
    // vector<vector<int>> p{{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    // vector<bool> ans{false, false, false, false, false, false, false};
    // printVertically("CONTEST IS COMING");
    vector<int> ans{1,0,1,4,1,4,1,2,3};
    totalFruit(ans);
    return 0;
}
