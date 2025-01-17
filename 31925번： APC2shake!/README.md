# 31925번: APC2shake! - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31925)


<p>2024년 아주대학교 프로그래밍 경시대회(이하 2024 APC) Division 1에서 훌륭한 성적을 거둔 참가자에게는 2024년 경인지역 6개 연합 프로그래밍 경시대회(이하 2024 shake!)에 진출할 수 있는 티켓이 주어진다. 2024 shake!의 진출자들은 아래의 규칙으로 선발된다.</p>

<ul>
<li>아주대학교 학부 소속의 재학생</li>
<li>역대 국제 대학생 프로그래밍 경시대회(이하 ICPC)의 수상자가 아닌 자</li>
<li>역대 shake! $3$위 이내의 수상자가 아닌 자</li>
<li>위 3가지 규칙을 만족하는 참가자 중 2024 APC에서 높은 성적을 가진 최대 $10$명의 참가자</li>
</ul>

<p>모든 참가자들의 이름과 재학 여부, 역대 ICPC 수상 여부, 역대 shake! 최고 성적, 2024 APC의 성적이 주어질 때, 2024 shake!의 진출자들을 알아내 보자.</p>



## 입력


<p>첫 번째 줄에 참가자의 수 $N$이 주어진다. $(1\leq N \leq 10^{4})$</p>

<p>이후 $N$개 줄에 걸쳐 다음의 정보가 순서대로 공백으로 구분되어 주어진다.</p>

<ul>
<li>이름: 공백 없이 알파벳 소문자로만 이루어진 문자열이 주어진다. 이름의 길이는 $10$을 넘지 않는다.</li>
<li>재학 여부: 재학 중이라면 <code><span style="color:#e74c3c;">jaehak</span></code>이, 휴학 중이라면 <code><span style="color:#e74c3c;">hewhak</span></code>가 주어진다.</li>
<li>역대 ICPC 수상 여부: 역대 ICPC에서 수상하였다면 <code><span style="color:#e74c3c;">winner</span></code>가, 아직 수상하지 못하였다면 <code><span style="color:#e74c3c;">notyet</span></code>가 주어진다.</li>
<li>역대 shake! 최고 성적: 참가자의 역대 shake! 최대 등수를 나타내는 정수 $S$가 주어진다. $-1$이라면 아직 한 번도 shake!에 진출하지 못하였단 뜻이다. $(1\leq S \leq 10^4)$</li>
<li>2024 APC 성적: 2024 APC의 결과 등수를 나타내는 정수 $A$가 주어진다. $(1\leq A \leq N)$</li>
</ul>

<p>같은 이름을 가지는 참가자들이 있을 수 있으며, 2024 APC에서 같은 등수를 가진 사람은 없다.</p>



## 출력


<p>첫 번째 줄에 2024 shake!에 참가할 수 있는 진출자들의 수 $M$을 출력한다.</p>

<p>이후 $M$개 줄에 걸쳐 참가자의 이름을 사전 순서대로 출력한다.</p>



## 소스코드

[소스코드 보기](APC2shake!.cpp)