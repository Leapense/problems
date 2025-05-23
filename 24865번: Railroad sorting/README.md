# 24865번: Railroad sorting - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24865)


<p>Arsenii works as an operator at a sorting station, the scheme of which is shown on the image.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/5adac2fa-22bc-41a0-8c99-d414711faac6/-/preview/" style="width: 352px; height: 91px;"></p>

<p>The station has an input track, an output track and two dead ends. The operator can move cars between tracks and dead ends.</p>

<p>If car $x$ is the first car on the input track, this car can be moved to any dead end. Command "<code>1</code>" moves the car to the dead end $1$, and command "<code>2</code>" moves car to the dead end $2$.</p>

<p>If the car $x$ is the closest car to the exit in one of the dead ends, it can be moved to output track. Command "<code>-1</code>" moves the car from the dead end $1$, and command "<code>-2</code>" moves the car from the dead end $2$.</p>

<p>Finally, you can move cars between dead ends. If $x$ is the closest car to the exit in one of the dead ends, it can be moved to another dead end. Command "<code>12</code>" moves the car from the dead end $1$ to the dead end $2$, and the command "<code>21</code>" moves the car from the dead end $2$ to the dead end $1$.</p>

<p>Please note that cars cannot be returned to a dead end from the output track and cannot be returned from a dead end to the input track. Also, you cannot move the car directly from the input track to the output track, it is required to use a dead end. Both dead ends can contain any number of cars.</p>

<p>A train of $n$ cars arrives on the input track, each car has a unique number from $1$ to $n$.</p>

<p>Arsenii must sort the cars so that they are all on the output track and their numbers from left to right are in ascending order. Help him form a sequence of commands that will help him to achieve this. The number of commands in the sequence must not be exceed $2 \cdot 10^6$.</p>



## 입력


<p>The first line of input contains integer $n$ --- the number of cars ($1 \le n \le 1000$).</p>

<p>The second line contains $n$ different integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le n$) --- the numbers on the cars in order from left to right on the input track.</p>



## 출력


<p>Print the sequence of commands that will cause the cars to be on the output track, and their numbers would be in ascending order. The sequence must contain no more than $2 \cdot 10^6$ command.</p>

<p>If there are multiple correct sequences, you can output any of them.</p>

<p>It is guaranteed that for any input data there is a sequence of commands containing at most $2 \cdot 10^6$ commands.</p>



## 소스코드

[소스코드 보기](Railroad%20sorting.py)