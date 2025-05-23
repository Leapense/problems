# 6913번: Constrained Permutations - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6913)


<p>A <em>permutation</em> on the numbers $1, 2, \dots, n$ is a linear ordering of the numbers. For example, there are $6$ permutations of the numbers $1, 2, 3$. They are $123$, $132$, $213$, $231$, $312$ and $321$. Another way to think of it is removing $n$ disks numbered $1$ to $n$ from a bag (without replacement) and recording the order in which they were drawn out.</p>

<p>Mathematicians (and other smart people) write down that there are $n! = n \times (n-1) \dots 3 \times 2 \times 1$ permutations of the numbers $1, \dots, n$. We call this "$n$ factorial."</p>

<p>For this problem, you will be given an integer $n$ $(1 \le n \le 9)$ and a series of $k$ $(k \ge 0)$ constraints on the ordering of the numbers. That is, you will be given $k$ pairs $(x,y)$ indicating that $x$ must come before $y$ in the permutation.</p>

<p>You are to output the number of permutations which satisfy all constraints.</p>



## 입력


<p>Your input will be $k + 2$ lines. The first line will contain the number $n$. The second line will contain the integer $k$, indicating the number of constraints. The remaining $k$ lines will be pairs of distinct integers which are in the range $1, \dots, n$.</p>



## 출력


<p>Your output will be one integer, indicating the number of permutations of $1, \dots, n$ which satisfy the $k$ constraints.</p>



## 소스코드

[소스코드 보기](Constrained%20Permutations.py)