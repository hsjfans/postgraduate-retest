#include "./pat.h"

using namespace std;

void pat_1001()
{

    int a, b;
    cin >> a >> b;
    string res = to_string(a + b);
    int k = 0, len = res.size();
    for (int i = 0; i < len; i++)
    {
        cout << res[i];
        if (res[i] == '-')
            continue;
        if ((i + 1) % 3 == len % 3 && i != len - 1)
            cout << ",";
    }
}

void pat_1002()
{
    float nums[1001] = {0.0};
    // int exists[1001] = {0};
    int sum = 0, i, j, k, nk;
    float ank;
    for (j = 0; j < 2; j++)
    {
        cin >> k;
        for (i = 0; i < k; i++)
        {
            cin >> nk >> ank;
            // if(exists[nk] == 0){
            //     sum++;
            //     exists[nk] = 1;
            // }
            nums[nk] += ank;
        }
    }
    for (i = 0; i <= 1000; i++)
    {
        if (nums[i] != 0.0)
            sum++;
    }
    cout << sum;
    for (i = 1000; i >= 0; i--)
    {
        if (nums[i])
            printf(" %d %.1f", i, nums[i]);
    }
}

void loop_print()
{

    int n, m, c1, c2, x, y, weight, i, j;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    // 邻接矩阵作为存储容器
    int roads[n][n], visited[n], cur;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
            roads[i][j] = -1;
    }
    // 有向有权图
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        cin >> weight;
        roads[x][y] = weight;
        // roads[y][x] = weight;
    }
    // 广度优先遍历
    queue<int> q;
    q.push(c1);
    visited[c1] = 1;
    while (!q.empty())
    {
        cur = q.front();
        printf(" %d", cur);
        q.pop();
        for (i = 0; i < n; i++)
        {
            if (i != cur && roads[cur][i] != -1 && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    cout << endl;
    // 深度优先遍历
    stack<int> s;
    s.push(c1);
    visited[c1] = 1;
    printf(" %d", c1);
    bool has = false;
    while (!s.empty())
    {
        cur = s.top();
        has = false;
        for (i = 0; i < n; i++)
        {
            if (i != cur && roads[cur][i] != -1 && !visited[i])
            {
                s.push(i);
                printf(" %d", i);
                has = true;
                visited[i] = 1;
                break;
            }
        }
        if (!has)
            s.pop();
    }
}

// 最短路径问题
void min_path()
{

    int n, m, c1, c2, x, y, weight, recure, i, j, min, min_id;
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    // 邻接矩阵作为存储容器
    int roads[n][n], visited[n], recures[n], weights[n], cur, recure_values[n], nums[n];
    for (i = 0; i < n; i++)
    {
        cin >> recures[i];
        visited[i] = 0;
        weights[i] = 0;
        nums[i] = 0;
        recure_values[i] = 0;
        for (j = 0; j < n; j++)
            roads[i][j] = -1;
    }
    // 有向有权图
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        cin >> weight;
        roads[x][y] = weight;
        roads[y][x] = weight;
    }

    // dijkstra 附体，单源最短路径问题
    // 本题是它的一个变形而已

    cur = c1;
    visited[cur] = 1;
    nums[cur] = 1;
    recure_values[cur] = recures[cur];
    int left = n;
    while (left > 0)
    {
        min = 0;
        for (i = 0; i < n; i++)
        {
            // update new value
            if (roads[cur][i] != -1 && !visited[i])
            {
                weight = weights[cur] + roads[cur][i];
                // handle the recure values
                recure = recure_values[cur] + recures[i];
                if (weight < weights[i] || weights[i] == 0)
                {
                    weights[i] = weight;
                    recure_values[i] = recure;
                    nums[i] = nums[cur];
                }
                else if (weights[i] == weight)
                {
                    // 相等怎么处理，一会再看，本题关键在这里，比较一下 对应的recures 值即可
                    // 更新 数量
                    nums[i] = nums[i] + nums[cur];
                    if (recure > recure_values[i])
                        recure_values[i] = recure;
                }
            }

            // find the min element of this loop
            if ((min == 0 || (min > weights[i] && weights[i] > 0)) && !visited[i])
            {
                min = weights[i];
                min_id = i;
            }
        }

        cur = min_id;
        visited[cur] = 1;
        left--;
        // // debug
        // for(j=0;j<n;j++) cout << weights[j] << " ";
        // cout << endl;
    }

    // cout << endl;
    // for(i=0;i<n;i++){
    //     if(i!=c1) printf("%d %d %d\n",c1,i,weights[i]);
    // }

    cout << nums[c2] << " " << recure_values[c2];
}

void pat_1003()
{
    min_path();
}

// the level loop of a tree
void pat_1004()
{
    // 树的层序遍历
    int n, m, i, j;
    cin >> n >> m;
    vector<int> nodes[100];
    int id, k, t;
    for (i = 0; i < m; i++)
    {
        cin >> id >> k;
        for (j = 0; j < k; j++)
        {
            cin >> t;
            nodes[id].push_back(t);
        }
    }

    int root = 1, level = 1, spare = 0, next_level;
    queue<int> q;
    q.push(root);
    bool flag = false;
    while (!q.empty())
    {
        spare = next_level = 0;
        for (i = 0; i < level; i++)
        {
            t = q.front();
            q.pop();
            if (nodes[t].size() == 0)
                spare++;
            else
            {
                for (j = 0; j < nodes[t].size(); j++)
                {
                    q.push(nodes[t][j]);
                    next_level++;
                }
            }
        }
        level = next_level;
        if (flag)
            cout << " ";
        else
            flag = true;
        cout << spare;
    }
}

void pat_1005()
{
    string codes[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string n;
    cin >> n;
    unsigned int i = 0, sum = 0;
    for (i = 0; i < n.size(); i++)
    {
        sum += n[i] - '0';
    }

    string p = to_string(sum);
    for (i = 0; i < p.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << codes[p[i] - '0'];
    }
}

void pat_1006()
{
    int n;
    cin >> n;
    int h, m, s, i;
    string id, first, last;
    int min = -1, max = -1, time;
    for (i = 0; i < n; i++)
    {
        cin >> id;
        scanf("%d:%d:%d", &h, &m, &s);
        time = (h * 60 + m) * 60 + s;
        if (min == -1 || min > time)
        {
            min = time;
            first = id;
        }
        scanf("%d:%d:%d", &h, &m, &s);
        time = (h * 60 + m) * 60 + s;
        if (max == -1 || max < time)
        {
            max = time;
            last = id;
        }
    }

    cout << first << " " << last;
}
void pat_1007()
{
    int n, i;
    cin >> n;
    int max = -1, sum = 0, first = 0, last = n - 1, sum_first = 0, nums[n];
    for (i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum = sum + nums[i];
        if (sum < 0)
        {
            sum = 0;
            sum_first = i + 1;
        }
        else if (sum > max)
        {
            last = i;
            max = sum;
            first = sum_first;
        }
    }

    printf("%d %d %d", max < 0 ? 0 : max, nums[first], nums[last]);
}

void pat_1008()
{
    int up = 6, down = 4, still = 5;
    // int maps[100] = {0};
    vector<int> floors;
    floors.push_back(0);
    int n, tmp, i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        floors.push_back(tmp);
    }
    int next = 1, offset, sum = 0;
    while (next < floors.size())
    {
        offset = floors[next] - floors[next - 1];
        if (offset > 0)
            sum += offset * up + still;
        else
            sum += offset * -1 * down + still;
        next++;
    }
    cout << sum;
}

void pat_1009()
{
    int n = 2, i, j, k, nk;
    float ank, sum[2001] = {0};
    float nums[2][1001] = {0};
    for (i = 0; i < n; i++)
    {
        cin >> k;
        for (j = 0; j < k; j++)
        {
            cin >> nk >> ank;
            nums[i][nk] = ank;
        }
    }
    int plot;
    float res;
    for (i = 0; i < 1001; i++)
    {
        for (j = 0; j < 1001 && nums[0][i] != 0; j++)
        {
            if (nums[1][j] != 0)
            {
                plot = i + j;
                res = nums[0][i] * nums[1][j];
                sum[plot] += res;
            }
        }
    }
    int count = 0;
    for (i = 0; i < 2001; i++)
    {
        if (sum[i] != 0)
            count++;
    }
    cout << count;
    for (i = 2000; i >= 0; i--)
    {
        if (sum[i] != 0)
            printf(" %d %.1f", i, sum[i]);
    }
}
int real_p(string a, int i)
{
    if (a[i] >= 'a' && a[i] <= 'z')
        return a[i] - 'a' + 10;
    else
        return a[i] - '0';
}

long long convert(string a, long long radix)
{
    long long sum = 0;
    int p;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        p = real_p(a, i);
        sum += p * pow(radix, (a.size() - 1 - i));
    }
    return sum;
}

