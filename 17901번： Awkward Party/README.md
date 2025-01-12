# 17901번: Awkward Party - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17901)


<p>Martin has invited everyone he knows to celebrate his 535th birthday, and a whopping n people from all over the world have accepted the invitation.</p>

<p>When deciding the seating arrangement, Martin’s mother Margarethe have decided that all the guests should be seated with maximum awkwardness; this is to ensure that nobody has anything meaningful to discuss during dinner, and everyone would instead silently enjoy her rather tasty coriander soup (as the saying goes; “when the food is good, conversation dies”).</p>

<p>Margarethe knows that awkwardness is maximized if the guests are seated in a long row along a single table, in such a way that nobody sits next to someone speaking the same language as themselves. Better yet, she has defined the awkwardness level of a seating arrangement to be the minimum number of seats separating any two guests speaking the same language. If no two people speak the same language, the awkwardness level is defined to be n (the number of guests). Two seats next to each other are said to be separated by 1.</p>

<p>Given the languages spoken in a proposed seating arrangement, can you help Margarethe determine the awkwardness level?</p>



## 입력


<p>The first line contains an integer n (1 ≤ n ≤ 100 000) denoting the number of guests. On the second line follows n integers, the i’th of which x<sub>i</sub> (0 ≤ x<sub>i</sub> ≤ 10<sup>9</sup>) indicating the language spoken by the guest seated at position i in the proposed arrangement (each guest speaks exactly one language).</p>



## 출력


<p>A single integer, the awkwardness level of the proposed seating arrangement.</p>



## 소스코드

[소스코드 보기](Awkward%20Party.cpp)