# 17487번: 타자 연습 - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17487)


<p style="text-align: center;"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/KB_United_States.svg/1024px-KB_United_States.svg.png" style="height: 200px; width: 600px;"></p>

<p style="text-align: center;">[그림1] QWERTY 키보드 영문 자판 배열. 출처: Wikipedia</p>

<p>건덕이는 최근 자신의 독수리 타법의 속도에 좌절하며 타자를 연습하기 시작했다. 건덕이가 연습하는 타자법은 QWERTY 자판 배열을 기준으로 Y, G, B와 같거나 왼쪽에 있는 키는 왼손으로, 나머지 키는 오른손으로 누르는 타자 기법이다. 기준은 키보드의 각 행에 한한다.</p>

<p>건덕이는 한 쪽 손이 더 많이 쓰이면 비효율적이라고 생각한다. 따라서 양 쪽에 달려 있는 Shift키와 길이가 긴 스페이스바를 통해 양손의 키를 누른 횟수의 차를 최소로 하도록 문장을&nbsp;입력하려고 한다. 건덕이의&nbsp;각 손이 키보드를 누른 횟수를 구해 보자. 불필요한 키를 누르지 않으며, Shift키를 누르고 글자를 입력한 경우, 글자를 입력한 후 Shift키에서 손을 뗀다.</p>



## 입력


<p>건덕이가 입력할 문장 <em>S</em>가 주어진다. <em>S</em>는 영어 대소문자와 공백으로 이루어져 있으며, 공백 포함 최대 100글자이다. 공백은 연속해서 나타나지 않으며, 문장의 시작과 끝은 공백이 아니다.</p>



## 출력


<p>왼손과 오른손으로 키보드를 누른 횟수를 공백으로 나누어 출력한다.</p>

<p>건덕이는 왼손잡이이기 때문에, 각 손이 눌러야 하는 키 개수의 차가 1일 경우에는&nbsp;왼손으로 한 번 더 누른다.</p>



## 소스코드

[소스코드 보기](타자%20연습.py)