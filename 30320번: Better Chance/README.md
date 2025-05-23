# 30320번: Better Chance - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30320)


<p>In recent years, the ICPC community has expanded its global presence, with annual participation encompassing 111 countries, involving 3,450 universities, and engaging 75,000 team members, coaches, and volunteers. However, it is important to note that only approximately 130 teams earn the opportunity to advance to the annual ICPC World Finals. Specifically, for the 2023 ICPC World Finals, only 16 teams from the Asia Pacific Region have qualified. In the 2022 ICPC Asia Pacific Regional Contests, an impressive turnout saw over 1,800 teams representing 283 universities. Regrettably, the vast majority of these teams, more than $99\%$, were unable to progress beyond the regional contests.</p>

<p>The ICPC Asia Pacific Region has introduced the Asia Pacific playoff as a new tier in the selection process for teams to participate in the 2024 ICPC World Finals. This playoff represents a higher level of competition compared to the regional contests. In 2024, the first Asia Pacific playoff will take place in Hanoi, Vietnam. Approximately 66 teams will earn their spots in this playoff based on the rules outlined in the ICPC Asia Pacific Rules section. This expansion ensures that a greater number of teams will have opportunities to engage in higher-level contests in the coming years.</p>

<p>Due to the introduction of ICPC Asia Pacific Playoff contest, the ICPC Asia Pacific Rules have been changed greatly. After reading the new rules, you find that you are allowed to participate two regional contests in 2023 to have a better chance to advance to the playoff. Your team plans to participate the ICPC Taoyuan Regional Contest and the ICPC Jakarta Regional Contest in 2023. Assume that your team's <u>recomputed team ranks</u> and the <u>site scores</u> of both regional contests are given. Please write a program to determine in which regional contest your team has a better chance of advancing.</p>

<p>(Note: The definition of <u>recomputed team rank</u> and <u>site score</u> can be found in the ICPC Asia Pacific Rules section.)</p>



## 입력


<p>The first line of the input contains four space-separated numbers $R_T$, $R_J$, $S_T$, $S_J$. $R_T$ and $R_J$ are your team's <u>recomputed team ranks</u> of Taoyuan Regional and Jakarta Regional, respectively. $S_T$ and $S_J$ are the site scores of Taoyuan Regional and Jakarta Regional, respectively.</p>



## 출력


<p>If your team has a better chance of advancing in Taoyuan Regional, output <code>TAOYUAN</code>. If your team has a better chance of advancing in Jakarta Regional, output <code>JAKARTA</code>. If the chances are equally good, output <code>SAME</code>.</p>



## 소스코드

[소스코드 보기](Better%20Chance.cpp)