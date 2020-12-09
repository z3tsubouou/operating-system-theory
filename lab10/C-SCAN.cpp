#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j, k, n = 1000, m = 5000, sum = 0, x, y, h;
    vector<int> a(n), b;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 100 + 1;
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] > m)
        {
            cout << "Error, Unknown position " << a[i] << "\n";
            return 0;
        }
    }
    cout << "Толгойн эхний байрлалыг оруулнуу:\n";
    cin >> h;
    int temp = h;
    a.push_back(h);
    a.push_back(m);
    a.push_back(0);
    sort(a.begin(), a.end());
    for (i = 0; i < a.size(); i++)
    {
        if (h == a[i])
            break;
    }
    k = i;
    if (k < n / 2)
    {
        for (i = k; i < a.size(); i++)
        {
            b.push_back(a[i]);
        }
        for (i = 0; i <= k - 1; i++)
        {
            b.push_back(a[i]);
        }
    }
    else
    {
        for (i = k; i >= 0; i--)
        {
            b.push_back(a[i]);
        }
        for (i = a.size() - 1; i >= k + 1; i--)
        {
            b.push_back(a[i]);
        }
    }
    temp = b[0];
    cout << temp;
    for (i = 1; i < b.size(); i++)
    {
        cout << " -> " << b[i];
        sum += abs(b[i] - temp);
        temp = b[i];
    }
    cout << '\n';
    cout << "Нийт толгойн шилжилт = " << sum << '\n';
    cout << "Дундаж толгойн шилжилт = " << (float)sum / n << '\n';
    return 0;
}