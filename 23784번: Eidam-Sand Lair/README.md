# 23784번: Eidam-Sand Lair - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/23784)


<p>In your base you have dug through sand and rock to construct a deep pit with stairs and a lift. The pit goes very deep into the ground where on various floors you leave equipment and on the deepest levels you leave cheeses to age, particularly Eidam. You often take a stroll downstairs, but wonder whether it is faster to go up to the surface by foot or take a lift for a part or all of the trip.</p>

<p>You know the position and the speed of yourself and the lift. The surface floor is numbered 0, positive numbers denote underground floors by their distance to the surface. You are alone on the Mars so only you will use the lift. Also, it takes (you and lift) almost no time to start and stop moving so you will neglect these. When the lift is called to multiple floors, it moves to them in the same order in which it was called. The lift is not very special – once you enter it, you may order it to go to an arbitrary floor. In such case, any previous calls must be processed first.</p>



## 입력


<p>The first input line contains a single integer T (1 ≤ T ≤ 10<sup>4</sup>), the number of test cases. Next T lines contain one test case each. Each test case is composed of four integers: Y<sub>p</sub>, L<sub>p</sub>, Y<sub>s</sub>, L<sub>s</sub> where 0 ≤ Y<sub>p</sub>, L<sub>p</sub> ≤ 10<sup>9</sup> are the initial floors of you and the lift, and 0 &lt; Y<sub>s</sub>, L<sub>s</sub> ≤ 10<sup>6</sup> are the times it takes you and of the lift to move by one floor, respectively.</p>



## 출력


<p>For each test case, print a single integer – the minimum time it takes you to move from your initial floor to the 0-th floor.</p>



## 소스코드

[소스코드 보기](Eidam-Sand%20Lair.py)