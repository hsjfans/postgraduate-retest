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
    bool first = true;
    string t = to_string(a * b);
    for (int i = t.length() - 1; i >= 0; i--)
    {
        if (t[i] != '0')
        {
            cout << t[i];
            first = false;
        }
        else if (!first)
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

void pat_1076()
{
    string str;
    while (cin >> str)
    {
        if (str.size() == 3 && str[2] == 'T')
        {
            cout << str[0] - 'A' + 1;
        }
    }
}

void pat_1071()
{
    int t, k;
    cin >> t >> k;
    int n1, b, reward, n2;
    int p = k;
    while (k > 0)
    {
        if (k < p)
        {
            cout << "\n";
        }
        k--;
        cin >> n1 >> b >> reward >> n2;
        if (reward > t)
        {
            printf("Not enough tokens.  Total = %d.", t);
            // return;
            continue;
        }
        if ((n2 > n1 && b == 1) || (n2 < n1 && b == 0))
        {
            t += reward;
            printf("Win %d!  Total = %d.", reward, t);
        }
        else
        {
            if (reward <= t)
            {
                t -= reward;
                printf("Lose %d.  Total = %d.", reward, t);
                if (t == 0)
                {
                    printf("\nGame Over.");
                    return;
                }
            }
        }
    }
}

int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int code[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

bool isTrue(string str)
{
    int total = 0;
    for (int i = 0; i < 17; i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;

        total += (str[i] - '0') * weight[i];
    }
    return code[total % 11] == str[17];
}

void pat_1031()
{

    int n, flag = 1;
    bool first = true;
    cin >> n;
    string str;
    while (n > 0)
    {
        cin >> str;
        if (!isTrue(str))
        {
            cout << str << endl;
            flag = 0;
        }
        n--;
    }
    if (flag)
    {
        cout << "All passed";
    }
}

void check_passward(string pwd)
{
    if (pwd.length() < 6)
    {
        // cout << "Your password is tai duan le.\n";
        printf("Your password is tai duan le.\n");
        return;
    }
    bool number, invalid, alphabet = number = invalid = false;
    for (unsigned int i = 0; i < pwd.length(); i++)
    {
        if (iswalpha(pwd[i]))
        {
            alphabet = true;
        }
        else if (iswdigit(pwd[i]))
        {
            number = true;
        }
        else if (pwd[i] != '.')
        {
            invalid = true;
            break;
        }
    }
    if (invalid)
    {
        printf("Your password is tai luan le.\n");
    }
    else if (alphabet && !number)
    {
        printf("Your password needs shu zi.\n");
    }
    else if (number && !alphabet)
    {
        printf("Your password needs zi mu.\n");
    }
    else
    {
        printf("Your password is wan mei.\n");
    }
}

void pat_1081()
{
    int n;
    string pwd;
    cin >> n;
    getchar();
    while (n--)
    {
        getline(cin, pwd);
        check_passward(pwd);
    }
}

void pat_1036()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int column = round(n / 2.0);
    string start;
    start += c;
    string content = start;
    for (int i = 1; i < n - 1; i++)
    {
        start += c;
        content += " ";
    }
    content += c;
    start += c;
    cout << start << "\n";
    for (int i = 1; i < column - 1; i++)
    {
        cout << content << "\n";
    }
    cout << start;
}

void pat_1041()
{
    int n;
    cin >> n;
    string cache[n + 1];
    int seatId, testId;
    string number;
    for (int i = 0; i < n; i++)
    {
        cin >> number >> seatId >> testId;
        cache[seatId] = number + " " + to_string(testId);
    }

    int m, seat;
    cin >> m;
    while (m--)
    {
        cin >> seat;
        cout << cache[seat] << endl;
    }
}

void pat_1046()
{
    int n;
    cin >> n;
    int a, b = a = 0;
    int pa, qa, pb, qb;
    bool at, bt;
    while (n--)
    {
        cin >> pa >> qa >> pb >> qb;
        at = qa == (pa + pb);
        bt = qb == (pa + pb);
        if (at && bt)
        {
            continue;
        }
        else if (!at && !bt)
        {
            continue;
        }
        else if (at)
        {
            b++;
        }
        else
        {
            a++;
        }
    }
    printf("%d %d", a, b);
}

void pat_1051()
{

    float r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    float a,
        b, c, d, e, f;
    a = r1 * cos(p1);
    b = r1 * sin(p1);
    c = r2 * cos(p2);
    d = r2 * sin(p2);
    e = a * c - b * d;
    f = a * d + b * c;
    printf("%.2f%.2fi", e, f);
}

void pat_1056()
{
    int n;
    cin >> n;
    int sum = 0;
    int tmp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> tmp[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                sum += 10 * tmp[i] + tmp[j];
            }
        }
    }
    cout << sum;
}

void pat_1061()
{
    int n, m;
    cin >> n >> m;
    int scores[m];
    int answers[m];
    for (int i = 0; i < m; i++)
    {
        cin >> scores[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> answers[i];
    }
    int sum, tmp;
    for (int j = 0; j < n; j++)
    {
        sum = 0;
        for (int i = 0; i < m; i++)
        {
            cin >> tmp;
            // cout << tmp;
            if (tmp == answers[i])
                sum += scores[i];
        }
        cout << sum << endl;
    }
}

void pat_1066()
{
    int m, n, a, b, alter;
    cin >> m >> n >> a >> b >> alter;
    int p;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p;
            if (p <= b && p >= a)
            {
                p = alter;
            }
            printf("%03d", p);
            if (j == n - 1)
            {
                printf("\n");
            }
            else
            {
                printf(" ");
            }
        }
    }
}

