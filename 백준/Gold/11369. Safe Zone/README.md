# [Gold V] Safe Zone - 11369 

[문제 링크](https://www.acmicpc.net/problem/11369) 

### 성능 요약

메모리: 2032 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 5월 5일 23:45:53

### 문제 설명

<p>Saruman’s army has mounted their seige upon Helm’s Deep, and are unleashing volley after volley of arrows on its walls – but the Rohirrim have only enough shields to defend a segment of Helm’s Deep’s walls! The Uruk-hai orcs are beating at the gate, and Saruman himself assaults your walls with sorcerous missiles cast from his tower at Isengard. You are a soldier in King Theoden’s army – with the walls shaking under your very feet, you must make your way to cover before the next volley of arrows land!</p>

<p>From left to right, the segments of the wall are labelled 0 to (N-1), and you are currently at segment J. The Rohirrim shields cover from P to Q, and you have time to make exactly K steps (each step can be either left or right) before the next volley of arrows lands (the wall’s rumbling makes it impossible to stand still). How many different combinations of steps can get you to safety?</p>

### 입력 

 <p>Input is given in the form of a single line per test case, with the order N P Q J K. The size of the wall is N, the safe zone is from P to Q, the starting position is at J, and the number of steps is K. A line with N equal to 0 marks the end of input and should not produce output.</p>

<p>Note that you cannot walk off the end of the wall. This means that if you are at either end of the wall, you must walk toward the center.</p>

### 출력 

 <p>For each test case, output on one line the number of ways to end up in the safe zone in K steps.</p>

