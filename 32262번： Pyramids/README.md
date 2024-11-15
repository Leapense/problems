# 32262번: Pyramids - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32262)


<p>Everyone knows that Pharaoh Khufu was a great ruler, but many are unaware that he was also a fashion enthusiast. Back in the day, he had $N$ pyramids numbered from $0$ to $N - 1$, with pyramid $i$ ($0 ≤ i &lt; N$) consisting of $A[i]$ stones. He also had the latest catalogue of the most fashionable pyramids of the year. The catalogue consists of $N$ pyramids numbered from $0$ to $N - 1$, with pyramid $i$ ($0 ≤ i &lt; N$) consisting of $B[i]$ stones.</p>

<p>For any $x$ and $y$, such that $0 ≤ x ≤ y &lt; N$, we define a <strong>range of pyramids</strong> $A[x..y]$ to be a sequence $A[x], A[x + 1], \dots , A[y]$. We also define a range of pyramids $B[x..y]$ analogously.</p>

<p>Every day, Khufu would browse the catalogue and choose two ranges of pyramids $A[L..R]$ and $B[X..Y ]$ where $R - L = Y - X$ (the values of $L$, $R$, $X$ and $Y$ may be different every day). After that, he would like to know whether it's possible to <strong>transform</strong> his range $A[L..R]$ to become equal to the catalogue's range $B[X..Y ]$. Transforming a range consists of performing the following step an arbitrary number of times: take one stone from a pyramid within the range and move it to an adjacent pyramid within the range.</p>

<p>Your task is to answer multiple questions of the following form. Given four integers $L$, $R$, $X$, and $Y$, determine whether it is possible to transform $A[L..R]$ into $B[X..Y ]$. Note that the number of stones in each pyramid never actually changes, Khufu only wonders if one range could be transformed into the other one.</p>



## 입력





## 출력





## 소스코드

[소스코드 보기](Pyramids.cpp)