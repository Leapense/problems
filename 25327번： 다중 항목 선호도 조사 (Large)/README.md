# 25327번: 다중 항목 선호도 조사 (Large) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25327)


<p><em>n</em>명의 학생에게 다음과 같이 선호도를 조사하였다. 각 학생은 아래 세 가지 조사 항목 각각에 대하여 반드시 1가지를 선택해야 한다.</p>

<ul>
<li>좋아하는 과목(subject)에 'kor', 'eng', 'math' 중 하나를 선택</li>
<li>좋아하는 과일(fruit)에 'apple', 'pear', 'orange' 중 하나를 선택</li>
<li>좋아하는 색깔(color)에 'red', 'blue', 'green' 중 하나를 선택</li>
</ul>

<p><em>n</em>명 학생의 선호도에 대하여&nbsp;<em>m</em>개의 질의를 순서대로 처리하자. 하나의 질의는 다음과 같다.</p>

<ul>
<li>질의 형식은 'subject fruit color'이다.</li>
<li>subject은 'kor', 'eng', 'math', '-' 중 하나이다.</li>
<li>fruit은 'apple', 'pear', 'orange', '-' 중 하나이다.</li>
<li>color는 'red', 'blue', 'green', '-' 중 하나이다.</li>
<li>'-' 표시는 해당 조건을 고려하지 않겠다는 의미이다.</li>
<li><em>n</em>명 학생 중 선호도가 subject fruit color와 일치하는 학생 수를 출력한다.</li>
</ul>

<p><em>n</em>명 학생의 선호도와&nbsp;<em>m</em>개의 질의가 주어 지면,&nbsp;<em>m</em>개의 질의를 순서대로 처리하자. <strong><em>n</em>과&nbsp;<em>m</em>이 매우 커서 고민하고 있는 우리 학생들을 도와주자.</strong></p>



## 입력


<p>첫 번째 줄에&nbsp;<em>n</em>과&nbsp;<em>m</em>이 공백을 사이에 두고 순서대로 주어진다.</p>

<p>두 번째 줄부터&nbsp;<em>n</em>개의 줄에 학생들의 선호도가 주어진다. 한 줄에 한 학생의 선호도가 주어진다. 한 학생의 선호도는 학생이 좋아하는 과목, 과일, 색깔을 공백을 사이에 두고 순서대로 주어진다.&nbsp;</p>

<p>다음 줄부터&nbsp;<em>m</em>개의 줄에 질의가 주어진다. 한 줄에 하나의 질의가 주어진다. 하나의 질의는 과목, 과일, 색깔을 공백을 사이에 두고 순서대로 주어진다.</p>



## 출력


<p>첫 번째 줄부터&nbsp;<em>m</em>개의 줄에 질의 결과를 순서대로 출력한다. 한 줄에 하나의 질의 결과를 나타내는 정수를 출력한다.</p>



## 소스코드

[소스코드 보기](다중%20항목%20선호도%20조사%20(Large).cpp)