int find_max(string b)
{
    int p, max = -1;
    for (int i = b.size() - 1; i >= 0; i--)
    {
        p = real_p(b, i);
        if (max < p)
            max = p;
    }
    return max++;
}

void pat_1010()
{
    char n1[10], n2[10];
    long long tag, radix;
    scanf("%s %s %lld %lld", n1, n2, &tag, &radix);
    long long sum1 = 0, sum2 = 0;
    string a, b;
    if (tag == 1)
    {
        a = n1;
        b = n2;
    }
    else
    {
        a = n2;
        b = n1;
    }
    sum1 = convert(a, radix);
    long long low = find_max(b);
    long long high = max(low, sum1), mid = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;
        sum2 = convert(b, mid);
        if (sum2 > sum1 || sum2 < 0)
            high = mid - 1;
        else if (sum1 == sum2)
        {
            cout << mid;
            return;
        }
        else
            low = mid + 1;
    }
    cout << "Impossible";
}

void pat_1011()
{
    int num = 3, i, j, max_id = 0;
    char codes[3] = {'W', 'T', 'L'};
    float max, cur = 0, sum = 1;
    for (i = 0; i < num; i++)
    {
        max = 0;
        for (j = 0; j < num; j++)
        {
            cin >> cur;
            if (max < cur)
            {
                max = cur;
                max_id = j;
            }
        }
        sum *= max;
        cout << codes[max_id] << " ";
    }
    printf("%.2f", (sum * 0.65 - 1) * 2);
}

void pat_1101()
{
    int n, tmp;
    cin >> n;
    int i, nums[n], checks[n];
    for (i = 0; i < n; i++)
    {
        cin >> nums[i];
        checks[i] = 0;
    }
    int max = nums[0];
    for (i = 0; i < n; i++)
    {
        if (max <= nums[i])
        {
            checks[i] = 1;
            max = nums[i];
        }
    }
    int min = nums[n - 1];
    for (i = n - 1; i >= 0; i--)
    {
        if (min < nums[i])
            checks[i] = 0;
        else
            min = nums[i];
    }
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        if (checks[i])
            sum++;
    }
    cout << sum << endl;
    if (sum == 0)
        cout << endl;
    else
    {
        bool flag = true;
        for (i = 0; i < n; i++)
        {
            if (checks[i])
            {
                if (!flag)
                    cout << " ";
                else
                    flag = false;
                cout << nums[i];
            }
        }
    }
}

/**
* 判断是否是增序还是降序
* 0 升 1 降 -1 无序
**/
int print_heap(int nums[], int i)
{
    bool up = false, down = false;
    int last = nums[i], j = i;
    stack<int> s;
    while (j != 0)
    {
        s.push(nums[j]);
        if (i != j)
        {
            if (nums[j] > last)
                down = true;
            else
                up = true;
        }
        last = nums[j];
        j = j / 2;
    }
    bool flag = true;
    while (!s.empty())
    {
        if (flag)
            flag = false;
        else
            cout << " ";
        cout << s.top();
        s.pop();
    }
    cout << endl;
    if (down && up)
        return -1;
    else if (down)
        return 1;
    else
        return 0;
}

