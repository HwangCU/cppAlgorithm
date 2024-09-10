#include <iostream>
#include <vector>
using namespace std;

int Arr[10];
bool visited[10];
int N, result, Sum;

//3 N 개수
//1 2 4 들어온 숫자들(각각 다름)

void func(int now,int left, int right) {
    //기저조건
    if (now == N) {
        result++;
        return;
    }

    if (left >= Sum - left) {
        int remain = N - now; //3
        int permuatations = 1;

        permuatations = 1 << remain; // 2^remain

        for (int i = remain; i > 0; i--) {
            permuatations = permuatations * i;
            //8 * 3
            //24 * 2 48
        }


        result += permuatations;
        return;
    }


    for (int i = 0; i < N; i++) {

        if (visited[i] == true) continue;

        visited[i] = true;



        //push_back(Arr[i])
        func(now + 1, left + Arr[i], right);

        if (right + Arr[i] <= left) {
            func(now + 1, left, right + Arr[i]);
        }


        visited[i] = false;
    }
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        cin >> N;
        result = 0;
        Sum = 0;

        for (int i = 0; i < N; i++) {
            visited[i] = false;
        }


        for (int i = 0; i < N; i++) {
            cin >> Arr[i]; //Arr[0] = 1 Arr[1] = 2 Arr[2] =4
            Sum = Sum + Arr[i]; //7
        }
        //cout << Sum;
        func(0,0,0);



        cout << "#" << t + 1 << " " << result << "\n";
    }


    return 0;
}