void pat_1017()
{
    string a;
    int b, tmp, last, next = last = 0;
    cin >> a >> b;
    bool zero = false;
    for (int i = 0; i < a.size(); i++)
    {
        tmp = (a[i] - '0') + last * 10;
        next = tmp / b;
        last = tmp % b;
        // cout << tmp << " " << next << " " << last << endl;
        if (next > 0)
            zero = true;
        if (zero)
            cout << next;
    }
    if (!zero)
        cout << 0;
    cout << " "
         << last;
}

typedef struct a_student
{
    int id;
    int ethicsId;
    int intelligentId;
    int sum;
} AStudent;

int cmp(AStudent s1, AStudent s2)
{
    // cout << s1.id << " " << s2.id << " " << s1.sum << " " << s2.sum << endl;
    // return s1.sum > s2.sum;
    if (s1.sum > s2.sum)
    {
        return 1;
    }
    else if (s1.sum == s2.sum && s1.ethicsId > s2.ethicsId)
    {
        return 1;
    }
    return s1.sum == s2.sum && s1.ethicsId == s2.ethicsId && s1.id < s2.id;
}

void print_f(vector<AStudent> a_students)
{
    int num = a_students.size();
    for (int i = 0; i < num; i++)
    {
        printf("%d %d %d\n", a_students[i].id, a_students[i].ethicsId, a_students[i].intelligentId);
    }
}

void pat_1015()
{
    int num, l, h, i = 0;
    cin >> num >> l >> h;
    vector<AStudent> p1, p2, p3, p4;
    AStudent tmp;
    while (i++ < num)
    {
        scanf("%d %d %d", &tmp.id, &tmp.ethicsId, &tmp.intelligentId);
        // cout << " input " << tmp.id << endl;
        tmp.sum = tmp.ethicsId + tmp.intelligentId;
        if (tmp.ethicsId < l || tmp.intelligentId < l)
        {
            continue;
        }
        if (tmp.ethicsId >= h && tmp.intelligentId >= h)
        {
            p1.push_back(tmp);
        }
        else if (tmp.ethicsId >= h && tmp.intelligentId < h)
        {
            p2.push_back(tmp);
        }
        else if (tmp.ethicsId < h && tmp.intelligentId < h && tmp.ethicsId >= tmp.intelligentId)
        {
            p3.push_back(tmp);
        }
        else
        {
            p4.push_back(tmp);
        }
    }
    sort(p1.begin(), p1.end(), cmp);
    sort(p2.begin(), p2.end(), cmp);
    sort(p3.begin(), p3.end(), cmp);
    sort(p4.begin(), p4.end(), cmp);
    cout << p1.size() + p2.size() + p3.size() + p4.size() << endl;
    print_f(p1);
    print_f(p2);
    print_f(p3);
    print_f(p4);
}

int cmp_1019(char a, char b)
{
    return a > b;
}

void pat_1019()
{
    string s, a, b;
    cin >> s;
    string res;
    s.insert(0, 4 - s.size(), '0');
    do
    {
        a = s, b = s;
        sort(a.begin(), a.end(), cmp_1019);
        sort(b.begin(), b.end());
        res = to_string(stoi(a) - stoi(b));
        res.insert(0, 4 - res.size(), '0');
        cout << a << " - " << b << " = " << res << endl;
        s = res;
    } while (res != "0000" && res != "6174");
}

typedef struct moon
{
    float stock, price, profit;
} Moon;

int cmp_1020(Moon m1, Moon m2)
{
    return m1.profit < m2.profit;
}

void pat_1020()
{
    int n, d;
    cin >> n >> d;
    float stock[n], price[n], profit, sum = 0;
    Moon m[n];
    int i, j = i = 0;
    while (i < n || j < n)
    {
        if (i < n)
            cin >> stock[i++];
        else
            cin >> price[j++];
    }
    for (i = 0; i < n; i++)
    {
        profit = price[i] / stock[i];
        m[i].stock = stock[i];
        m[i].price = price[i];
        m[i].profit = profit;
    }
    sort(m, m + n, cmp_1020);
    for (i = n - 1; i >= 0 && d > 0; i--)
    {
        // cout << m[i].stock << " " << m[i].price << "  stock " << d << endl;
        if (d >= m[i].stock)
        {
            sum += m[i].price;
            d -= m[i].stock;
        }
        else
        {
            sum += m[i].profit * d;
            break;
        }
    }
    printf("%.2f", sum);
}

void pat_1022()
{
    int a, b, d, sum, p;
    string res;
    cin >> a >> b >> d;
    sum = a + b;
    while (sum)
    {
        p = sum % d;
        sum = sum / d;
        res = to_string(p) + res;
    }
    if (res.size() > 0)
        cout << res;
    else
        cout << "0";
}

void pat_1023()
{

    int p[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> p[i];
    }
    bool small = true;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < p[i]; j++)
        {
            cout << i;
            if (small)
            {
                for (int k = 0; k < p[0]; k++)
                {
                    cout << 0;
                }
                small = false;
            }
        }
    }
}