void pat_1155()
{
    int n, num, k;
    cin >> n;
    k = ceil(log2(n + 1));
    int nums[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    num = pow(2, k) - 1;
    int offset = num - n, nextNum = pow(2, k - 1);
    int up = offset / 2, low = n - nextNum + 1, j;
    bool max = false, min = false, chaos = false;
    int res;
    for (int i = 0; i < up; i++)
    {
        res = print_heap(nums, n - i - low);
        if (!chaos)
        {
            if (res == -1)
                chaos = true;
            else if (res == 0 && !max)
                min = true;
            else if (res == 1 && !min)
                max = true;
            else
                chaos = true;
        }
    }
    for (int i = 0; i < low; i++)
    {
        res = print_heap(nums, n - i);
        if (!chaos)
        {
            if (res == -1)
                chaos = true;
            else if (res == 0 && !max)
                min = true;
            else if (res == 1 && !min)
                max = true;
            else
                chaos = true;
        }
    }
    if (chaos)
        cout << "Not Heap";
    else if (max)
        cout << "Max Heap";
    else
        cout << "Min Heap";
}

struct node
{
    int val;
    struct node *left, *right;
};

typedef struct node *Node, *Tree;

Node insert(int *inorders, int *preorders, int left1, int right1, int left2, int right2)
{
    if (left1 <= right1 && left2 <= right2)
    {
        Node n = new node();
        n->val = preorders[left1];
        int i, j = 0;
        for (i = left2; i <= right2 && inorders[i] != preorders[left1]; i++)
        {
            j++;
        }
        n->left = insert(inorders, preorders, left1 + 1, left1 + j, left2, i - 1);
        n->right = insert(inorders, preorders, left1 + j + 1, right1, i + 1, right2);
        return n;
    }
    return NULL;
}

void preprint(Node n)
{
    if (n)
    {
        cout << n->val << " ";
        preprint(n->left);
        preprint(n->right);
    }
}

void inorderprint(Node n)
{
    if (n)
    {
        inorderprint(n->left);
        cout << n->val << " ";
        inorderprint(n->right);
    }
}

void backorderprint(Node n)
{
    if (n)
    {
        backorderprint(n->left);
        backorderprint(n->right);
        cout << n->val << " ";
    }
}

void nocurisepreprint(Node n)
{
    stack<Node> s;
    Node p = n;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            cout << p->val << " ";
            p = p->left;
        }
        p = s.top();
        s.pop();
        p = p->right;
    }
}

void nocuriseinorderprint(Node n)
{
    stack<Node> s;
    Node p = n;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        cout << p->val << " ";
        p = p->right;
    }
}

void nocurisebackorderprint(Node n)
{
    stack<Node> s;
    Node p = n, r = NULL;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        if (p->right && p->right != r)
            p = p->right;
        else
        {
            s.pop();
            cout << p->val << " ";
            r = p;
            p = NULL;
        }
    }
}

// level print
void bfs(Node n)
{
    queue<Node> q;
    q.push(n);
    Node tmp;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        cout << tmp->val << " ";
        if (tmp->left)
            q.push(tmp->left);
        if (tmp->right)
            q.push(tmp->right);
    }
}

void dfs(Node n)
{
    vector<Node> s;
    Node p = n, r = NULL;
    int i;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push_back(p);
            p = p->left;
        }
        p = s.back();
        if (p->right && p->right != r)
            p = p->right;
        else
        {
            if (!p->right && !p->left)
            {
                for (i = 0; i < s.size(); i++)
                {
                    cout << s[i]->val << " ";
                }
                cout << endl;
            }
            s.pop_back();
            r = p;
            p = NULL;
        }
    }
}

void buildBinaryTree()
{
    int m, n, i;
    cin >> m >> n;
    int inorders[n], preorders[n];
    for (i = 0; i < n; i++)
        cin >> inorders[i];
    for (i = 0; i < n; i++)
        cin >> preorders[i];
    // 构建一棵二叉树
    Tree t = insert(inorders, preorders, 0, n - 1, 0, n - 1);
    Node p1 = t, p2 = t, p3 = t;
    inorderprint(p1);
    cout << endl;
    preprint(p2);
    cout << endl;
    backorderprint(p3);

    cout << endl;
    nocurisepreprint(t);
    // int n1,n2;
    cout << endl;
    nocuriseinorderprint(t);
    cout << endl;
    nocurisebackorderprint(t);

    cout << endl;
    bfs(t);

    cout << endl;
    dfs(t);
    // for(i=0;i<m;i++){
    //     cin >> n1 >> n2;
    //     // 然后分别查出给定的元素的轨迹，采用非递归先序遍历
    //     vector<Node> path1,path2;
    //     vector<Node> s;
    //     Node p = t;
    //     s.push_back(p);

    //     while(!s.empty()){
    //         Node tmp = s.back();

    //     }

    //     // 根据轨迹来分析

    // }
}

vector<Node> find_path(Tree t, int val)
{
    vector<Node> s;
    Node p = t, r = NULL;
    while (p || !s.empty())
    {
        while (p)
        {
            s.push_back(p);
            p = p->left;
        }
        p = s.back();
        if (p->right && p->right != r)
            p = p->right;
        else
        {
            if (p->val == val)
            {
                return s;
            }
            s.pop_back();
            r = p;
            p = NULL;
        }
    }
    return s;
}
map<int, int> pos;

void lca(int *inorders, int *preorders, int l1, int r1, int l2, int r2, int n1, int n2)
{
    if (l1 > r1)
        return;
    int pivot = pos[preorders[l1]] - 1, idx1 = pos[n1] - 1, idx2 = pos[n2] - 1;
    // 都在左边
    if (idx1 < pivot && idx2 < pivot)
        lca(inorders, preorders, l1 + 1, l1 + pivot - l2, l2, pivot - 1, n1, n2);
    // 都在右边
    else if (idx1 > pivot && idx2 > pivot)
        lca(inorders, preorders, l1 + pivot - l2 + 1, r1, pivot + 1, r2, n1, n2);
    // n1 在枢纽
    else if (idx1 == pivot)
        printf("%d is an ancestor of %d.\n", n1, n2);
    else if (idx2 == pivot)
        printf("%d is an ancestor of %d.\n", n2, n1);
    // 在两边
    else
        printf("LCA of %d and %d is %d.\n", n1, n2, inorders[pivot]);
}

