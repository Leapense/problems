# 31448번: Ascending hike - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31448)


<p>Participating in the Olympics requires training, e.g., climbing from deep valleys to high peaks. Hence, you decided to go out for a hike in which you would be continuously walking on an upward slope, with the largest possible elevation gain.</p>

<p>You have noted the altitude of several remarkable points through which your hike would go: these altitudes are pairwise distinct integers $A_1, A_2, \dots , A_N$. The slope between the $k$<sup>th</sup> and $(k + 1)$<sup>th</sup> remarkable points is upward if $A_k &lt; A_{k+1}$, and downward if $A_k &gt; A_{k+1}$ . Given this list of altitudes, what is the maximal elevation gain of a continuously upward slope on your hike?</p>



## 입력


<p>The input consists of two lines. The first line contains the number $N$. The second line contains $N$ space-separated integers $A_1, A_2, \dots , A_N$.</p>



## 출력


<p>The output should contain a single line, consisting of a single number: the maximal integer $G$ for which there exist integers $k, k + 1, k + 2, \dots , \ell$ such that $A_k &lt; A_{k+1} &lt; A_{k+2} &lt; \dots &lt; A_{\ell} = A_k + G$.</p>



## 소스코드

[소스코드 보기](Ascending%20hike.py)