# 15322번: Košnja - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15322)


<p>Mirko wants to buy land on which he will build a house for his family. So far, he’s seen K pieces of land. Each of them is in the shape of a rectangle and we can think of it as a matrix with N rows and M columns, N × M fields in total.</p>

<p>Mirko is aware that, before construction begins, the property needs to be regularly maintained and the lawn needs to be mowed. Because of this, Mirko bought a lawn mower. In order to mow the entire lawn of N rows and M columns, he needs to go over each field at least once. He can start from any field facing one of the four main directions (up, down, left, and right). His lawn mower can only go forwards (to the adjacent field facing the current direction) or make a 90 degree turn. Additionally, because of his own safety, Mirko can only use the lawn mower on his land, so he cannot leave the matrix.</p>

<p>Since making the lawn mower turn isn’t simple, Mirko wants to mow the lawn with the minimal amount of turns. For each piece of land he saw so far, Mirko wants to know the minimal number of turns he can make so that the entire lawn is mowed. Help Mirko solve this problem.</p>



## 입력


<p>The first line of input contains the positive integer K (1 ≤ K ≤ 50 000), the number from the task.</p>

<p>Each of the following K lines contains two positive integers N and M (1 ≤ N, M ≤ 1 000 000), the numbers from the task.</p>



## 출력


<p>For each piece of land Mirko saw so far, output in a separate line the minimal amount of turns he can take so that the entire lawn is mowed.</p>



## 소스코드

[소스코드 보기](Košnja.py)