// standard file head
typedef struct pat_student
{
    string number;
    char level;
    int plaId;
    string date;
    int stuId;
    int score;
} PStudent;

typedef struct place
{
    int plaId;
    int sum;
} Place;

/**
第 1 位是级别，即 T 代表顶级；A 代表甲级；B 代表乙级；
第 2~4 位是考场编号，范围从 101 到 999；
第 5~10 位是考试日期，格式为年、月、日顺次各占 2 位；
最后 11~13 位是考生编号，范围从 000 到 999。
*/
PStudent
parseStudent(string number, int score)
{
    // printf("number -> %s \n ", number.c_str());
    PStudent student;
    student.number = number;
    student.level = number[0];
    student.plaId = stoi(number.substr(1, 3));
    student.date = number.substr(4, 6);
    student.stuId = stoi(number.substr(10, 3));
    student.score = score;
    return student;
}

int cmp_1(PStudent s1, PStudent s2)
{
    if (s1.score != s2.score)
    {
        return s1.score > s2.score;
    }
    return s1.number < s2.number;
}

int cmp_2(Place p1, Place p2)
{
    if (p1.sum != p2.sum)
        return p1.sum > p2.sum;
    return p1.plaId < p2.plaId;
}

void pat_1095()
{
    int n, m, l, t, score;
    cin >> n >> m;
    PStudent students[n];
    l = n, t = m;
    char number[13];
    while (n--)
    {
        scanf("%s %d", number, &score);
        students[n] = parseStudent(number, score);
    }
    int code, g;
    char p[6];
    while (m--)
    {
        scanf("%d %s", &code, p);
        printf("Case %d: %d %s\n", t - m, code, p);
        bool ok = true;
        if (code == 1)
        {
            // 类型 为 1 的指令，输出格式与输入的考生信息格式相同，即 准考证号 成绩。
            // 对于分数并列的考生，按其准考证号的字典序递增输出（题目保证无重复准考证号）；
            sort(students, students + l, cmp_1);
            for (int i = 0; i < l; i++)
            {
                if (students[i].level == p[0])
                {
                    printf("%s %d\n", students[i].number.c_str(), students[i].score);
                    ok = false;
                }
            }
        }
        else if (code == 2)
        {
            int amount, sum = amount = 0;
            int pl = stoi(p);
            for (int i = 0; i < l; i++)
            {
                if (students[i].plaId == pl)
                {
                    ok = false;
                    sum += students[i].score;
                    amount++;
                }
            }
            if (!ok)
            {
                printf("%d %d\n", amount, sum);
            }
        }
        else if (code == 3)
        {
            ok = l == 0;
            Place places[1000];
            for (int i = 0; i < 1000; i++)
            {
                places[i].plaId = i;
                places[i].sum = 0;
            }
            for (int i = 0; i < l; i++)
            {
                if (students[i].date == p)
                {
                    places[students[i].plaId].sum++;
                }
            }

            sort(places, places + 1000, cmp_2);
            for (int i = 0; i < 1000; i++)
            {
                if (places[i].sum > 0)
                {
                    printf("%d %d\n", places[i].plaId, places[i].sum);
                }
            }
        }
        if (ok)
            cout << "NA\n";
    }
}

void pat_1093()
{
    string res, tmp;
    int map[127];
    for (int i = 31; i < 127; i++)
        map[i] = 0;
    int n = 2;
    while (n--)
    {
        getline(cin, tmp);
        // cout << tmp << endl;
        for (int i = 0; i < tmp.size(); i++)
        {
            int c = tmp[i];
            // cout << c << " c " << tmp[i] << endl;
            if (c >= 32 && c <= 126)
            {
                if (map[c] == 0)
                {
                    res += c;
                    map[c] = 1;
                }
            }
        }
    }
    cout << res;
}

void pat_1092()
{
    int n, m, tmp, sum_max = 0;
    scanf("%d %d", &n, &m);
    int stock[n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &tmp);
            if (i == 0)
                stock[j] = 0;
            stock[j] += tmp;
            if (stock[j] > sum_max)
                sum_max = stock[j];
        }
    }

    cout << sum_max << endl;
    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (stock[i] == sum_max)
        {
            if (!first)
                cout << " ";
            else
                first = false;
            cout << i + 1;
        }
    }
}

