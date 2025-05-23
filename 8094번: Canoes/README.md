# 8094번: Canoes - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8094)


<p>We are organizing a canoe tour. Canoes can be hired at the harbour. Canoes are all alike. A canoe can take at most two persons. The sum of weights of these persons cannot exceed the fixed maximal weight. We want to pay as little as possible so we should try to place all participants of our tour in the minimal number of canoes.</p>

<p>Write a program that:</p>

<ul>
<li>reads the maximal weight of a canoe crew, the number of participants of the tour and the weight of each of them, from the standard input,</li>
<li>computes the minimal number of canoes that should be hired to place all the participants of the tour according to the rules,</li>
<li>writes the result to the standard output.</li>
</ul>



## 입력


<p>In the first line of the standard input there is one integer&nbsp;w, 80 ≤ w ≤ 200, which is the maximal weight of a canoe crew. In the second line there is one integer n, 1 ≤ n ≤ 30,000, which is the number of participants of the tour.</p>

<p>Each of the following n&nbsp;lines contains one integer from the range [5..w]. These numbers equal the weights of the participants.</p>



## 출력


<p>In the first line of the standard output there should be written one integer — the minimal number of canoes that should be hired.</p>



## 소스코드

[소스코드 보기](Canoes.cpp)