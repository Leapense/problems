# 31312번: Water Journal - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31312)


<p>Every day, Eugene logs how many cups of water he drank. He forgot to log one entry in his journal though, but he remembers the minimum number and maximum number of cups of water he drank every day since he started logging his journal, and that there was at least one day where he drank the minimum and one day where he drank the maximum. Compute all possible amounts of cups of water he could have imbibed on the day he forgot to log.</p>



## 입력


<p>The first line of input contains three integers $n$ ($2 \le n \le 50$), $a$ and $b$ ($1 \le a \le b \le 50$), where $n$ is the number of days in Eugene's log, $a$ is the minimum number of cups of water he drank on any day, and $b$ is the associated maximum.</p>

<p>Each of the next $n-1$ lines contains a single integers $w$ ($a \le w \le b$). These are the entries in Eugene's log for every day except the day he forgot to log an entry. </p>



## 출력


<p>Output in increasing order, all of the possible values for the missing entry separated by whitespace, or simply output -1 if Eugene's memory is faulty and it isn't possible. </p>



## 소스코드

[소스코드 보기](Water%20Journal.py)