void pat_1090()
{

    int k, n;
    cin >> k >> n;
    map<string, vector<string> > maps;
    string str1, str2;
    while (k--)
    {
        // double trend
        cin >> str1 >> str2;
        maps[str1].push_back(str2);
    }
    int num;
    string key;
    bool repeat;
    while (n--)
    {
        // 每次初始化一下
        repeat = false;
        cin >> num;
        map<string, int> codes;
        while (num--)
        {
            cin >> key;
            // printf("num---> %d key----> %s\n", num, key.c_str());
            // 判断是否已经存在，若存在则输出 no
            // 否则添加false
            if (!repeat)
            {
                vector<string> values = maps[key];
                for (int j = 0; j < values.size(); j++)
                {
                    // cout << key << " "<< values[j] << endl;
                    if (codes[values[j]] == 1)
                    {
                        repeat = true;
                    }
                }
                codes[key] = 1;
            }
        }
        if (!repeat)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

void check(int m, int p)
{
    cout << " ";
    if (m == p)
        cout << "Ping";
    else if (m < p)
        cout << "Cong";
    else
        cout << "Gai";
}

void pat_1088()
{
    int b, c, m, x, y, a = 10;
    cin >> m >> x >> y;
    int tmp1, tmp2;
    int p1, p2, p3;
    bool suc = false;
    while (a > 0)
    {
        tmp1 = (9 * y - x) * a;
        tmp2 = (10 * x + 9 * y);
        if (tmp1 % tmp2 == 0)
        {
            b = tmp1 / tmp2;
            p1 = 10 * a + b;
            if ((9 * (a - b) % x == 0) && (p1 <= 100))
            {
                c = 9 * (a - b) / x;
                p2 = 10 * b + a;
                p3 = p1 - p2;
                if (p2 <= 100 && p3 < 100 && p3 > 0)
                {
                    suc = true;
                    break;
                }
            }
        }
        a--;
    }

    if (!suc)
        cout << "No Solution";
    else
    {
        cout << p1;
        check(m, p1);
        check(m, p2);
        check(m, p3);
    }
}

void pat_1087()
{
    map<int, int> maps;
    int n, value, tmp, sum = 0;
    cin >> n;
    // cout << " n" << n << endl;
    for (tmp = 1; tmp <= n; tmp++)
    {
        value = tmp / 2 + tmp / 3 + tmp / 5;
        if (maps[value] != 1)
            sum++;
        maps[value] = 1;
    }
    cout << sum << endl;
}

typedef struct school
{
    int num;
    string company;
    float score;
} School;

string transform(string key)
{
    // string p;
    for (int i = 0; i < key.size(); i++)
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
        {
            key[i] = (char)(key[i] ^ 0x20);
        }
    }
    return key;
}

int cmp_1085(School s1, School s2)
{
    if (s1.score != s2.score)
    {
        return s1.score > s2.score;
    }
    else if (s1.num != s2.num)
    {
        return s1.num < s2.num;
    }
    else
    {
        return s1.company < s2.company;
    }
}

void pat_1085()
{
    int n;
    cin >> n;
    map<string, School> schools;
    char id[6], company[6];
    int score;
    string key;
    while (n--)
    {
        scanf("%s %d %s", id, &score, company);
        key = transform(company);
        School sc;
        if (!schools.count(key))
            sc = {0, key, 0.0};
        else
            sc = schools.at(key);
        sc.num++;
        if (id[0] == 'B')
            sc.score += score / 1.5;
        else if (id[0] == 'A')
            sc.score += score;
        else
            sc.score += score * 1.5;
        schools[key] = sc;
    }

    vector<School> scs;
    for (map<string, School>::iterator it = schools.begin(); it != schools.end();)
    {
        scs.push_back(it->second);
        it++;
    }
    sort(scs.begin(), scs.end(), cmp_1085);
    int idx = 1, prevscore = -1, offset = 0;
    for (unsigned int i = 0; i < scs.size(); i++)
    {
        if (scs[i].score == prevscore)
        {
            offset++;
            printf("%d %s %.0f %d", idx, scs[i].company.c_str(), scs[i].score, scs[i].num);
        }
        else
        {
            prevscore = scs[i].score;
            printf("%d %s %.0f %d", idx + offset, scs[i].company.c_str(), scs[i].score, scs[i].num);
            offset = 0;
        }
    }
}

void pat_1084()
{

    int d, n;
    cin >> d >> n;
    string t = to_string(d);
    unsigned int j;
    char tmp;
    while (n--)
    {
        if (n == 0)
            cout << t << endl;
        unsigned int sum = 1;
        string p;
        tmp = t[0];
        for (j = 1; j < t.size(); j++)
        {
            if (tmp == t[j])
                sum++;
            else
            {
                p += tmp + to_string(sum);
                sum = 1;
                tmp = t[j];
            }
        }
        if (sum > 0)
            p += tmp + to_string(sum);
        t = p;
    }
}

void pat_1083()
{
    int n, tmp, nums[10000] = {0}, j = 1;
    cin >> n;
    while (j <= n)
    {
        cin >> tmp;
        nums[abs(tmp - j)]++;
        j++;
    }
    for (j = 9999; j >= 0; j--)
    {
        if (nums[j] > 1)
            printf("%d %d\n", j, nums[j]);
    }
}

void pat_1082()
{
    string min_id, max_id;
    int n, x, y, max, min = max = -1;
    float tmp;
    cin >> n;
    char id[4];
    while (n--)
    {
        scanf("%s %d %d", id, &x, &y);
        tmp = sqrt(x * x + y * y);
        if (max == min && min == -1)
        {
            max = min = tmp;
            min_id = max_id = id;
        }
        else if (max < tmp)
        {
            max_id = id;
            max = tmp;
        }
        else if (min > tmp)
        {
            min = tmp;
            min_id = id;
        }
    }
    cout << min_id << " " << max_id;
}

typedef struct student_score
{
    string id;
    int gp, gm, gf, g;

} StudentScore;

int cmp_1080(StudentScore s1, StudentScore s2)
{
    if (s1.g != s2.g)
        return s1.g > s2.g;
    else
        return s1.id < s2.id;
}

void pat_1080()
{
    char id[20];
    int tmp;
    int p, m, n;
    cin >> p >> m >> n;
    int num = p + m + n;
    map<string, StudentScore> maps;
    while (num)
    {
        scanf("%s %d", id, &tmp);
        if (!maps.count(id))
        {
            StudentScore score{id, -1, -1, -1, -1};
            maps[id] = score;
        }
        if (p)
        {
            maps[id].gp = tmp;
            p--;
        }
        else if (m)
        {
            maps[id].gm = tmp;
            m--;
        }
        else
        {
            maps[id].gf = tmp;
            n--;
        }

        num--;
    }

    vector<StudentScore> scs;
    for (map<string, StudentScore>::iterator it = maps.begin(); it != maps.end();)
    {
        scs.push_back(it->second);
        it++;
    }

    for (unsigned int i = 0; i < scs.size(); i++)
    {
        if (scs[i].gm > scs[i].gf)
        {
            if (scs[i].gf == -1)
                scs[i].g = (int)(scs[i].gm * 0.4 + 0.5);
            else
                scs[i].g = (int)(scs[i].gm * 0.4 + scs[i].gf * 0.6 + 0.5);
        }
        else
            scs[i].g = scs[i].gf;
    }
    sort(scs.begin(), scs.end(), cmp_1080);
    for (unsigned int j = 0; j < scs.size(); j++)
        if (scs[j].gp >= 200 && scs[j].g >= 60)
            printf("%s %d %d %d %d\n", scs[j].id.c_str(), scs[j].gp, scs[j].gm, scs[j].gf, scs[j].g);
}

bool recircle(int num)
{
    string p = to_string(num);
    int i = 0, j = p.size() - 1;
    while (i < j)
    {
        if (p[i]++ != p[j--])
            return false;
    }
    return true;
}

string reverse_p(int n)
{
    string p = to_string(n);
    int i = 0, j = p.size() - 1;
    char tmp;
    while (i < j)
    {
        tmp = p[i];
        p[i++] = p[j];
        p[j--] = tmp;
    }
    return p;
}

void pat_1079()
{
    int n, tmp;
    cin >> n;
    int count = 10;
    bool circle;
    string re;
    while (!(circle = recircle(n)) && count > 0)
    {
        re = reverse_p(n);
        tmp = stoi(re);
        cout << n << " + " << re << " = " << n + tmp << endl;
        n = tmp + n;
        count--;
    }
    if (circle)
        printf("%d is a palindromic number.", n);
    else
        cout << "Not found in 10 iterations.";
}

void encode(string str)
{
    char tmp = str[0];
    int sum = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (tmp == str[i])
            sum++;
        else
        {
            if (sum > 1)
                cout << sum;
            cout << tmp;
            tmp = str[i];
            sum = 1;
        }
    }
    if (sum > 0)
        cout << tmp;
}
void decode(string str)
{
    string n;
    int tmp;
    for (int j = 0; j < str.size(); j++)
    {
        if (str[j] >= '0' && str[j] <= '9')
        {
            n += str[j];
        }
        else
        {
            if (n.size() == 0)
                cout << str[j];
            else
            {
                tmp = stoi(n);
                while (tmp--)
                {
                    cout << str[j];
                }
                n = "";
            }
        }
    }
}

