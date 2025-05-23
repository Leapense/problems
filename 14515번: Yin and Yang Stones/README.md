# 14515번: Yin and Yang Stones - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14515)


<p>A mysterious circular arrangement of black stones and white stones has appeared. Ming has been tasked with balancing the stones so that only one black and one white stone remain.</p>

<p>Ming has two operations for balancing the stones:</p>

<ol>
<li>Take some consecutive sequence of stones where there is exactly one more black stone than a white stone and replace the stones with a single black stone</li>
<li>Take some consecutive sequence of stones where there is exactly one more white stone than black stone and replace the stones with a single white stone</li>
</ol>

<p>Given a circular arrangement, determine if it is possible for Ming to balance the stones.</p>



## 입력


<p>Each input will consist of a single test case. Note that your program may be run multiple times on different inputs. The input will consist of a single string s (1 ≤ |s| ≤ 10<sup>5</sup>), with only the characters capital ‘B’ and ‘W’. The stones are arranged in a circle, so the first stone and the last stone are adjacent.</p>



## 출력


<p>Output 1 if it is possible for Ming to balance the stones with his rules. Otherwise, output 0.</p>



## 소스코드

[소스코드 보기](Main.java)