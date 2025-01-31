# 25487번: 단순한 문제 (Large) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25487)


<p>세 양의 정수 $a$, $b$, $c$가 주어질 때, 다음 조건을 만족하는 정수 쌍 $(x, y, z)$의 개수를 구하시오.</p>

<ul>
<li>$1 \le x \le a$</li>
<li>$1 \le y \le b$</li>
<li>$1 \le z \le c$</li>
<li>$(x\,\bmod\,y) = (y\,\bmod\,z) = (z\,\bmod\,x)$</li>
</ul>

<p>$(A\,\bmod\,B)$는 $A$를 $B$로 나눈 나머지를 의미한다.</p>



## 입력


<p>첫째 줄에 테스트 케이스의 수 $T$가 주어진다. $(1 \le T \le 600\,000)$</p>

<p>다음 $T$개의 각 줄에는 세 정수 $a$, $b$, $c$가 공백으로 구분되어 주어진다. $(1 \le a, b, c \le 100\,000)$</p>



## 출력


<p>한 줄에 하나씩 정답을 출력한다.</p>



## 소스코드

[소스코드 보기](단순한%20문제%20(Large).cpp)