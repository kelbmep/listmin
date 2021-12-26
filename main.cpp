#include <bits/stdc++.h>

using namespace std;
unsigned int fast_atoi(const char* str)
{
    unsigned int val = 0;
    while(*str)
        val = val * 10 + (*str++ - '0');
    return val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int> sorted;
    list<int> numbers;
    int q, min = 1000000001;
    string s;
    cin >> q;
    string *op = new string[q + 1];
    getline(cin, s);
    for(int i = 0; i < q; i++)
        getline(cin, op[i]);
    int x = 0;
    for(int i = 0; i < q; i++)
    {
        string action = op[i].substr(0, 2);
        if(action == "+L")
        {
            x = fast_atoi((op[i].substr(3, op[i].length() - 3)).c_str());
            numbers.push_front(x);
            sorted[x]++;
            if(x < min || numbers.size() == 1)
                min = x;
            cout << min << "\n";
        }
        else if(action == "+R")
        {
            x = fast_atoi((op[i].substr(3, op[i].length() - 3)).c_str());
            numbers.push_back(x);
            sorted[x]++;
            if(x < min || numbers.size() == 1)
                min = x;
            cout << min << "\n";
        }
        else if(action == "-L")
        {
            int del = *numbers.begin();
            numbers.pop_front();
            if(sorted[del] == 1)
                sorted.erase(del);
            else
                sorted[del]--;
            min = sorted.begin()->first;
            if(numbers.size() == 0)
                cout << -1 << "\n";
            else
                cout << min << "\n";
        }
        else if(action == "-R")
        {
            int del = *numbers.rbegin();
            numbers.pop_back();
            if(sorted[del] == 1)
                sorted.erase(del);
            else
                sorted[del]--;
            min = sorted.begin()->first;
            if(numbers.size() == 0)
                cout << -1 << "\n";
            else
                cout << min << "\n";
        }
    }
    return 0;
}
