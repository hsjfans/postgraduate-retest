void pat_1086()
{
    int a, b, tmp;
    cin >> a >> b;
    int g = a * b;
    int bitwide = 0;
    while (g >= pow(10, bitwide))
    {
        bitwide++;
    }
    // cout << bitwide << "\n";
    int high;
    int cache[bitwide];
    for (int i = bitwide - 1; i >= 0; i--)
    {
        tmp = pow(10, i);
        high = g / tmp;
        g = g - tmp * high;
        // cout << high;
        cache[i] = high;
    }
    for (int i = 0; i < bitwide; i++)
    {
        cout << cache[i];
    }
}

int main()
{
    pat_1086();
    return 0;
}