void pat_1078()
{
    char code;
    cin >> code;
    getchar();
    string str;
    getline(cin, str);
    if (code == 'C')
        encode(str);
    else
        decode(str);
}

void pat_1077()
{
    int n, m;
    cin >> n >> m;
    int scores[101] = {0}, g1, tmp, sum, max, min;
    int column = n;
    while (n--)
    {
        // 老师的评分
        cin >> g1;
        // 输入其它同学的评分
        for (int i = 1; i < column; i++)
        {
            cin >> tmp;
            if (tmp >= 0 && tmp <= m)
                scores[tmp]++;
        }
        sum = 0;
        min = -1;
        max = 0;
        // 开始处理学生的评分
        for (int i = 0; i <= m; i++)
        {
            if (scores[i] > 0)
            {
                max = i;
                if (min < 0)
                    min = 0;
                else
                {
                    sum += i;
                    min++;
                }
                for (int j = 1; j < scores[i]; j++)
                {
                    sum += i;
                    min++;
                }
                scores[i] = 0;
            }
        }
        // 去掉一个最大值
        sum = sum - max;
        // 输出最终结果
        cout << (int)((g1 + sum * 1.0 / (min - 1)) / 2.0 + 0.5) << endl;
    }
}

typedef struct node
{
    int n, d;
} Node;

void pat_1075()
{
    int start, num, k, a, d, n, data;
    scanf("%d %d %d", &start, &num, &k);
    vector<int> v[3];
    Node maps[100000];
    while (num--)
    {
        scanf("%d", &a);
        scanf("%d %d", &maps[a].d, &maps[a].n);
    }
    // 恢复次序
    while (start != -1)
    {
        data = maps[start].d;
        if (data < 0)
            v[0].push_back(start);
        else if (data <= k)
            v[1].push_back(start);
        else
            v[2].push_back(start);
        start = maps[start].n;
    }
    bool first = true;
    for (int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < v[i].size(); j++)
        {

            if (first)
                first = false;
            else
                printf("%05d\n", v[i][j]);
            printf("%05d %d ", v[i][j], maps[v[i][j]].d);
        }
    }
    cout << "-1" << endl;
}

