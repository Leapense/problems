# 32533번: Skokovi - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32533)


<p>In a land who knows where, in a world who knows when, lives a bee named Maya. Her adventure-filled life is an endless source of ideas for tasks, so we chose one of them.</p>

<p>Maya’s friend, a grasshopper named Filip, is preparing for the Olympics in flower jumping. The flowers in the meadow can be represented as a sequence of positive intergers $a$ of length $N$. The height of each flower is given by the number $a_i$.</p>

<p>Filip always jumps from left to right. Additionally, since this whole sport is new to him, he cannot jump to a flower whose height differs too much from the one he is currently on. Specifically, from flower $i$, he can jump to flower $j$ if and only if $i &lt; j$ and $|a_i - a_j | ≤ K$, where $K$ is a positive integer given in the input.</p>

<p>Help Maya plan Filip’s training by determining which flowers Filip can reach if he starts on the leftmost flower. In other words, for each flower, determine if there is a sequence of jumps that leads to it, starting from the first flower.</p>



## 입력


<p>The first line contains positive integers $N$ ($1 ≤ N ≤ 2 \cdot 10^5$) and $K$ ($1 ≤ K ≤ 10^9$). The second line contains a sequence of positive integers a, i.e., $N$ numbers $a_i$ ($1 ≤ a_i ≤ 10^9$), representing the heights of the flowers.</p>



## 출력


<p>In a single line, output $N$ numbers, either $0$ or $1$, where each number indicates whether the corresponding flower is reachable. The number $0$ means that it is not possible to reach that flower, while $1$ means the flower is reachable. The first flower is always reachable as Filip starts from there.</p>



## 소스코드

[소스코드 보기](Skokovi.py)