# 11142번: Cross Country Race - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11142)


<p>The organizers of the world championship in interval start cross country have made a fatal blunder. It is impossible to pass the person in front of you anywhere along the race tracks. If one person catches up with the one that started before him/her, they will have to stay together for the rest of the race.</p>

<p>This is obviously no just way of declaring a world champion, so the organizers decide to only record the times of the people who reach goal without someone right in front of them. The rest will run another race (when they have rested), to decide their race time.</p>

<p>The danger of this setup is that you will have to arrange too many races. Given the length of the race, and the speeds of the participants, how many races will they need to arrange?</p>

<p>In the race, there is one minute between each starter, in the order given in the input. In subsequent races, the relative order between the participants is the same, but their starting times will be adjusted so that it is still exactly one minute between each start.</p>



## 입력


<p>The first line of input contains a single number T, the number of test cases to follow. Each test case begins with a line containing two numbers, N, the number of participants in the championship, and S, the length of the race, in meters. Then follow a single line containing N numbers v<sub>1</sub>, v<sub>2</sub>, ..., v<sub>N</sub>, the speeds of the participants in the order they will start the race, given in meters/minute.</p>

<ul>
<li>0 &lt; T ≤ 100</li>
<li>0 &lt; N ≤ 1000</li>
<li>0 &lt; S ≤ 50000</li>
<li>0 &lt; v<sub>i</sub> &lt; 1000</li>
<li>For the purposes of this problem, each participant is considered a single point.</li>
<li>A participant can reach the exact point of the previous starter, but not pass it.</li>
<li>For the purposes of this problem, a participant has someone right in front of them if and only if they are at the exact same point, and he did not start first of them.</li>
<li>The relationship between the distance s, the velocity v and the time t can be expressed as s = v ∗ t.</li>
</ul>



## 출력


<p>For each test case, output a line containing a single number, the amount of races that will have to be arranged.</p>



## 소스코드

[소스코드 보기](Cross%20Country%20Race.cpp)