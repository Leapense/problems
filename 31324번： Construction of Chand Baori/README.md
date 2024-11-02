# 31324번: Construction of Chand Baori - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31324)


<p><img alt="" src="https://upload.acmicpc.net/ab0cfbfd-cd38-4a2c-a5e6-e3197954494c/-/preview/" style="width: 200px; height: 132px; float: right;">The Indian stepped well Chand Baori is, with some simplifications, a pyramid tapering down. Faces of the pyramid are made up of rows of trapezoid stairs which can be used to descend to reach the water. The first (lowest) level is a single stairway with two flights of stairs on the left and on the right. The second level has two such stairways, etc.</p>

<p>To visit the "Harshat Mata" shrine dedicated to the goddess of happiness and joy pilgrims need to cleanse themselves in the waters of the well, that is, to descend to the very bottom. Pilgrims on their way to the water can only descend or walk horizontally along the current level, but not climb up.</p>

<p>The builders of the well want to construct it in such a way that the number of possible ways of descend would be no less than the number of pilgrims. Two paths are considered different if there exists a level with a different stairway used for descending, or different flight of the same stairway used.</p>



## 입력


<p>The first line of the input file contains two integers $N$ and $M$  -- the number of levels in the well and the number of pilgrims descending along the single face, respectively ($1 \le N \le 20$, $0 \le M \le 1.5 \cdot 10^{18}$). </p>



## 출력


<p>The output file must contain  "<code>Harshat Mata</code>", if the number of possible ways to descend along one face of the well is less than the given number of pilgrims (also for one face), otherwise it must contain "<code>Nope</code>".</p>



## 소스코드

[소스코드 보기](Construction%20of%20Chand%20Baori.py)