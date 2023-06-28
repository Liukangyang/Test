#include<iostream>
#include<string>
using namespace std;


void Getnext(string t, int* next)
{
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.length() - 1)
    {
        if (k == -1 || t[k] == t[j])
        {
            j++; k++;
            next[j] = k;
            //next[++j]=++k;
        }
        else
            k = next[k];
    }

}


int KMP(string& s, string& t)
{
    int i = 0, j = 0;
    int* next = new int[t.length()];
    Getnext(t, next);
    for (int k = 0; k < t.length(); k++)
        cout << next[k] << " ";
    cout << endl;

    while (i < int(s.length()) && j < int(t.length()))
    {
        if ((j == -1) || (s[i] == t[j]))
        {
            i++;
            j++;
        }
        else j = next[j]; //子串指针回溯，主串指针不回溯
    }

    cout << i << endl;//i总是0?
    cout << j << endl;//j总是-1！！！！！！！！！
    if (j >= int(t.length()))
    {
        cout << i << " " << j << endl;   //?问题！！！！！！！！！！！！！
        return i - j + 1;  //匹配时，返回子串首字符在主串中的位置
    }
    else
        return -1;
}


int main()
{
    string s, t;
    cout << "输入主串:";
    cin >> s;
    cout << s.length() << endl;
    cout << "输入子串:";
    cin >> t;
    cout << t.length() << endl;

    int result = KMP(s, t);

    if (result == -1) cout << "子串与主串不匹配" << endl;
    else cout << "子串与主串匹配,匹配起始位置为:" << result << endl;

    system("pause");
    return 0;
}