void pat_1151()
{

    int m, n, i;
    cin >> m >> n;
    int inorders[n], preorders[n];
    for (i = 0; i < n; i++)
    {
        cin >> inorders[i];
        pos[inorders[i]] = i + 1;
    }
    for (i = 0; i < n; i++)
        cin >> preorders[i];
    int n1, n2;
    for (i = 0; i < m; i++)
    {
        cin >> n1 >> n2;
        if (pos[n1] == 0 && pos[n2] == 0)
            printf("ERROR: %d and %d are not found.\n", n1, n2);
        else if (pos[n1] == 0 || pos[n2] == 0)
            printf("ERROR: %d is not found.\n", pos[n1] == 0 ? n1 : n2);
        else
            lca(inorders, preorders, 0, n - 1, 0, n - 1, n1, n2);
    }
}

void pat_11552()
{
    vector<int> s;
    int n;
    cin >> n;
    int i, nums[n + 1];
    for (i = 1; i <= n; i++)
        cin >> nums[i];
    int p = 1, r = -1;
    while ((1 <= p && p <= n) || !s.empty())
    {
        while (1 <= p && p <= n)
        {
            s.push_back(p);
            p = p * 2 + 1;
        }
        p = s.back();

        // 左子树是否访问过？
        if (p * 2 <= n && p * 2 != r)
            p = p * 2;
        else
        {
            // is leaf
            if (p * 2 > n)
            {
                for (i = 0; i < s.size(); i++)
                {
                    if (i != 0)
                        cout << " ";
                    cout << nums[s[i]];
                }
                cout << endl;
            }
            s.pop_back();
            r = p;
            p = n + 1;
        }
    }

    bool max = true, min = true;
    for (i = 2; i <= n; i++)
    {
        if (nums[i] < nums[i / 2])
            min = false;
        else
            max = false;
    }
    if (max)
        cout << "Max Heap";
    else if (min)
        cout << "Min Heap";
    else
        cout << "No Heap";
}

void postorder(int *nums, int p, int n)
{
    if (p >= 1 && p <= n)
    {
        postorder(nums, p * 2, n);
        postorder(nums, p * 2 + 1, n);
        cout << nums[p];
        if (p != 1)
            cout << " ";
    }
}

void pat_1147()
{
    int m, n, i;
    cin >> m >> n;
    int j, nums[n + 1], res[n + 1];
    bool max, min;
    for (i = 0; i < m; i++)
    {
        max = true;
        min = true;
        cin >> nums[1];
        for (j = 2; j <= n; j++)
        {
            cin >> nums[j];
            if (nums[j] > nums[j / 2])
                max = false;
            else
                min = false;
        }
        if (max)
            cout << "Max Heap\n";
        else if (min)
            cout << "Min Heap\n";
        else
            cout << "Not Heap\n";
        postorder(nums, 1, n);
        cout << endl;
    }
}

map<int, int> maps;

// void lca(int *nums,int left,int right,int n1,int n2){
//     if(left > right) return;
//     int i;
//     // 找到分界线，这个怎么优化一下啊
//     for(i= left ;i<= right; i++)
//         if(nums[i] > nums[left]) break;
//     // 都在左子树上
//     if( n1 < nums[left] && n2 < nums[left] )
//        lca(nums,left+1,i-1,n1,n2);
//     // 都在右子树上
//     else if(n2 > nums[left] && n1 > nums[left])
//        lca(nums,i,right,n1,n2);
//     // 刚好在中枢
//     else if(n1 == nums[left] || n2 == nums[left]){
//         if(n1 == nums[left]) printf("%d is an ancestor of %d.\n",n1,n2);
//         else printf("%d is an ancestor of %d.\n",n2,n1);
//     }else printf("LCA of %d and %d is %d.\n",n1,n2,nums[left]);
// }

void pat_1143()
{

    int m, n, i, j;
    cin >> m >> n;
    int nums[n + 1];
    for (i = 1; i <= n; i++)
    {
        cin >> nums[i];
        maps[nums[i]] = i;
    }
    int n1, n2, a;
    for (i = 0; i < m; i++)
    {
        cin >> n1 >> n2;
        if (maps[n1] == 0 && maps[n2] == 0)
            printf("ERROR: %d and %d are not found.\n", n1, n2);
        else if (maps[n1] == 0)
            printf("ERROR: %d is not found.\n", n1);
        else if (maps[n2] == 0)
            printf("ERROR: %d is not found.\n", n2);
        else
        {
            for (j = 1; j <= n; j++)
            {
                a = nums[j];
                if ((a <= n1 && a >= n2) || (a >= n1 && a <= n2))
                    break;
            }
            if (a == n1)
                printf("%d is an ancestor of %d.\n", n1, n2);
            else if (a == n2)
                printf("%d is an ancestor of %d.\n", n2, n1);
            else
                printf("LCA of %d and %d is %d.\n", n1, n2, a);
        }
    }
}

void pat_1068()
{
    int n, m;
    cin >> n >> m;
    int i, nums[n], sum = 0;
    for (i = 0; i < n; i++)
        cin >> nums[i];
    // 排序
    sort(nums, nums + n);

    // 贪心算法
}

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    int k = sqrt(n);
    for (int i = 3; i <= k; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int real_int(int n, int d)
{
    string real;
    int k;
    while (n != 0)
    {
        k = n % d;
        real += to_string(k);
        n = n / d;
    }
    int sum = real.size() > 0 ? real[0] - '0' : 0;
    for (int i = 1; i < real.size(); i++)
    {
        sum = sum * d + (real[i] - '0');
    }
    return sum;
}

void pat_1015()
{
    int n, d, real, rev;
    cin >> n;
    while (n > 0)
    {
        cin >> d;
        real = n;
        rev = real_int(n, d);
        if (is_prime(real) && is_prime(rev))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cin >> n;
    }
}

bool isPalindromic(string str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i++] != str[j--])
            return false;
    }
    return true;
}

