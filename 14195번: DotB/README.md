# 14195번: DotB - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14195)


<p>The new DotA game is coming out soon. All the fans around the world are waiting to try the new version of DotA: ”DotB”.</p>

<p>There’s a lot of pressure on the developers of the game to add new heroes to it. They come up with ideas but not all of them are worth implementing. For one particular hero they are working on, they asked you to write a program to analyze one of its abilities. The hero’s name is ”Cave Man”, and his ability is to summon a crow to attack a line of enemies.</p>

<p>The line has n enemies with hitpoint h<sub>1</sub>h<sub>2</sub>...h<sub>n</sub>. The crow always starts at the first enemy and attacks each one and goes to the next. It attacks exactly n + 5 times in total, and if it reaches the end of the line, it continues the attack from the other end of the line.</p>

<p>The crow has the damage C. Which means C would be deducted from the enemy’s hitpoint if it receive an attack. If an enemy’s hitpoint hits zero or less, well ... he’s dead.</p>

<p>If the crow’s attack causes death of an enemy, the crow reverses its movement direction.</p>

<p>Now it’s your task to find which enemy receives the last attack of the crow, given the enemies’ hitpoint and the crow’s damage.</p>



## 입력


<p>The first line contains the number of test cases T.</p>

<p>Each test case begins with two space-separated integers n (2 ≤ n ≤ 32) and C (32 ≤ C ≤ 128). Then comes n integers indicating the initial hitpoint of the enemies. The ith integer indicates the hitpoint of ith enemy in the line.</p>



## 출력


<p>For each test case, print a single line containing the serial number of the enemy the crow finally attacks.</p>



## 소스코드

[소스코드 보기](DotB.py)