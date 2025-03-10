# 10552번: DOM - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10552)


<p>In a retirement home, N senior citizens are watching television. The television programme consists of M channels denoted with numbers from 1 to M. Each of the pensioners has their own favourite and hated TV channel.</p>

<p>If the television is currently displaying the hated channel of a certain pensioner, he will get up, slowly walk over to the TV set and change the channel to his favourite and get back to his comfortable chair. If there are multiple pensioners who hate the current channel, the youngest of them will get up (he’s young, he doesn’t mind) and the rest will remain seated.</p>

<p>Of course, after one change of channel, it is possible that another pensioner finds the new channel intolerable so he will change that channel. Given the fact that the pensioners are stubborn, this may continue indefinitely.</p>

<p>For the pensioners’ favourite and hated channels and the initial channel on TV, determine the number of channel changes it takes for the pensioners to remain happy and seated.</p>



## 입력


<p>The first line of input contains three integers N, M and P (1 ≤ N, M ≤ 10<sup>5</sup>, 1 ≤ P ≤&nbsp;M), the number of pensioners, the number of TV channels and the initial channel displayed on TV.</p>

<p>Each of the following N lines contains two integers a<sub>i</sub> and b<sub>i</sub> (1 ≤ a<sub>i</sub>, b<sub>i</sub> ≤ M, a<sub>i</sub> ≠ b<sub>i</sub>), the favourite and hated channel of each pensioner.</p>

<p>The ordering of pensioners in the input is from the youngest to the oldest.</p>



## 출력


<p>The first and only line of output must contain the required number of channel changes. If the changes continue indefinitely, output -1.</p>



## 소스코드

[소스코드 보기](DOM.cpp)