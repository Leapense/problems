# 21979번: 16진수 쪼개기 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21979)


<p>길이가 n인 문자열 S를 아래 조건에 따라&nbsp;k개의 부분문자열 (substring) T<sub>1</sub>, T<sub>2</sub>, ..., T<sub>k</sub>로 쪼개는 경우를 생각해보자:</p>

<ul>
<li>1 ≤ k ≤ n</li>
<li>1 ≤ i ≤ k를 만족하는 i에 대하여 각 부분문자열 T<sub>i</sub>는 길이 1 이상이며 S의 부분문자열이다 (즉, S를 구성하는 연속한 문자들로 구성되어있다).</li>
<li>T<sub>1</sub>, T<sub>2</sub>, ..., T<sub>k</sub> 를 순서대로 이어붙이면 (string&nbsp;concatenation) 원래의 문자열 S가 된다.</li>
</ul>

<p>예를 들어 S = "FED" 인 경우 아래와 같은 총 4가지의 방법으로 쪼갤 수 있다:</p>

<ul>
<li><img alt="" src="https://upload.acmicpc.net/7066b041-642b-4482-a97d-dc7e5b1e5fb4/-/preview/" style="width: 120px; height: 145px; float: right;">방법 1: T1 = "FED" (이 경우, k = 1)</li>
<li>방법 2: T1 = "F", T2 = "ED" (이 경우, k = 2)</li>
<li>방법 3: T1 = "FE", T2 = "D" (이 경우, k = 2)</li>
<li>방법 4: T1 = "F", T2 = "E", T3 = "D" (이 경우, k = 3)</li>
</ul>

<p>참고로&nbsp;길이가 n인 문자열을 위 조건대로 쪼개는 방법은 총 2<sup>n-1</sup> 가지 존재한다.</p>

<p>이 문제에서는 원래의 문자열 S가 0-9와 A-F로만 구성된 16진수라 가정한다.</p>

<p>Albert는 위 조건대로 S를&nbsp;쪼개서 T<sub>1</sub>, T<sub>2</sub>, ..., T<sub>k</sub>가 비감소수열이 (non-decreasing sequence)&nbsp;되는 경우가 몇 가지나 되는지 알고 싶다.<br>
구체적으로, Albert는 S를 쪼갠 후&nbsp;각 부분 문자열이 타나내는 16진수 값이 T<sub>1</sub> ≤ T<sub>2</sub> ≤ ... ≤ T<sub>k</sub> 를 만족하도록 하고 싶다.</p>

<p>위 예제의 경우, 상기한 네 가지 방법을 통해 만들어지는 수열은 아래와 같다:</p>

<ul>
<li>방법1: [FED<sub>(16)</sub> = 4077] (비감소수열)</li>
<li>방법2: [F<sub>(16)</sub> = 15, ED<sub>(16)</sub> = 237] (비감소수열)</li>
<li>방법3: [FE<sub>(16)</sub> = 254, D<sub>(16)</sub> = 13]</li>
<li>방법4: [F<sub>(16)</sub> = 15, E<sub>(16)</sub> = 14, D<sub>(16)</sub> = 13]</li>
</ul>

<p>이 경우 비감소수열은 방법1, 방법2을 통해 얻을 수 있으므로 답이 2가 된다.</p>

<p>다른 예로 S = "0070"인 경우, 아래와 같은 4가지 방법이 가능하다.</p>

<ul>
<li>방법 1: T1 = "0070"</li>
<li>방법 2: T1 = "0", T2 = "0", T3 = "70" (이 경우 [0, 0, 70<sub>(16)</sub> = 112] 이다)</li>
<li>방법 3: T1 = "00", T2 = "70"</li>
<li>방법 4: T1 = "0", T2 = "070"</li>
</ul>

<p>방법1, 방법3,&nbsp;방법4에서 보이듯 부분 문자열이 선행 0을&nbsp;(leading zero) 포함하는 것도 허용된다.</p>

<p>입력으로 16진수 문자열 S가 주어졌을 때, Albert가 몇 가지 방법으로 S를 부분 문자열로 쪼개서 비감소수열을 얻을 수 있는지 구해보자.</p>



## 입력


<p>첫 줄에 테스트 케이스의 수 T가 주어진다.&nbsp;</p>

<p>다음 각 줄에 문자열 S가 주어진다.</p>

<p>문자열 S를 구성하는 문자는 16진법에 사용되는&nbsp;0-9 (숫자)와 A-F (영대문자) 뿐이다.</p>



## 출력


<p>각 테스트 케이스의 정답을 각 줄에 출력한다.</p>



## 소스코드

[소스코드 보기](16진수%20쪼개기.py)