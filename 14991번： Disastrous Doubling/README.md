# 14991번: Disastrous Doubling - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14991)


<p>A scientist, E. Collie, is going to do some experiments with bacteria. Right now, she has one bacterium. She already knows that this species of bacteria doubles itself every hour. Hence, after one hour there will be 2 bacteria. E.</p>

<p>E. Collie will do one experiment every hour, for n consecutive hours. She starts the first experiment exactly one hour after the first bacterium starts growing. In experiment i she will need b<sub>i</sub> bacteria.</p>

<p>How many bacteria will be left directly after starting the last experiment? If at any point there are not enough bacteria to do the experiment, print “error”.</p>

<p>Since the answer may be very large, please print it modulo 10<sup>9</sup> + 7.</p>



## 입력


<p>The input consists of two lines.</p>

<ul>
<li>The first line contains an integer 1 ≤ n ≤ 10<sup>5</sup>, the number of experiments.</li>
<li>The second line contains n integers b<sub>1</sub>, . . . , b<sub>n</sub>, where 0 ≤ b<sub>i</sub> ≤ 2<sup>60</sup> is the number of bacteria used in the ith experiment.</li>
</ul>



## 출력


<p>Output a single line containing the number of bacteria that remains after doing all the experiments, or “error”.</p>



## 소스코드

[소스코드 보기](Disastrous%20Doubling.py)