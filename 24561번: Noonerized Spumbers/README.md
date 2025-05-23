# 24561번: Noonerized Spumbers - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24561)


<p>Everyone has heard of spoonerisms, named after William Archibald Spooner, an Oxford professor who had a habit of swapping prefixes of words, often with comical results. "May I show you to your seat?" became "May I sew you to your sheet?" and "a crushing blow" became "a blushing crow."</p>

<p>Just imagine him as a student of arithmetic, occasionally swapping the prefixes of the numbers he was calculating with and then wondering why his equations never made any sense. For instance, when he writes:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/51a71cf5-2554-40d1-8349-f55cf4600990/-/preview/" style="width: 243px; height: 20px;"></p>

<p>what he really intended to write was:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/aee2b4d4-d569-40d8-87cd-246fd3a8844e/-/preview/" style="width: 261px; height: 20px;"></p>

<p>(He swapped prefixes "$9$" and "$669$" in the first and third numbers.) And when he writes:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/130f78a4-d36a-4e6a-ab6b-83ff89d1e8b8/-/preview/" style="width: 273px; height: 20px;"></p>

<p>what he really intended to write was:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/f1d53438-c73c-4060-b9a4-aabaeb594fd6/-/preview/" style="width: 320px; height: 20px;"></p>

<p>(He swapped the prefix "$72$" with the prefix "$68$" in the first and second numbers.)</p>

<p>Grading homework from young Mr. Spooner is quite a challenge. Fleas pined a way to help!</p>



## 입력


<p>The input consists of a single line containing an expression of the form "$x + y = z$" or "$x * y = z$", where $x$, $y$, and $z$ are positive integers less than $2^{31}$. There will be single spaces surrounding the "$+$" and "$*$" operators and the "$=$" sign. The expression will not be a mathematically correct equation.</p>



## 출력


<p>Output a mathematically correct equation consisting of the input line modified by swapping proper prefixes of two of the three numbers $x$, $y$, $z$. (A proper prefix of a string $s$ is a prefix that is neither empty nor equal to $s$.) Separate the numbers, operators, and the "$=$" sign with single spaces. All integers in the correct equation will be non-negative and less than $2^{31}$. There is guaranteed to be only one possible correct equation that can be formed by swapping proper prefixes.</p>



## 소스코드

[소스코드 보기](Noonerized%20Spumbers.cpp)