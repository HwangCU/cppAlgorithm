// 필터의 다른 사용법
// id 가 123 인 것만 배열로 뽑아내시오.
// 즉, 사이즈가 1인 배열이 되어야 합니다!
const menus = [
    {
      id: 123,
      name: "짜장면",
      isPossible: true,
    },
    {
      id: 456,
      name: "짬뽕",
      isPossible: true,
    },
    {
      id: 789,
      name: "탕수육",
      isPossible: false,
    },
  ];
  
  const foundMenu = menus.filter((menu) => menu.id === 123);
  console.log(foundMenu);