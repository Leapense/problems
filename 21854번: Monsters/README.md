# 21854번: Monsters - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21854)


<p>The 2017 International Congress of Monsters gathers n monsters coming from all over the world. Their chairman has to solve the following problem: if the i<sup>th</sup> monster (1 ≤ i ≤ n) has k<sub>i</sub> fingers, indexed from 0 to k<sub>i</sub> - 1, so he can lift j of those fingers (0 ≤ j ≤ k<sub>i</sub>), obtaining a certain number, in the following way: if a certain finger is lifted, 2<sup>finger index</sup> is added to the current number. As a result, the i<sup>th</sup> monster can count on his fingers nr<sub>i</sub> distinct numbers. Therefore, the demanded result is nr<sub>1</sub> + nr<sub>2</sub> + … + nr<sub>n</sub>, modulo 10<sup>9</sup>+7.</p>

<p>Compute the required sum, modulo 10<sup>9</sup>+7.</p>



## 입력


<p>The first line of the input&nbsp;contains the number n.</p>

<p>The second line contains n positive integers, k<sub>1</sub>, k<sub>2</sub>, …, k<sub>n</sub>, representing the numbers of fingers of each monster.</p>



## 출력


<p>The output must contain a single positive integer, the requested sum, modulo 10<sup>9</sup>+7.</p>



## 소스코드

[소스코드 보기](Monsters.cpp)