string getBaseNumber(int n, int b)
{
    if (n < b)
        return to_string(n);
    string res;
    int k;
    while (n > 0)
    {
        k = n % b;
        res = res + to_string(k);
        n = n / b;
    }
    return res;
}

void pat_1019()
{
    int n, b;
    cin >> n >> b;
    string res = getBaseNumber(n, b);
    if (isPalindromic(res))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    for (int i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
        if (i != 0)
            cout << " ";
    }
}

typedef struct customer
{
    int h, m, s, t;
    int seconds;
} Customer;

int Seconds(Customer c)
{
    return (c.h * 60 + c.m) * 60 + c.s;
}

int cmp_1017(Customer c1, Customer c2)
{
    return c1.seconds < c2.seconds;
}

void pat_1017()
{
    int n, k, wait = 0, num = 0;
    cin >> n >> k;
    Customer cus[n];
    int wins[k];
    int start = 8 * 60 * 60, end = 17 * 60 * 60;
    for (int i = 0; i < n; i++)
    {
        scanf("%d:%d:%d %d", &cus[i].h, &cus[i].m, &cus[i].s, &cus[i].t);
        cus[i].seconds = Seconds(cus[i]);
    }
    for (int i = 0; i < k; i++)
        wins[i] = start;
    sort(cus, cus + n, cmp_1017);
    int i = 0, j = 0;
    while (i != n - 1)
    {
        j = 0;
        while (j < k)
        {
            if (cus[i].seconds > end)
            {
                break;
            }
            else
            {
                if (cus[i].seconds < wins[j])
                {
                    wait += wins[j] - cus[i].seconds;
                    cus[i].seconds = wins[j];
                }
                wins[j] = cus[i].seconds + cus[i].t * 60;
                j++;
                num++;
                i++;
            }
        }
        sort(wins, wins + k);
    }
    printf("%.1f", wait / 60.0 / num);
}

void pat_1018()
{
    int cmax, n, sp, m;
    cin >> cmax >> n >> sp >> m;
    int i, j, c[n + 1];
    for (i = 1; i <= n; i++)
        cin >> c[i];
    int maps[n + 1][n + 1], x, y, t;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> t;
        maps[x][y] = t;
        maps[y][x] = t;
    }
    // dijkstra 最短路径问题
    // 权重,初始化为无穷大 == 101
    // 初始化集合
    int weights[n + 1], sets[n + 1], max = 100, cur = 0;
    // 路径
    int paths[n + 1], sends[n + 1];
    for (i = 0; i <= n; i++)
    {
        weights[i] = 101;
        sets[i] = 1;
        paths[i] = 0;
    }
    // 先从0开始
    weights[0] = 0;
    sets[0] = 0;
    sends[0] = 0;
    j = n;
    // 一些必要的值
    int weight, min, min_id, send;
    while (j > 0)
    {
        min = 101;
        for (i = 1; i <= n; i++)
        {
            // 有边并且为访问过的节点
            if (maps[cur][i] <= max && maps[cur][i] != 0 && sets[i] == 1)
            {
                // 当前路径的权重和发送数量
                weight = maps[cur][i] + weights[cur];
                send = sends[cur] + cmax / 2 - c[i];
                // 记录路径
                if (weight < weights[i])
                {
                    weights[i] = weight;
                    paths[i] = cur;
                    sends[i] = send;
                }
                // 更新问题，这是关键所在，找到 take back 最小的数量
                else if (weights[i] == weight)
                {
                    // 这里·缺了一步，没太看懂题目啥意思
                    if (sends[i] > send)
                    {
                        sends[i] = send;
                        paths[i] = cur;
                    }
                }
            }
            // 找到当前最短路径
            if (sets[i] == 1)
            {
                if (min > weights[i])
                {
                    min_id = i;
                    min = weights[i];
                }
            }
        }
        // 找到当前最小的
        sets[min_id] = 0;
        cur = min_id;
        // 如果目标已经找到退出即可
        if (cur == sp)
            break;
        j--;
    }

    send = 0;
    int collect = 0;
    if (sends[sp] < 0)
    {
        collect = -1 * sends[sp];
    }
    else
        send = sends[sp];

    cout << send << " ";
    // 打印路径
    int idx = sp;
    string res = to_string(sp);
    while (idx != 0)
    {
        res = to_string(paths[idx]) + "->" + res;
        idx = paths[idx];
    }
    cout << res << " " << collect;
}

// 采用移位运算
int divide(int dividend, int divisor)
{

    bool negative = (dividend < 0) ^ (divisor < 0) ? false : true;
    // 考虑溢出情况,这里采用 long 型
    long a = labs(dividend), b = labs(divisor), tmp;
    // 最大是 31，最小是0
    int left = 1, right = 31;
    int res = 0;
    while (left < right)
    {
        tmp = b << left;
        if (tmp > a)
        {
            res = left;
            break;
        }
        left++;
    }
    return res * (negative ? -1 : 1);
}

struct Point
{
    int left, right, target;
};

void pat_1020()
{

    int n, i;
    cin >> n;
    int postorders[n + 1], inorders[n + 1];
    // 记录中序的节点索引值，便于查询位置
    // 典型的空间换时间的算法
    map<int, int> ms;
    for (i = 1; i <= n; i++)
        cin >> postorders[i];
    for (i = 1; i <= n; i++)
    {
        cin >> inorders[i];
        ms[inorders[i]] = i;
    }

    // 采用一个队列保存路径
    int size, mid, left, right, target;
    // 一个三元组队列 {left,right,target}
    queue<Point> q;
    q.push(Point{1, n, n});
    cout << postorders[n];
    // 开始模拟层序遍历过程
    while (!q.empty())
    {
        size = q.size();
        for (i = 0; i < size; i++)
        {
            Point dot = q.front();
            q.pop();
            left = dot.left, right = dot.right, target = dot.target;
            // 放入时打印
            // 找到目标节点的位置
            mid = ms[postorders[target]];
            // 还存在左节点，打印，并放入
            if (left < mid)
            {
                cout << " " << postorders[target - (right - mid + 1)];
                q.push(Point{left, mid - 1, target - (right - mid + 1)});
            }
            // 还存在右节点，打印，并放入
            if (right > mid)
            {
                cout << " " << postorders[target - 1];
                q.push(Point{mid + 1, right, target - 1});
            }
        }
    }
}

