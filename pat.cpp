/*
 * @Description: 
 * @Date: 2020-01-05 09:49:04
 * @LastEditors  : hsjfans
 * @LastEditTime : 2020-01-09 15:16:03
 * @Email: hsjfans.scholar@gmail.com
 */

#include "./pat.h"
using namespace std;

/**
 *  pat 1001
 * */
int pat_1001()
{
    cout << "This code is for pat-1001, please input a integer to control the following program \n";
    cout << "please input a interger to control the frequent \n";
    int m;
    cin >> m;
    cout << "please input a string of interger \n";
    while (m)
    {
        int n;
        cin >> n;
        int step = 0;
        while (n != 1)
        {
            n = (n % 2 == 0) ? n / 2 : (3 * n + 1) / 2;
            step++;
        }
        cout << step << "\n";
        m--;
    }

    return 0;
}

int pat_1002()
{
    cout << "This code is for pat-1002, please input a integer to control the following program \n";
    string m; // input a integer
    getline(cin, m);
    // cout << "m is "<< m << "\n";
    string numbers[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int sum = 0;
    const char *s = m.c_str();
    int len = m.length();
    int p;
    for (int i = len - 1; i >= 0; i--)
    {
        p = s[i] - '0';
        // cout << "p is " << p << "\n";
        sum += p;
    }
    stack<string> outs;
    while (sum)
    {
        p = sum % 10;
        sum = sum / 10;
        outs.push(numbers[p]);
    }

    len = outs.size();
    int i = 0;
    while (i < len - 1)
    {
        cout << outs.top() << " ";
        outs.pop();
        i++;
    }
    cout << outs.top();
    outs.pop();
    return 0;
}

int pat_right(string str)
{
    const char *ms = str.c_str();
    int n1, n2, n3 = n1 = n2 = 0;
    int p, t = p = -1;
    for (int i = 0; i < str.length(); i++)
    {
        if (ms[i] == 'P')
        {
            p = i;
        }
        else if (ms[i] == 'T')
        {
            t = i;
        }
        else if (ms[i] == 'A')
        {
            if (p == -1)
            {
                n1++;
            }
            else if (p != -1 && t == -1)
            {
                n2++;
            }
            else
            {
                n3++;
            }
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    if (p >= t)
    {
        cout << "NO";
        return 0;
    }
    // cout << str << n1 << n2 << n3 << "\n";
    if (n1 == n3 && n1 == 0 && n2 > 0)
    {
        cout << "YES";
    }
    else if (n1 != 0 && n3 == n1 * n2)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}

int pat_1003()
{
    int count, i = 0;
    string str;
    // cout << "please input an integer and a series of string \n";
    cin >> count;
    while (i < count)
    {
        if (i != 0)
        {
            cout << "\n";
        }
        // getline(cin, str);
        cin >> str;
        pat_right(str);
        i++;
    }
    return 0;
}

struct Student
{
    int score;
    char name[20];
    char id[20];
};

int pat_1004()
{
    int n, i = 0;
    cin >> n;
    struct Student students[n];
    while (i < n)
    {
        scanf("%s %s %d", students[i].name, students[i].id, &students[i].score);
        i++;
    }
    int max = 0;
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        if (students[i].score > students[max].score)
        {
            max = i;
        }
        else if (students[i].score < students[min].score)
        {
            min = i;
        }
    }
    printf("%s %s\n%s %s", students[max].name, students[max].id,
           students[min].name, students[min].id);
    return 0;
}

void pat_1005()
{

    int k, p, i = 0;
    cin >> k;
    // cout << "k is" << k << "\n";
    int len = 11100;
    int numbers[len];
    int ins[k];
    for (int j = 0; j < len; j++)
    {
        numbers[j] = 0;
    }
    while (i < k)
    {
        cin >> p;
        numbers[p] = 1;
        ins[i] = p;
        i++;
    }
    for (int j = 0; j < k; j++)
    {
        int tp = ins[j];
        if (numbers[tp] == 1)
        {
            while (tp != 1)
            {
                if (tp % 2 == 0)
                {
                    tp = tp / 2;
                }
                else
                {
                    tp = (3 * tp + 1) / 2;
                }
                numbers[tp] = 0;
            }
        }
    }
    bool first = true;
    while (len >= 3)
    {
        if (numbers[len - 1] == 1)
        {
            if (first)
            {
                cout << len - 1;
                first = false;
            }
            else
            {
                cout << " " << len - 1;
            }
        }
        len--;
    }
}

void pat_1006()
{
    int n;
    cin >> n;
    int b, s, t;
    b = n / 100;
    n = n - b * 100;
    s = n / 10;
    t = n - 10 * s;
    // cout << b << s << t;
    for (int i = 0; i < b; i++)
    {
        cout << "B";
    }
    for (int i = 0; i < s; i++)
    {
        cout << "S";
    }
    for (int i = 1; i <= t; i++)
    {
        cout << i;
    }
}

void pat_1007()
{
    int k, p;
    cin >> k;
    bool prime;
    vector<int> numbers;
    for (int i = 3; i <= k; i++)
    {
        p = sqrt(i);
        prime = true;
        while (p > 1)
        {
            if (i % p == 0)
            {
                prime = false;
                break;
            }
            p--;
        }
        if (prime)
        {
            numbers.push_back(i);
        }
    }
    int p1 = 0, p2 = 1;
    int count = 0;
    while (p2 < numbers.size())
    {
        if (numbers[p2] - numbers[p1] == 2)
        {
            count++;
        }
        p1 = p2;
        p2++;
    }
    cout << count;
}

void reverse(int numbers[], int left, int right)
{
    int tmp;
    while (left < right)
    {
        tmp = numbers[left];
        numbers[left] = numbers[right];
        numbers[right] = tmp;
        left++;
        right--;
    }
}

void pat_1008()
{
    int n, step, i = 0;
    cin >> n >> step;
    step = step % n;
    int numbers[n], tmp;
    while (i < n)
    {
        cin >> tmp;
        numbers[i++] = tmp;
    }
    reverse(numbers, 0, n - 1);
    reverse(numbers, 0, step - 1);
    reverse(numbers, step, n - 1);
    for (int j = 0; j < n; j++)
    {
        cout << numbers[j];
        if (j != n - 1)
        {
            cout << " ";
        }
    }
}

void pat_1009()
{
    string ms;
    getline(cin, ms);
    // cout << ms;
    stack<string> container;
    int left, right = left = 0, len = ms.length();
    while (right < len)
    {
        if (ms[right] == ' ')
        {
            container.push(ms.substr(left, right - left));
            left = right + 1;
        }
        right++;
    }
    container.push(ms.substr(left, right - left));
    // cout << container.size() << "\n";
    while (!container.empty())
    {
        cout << container.top();
        container.pop();
        if (container.size() >= 1)
        {
            cout << " ";
        }
    }
}

struct Item
{
    int p;
    int e;
};

void pat_1010()
{
    vector<Item> items;
    int p, e;
    unsigned int i = 0;
    while (true)
    {
        // cout << p << e;
        cin >> p >> e;
        Item item;
        item.e = e;
        item.p = p;
        items.push_back(item);
        if (getchar() != ' ')
        {
            break;
        }
    }
    // cout << items.size() << "\n";
    bool first = true;
    for (; i < items.size(); i++)
    {
        if (items[i].e == 0)
        {
            continue;
        }
        if (first)
        {
            first = false;
        }
        else
        {
            cout << " ";
        }
        p = items[i].p * items[i].e;
        e = items[i].e - 1;

        cout << p << " " << e;
    }
    if (first)
    {
        cout << "0 0";
    }
}

void pat_1011()
{

    int n, i = 0;
    cin >> n;
    long as[n], bs[n], cs[n];
    while (i < n)
    {
        cin >> as[i] >> bs[i] >> cs[i];
        i++;
    }

    for (i = 0; i < n; i++)
    {
        if (as[i] + bs[i] > cs[i])
        {
            printf("Case #%d: %s", i + 1, "true");
        }
        else
        {
            printf("Case #%d: %s", i + 1, "false");
        }
        if (i != n - 1)
        {
            cout << "\n";
        }
    }
}

void pat_1012()
{
    int n, i, a2, a3, a4, a5 = a2 = a3 = a4 = 0;
    cin >> n;
    int sum1, sum2, sum3, sum4, max5 = sum1 = sum2 = sum3 = sum4 = 0;
    int p, k = 0;
    while (n-- > 0)
    {
        cin >> p;
        if (p % 10 == 0)
        {
            sum1 += p;
        }
        if (p % 5 == 1)
        {
            sum2 = (k % 2 == 0) ? sum2 + p : sum2 - p;
            a2++;
            k++;
        }
        if (p % 5 == 2)
        {
            a3++;
        }
        if (p % 5 == 3)
        {
            sum4 += p;
            a4++;
        }
        if (p % 5 == 4 && p > max5)
        {
            max5 = p;
        }
    }
    if (sum1 == 0)
        cout << "N ";
    else
        cout << sum1 << " ";
    if (a2 == 0)
        cout << "N ";
    else
        cout << sum2 << " ";
    if (a3 == 0)
        cout << "N ";
    else
        cout << a3 << " ";
    if (a4 == 0)
        cout << "N ";
    else
        printf("%.1f ", sum4 / (a4 * 1.0));
    if (max5 == 0)
        cout << "N";
    else
        cout << max5;
    ;
}

void pat_1013()
{
    int n, m, tmp, k, count, j, i = k = count = 0;
    cin >> m >> n;
    bool prime;
    j = 2;
    while (j)
    {
        prime = true;
        tmp = sqrt(j);
        for (i = 2; i <= tmp; i++)
        {
            if (j % i == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime)
        {
            count++;
            if (count >= m && count <= n)
            {
                if (k <= 9)
                {
                    if (k != 0)
                    {
                        cout << " ";
                    }
                    cout << j;
                    k++;
                }
                else
                {
                    cout << "\n"
                         << j;
                    k = 1;
                }
            }
            else if (count > n)
            {
                break;
            }
        }
        j++;
    }
}

void pat_1014()
{
    int n = 4, i = 0;
    string ms[4];
    while (i < n)
    {
        getline(cin, ms[i]);
        i++;
    }
    string weeks[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int p = min(ms[0].length(), ms[1].length());
    bool first = true;
    int h;
    for (int j = 0; j < p; j++)
    {
        if (ms[0][j] == ms[1][j])
        {
            // cout << ms[0][j] << "\n";
            if (ms[0][j] >= 'A' && ms[0][j] <= 'G' && first)
            {
                cout << weeks[ms[0][j] - 'A'] << " ";
                first = false;
            }
            else if (!first &&
                     ((ms[0][j] >= 'A' && ms[0][j] <= 'N') ||
                      (ms[0][j] >= '0' && ms[0][j] <= '9')))
            {
                h = ms[0][j] >= 'A' ? ms[0][j] - 'A' + 10 : ms[0][j] - '0';
                if (h < 9)
                {
                    cout << "0";
                }
                cout << h << ":";
                break;
            }
        }
    }
    p = min(ms[2].length(), ms[3].length());
    for (int j = 0; j < p; j++)
    {
        if (ms[2][j] == ms[3][j] &&
            ((ms[2][j] >= 'a' && ms[2][j] <= 'z') ||
             (ms[2][j] >= 'A' && ms[2][j] <= 'Z')))
        {
            if (j < 10)
            {
                cout << "0" << j;
            }
            else
            {
                cout << j;
            }
            break;
        }
    }
}

typedef struct graduate
{
    char id[8];
    int ethics;
    int tech;
    int total;
} Graduate;

void sort_graduates(Graduate graduates[])
{
}

void pat_1015()
{
    int n, l, h;
    cin >> n >> l >> h;
    Graduate graduate;
    Graduate graduates_out[n];
    int i = 0;
    while (i < n)
    {
        scanf("%s %d %d", graduate.id, &graduate.ethics, &graduate.tech);
        graduate.total = graduate.ethics + graduate.tech;
        i++;
    }
}

int get_pa(int a, int da)
{
    int p = 9, tmp;
    bool start = false;
    while (p >= 0)
    {
        if (start)
        {
        }
        if (!start && da >= pow(10, p))
        {
            start = true;
        }
        p--;
    }
    return p;
}

void pat_1095()
{
}

void pat_1096()
{
}

bool is_prime(int i)
{
    bool is = true;
    int k = sqrt(i);
    while (k > 1)
    {
        if (i % k == 0)
        {
            is = false;
            break;
        }
        k--;
    }
    // cout << i << "\0" << is << "\n";
    return is;
}

void pat_1094(void)
{
    int l, k;
    string n;
    // scanf("%d %d\n%s", &l, &k, n);
    cin >> l >> k >> n;
    // cout << n << l << k;
    int p = k;
    bool zero = false;
    for (int i = 0; i < l; i++)
    {
        if (is_prime(n[i] - '0'))
        {
            if (p > 1)
            {
                p--;
            }
            else
            {
                for (int j = i - k + 1; j <= i; j++)
                {
                    cout << n[j];
                }
                return;
            }
        }
        else if (n[i] - '0' == 0)
        {
            if (zero)
            {
                p--;
            }
            else
            {
                zero = true;
            }
        }
        else
        {
            p = k;
        }
    }
    // cout << p << " !!";
    if (p != 1)
    {
        cout << "404";
    }
}

void self_control(int k)
{
    bool self = true;
    int n = 1;

    // 检测位数
    int bitwise = 0;
    while (k >= pow(10, bitwise))
    {
        bitwise += 1;
    }
    // cout << k << " " << pow(10, bitwise) << " bitwise\n";
    // check是否为自守数
    long p;
    long pw = pow(10, bitwise);
    while (n < 10)
    {
        p = n * k * k;
        if (p % pw == k)
        {
            cout << n << " " << p << "\n";
            return;
        }
        n++;
    }
    cout << "No\n";
}

void pat_1091()
{
    int m, tmp;
    cin >> m;
    while (m > 0)
    {
        cin >> tmp;
        self_control(tmp);
        m--;
    }
}

void pat_1086()
{
    int a, b;
    cin >> a >> b;
    string t = to_string(a * b);
    for (int i = t.length() - 1; i >= 0; i--)
    {
        cout << t[i];
    }
}

int get_p(string a, string da)
{
    string tmp;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == da[0])
        {
            tmp.append(da);
        }
    }
    if (tmp.length() > 0)
    {
        return atoi(tmp.c_str());
    }
    return 0;
}

void pat_1016()
{
    string a, da, b, db;
    cin >> a >> da >> b >> db;
    // cout << a << da << b << db;
    int pa, pb;
    pa = get_p(a, da);
    pb = get_p(b, db);
    cout << (pa + pb);
}

void pat_1021()
{
    string n;
    cin >> n;
    int cache[10], p, first = 1;
    for (int i = 0; i < 10; i++)
    {
        cache[i] = 0;
    }

    for (int i = 0; i < n.length(); i++)
    {
        cache[n[i] - '0'] += 1;
    }
    for (int i = 0; i < 10; i++)
    {
        p = cache[i];
        if (p)
        {
            if (first)
                first = 0;
            else
                cout << "\n";
            cout << i << ":" << p;
        }
    }
}

void pat_1026()
{
    double a, b;
    cin >> a >> b;
    int c = (int)((b - a) / 100 + 0.5);
    int h = c / 3600;
    int m = c % 3600 / 60;
    int s = c % 60;
    printf("%02d:%02d:%02d", h, m, s);
}

void pat_1066()
{
    int m, n, a, b, grey;
    cin >> m >> n >> a >> b >> grey;
    string result;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
        }
    }
}

int main()
{
    pat_1026();
    return 0;
}
