# 20126번: 교수님의 기말고사 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20126)


<p>안형찬 교수님은 알고리즘 분석 기말고사를 준비하려고 한다.</p>

<p>알고리즘 기말고사는 총 <em>M</em>분 동안 쉬는 시간 없이 볼 예정이며, 인원이 너무 많아서 공학관 C040호에서 말고 다른 강의실에서 시험을 치를 수 없게 되었다.</p>

<p>공학관 C040호는 0분부터 <em>S</em>분까지 사용 가능하다. <em>S</em>는 무조건 <em>M</em>&nbsp;이상이기 때문에 안 교수님은 별문제 없이 시험을 치를 것으로&nbsp;생각하였다. 그러나 공학과 C040호에는 다른 시험도 예정되어 있어서 겹치지 않는 시간을 잡아야 한다.</p>

<p>각 시험은 <em>x<sub>i</sub></em>분에&nbsp;시작해서&nbsp;<em>y<sub>i</sub></em>분 동안 진행하며&nbsp;서로 겹치지 않는다. 한&nbsp;시험이 끝난 직후 다음 시험이 있는 경우도 겹치지 않는 것으로 판단한다.&nbsp;즉, <em>x<sub>i</sub></em> + <em>y<sub>i</sub></em> ≤ <em>x<sub>j</sub></em> 일 때 <em>i</em> 시험과 <em>j</em> 시험은 서로 겹치지 않는다.</p>

<p>안형찬 교수님이 시험을 언제 치를 수 있는지 구해보자.</p>



## 입력


<p>다음과 같이 입력이 주어진다.</p>

<div style="background:#eeeeee;border:1px solid #cccccc;padding:5px 10px;"><em>N</em> <em>M</em> <em>S</em><br>
<i>x<sub>1</sub></i> <em>y<sub>1</sub></em><br>
. . .<br>
<em>x<sub>N</sub></em> <em>y</em><i><sub>N</sub></i></div>



## 출력


<p>교수님이 시험을 시작할 수 있는 시각을 출력하여라. 시작 가능한 시각이 여러 개 있으면 그중 가장 앞선 시각을 출력한다. 시험을 치룰 수 없다면 <span style="color:#e74c3c;"><code>-1</code></span>을 출력하여라.</p>



## 소스코드

[소스코드 보기](교수님의%20기말고사.cpp)