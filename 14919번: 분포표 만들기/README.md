# 14919번: 분포표 만들기 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14919)


<p>0과 1사이의 실수 a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>N</sub>이 입력으로 주어졌다고 하자.&nbsp; 구간 [0,1)을 다음과 같이 m개의 길이 L=1/m인 부분구간으로 나누자. 각 구간은 순서대로 b<sub>1</sub>, b<sub>2</sub>, ..., b<sub>m</sub>이다.</p>

<ul>
<li>b<sub>1</sub>: 0 ≤ x &lt; L,</li>
<li>b<sub>2</sub>: L ≤&nbsp;x &lt; 2L,</li>
<li>...</li>
<li>b<sub>m</sub>: (m-1)L ≤&nbsp;x &lt; 1.</li>
</ul>

<p>입력된 실수중, 각 구간&nbsp;b<sub>1</sub>, b<sub>2</sub>, ..., b<sub>m</sub>에 포함되는 수의 개수를&nbsp;출력하시오.</p>



## 입력


<p>첫줄에 m (1 ≤ m ≤ 1,000), 둘째 줄에 N (1 ≤ N ≤ 1,000,000)개의 실수 a<sub>1</sub>, …, a<sub>N</sub>이 빈칸으로 구분되어 입력된다. 실수는 소수점 여섯째 자리까지 주어진다.</p>



## 출력


<p>각 구간 b<sub>1</sub>, b<sub>2</sub>, ..., b<sub>m</sub>에 포함된 수를&nbsp;빈 칸으로 구분해&nbsp;출력한다.</p>



## 소스코드

[소스코드 보기](분포표%20만들기.py)