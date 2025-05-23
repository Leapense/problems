# 26022번: Lots of Land - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26022)


<p>Farmer Robert has been running a very successful cereal farm for many years. Now he wants to diversify his business and get into growing potatoes. To this end, he has bought a new plot of land on which he plans to plant the potatoes. This field is a rectangle and is exactly $\ell$ metres long and $w$ metres wide.</p>

<p>Since Robert is new to the potato business, he has initially purchased $n$ different potato varieties to try out in the first year. He plans to divide his plot of land into $n$ parts of equal area and plant one of the varieties on each. To make it easier for him to work the fields with his tractor, each new piece of land should itself be a rectangle and have integer side lengths. Help Robert to find a suitable division of his field.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with three integers $\ell, w, n$ ($1 \le \ell,w \le 100$, $1 \le n \le 26$), the length and width of Robert's field and the number of potato varieties.</li>
</ul>



## 출력


<p>If there is no solution, output <code>impossible</code>. Otherwise output $\ell$ lines, each with $w$ uppercase letters, describing a possible division of Robert's field. There should be the same number of occurrences of each of the first $n$ letters of the English alphabet, and for each letter, its occurrences should form a single rectangular region. If there is more than one solution, any one of them will be accepted.</p>



## 소스코드

[소스코드 보기](Lots%20of%20Land.cpp)