# 매일 알고리즘 정리
## 2024.08-13 (화) 

## Union Find

1. 어떤 사람이, 어떤 그룹에 속해 있는지?

- 어느 그룹에 속해 있는지 궁금하다.

2. 어떤 두 사람을 뽑았더니 같은 그룹에 속해 있는지? 

- 생일이 같을까?

값이 같은 것을 앞에서부터 하나하나 그룹으로 묶는 형태

find 재귀 함수 사용, 그래프 구조 표현

구현

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// 부모 노드
int parent[10];
// 각 사람의 생일을 나타내는 배열
int birthdays[10] = { 8, 2, 2, 8, 3, 3, 12, 12, 6, 8 };

int find(int tar)
{
    if (tar == parent[tar])
        return tar;

//  경로압축
//  int ret = find(parent[tar])
//  parent[tar]=ret;
//  return paretn[tar];
    return find(parent[tar]);
}

void setUnion(int a, int b)
{
    int t1 = find(a);
    int t2 = find(b);

    if (t1 == t2)
        return;

    parent[t2] = t1;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        parent[i] = i;
    }

    // 생일이 같은 사람들끼리 집합을 만듭니다.
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (birthdays[i] == birthdays[j])
            {
                setUnion(i, j);
            }
        }
    }

    // 각 사람이 어떤 집합에 속하는지 출력합니다.
    for (int i = 0; i < 10; i++)
    {
        cout << i << "는" << find(i) << "그룹에 속해있습니다." << endl;
    }

    return 0;
}
```


### 경로 압축 Path Compression

Root로 전부 묶어버린다
find함수 수정

```c++
//  경로압축
//  int ret = find(parent[tar])
//  parent[tar]=ret;
//  return paretn[tar];
```
## MST

### 최소신장트리 Minimum Spanning Tree

- 다음과 같은 조건을 만족하는 그래프

1. 모든 노드를 포함한다.
2. edge의 개수는 N-1개
3. 사이클 없음
4. 최소한의 비용을 사용한다

> 도시계획 - 수로, 전기, 도로, 배관, 네트워크

두가지 방법이 있다.
- Cruscal - Union Find 활용 MST만들기
- Prim

### Cruscal

- edge의 cost를 오름차순 정렬 후 낮은 순으로 넣는다

- union find의 find함수를 사용해 같은 그룹인지 아닌지 cycle을 체크한다.

- edge의 개수가 N-1이면 끝낸다

```c++

```

## Flood Fill

### SWEA 1953. 탈주범 검거

문제 

---

```plain

교도소로 이송 중이던 흉악범이 탈출하는 사건이 발생하여 수색에 나섰다.

탈주범은 탈출한 지 한 시간 뒤, 맨홀 뚜껑을 통해 지하터널의 어느 한 지점으로 들어갔으며,

지하 터널 어딘가에서 은신 중인 것으로 추정된다.

터널끼리 연결이 되어 있는 경우 이동이 가능하므로 탈주범이 있을 수 있는 위치의 개수를 계산하여야 한다.

탈주범은 시간당 1의 거리를 움직일 수 있다.

탈주범이 탈출 한 시간 뒤 도달할 수 있는 지점은 한 곳이다.

3시간 후에는 [그림 1-4] 과 같이 총 5개의 지점에 있을 수 있다.

```
---

### 지문 속 중요한 구문

> 한 시간 뒤, 맨홀 뚜껑을 통해 지하터널의 어느 한 지점으로 들어갔다

- L(시간)이 1일 경우 탈주범이 할 수 있는건 하나다. 

> 터널끼리 연결이 되어 있는 경우 이동이 가능하다

> 탈주범은 시간당 1의 거리를 움직일 수 있다.

> 맨홀 위치가 주어진다.

- 맨홀 위치부터 터널을 따라 퍼지는 flood fill

---
### 아이디어

- 파이프는 현재 뿐만 다음 좌표의 파이프도 고려해야한다.

- BFS - Flood fill문제

- now에서 next로 간다

- next에서 now로 올 수 있는지 확인한다.<중요>