void dfs_1021(vector<int> *graph, int *visited, int node, int height, int &maxheight, vector<int> &res)
{
    visited[node] = 1;
    if (height > maxheight)
    {
        maxheight = height;
        res.clear();
        res.push_back(node);
    }
    else if (height == maxheight)
    {
        res.push_back(node);
    }
    for (int i = 0; i < graph[node].size(); i++)
    {
        if (!visited[graph[node][i]])
        {
            dfs_1021(graph, visited, graph[node][i], height + 1, maxheight, res);
        }
    }
}

void pat_1021()
{
    int n, i;
    cin >> n;
    // 采用邻接表的来存储无向图
    vector<int> graph[n + 1];
    int x, y, visited[n + 1];
    // 标记为未访问过
    fill(visited, visited + n + 1, 0);
    for (i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> res;
    int maxheight = 0;
    int k = 0;
    for (int j = 1; j <= n; j++)
    {
        if (visited[j] == 0)
        {
            dfs_1021(graph, visited, j, 1, maxheight, res);
            k++;
        }
    }
    if (k > 1)
        printf("Error: %d components\n", k);
    else
    {
        int nodes[n + 1], node = res[0];
        fill(nodes, nodes + n + 1, 0);
        for (i = 0; i < res.size(); i++)
            nodes[res[i]]++;
        res.clear();
        fill(visited, visited + n + 1, 0);
        maxheight = 0;
        dfs_1021(graph, visited, node, 1, maxheight, res);
        for (i = 0; i < res.size(); i++)
            nodes[res[i]]++;
        for (i = 1; i <= n; i++)
        {
            if (nodes[i] > 0)
                cout << i << endl;
        }
    }
}

void pat_1090()
{

    // n the total number of the numbers in the supply chain
    int n;
    // p is the original price
    // r is the up rate in every convery
    double p, r;
    cin >> n >> p >> r;

    // 拓扑图(无环，有向图)，采用树来模拟
    vector<int> tree[n + 1];
    // 构建树
    int i, parent, root;
    for (int i = 0; i < n; i++)
    {
        cin >> parent;
        if (parent == -1)
            root = i;
        else
            tree[parent].push_back(i);
    }

    int size, height = 0, node;

    // 采用树的层序遍历。即类似于图的 BFS 来寻找最长路径
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        size = q.size();
        height++;
        for (i = 0; i < size; i++)
        {
            node = q.front();
            q.pop();
            // 这里由于是有向无环图，每个节点只访问一次，故无需标记
            for (int j = 0; j < tree[node].size(); j++)
            {
                q.push(tree[node][j]);
            }
        }
    }
    r = 1 + 0.01 * r;
    double res = pow(r, height - 1) * p;
    printf("%.2lf %d\n", res, size);
}

void pat_1040()
{

    string str;
    getline(cin, str);
    int i = 0, l = str.size() - 1, j = l, res = 1;
    bool is[l + 1][l + 1];
    fill(is[0], is[0] + (l + 1) * (l + 1), false);
    // 标记 长度为1 和 2
    for (i = 0; i <= l; i++)
    {
        is[i][i] = true;
        if (i + 1 <= l && str[i + 1] == str[i])
        {
            is[i][i + 1] = true;
            res = 2;
        }
    }
    j = 3;
    while (j <= l + 1)
    {
        for (i = 0; i + j - 1 <= l; i++)
        {
            int k = i + j - 1;
            if (str[i] == str[k] && is[i + 1][k - 1])
            {
                res = j;
                is[i][k] = true;
            }
        }
        j++;
    }

    cout << res;
}

void pat_1030()
{
    int n, m, s, d;
    cin >> n >> m >> s >> d;
    // 距离,成本，路径以及是否访问过
    int distance[n], costs[n], paths[n], visited[n];
    int v[n][n], c[n][n];
    fill(v[0], v[0] + n * n, 0);
    fill(distance, distance + n, -1);
    fill(costs, costs + n, -1);
    fill(visited, visited + n, 0);
    fill(paths, paths + n, s);
    int i, x, y, dis, cost;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y >> dis >> cost;
        v[x][y] = dis;
        v[y][x] = dis;
        c[x][y] = cost;
        c[y][x] = cost;
    }

    // 最短路径问题
    int visit = 0, cur = s, min_id = s, min;
    visited[cur] = 1;
    costs[cur] = 0;
    distance[cur] = 0;
    while (visit < n)
    {
        min = -1;
        for (int k = 0; k < n; k++)
        {
            // 存在路径
            if (v[cur][k] > 0 && !visited[k])
            {
                dis = v[cur][k] + distance[cur];
                cost = c[cur][k] + costs[cur];
                if (dis < distance[k] || distance[k] == -1)
                {
                    distance[k] = dis;
                    paths[k] = cur;
                    costs[k] = cost;
                }
                else if (dis == distance[k])
                {
                    if (cost < costs[k] || costs[k] == -1)
                    {
                        costs[k] = cost;
                        paths[k] = cur;
                    }
                }
            }
            if (!visited[k] && (distance[k] < min || min == -1))
            {
                min = distance[k];
                min_id = k;
            }
        }

        cur = min_id;
        visited[cur] = 1;
        visit++;
        if (cur == d)
            break;
    }

    int count = 1, target = d;
    string res = to_string(d) + " ";
    while (d != paths[d])
    {
        res = to_string(paths[d]) + " " + res;
        d = paths[d];
        count++;
    }
    cout << res << count << " " << costs[target];
}

