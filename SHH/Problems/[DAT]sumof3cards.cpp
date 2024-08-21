#include <iostream>
using namespace std;

int DAT[100001];  // 각 숫자의 존재 여부를 저장하는 배열 (최대 숫자 100000)
int arr[5000];    // 입력된 숫자들을 저장하는 배열

int main() {
	int N, K;    // N은 숫자의 개수, K는 목표 합
	cin >> N >> K; // N과 K를 입력 받음
	for (int i = 0; i < N; i++) {
		cin >> arr[i];   // 숫자들을 입력 받아 arr 배열에 저장
		DAT[arr[i]] = 1; // 해당 숫자가 존재함을 표시
	}

	int cnt = 0; // 세 수의 합이 K가 되는 경우의 수를 세기 위한 변수
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int target = K - (arr[i] + arr[j]); // 세 번째 숫자를 계산
			if (target < 0 || target > 100000)  // target이 범위를 벗어나면 무시
				continue;
			// target이 arr[i]와 arr[j]가 아니고, DAT에 존재하는 경우
			if (target != arr[i] && target != arr[j] && DAT[target] == 1) {
				cnt++; // 조건을 만족하는 경우를 세기
			}
		}
	}

	cout << cnt / 3; // 각 경우가 3번씩 세어지므로 3으로 나눔
	return 0;
}