void pat_1074()
{
    string code, a, b;
    cin >> code >> a >> b;
    string result;
    int up = 0, sum = 0, p;
    int n = code.size() - 1;
    a.insert(0, n - a.size() + 1, '0');
    b.insert(0, n - b.size() + 1, '0');
    while (n >= 0)
    {
        sum = (a[n] - '0') + (b[n] - '0') + up;
        p = code[n] == '0' ? 10 : code[n] - '0';
        up = sum / p;
        result += (sum % p + '0');
        n--;
    }
    if (up != 0)
        result += (up + '0');
    bool ok = false;
    for (int j = result.size() - 1; j >= 0; j--)
    {
        if (result[j] > '0')
            ok = true;
        if (ok)
            cout << result[j];
    }
    if (!ok)
        cout << "0";
}

typedef struct question
{
    int score, num, rights; // 编号 分数 选项数量
    int options[5];         // 是否为正确选项
} Question;

typedef struct error
{
    int id, idx, count;
} Error;

int cmp_1073(Error e1, Error e2)
{
    if (e1.count != e2.count)
    {
        return e1.count > e2.count;
    }
    else if (e1.id != e2.id)
    {
        return e1.id < e2.id;
    }
    else
        return e1.idx < e2.idx;
}

void pat_1073()
{
    int n, m; // 学生 多选题个数
    scanf("%d %d",&n,&m);
    bool hasErr = false;
    Question questions[m];
    map<string, Error> errors;
    vector<Error> sortErrors;
    // 每行顺次给出一道题的满分值（不超过 5 的正整数）、选项个数（不少于 2 且不超过 5 的正整数）、正确选项个数（不超过选项个数的正整数）、所有正确选项。
    char option;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &questions[i].score, &questions[i].num, &questions[i].rights);
        for (int j = 0; j < questions[i].rights; j++)
        {
            cin >> option;
            questions[i].options[option - 'a'] = 1;
        }
    }
    string str, key;
    // 学生选项
    for (int i = 0; i < n; i++)
    {
        // 处理每一个学生
        getline(cin, str);
        // 题目id
        int idx = 0, j = 0, count = 0, rights;
        float scores = 0; // 学生的得分综合
        while (j < str.size())
        {
            // 在 0和9 之间
            // 每一道题
            if (str[j] <= '9' && str[j] >= '0')
            {
                rights = questions[idx].rights;
                count = str[j] - '0';
                while (count > 0)
                {
                    j++;
                    if (str[j] != ' ')
                    {
                        // 如果选择正确
                        if (questions[idx].options[str[j] - 'a'])
                        {
                            rights--;
                            count--;
                        }
                        // 选项错误
                        else
                        {
                            hasErr = true;
                            rights = -1;
                            key = to_string(idx) + "-" + str[j];
                            if (!errors.count(key))
                            {
                                Error error = {idx + 1, str[j] - 'a' + 1, 1};
                                errors[key] = error;
                            }
                            else
                                errors[key].count++;
                        }
                    }
                }
                //
                if (rights == 0)
                {
                    scores += questions[idx].score;
                }
                else if (rights > 0)
                    scores += questions[idx].score * 0.5;
                idx++;
            }
            else
                j++;
        }
        printf("%0.1f\n", scores);
    }

    if (hasErr)
    {
        for (map<string, Error>::iterator it = errors.begin(); it != errors.end();)
        {
            sortErrors.push_back(it->second);
            it++;
        }
        sort(sortErrors.begin(), sortErrors.end(), cmp_1073);
        int max = sortErrors[0].count;
        for (int i = 0; i < sortErrors.size(); i++){
            if(sortErrors[i].count == max){
                 printf("%d %d-%c\n", sortErrors[i].count, (sortErrors[i].id + 1), sortErrors[i].idx + 'a');
            }else break;
        }
           
    }else cout << "Too simple";
}

typedef struct p_node{
    int value,next,address;
} PNode;

void pat_1025(){

    PNode nodes[100000];
    int start,n,k,idx;
    cin >> start >> n >> k;
    for(int i=0;i<n;i++){
        scanf("%d",&idx);
        scanf("%d %d",&nodes[idx].value,&nodes[idx].next);
        nodes[idx].address = idx;
    }
    PNode p;
    int left = start,num = 0;
    while(left!=-1){
       p = nodes[left];
       num ++;
       left = p.next; 
    }
    n = num;
    int keys[k];
    bool first = true;
    int next;
    while(start!=-1){
        if(n >= k){
            for(int j=0;j< k ;j++){
                p = nodes[start];
                keys[k-j-1] = p.address;
                start = p.next;
            }
            for(int j=0;j<k; j++){
                if(!first) printf(" %05d\n",nodes[keys[j]].address); 
                else first = false;
                printf("%05d %d",nodes[keys[j]].address,nodes[keys[j]].value);
            }
            n -= k;
        }else{
            p = nodes[start];
            if(!first) printf(" %05d\n",p.address); 
            else first = false;
            printf("%05d %d",p.address,p.value);
            start = p.next;      
        }
    }
    cout << " -1\n";
}

void pat_1024(){
    string p;
    cin >> p;
    int zero,i  = 0;
    bool e = false;
    while( i < p.size()){
        // 指数部分
        if(p[i]=='E') {zero = stoi(p.substr(i+1,p.size()-i));break;}
        // update i
        i++;
    }
    // positive or negivate
    bool positive = p[0]=='-'?false:true;
    // 数字部分
    p = p.substr(1,i-1);
    // 小数点去掉
    p.erase(1,1);
    if(!positive) cout << "-";
    if(zero<0){
       cout << "0.";
       p.insert(0,zero*-1-1,'0');
    }else{
        if(zero<p.size()-1) p.insert(zero+1,1,'.');
        else  p.insert(p.end(),zero - p.size()+ 1,'0');
    }
    cout << p;
}

