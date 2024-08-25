# JavaScript 공부

## 호이스팅

- 호이스팅 변수호이스팅은 오직 var만 가능
- 함수 호이스팅은 함수선언식만 가능

## 변수의 범위

- 블록레벨 스코프 const, let은 블록레벨 (중괄호)
- 함수레벨 스코프 var은 함수레벨 스코프(function)

## 애로우 펑션의 축약

- 내용이 한줄이면 중괄호 생략
- 한줄이 리턴이면 리턴생략


## if 긍정과 부정

- false, null , undefined, 0 ,"" 만 부정의 5가지
- []와 {}은 긍정이다 빈 배열, 빈 객체

## map

- map은 복사용, =으로 값 복사가 안되는 js
- map의 파라미터는 함수

```js
const arr = [1,2,3,4,5];
const newarr = arr.map((el)=>el+1);
```

## 길이가 유동적으로 변하는 리스트

```js
const menus = ["짜장","짬뽕","탕수육"];
const ul = document.querySelector("ul");

const tempmenu = menus.map((e)=>`<li>${e}</li>`);

const parsedmenu = tempmenu.join('');
ul.innerHTML=parsedmenu;
```

## foreach

- Map은 리턴있다. foreach는 없다
- Map에서는 const newarr = arr.map();형식이였다면
- foreach는 직접사용한다 리턴없다

### 만약 홀수만 넢고 싶다면?

```js
const nums = [1,2,3,4,5];
const odd = [];

nums.foreach((num)=>{
    if(num%2==1)
    odd.push(num);
})
```

## filter

- filter도 map처럼 return이 있다
- 하지만 map은 사이즈가 항상 똑같은데
- filter는 조건으로 true가 되는 값만 리턴한다

1. 필터링

2. 탐색

## Class 
