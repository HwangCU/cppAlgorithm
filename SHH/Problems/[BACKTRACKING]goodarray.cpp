#include <iostream>
using namespace std;

int N;
int flag;
int path[100];

void printpath(int level)
{
    for (int i = 0; i < level; i++)
        cout << path[i];
}

bool isGood(int level)
{
    int len = (level + 1) / 2;
    for (int i = 1; i <= len; i++)
    {
        int cnt = 0;
        for (int j = 0; j < i; j++)
        {
            if (path[level - j] == path[level - j - i])
                cnt++;
        }
        // 만약 인접한 수열이 완벽하게 일치한다면
        if (cnt == i)
            return false; // 좋은 수열이 아니다.
    }
    return true;
}

void func(int level)
{
    if (level == N)
    {
        flag = 1;
        printpath(level);
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        path[level] = i;
        if (isGood(level))
        {
            func(level + 1);
            if (flag == 1)
                return;
        }
        path[level] = 0;
    }
}

int main()
{
    cin >> N;
    func(0);
}