void pat_1027(){
    int n;
    char c;
    cin >> n >> c;
    int k = 0,prev,current = prev = 1;
    while( current<= n ){
        prev = current;
        k++;
        current = 2*k*(k+2)+1;
    }
    // int max = 2*(k-1)+1;
    for(int i=k-1;i>=0;i--){
        string p;
        p.insert(0,2*i+1,c);
        p.insert(0,k-i-1,' ');
        cout << p << endl;
    }

    for(int i=1;i<k;i++){
        string p;
        p.insert(0,2*i+1,c);
        p.insert(0,k-i-1,' ');
        cout << p <<  endl;
    }

    cout << n - prev << endl;
    
}




int duration(string date){
    int year = 2014,month = 9,day = 6;
    int y,m,d;
    y = stoi(date.substr(0,4));
    m = stoi(date.substr(5,2));
    d = stoi(date.substr(8,2));
    return (year-y)*365+(month-m)*30+day-d;        
}

void pat_1028(){
    int n;
    cin >> n;
    int max = 200*365;
    string name,date;
    string old,yough;
    int validNum = 0,oldNum, youghNum ,tmp;  
    bool first = true;
    while(n--){
        cin >> name >> date;
        tmp = duration(date);
        if(tmp>= 0 && tmp <= max){
            validNum ++;
            if(first){
                youghNum = oldNum = tmp;
                yough = old = name;
                first = false;
            }else {
                if(tmp > oldNum){old = name;oldNum = tmp;}
                else if(tmp < youghNum){ yough = name;youghNum = tmp;}
            }
        }
    }
    cout << validNum ;
    if(old.size()>0) cout << " " << old;
    if(yough.size()>0) cout <<  " " << yough << endl;
}



char to_down(string s1,int p1){
     if(s1[p1]<='z' && s1[p1]>='a'){
       return (char)(s1[p1] - ('a'-'A'));
     }else return s1[p1];
}

void pat_1029(){
    string s1,s2;
    cin >> s1 >> s2;
    int p1, p2 = p1 = 0;
    int maps[256] = {0}; // ascii 
    char a,b;
    while(p1<s1.size() && p2 < s2.size()){
        a = to_down(s1,p1);
        b = to_down(s2,p2);
        if(a!=b){
            if(!maps[a-'0']){ 
                maps[a-'0'] = 1;
                cout << a;
            } 
        }else p2++; 
        p1++;
    }
    while(p1<s1.size()){
        a = to_down(s1,p1);
        if(!maps[a-'0']){
            maps[a-'0'] = 1;
            cout << a;
        }
        p1++;
    }
}


void pat_1030(){
    int n;
    long p;
    cin >> n >> p;
    int nums[n];
    for(int i=0; i < n; i++) cin >> nums[i];
    sort(nums,nums+n);
    int max = 0;
    for(int j= 0;j < n ;j++ ){
        for(int i = j + max; i < n; i++ ){
            if(nums[i] <= nums[j]*p) max = i - j + 1 > max ? i - j + 1 : max;
            else break;
        }
    }
    cout << max;
}


void pat_1032(){
    int n,maps[100001] = {0};
    cin >> n;
    int idx, score;
    while(n--){
        scanf("%d %d",&idx,&score);
        maps[idx] += score;
    }
    
    int max = maps[1],id = 1;
    for(int i= 2;i<100001;i++){
        if(max<maps[i]){
            max =maps[i];
            id = i;
        }
    }
    printf("%d %d\n",id,max);
}

void pat_1033(){
    
    // 键是否坏掉了
    int errors[128] = {0};
    string error,s2;
    getline(cin,error);
    getline(cin,s2);
    for(unsigned int i= 0;i<error.size();i++){
        // 大写字母,小写字母是坏键
        if(error[i]<='Z' && error[i]>='A'){errors[(char)(error[i]^0x20)-'+']=1;}
        // 其它均是坏键
        errors[error[i]-'+']  = 1;
    }
    // 如果上当键坏掉，所有的大写字母均是坏键
    if(errors[0]==1) for(int i='A'-'+';i<='Z'-'+';i++) errors[i] = 1;
    for(unsigned int i=0;i<s2.size();i++){
        // 键没有坏
        if(errors[s2[i]-'+']!=1){
             cout << s2[i];
        }
    }
    cout << endl;
}

// 辗转相除法
long long gcd(long long a,long long b){
    return b == 0 ? a: gcd(b,a%b);
}

// 返回运算结果
string operate_a_divide_b(long long a,long long b){
    if(a == 0) return "0";
    if(b == 0) return "INF";
    bool positive = false;
    if((a>0 && b >0)||(a<0 && b <0)) positive = true;
    a = abs(a); b = abs(b);
    // 找最大公约数 ，辗转相除法
    long long c = gcd(a,b);
    // 去掉最大公约数
    a = a/c; b = b/c;
    string res;
    // 结果
    if(a/b>0){
        res = to_string(a/b);
        if(a%b!=0)  res = res + " " + to_string(a%b) + "/" + to_string(b);
        if(!positive) res = "(-" + res + ")";
    }else res = to_string(a) + "/" + to_string(b);
    if(!positive) res = "(-" + res +")";
    return res;
}