struct TreeNode
{
    int parent, left, right;
};

TreeNode nodes[100];
vector<int> orders;

void inorders(int parent)
{
    if (parent != -1)
    {
        TreeNode node = nodes[parent];
        inorders(node.left);
        orders.push_back(node.parent);
        inorders(node.right);
    }
}

void pat_1099()
{
    int n, parent = 0, i, j;
    cin >> n;
    // 构建树
    for (i = 0; i < n; i++)
    {
        cin >> nodes[i].left >> nodes[i].right;
        nodes[i].parent = i;
    }
    // 中序序列
    inorders(parent);
    int nums[n], maps[n];
    // 建立起 中序序列与其索引之间的关系
    for (i = 0; i < orders.size(); i++)
        maps[orders[i]] = i;
    for (i = 0; i < n; i++)
        scanf("%d", &nums[i]);
    // 中序序列为有序序列
    sort(nums, nums + n);
    queue<TreeNode> q;
    q.push(nodes[0]);
    int size = 1;
    // 层序遍历，打印结果
    while (!q.empty())
    {
        size = q.size();
        for (j = 0; j < size; j++)
        {
            TreeNode node = q.front();
            q.pop();
            if (node.parent != 0)
                cout << " ";
            cout << nums[maps[node.parent]];
            if (node.left != -1)
                q.push(nodes[node.left]);
            if (node.right != -1)
                q.push(nodes[node.right]);
        }
    }
}

struct BinaryNode
{
    int left, right, data, level;
};

void pat_1115()
{
    int n, val, i;
    cin >> n;
    BinaryNode nodes[n];
    for (i = 0; i < n; i++)
    {
        cin >> val;
        nodes[i] = {-1, -1, val, 0};
    }
    int root = 0, cur, maxLevel = 0;
    for (i = 1; i < n; i++)
    {
        root = 0;
        while (root != -1)
        {
            if (nodes[root].data >= nodes[i].data)
            {
                cur = nodes[root].left;
                if (cur == -1)
                {
                    nodes[root].left = i;
                    nodes[i].level = nodes[root].level + 1;
                }
            }
            else
            {
                cur = nodes[root].right;
                if (cur == -1)
                {
                    nodes[root].right = i;
                    nodes[i].level = nodes[root].level + 1;
                }
            }
            maxLevel = max(maxLevel, nodes[i].level);
            root = cur;
        }
    }

    int prelevel = 0, curlevel = 0;
    for (i = 0; i < n; i++)
    {
        if (nodes[i].level == maxLevel)
            curlevel++;
        else if (nodes[i].level == maxLevel - 1)
            prelevel++;
    }
    printf("%d + %d = %d\n", curlevel, prelevel, curlevel + prelevel);
}

struct avl_node
{
    struct avl_node *left, *right;
    int data, height;
};
typedef struct avl_node *AvlTree, *AvlNode;

int height(AvlNode k)
{
    return k ? k->height : -1;
}

// lr 旋转
AvlNode left_right_rotate(AvlNode k2)
{
    AvlNode k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k2->height = max(height(k2->left), height(k2->right)) + 1;
    k1->height = max(height(k1->left), height(k1->right)) + 1;
    return k1;
}

// rl 旋转
AvlNode right_left_rotate(AvlNode k1)
{
    AvlNode k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = max(height(k1->left), height(k1->right)) + 1;
    k2->height = max(height(k2->left), height(k2->right)) + 1;
    return k2;
}

// ll 旋转
AvlNode left_left_rotate(AvlNode k3)
{
    k3->left = right_left_rotate(k3->left);
    return left_right_rotate(k3);
}

// rr 旋转
AvlNode right_right_rotate(AvlNode k1)
{
    k1->right = left_right_rotate(k1->right);
    return right_left_rotate(k1);
}

AvlNode insert(AvlNode t, int val)
{
    if (!t)
    {
        t = new avl_node();
        t->data = val;
        t->height = 0;
        t->left = t->right = nullptr;
        return t;
    }
    // self-check
    if (t->data > val)
    {
        t->left = insert(t->left, val);
        if (height(t->left) - height(t->right) == 2)
        {
            // lr 旋转
            if (t->left->data > val)
                t = left_right_rotate(t);
            else
                t = left_left_rotate(t);
        }
    }
    else
    {
        t->right = insert(t->right, val);
        if (height(t->right) - height(t->left) == 2)
        {
            // rl 旋转
            if (t->right->data < val)
                t = right_left_rotate(t);
            else
                t = right_right_rotate(t);
        }
    }
    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}

bool level_loop(AvlNode tree)
{
    queue<AvlNode> q;
    q.push(tree);
    int flag = 1;
    bool complete = true, leaf = false, falg = true;
    while (!q.empty())
    {
        AvlNode node = q.front();
        q.pop();
        if (!flag)
            cout << " ";
        else
            flag = false;
        cout << node->data;
        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
        if (!node->left && node->right)
            complete = false;
        if (leaf && (node->left || node->right))
            complete = false;
        if (!node->left || !node->right)
            leaf = true;
    }
    cout << endl;
    return complete;
}

void pat_1123()
{

    int n, i, val;
    cin >> n;
    AvlTree root = nullptr;
    for (i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }
    bool complete = level_loop(root);
    if (complete)
        cout << endl
             << "YES";
    else
        cout << endl
             << "NO";
}

struct RBNode
{
    struct RBNode *left, *right;
    int key;
};

int getheight(RBNode *root)
{
    if (!root)
        return 0;
    int l = getheight(root->left);
    int r = getheight(root->right);
    return root->key > 0 ? max(l, r) + 1 : max(l, r);
}

RBNode *insertRBTree(RBNode *root, int val)
{
    if (!root)
    {
        root = new RBNode();
        root->left = root->right = nullptr;
        root->key = val;
    }
    else
    {
        if (abs(val) <= abs(root->key))
        {
            root->left = insertRBTree(root->left, val);
        }
        else
            root->right = insertRBTree(root->right, val);
    }
    return root;
}

