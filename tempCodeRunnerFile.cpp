void split_str(string str)
{
    int start = 2;
    for (int i = start; i < str.length(); i += 4)
    {
        if (str[i] == 'T')
        {
            cout << (str[i - 2] - 'A');
            return;
        }
    }
}

void pat_1076()
{
    int n;
    cin >> n;
    string str;
    while (n > 0)
    {
        cin >> str;
        split_str(str);
        n--;
    }
}

int main()
{
    pat_1076();
    return 0;
}