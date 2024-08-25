// reduce => 누적해서 새로운 값을 만든다.

const arr = [1, 2, 3, 4, 5];

const newArr = arr.reduce((acc, cur) => [...acc, cur + 1], []);

console.log(newArr);


const h1 = document.querySelector("h1");

h1.setAttribute("class", "red");


//호이스팅 변수호이스팅은 오직 var만 가능
//함수 호이스팅은 함수선언식만 가능
//블록레벨 스코프 const, let은 블록레벨 (중괄호)
//함수레벨 스코프 var은 함수레벨 스코프(function)

//애로우 펑션의 축약
// 내용이 한줄이면 중괄호 생략
// 한줄이 리턴이면 리턴생략

//긍정과 부정
//false, null , undefined, 0 ,"" 만 부정의 5가지

// []와 {}은 긍정이다 빈 배열, 빈 객체

//map을 왜써야할까?
// 복사용으로

//map , filter, foreach