// 判断是非为 rb tree
bool isRBTree(RBNode *root)
{
    // 采用 层序遍历 来判断是否符合要求
    queue<RBNode *> q;
    q.push(root);
    bool is = true;
    while (!q.empty() && is)
    {
        RBNode *node = q.front();
        q.pop();
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
        int left = getheight(node->left), right = getheight(node->right);
        if (left != right)
            is = false;
        if (node->key < 0)
        {
            if (!((!node->left && !node->right) || (node->left && node->left->key > 0 && node->right && node->right->key > 0)))
                is = false;
        }
        else if (node->key == 0)
            is = false;
    }
    return is;
}

void pat_1135()
{
    int k, i, j, n, val;
    cin >> k;
    for (i = 0; i < k; i++)
    {
        cin >> n;
        RBNode *root = nullptr;
        for (j = 0; j < n; j++)
        {
            cin >> val;
            root = insertRBTree(root, val);
        }
        if (root->key < 0 || !isRBTree(root))
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}

void pat_1154()
{

    int n, m;
    cin >> n >> m;
    int i, v1, v2, visited[n];
    vector<int> vertices[n];
    for (i = 0; i < m; i++)
    {
        cin >> v1 >> v2;
        vertices[v1].push_back(v2);
        vertices[v2].push_back(v1);
    }
    int k;
    cin >> k;
    for (int j = 0; j < k; j++)
    {
        int color = 0, colors[n], num = 0;
        map<int, int> maps;
        fill(visited, visited + n, 0);
        for (i = 0; i < n; i++)
        {
            cin >> color;
            if (maps.count(color) == 0)
            {
                num++;
                maps[color] = 1;
            }
            colors[i] = color;
        }
        bool ok = true;
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                for (int k = 0; k < vertices[i].size(); k++)
                {
                    if (!visited[vertices[i][k]])
                    {
                        if (colors[i] == colors[vertices[i][k]])
                        {
                            ok = false;
                            break;
                        }
                    }
                }
                visited[i] = 1;
            }
        }
        if (ok)
            printf("%d-coloring\n", num);
        else
            cout << "No" << endl;
    }
}

void pat_1107()
{
    int n;
    cin >> n;
    int vistsied[n + 1], tags[n + 1];
    vector<int> graphs[n + 1];
    fill(vistsied, vistsied + n + 1, 0);
    int hobby, i, k;
    vector<int> hobbies[1001];
    for (i = 1; i <= n; i++)
    {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++)
        {
            cin >> hobby;
            graphs[i].push_back(hobby);
            hobbies[hobby].push_back(i);
        }
    }

    k = 0;
    vector<int> res;
    for (i = 1; i <= n; i++)
    {
        if (!vistsied[i])
        {
            k++;
            int num = 1;
            fill(tags, tags + n + 1, 0);
            // bfs or dfs 图的遍历
            queue<int> q;
            q.push(i);
            vistsied[i] = 1;
            tags[i] = 1;
            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (int j = 0; j < graphs[v].size(); j++)
                {
                    int h = graphs[v][j];
                    for (int t = 0; t < hobbies[h].size(); t++)
                    {
                        if (!tags[hobbies[h][t]])
                        {
                            vistsied[hobbies[h][t]] = 1;
                            tags[hobbies[h][t]] = 1;
                            q.push(hobbies[h][t]);
                            num++;
                        }
                    }
                }
            }
            res.push_back(num);
        }
    }

    sort(res.begin(), res.end());

    cout << k << endl;
    for (i = res.size() - 1; i >= 0; i--)
    {
        cout << res[i];
        if (i != 0)
            cout << " ";
    }
}

int stationLines[10000] = {-1};
int stations[10000][10000] = {0};

//  采用 bfs 即可
void bfs_1131(int start, int end)
{
    int visisted[10000] = {0}, paths[10000] = {start}, weight = -1;
    queue<int> q;
    q.push(start);
    visisted[start] = 1;
    int size, i, flag = 1;
    while (!q.empty() && flag)
    {
        size = q.size();
        for (i = 0; i < size; i++)
        {
            int node = q.front();
            q.pop();
            if (node == end)
            {
                flag = 0;
                break;
            }
            for (int j = 0; j < 10000; j++)
            {
                if (!visisted[j] && stations[node][j] == 1)
                {
                    paths[j] = node;
                    visisted[j] = 1;
                    q.push(j);
                }
            }
        }
        weight++;
    }
    cout << weight << endl;
    vector<int> res;
    res.push_back(end);
    while (end != start)
    {
        end = paths[end];
        res.push_back(end);
    }

    int len = res.size() - 1;
    int prev = res[len--], x = stationLines[prev], node, line;
    while (len >= 0)
    {
        node = res[len];
        line = stationLines[node];
        if (len == 0)
            printf("Take Line#%d from %d to %d.\n", x, prev, node);
        else if (line != x)
        {
            printf("Take Line#%d from %d to %d.\n", x, prev, res[len - 1]);
            if (len != 0)
            {
                prev = res[len - 1];
                x = line;
            }
        }
        len--;
    }
}

void pat_1131()
{
    int n, k;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        int prev = -1, s;
        for (int j = 0; j < k; j++)
        {
            cin >> s;
            stationLines[s] = i;
            if (prev != -1 && prev != s)
            {
                stations[prev][s] = 1;
                stations[s][prev] = 1;
            }
            prev = s;
        }
    }
    int m, start, end;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> start >> end;
        bfs_1131(start, end);
    }
}

void pat_1048()
{
    int n, m;
    cin >> n >> m;
    int maps[m];
    fill(maps, maps + m, 0);
    int v1 = m, coin;
    for (int i = 0; i < n; i++)
    {
        cin >> coin;
        if (m > coin)
        {
            if (maps[coin] == 1)
                v1 = min(coin, min(m - coin, v1));
            else
                maps[m - coin] = 1;
        }
    }
    if (v1 != m)
        cout << v1 << " " << m - v1;
    else
        cout << "No Solution" << endl;
}


