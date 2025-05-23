# 15141번: Kotlin Island - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15141)


<p>There is an urban myth that Peter the Great wanted to make a rectangular channel-grid engineering masterpiece not only from Vasilyevskiy island, but also from Kotlin island (where the town of Kronstadt is located nowadays).</p>

<p>The following mathematical model was (allegedly) presented to the tsar. The island is considered a rectangular grid h cells high and w cells wide. Each cell is dry land initially but can become water.</p>

<p>Technologies of those days allowed engineers to dig a channel across the entire island. In that case an entire row or an entire column of cells became water. If some of these cells already were water, their status did not change.</p>

<p>Your task is to propose a plan of the island which has exactly n connected components of dry land cells.</p>



## 입력


<p>The only line of the input contains three integers h, w, and n — grid’s height, width and the desired number of connected components (1 ≤ h, w ≤ 100; 1 ≤ n ≤ 10<sup>9</sup>).</p>



## 출력


<p>If there is no valid plan containing n connected components, output a single word “Impossible”.</p>

<p>Otherwise output h lines of length w depicting the plan. Dot (‘.’) represents a dry land cell, hash (‘#’) represents a water cell.</p>



## 소스코드

[소스코드 보기](Kotlin%20Island.cpp)