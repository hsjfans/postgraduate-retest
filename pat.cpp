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

int main()
{
    pat_1015();
    return 0;
}