void pat_1034(){
    long long a1,b1,a2,b2;
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    // 运算符
    string operation[4] =  {" + "," - "," * "," / "};
    string s1,s2;
    s1 = operate_a_divide_b(a1,b1) ;s2 =  operate_a_divide_b(a2,b2) + " = ";
    // 加法
    cout << s1 << operation[0] << s2  << operate_a_divide_b(a1*b2+a2*b1,b1*b2) << endl;
    // 减法
    cout << s1 << operation[1] << s2  << operate_a_divide_b(a1*b2-a2*b1,b1*b2) << endl;
    // 乘法
    cout << s1 << operation[2] << s2  << operate_a_divide_b(a1*a2,b1*b2) << endl;
    // 除法
    cout << s1 << operation[3] << s2  << operate_a_divide_b(a1*b2,b1*a2);
}


// // 插入排序
// bool insert_sort(int* nums,int n,int* next){
//     bool is = false;
//     for(int i = 1;i<n;i++){
//         is = collection_to_str(nums,n) == collection_to_str(next,n);
//         int tmp;
//         for(int j=i-1;j>=0; j--){
//             if(nums[j+1]<nums[j]){
//                 tmp = nums[j];nums[j] = nums[j+1];nums[j+1] = tmp;
//             }else break;
//         }
//         if(is) break;
//     }
//     return is;
// }

// void merge(int* nums,int start,int mid,int end,int* result,int *next,int n){
//     int i,j,k;
//     i = start;
//     j = mid+1;
//     k = 0;
//     while(i<=mid && j <= end){
//         if(nums[i]<nums[j])
//             result[k++] = nums[i++];
//         else result[k++] = nums[j++];
//     }
//     while(i<=mid) result[k++] = nums[i++];
//     while(j<=end) result[k++] = nums[j++];
//     for(i=0;i<k;i++) nums[start+i] = result[i];
// }

// // merge 排序
// void merge_sort(int *nums,int start,int end,int *result,int *next,int n){
//     if(start < end){
//         int mid = (start+end)/2;
//         merge_sort(nums,start,mid,result,next,n);
//         merge_sort(nums,mid+1,end,result,next,n);
//         merge(nums,start,mid,end,result,next,n);
//         // 对比一下是否相等
//     }
// }


void pat_1035(){
    int n,i,j,nums[100],next[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++)
        cin >> next[i];
    for(i=0;i<n-1 && next[i] <= next[i+1];i++);
    for(j=i+1;j<n && nums[j]==next[j];j++);
    if(j==n){
        cout << "Insertion Sort\n";
        sort(nums,nums+i+2);
    }
    else {
        // 无需如此
        cout << "Merge Sort\n";
        // 找到 merge 的长度即可
        int k = 1,is = 1;
        while(is){
            is = 0;
            for(i =0 ;i<n;i++) if(nums[i]!=next[i]) is = 1;
            k = k*2;
            for(int i=0; i< n/k ;i++) sort(nums+i*k,nums+(i+1)*k);
            sort(nums+n/k*k,nums+n);
        }
    }
    for(i =0 ;i<n ;i++) {
        if(i!=0) cout << " ";
        cout << nums[i];
    }
}

void pat_1037(){
    int g1,s1,k1,g2,s2,k2;
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    long num1,num2,res;
    num1 = (g1*17+ s1)*29 + k1;  
    num2 = (g2*17+ s2)*29 + k2;
    res = num2-num1;
    if(res<0) cout << "-";
    res = abs(res);
    // 多少加隆
    cout << res/(17*29) << ".";
    res = res%(17*29);
    // 多少sickle
    cout << res/29 << ".";
    res = res%(29);
    // 多少 knu t
    cout << res;
}


void pat_1038(){
    int scores[101] = {0};
    int n,score,k;
    cin >> n;
    while(n--){
        scanf("%d",&score);
        scores[score] ++;
    }
    cin >> k;
    for(int i= 0;i<k;i++){
        scanf("%d",&score);
        cout << scores[score];
        if(i!=k-1) cout << " ";
    }
    
}

void pat_1039(){
    string s1,s2;
    unsigned int i;
    getline(cin,s1);
    getline(cin,s2);
    int givens[127] = {0};
    for(i = 0;i<s1.size(); i++) givens[s1[i]-'0']++;
    for(i = 0;i<s2.size(); i++) givens[s2[i]-'0']-- ;
    
    int left, offset = left = 0;
    for(i =0; i < 127; i++){
        if(givens[i]>0) left += givens[i];
        else if(givens[i]<0) offset += givens[i];
    }
    if(offset<0) printf("No %d",offset*-1);
    else printf("Yes %d",left);
}


void pat_1042(){
    string s;
    getline(cin,s);
    int nums[26] = {0},max = 0,i ;
    char t;
    for(i = 0;i<s.size();i++){
        t = s[i];
        // 大写改小写
        if((t<='Z'&&t>='A')) t = t^0x20;
        if(t<='z'&&t>='a'){
            nums[t-'a'] ++;
            if(max<nums[t-'a']) max = nums[t-'a'];
        }
    }

    for(i=0;i<26;i++){
        if(nums[i]==max){
            printf("%c %d",(char)(i+'a'),nums[i]);
            break;
        }
    }

}

int main(){
    pat_1042();
    return 0;
}