#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int main()
{
    int i, j, k, n = 1000, m = 5000, sum = 0, x, y, h;
    vector<int> a(n);
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
    cout << temp;
    for (i = 0; i < n; i++)
    {
        cout << " -> " << a[i] << ' ';
        sum += abs(a[i] - temp);
        temp = a[i];
    }
    cout << '\n';
    cout << "Нийт толгойн шилжилт = " << sum << '\n';
    cout << "Дундаж толгойн шилжилт = " << (float)sum / n << '\n';
    return 0;
}