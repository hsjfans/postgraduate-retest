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
                    nums2.erase(nums2.end()-1);
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

int consecutiveNumbersSum(int N) {
      
        int i=2,num = 1;
        int sum = 0,a;
        
        while(i*i + i <= 2*N){
            if(N%i == 0 && i%2 != 0) num ++; 
            else{
              a = N/i;
              sum = i * (a - (i-1)/2) + (i-1)*i/2;
              if(sum == N) num++;
            }  
            i++;
        }
        return num;
    }

   int numTeams(vector<int>& rating) {
        if(rating.size() <= 2) return 0;
        int res = 0,m ,n;
        for(int i=1;i<rating.size()-1;i++){
            m = n = 0;
            for(int j=2;j<rating.size();j++){
                if(rating[j] > rating[i]){
                    m++;
                }
            }
            for(int k=0;k<i;k++){
                if(rating[k] < rating[i]){
                    n++;
                }
            }
            res += m*n + (rating.size()-i-1-m) * (i-n);
        }
        return res;
    }

 int distance(string a,string b,int n){
        int sum = b[0] - a[0];
        for(int i=1;i<n;i++){
            sum = sum * 26 + b[i]- a[i];
        }
        return sum;
    }
    
    int findGoodStrings(int n, string s1, string s2, string evil) {
        int sum = distance(s1,s2,n);
        
        // 减去 前缀为 evil 的数量
        for(int i=0;i+evil.size() <= n;i++){
            if(evil < s1.substr(i,evil.size()) || evil > s2.substr(i,evil.size())){
                continue;
            }else{
                sum  -= distance(s1.substr(i,evil.size()),evil,evil.size())*pow(26,(n-evil.size()));
                // sum  -= distance(evil,s2.substr(i,evil.size()),evil.size())*pow(26,(n-evil.size()));
            }
        }
      
        return sum;
    }

   string add(string a,string b){
        string res;
        int next =0,l1 = a.size(),l2 = b.size(),len = l2,c;
        if(l2 > l1){
            len = l1;
            l1 = l2;
            l2 = len;
            res = a;
            a = b;
            b = res;
            res = "";
        }
        while(len > 0){
            c = a[l1-1]-'0' + b[len-1]-'0' + next;
            res = to_string(c%10) + res;
            next = c/10;
            l1 --;
            len --;
        }               
        while(l1 > 0){
            c = a[l1-1] -'0' + next;
            res = to_string(c%10) + res;
            next = c/10;
            l1 --;
        }
        if(next > 0) res = to_string(next) + res;
        return res;
    }
    
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if(len < 3 ) return false;
        int n = (len-1)/2;
        string a,b;
        int k,flag = 0;
        string res;
        for(int i =1;i <= n;i++){
            if(i>1 && num[0] == '0') return false;
            for(int j=1;j<=n;j++){
                if(j > 1 && num[i] == '0') break;
                flag = 1;
                a = num.substr(0,i);
                b = num.substr(i,j);
                k = i + j;
                if(k >= len) flag = 0;
                while(k < len){
                    res = add(a,b);
                    if((res.size() > 1 && num[k] =='0')||  res.size() > len - k || res != num.substr(k,res.size())) {
                        flag = 0;break;
                    }
                    a = b;
                    b = res;
                    k += res.size();
                }
                if(flag) return true;
            }
        }
        return false;
    }

    bool isMatch(string s, string p) {
        if(p == ".*") return true;
        int l1 = s.size(),l2 = p.size();
        int i =0, j = 0;
        char a , b, prev = '0';
        while(i < l1 && j < l2){
            a = s[i];
            b = p[j];
            if(a == b || b == '.'){
                i ++;
                j ++;
                prev = b;
            }else if(b!='*'){
                prev = b;
                b = p[++j];
                if(b == '*') j++;
                else return false;
            }else{
                if(prev != a) j++;
                else i++; 
            }
        }  
        if( i == l1 && j < l2 ) return isMatch(s.substr(l1-1,1),p.substr(j+1,l2-j-1)); 
        return i==l1 && j==l2;
    }

        

    int main(){
        
        cout << isMatch("aaa","a*ab*");
        return 0;
    }