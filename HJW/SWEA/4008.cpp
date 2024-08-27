// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeRZV6kBUDFAVH
// 4008. 숫자 만들기


#include <iostream>

using namespace std;

int N, M; // 숫자 카드, 연산자 카드 수
int max_sum;
int min_sum;

int num_card[12];
int opt_card[11];
int opt_card_cnt[4];  // +, -. *, /

int cnt[4] = {0};

void init()
{
    fill(num_card, num_card + 12, 0);
    fill(opt_card, opt_card + 11, 0);
    fill(opt_card_cnt, opt_card_cnt + 4, 0);

    max_sum = -10e8;
    min_sum = 10e8;
}

void input()
{
    cin >> N;
    M = N - 1;

    for (int i = 0; i < 4; i++)
    {
        cin >> opt_card_cnt[i];
    }


    for (int i = 0; i < N; i++)
    {
        cin >> num_card[i];
    }
}

void dfs(int lvl, int sum)
{
    if (lvl == M)
    {
        if (sum > max_sum)
        {
            max_sum = sum;
        }
        if (sum < min_sum)
        {
            min_sum = sum;
        }
        return;
    }

    if (opt_card_cnt[0] > 0)
    {
        opt_card_cnt[0]--;
        dfs(lvl + 1, sum + num_card[lvl+1]);
        opt_card_cnt[0]++;
    }
    if (opt_card_cnt[1] > 0)
    {
        opt_card_cnt[1]--;
        dfs(lvl + 1, sum - num_card[lvl+1]);
        opt_card_cnt[1]++;
    }
    if (opt_card_cnt[2] > 0)
    {
        opt_card_cnt[2]--;
        dfs(lvl + 1, sum * num_card[lvl+1]);
        opt_card_cnt[2]++;
    }
    if (opt_card_cnt[3] > 0)
    {
        opt_card_cnt[3]--;
        dfs(lvl + 1, sum / num_card[lvl+1]);
        opt_card_cnt[3]++;
    }

}

void output(int t)
{
    cout << "#" << t+1 << " " << max_sum-min_sum << "\n";
}

int main()
{
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        init();
        input();
        dfs(0, num_card[0]);
        output(i);
    }

    return 0;
}