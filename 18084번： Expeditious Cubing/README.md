# 18084번: Expeditious Cubing - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18084)


<p>Your friend Claire has dragged you along to a speedcubing event that is happening in Eindhoven. These events are all about solving the Rubik’s cube and similar twisty puzzles as quickly as possible. The attendants of the event can enter into various competitions based on the type and size of the puzzle, and there are even special competitions where the puzzles need to be solved one-handed or blindfolded.</p>

<p>Claire is competing in the most popular competition: speedsolving the 3 × 3 × 3 Rubik’s cube, pictured on the right. Each contestant needs to solve the cube five times, each time with a different random scramble. After all solves are completed, the best and the worst times are discarded and the final score is the average of the remaining three times. The contestant with the smallest final score wins.</p>

<p>Claire has done well in the competition so far and is among the contenders for the overall victory. All the other contestants have already finished their five solves, but Claire has one solve remaining. By looking at the final scores of the other contestants, she has deduced her own target final score. As long as her final score is less than or equal to this target score, she will be declared the overall winner. Is it possible for her to win the competition, and if so, what is the worst time she can have on her last solve in order to do so?</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with four real numbers t<sub>1</sub>, t<sub>2</sub>, t<sub>3</sub> and t<sub>4</sub>, the times Claire got on her first four solves.</li>
<li>One line with a real number t, Claire’s target final score, the worst final score she can have in order to be declared the overall winner.</li>
</ul>

<p>Each number is between 1 and 20, inclusive, and is given with exactly two decimal places.</p>



## 출력


<p>If it is not possible for Claire to win the event, output “impossible”. If she will win regardless of the time she gets on her last solve, output “infinite”. Otherwise, output the worst time she can have on her last solve in order to be declared the overall winner. Output the number to <em>exactly</em> two decimal places.</p>



## 소스코드

[소스코드 보기](Expeditious%20Cubing.py)