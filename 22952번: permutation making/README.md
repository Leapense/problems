# 22952번: permutation making - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/22952)


<blockquote>
<p>길이가 $N$인 순열이란, $1$이상 $N$이하의 자연수 $N$개로 이루어진, 같은 수가 두 번 이상 등장하지 않는 수열을 의미한다.&nbsp;</p>
</blockquote>

<p>여기 길이가 $N$인 순열 $A$가 있다.</p>

<p>이때 새로운 수열 $P$의 $i$번째 원소는&nbsp;다음과 같이 정의된다. ($1 \le i \le N$)<br>
$$P_i = \left(\sum_{k=1}^{i}A_k\right)\ \bmod N$$<br>
$P$의 원소들&nbsp;중 서로 다른 값이 $\frac{N}{2}&nbsp;+ 1$개 이하가&nbsp;되도록 하는 순열 $A$를 아무거나 하나 구해보자.</p>



## 입력


<p>첫째 줄에 $N$ ($1 \le N \le 100\,000$)이 주어진다.</p>



## 출력


<p>$A_1$부터 $A_N$까지의 원소를 공백을 기준으로 출력한다.</p>

<p>조건을 만족하는 순열 $A$가 항상 존재한다.</p>



## 소스코드

[소스코드 보기](permutation%20making.cpp)