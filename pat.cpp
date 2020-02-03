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
    map<string, vector<string>> maps;
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
    int n,d;
} Node;

void pat_1075()
{
    int start,num, k,a,d,n,data;
    scanf("%d %d %d",&start,&num,&k);
    vector<int> v[3];
    Node maps[100000];
    while (num--)
    {
        scanf("%d",&a);
        scanf("%d %d",&maps[a].d,&maps[a].n);   
    }
    // 恢复次序
    while(start!=-1){
        data = maps[start].d;
        if(data<0) v[0].push_back(start);
        else if(data<=k) v[1].push_back(start);
        else v[2].push_back(start);
        start = maps[start].n;
    }
    bool first = true;
    for (int i=0;i<3;i++)
    {
        for(unsigned int j=0;j<v[i].size();j++){

            if (first)
                first = false;
            else
                printf("%05d\n",v[i][j]);
            printf("%05d %d ",v[i][j],maps[v[i][j]].d);
        }
    }
    cout << "-1" << endl;
}

void pat_1074(){
    string code,a,b;
    cin >> code >> a >> b;
    string result;
    int up=0,sum=0,p;
    int n = code.size()-1;
    a.insert(0,n-a.size()+1,'0');
    b.insert(0,n-b.size()+1,'0');
    while(n>=0){
        sum = (a[n]-'0')+(b[n]-'0')+up;
        p = code[n]=='0'?10:code[n]-'0';
        up = sum/p;
        result += (sum % p+'0');
        n--;
    }
    if(up!=0) result+=(up+'0');
    bool ok = false;
    for(int j=result.size()-1;j>=0;j--){
        if(result[j]>'0') ok = true;
        if(ok) cout << result[j];
    }
    if(!ok) cout << "0";

}

int main(){
    pat_1074();
    return 0;
}