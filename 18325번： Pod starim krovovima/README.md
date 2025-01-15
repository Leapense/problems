# 18325번: Pod starim krovovima - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18325)


<p><strong>Setting</strong>: Legendary Zagrebian Inn called Kod Žnidaršića.</p>

<p><strong>Time</strong>: The year 1936.</p>

<p><strong>Plot summary</strong>: Franjo and his friends are discussing the current events in Abyssinia while enjoying a couple of drinks at the bar. His son, little Perica, is sitting at a small table in the corner of the bar. In front of Perica there are N glasses conveniently numbered from 1 to N. The volume (in nanoliters) of each glass is known as well as the amount of liquid that is currently inside it.</p>

<p><strong>Problem</strong>: Little Perica wants to know what is the largest possible number of glasses that can be emptied by pouring the liquid between glasses. He can freely pour any integer number of nanoliters from one glass to another, as many times as he wants, as long as no liquid is spilled over.</p>

<p>Your task is to output the number of empty glasses along with one possible configuration of liquid in all glasses. If there are multiple configurations that yield the same number of empty glasses, output any of them. Note that it is not necessary to minimize the number of times liquid was poured between two glasses.</p>



## 입력


<p>The first line contains an integer N (1 ≤ N ≤ 1 000) from the task description.</p>

<p>Each of the next N lines contains two integers T<sub>i</sub> (0 ≤ T<sub>i</sub> ≤ 10<sup>9</sup>) and Z<sub>i</sub> (1 ≤ Z<sub>i</sub> ≤ 10<sup>9</sup>) which, in that order, represent the current amount of liquid in the i-th glass and its volume. Both quantities are given in nanoliters and the current amount of liquid cannot be greater than the volume of the glass, i.e. T<sub>i</sub> ≤ Z<sub>i</sub> holds.</p>



## 출력


<p>In the first line you should output the largest number of glasses that can be emptied by pouring the liquid between glasses.</p>

<p>In the second line you should output the amount of liquid in each of the glasses after Perica has performed the necessary pourings. The glasses should be ordered from glass numbered 1 to glass numbered N.</p>



## 소스코드

[소스코드 보기](Pod%20starim%20krovovima.cpp)