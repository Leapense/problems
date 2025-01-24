# 24245번: Irritating accountants - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24245)


<p>You are shopping on behalf of a company for a big upcoming event and the pesky accountants ask you to sort the items you buy according to their own rigid standards. Why you ask? Nobody knows except for the accountants.</p>



## 입력


<p>The first line of input contains two space-separated integers $1 \leq n \leq 10^5$ and $1 \leq k \leq 10^5$, indicating how many items you have bought and how many categories the accountants operate with respectively. On the second line follows $n$ space-separated strings $t_1, t_2, \ldots, t_n$, the names of the items you have bought. Some items may have been bought multiple times. On the third line follows $c$ space-separated distinct strings $c_1, c_2, \ldots, c_k$, the names of the categories in the order that the accountants require your items to be sorted.</p>

<p>Next follows $k$ lines, one describing each category. The $i^{\text{th}}$ such line begins with a string $s_i$, the name of the category it describes. It is followed by a positive integer $m_i$ and then $m_i$ space-separated distinct strings $t^i_1, t^i_2, \ldots, t^i_{m_i}$, the items that belong to category $s_i$.</p>

<p>All strings in the input consists of between $1$ and $10$ characters from the English alphabet ([A-Za-z]). It is guaranteed that each item you bought belongs to exactly one category, and that $c_1, c_2, \ldots, c_k$ is a permutation of $m_1, m_2, \ldots, m_k$. It also holds that $\sum_{i=1}^{k} m_i \leq 10^5$.</p>



## 출력


<p>On a single line, output $n$ strings representing the items you bought in sorted order according to the accountants. If there are multiple ways of sorting the items according to the requirements, output any of them.</p>



## 소스코드

[소스코드 보기](Irritating%20accountants.py)