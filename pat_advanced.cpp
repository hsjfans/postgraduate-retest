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

int main()
{
    pat_1143();
    return 0;
}