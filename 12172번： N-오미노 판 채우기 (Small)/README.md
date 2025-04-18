# 12172번: N-오미노 판 채우기 (Small) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12172)


<p>N-오미노는 이차원 평면 위에 N개의 정사각형이 연결된 도형이다. 1-오미노는 1*1 크기의 정사각형이다. 그래서 n-노미노는 n - 1오미노에 1-오미노, 즉 1*1짜리 정사각형을 추가 한 것과 같다. 단, 두 N-오미노가 합동이면 같다고 가정한다.</p>

<p>아래에는 가능한 5가지 4-오미노가 있다.</p>

<p><img alt="images-73.png" src="https://upload.acmicpc.net/e9ed4bdd-14d6-477c-85f1-4b487f2c094f/-/preview/"></p>

<p>아래에는 전체 108가지의 7-오미노 중 일부가 있다.</p>

<p><img alt="images-74.png" src="https://upload.acmicpc.net/002f9f2d-5cde-4031-9b74-950f14df52b4/-/preview/"></p>

<p>철수와 동수는 변수 X, R, C가 정해진 상태에서 아래의 절차대로 게임을 진행하려고 한다.</p>

<p>1.철수는 가능한 X-오미노 중에서&nbsp;하나를 고른다.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</p>

<p>2.동수는&nbsp;여러 가지 X-오미노를 이용해서 넘치지도 부족하지도 않게 R*C 판을 채운다. 단, 철수가 고른 X-오미노를 적어도 한개를 이용해야 하며 X-오미노를 뒤집거나 회전하여 이용해도 된다. 동수가 위의 조건을 만족하면서 판을 채우면 동수는 승리하고 판을 채우지 못하면 패배한다.</p>

<p>X, R, C가 주어질때 철수가 무조건 이길지 동수가 무조건 이길지 판별하라.</p>



## 입력


<p>입력의 첫째 줄에는 테스트케이스의 수 T가 주어진다</p>

<p>다음 T개의 줄에서는 각각 X, R, C가 차례대로 주어진다.</p>

<p><strong>T</strong>&nbsp;= 64., 1 ≤&nbsp;<strong>X, R, C</strong>&nbsp;≤ 4</p>



## 출력


<p>각각의 테스트케이스에 대하여 "Case #x:y"를 출력한다. 이때 x는 테스트케이스 번호(1부터 시작한다). 철수가 선택했을때 무조건 이기는 X-오미노가 하나라도 있으면 y는 RICHARD이고 하나도 없으면 y는 GABRIEL이다.</p>



## 소스코드

[소스코드 보기](N-오미노%20판%20채우기%20(Small).cpp)