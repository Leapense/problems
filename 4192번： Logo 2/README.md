# 4192번: Logo 2 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4192)


<p>Logo is a programming language built around a turtle. Commands in the language cause the turtle to move. The turtle has a pen attached to it. As the turtle moves, it draw lines on the page. The turtle can be programmed to draw interesting pictures.</p>

<p>We are interested in making the turtle draw a picture, then return to the point that it started from. For example, we could give the turtle the following program:</p>

<pre>fd 100 lt 120 fd 100 lt 120 fd 100</pre>

<p>The command fd causes the turtle to move forward by the specified number of units. The command lt causes the turtle to turn left by the specified number of degrees. Thus the above commands cause the turtle to draw an equilateral triangle with sides 100 units long. Notice that after executing the commands, the turtle ends up in the same place as it started. The turtle understands two additional commands. The command bk causes the turtle to move backward by the specified number of units. The command rt causes the turtle to turn right by the specified number of degrees. The distances and angles in all commands are always non-negative integers.</p>

<p>Unfortunately, we have been messy in writing the program down, and cannot read our own writing. One of the numbers in the program is missing. Assuming the turtle ends up at the place that it started at the end of its journey, can you find the missing number?</p>



## 입력


<p>The first line of input contains one integer specifying the number of test cases to follow. Each test case starts with a line containing one integer, the number of commands to follow. The commands follow, one on each line. Each test case will contain no more than 1000 commands. The argument of each command is either an integer or a question mark (?). There will be exactly one question mark in each test case.</p>



## 출력


<p>For each test case, output line containing a single integer n such that when the question mark in the program is replaced by n, the turtle ends up at the same point that it started from once the program completes. If the question mark is the argument of an lt or rt command, the angle in the output must be between 0 and 359 degrees, inclusive. The correct answer will always be an integer, and we guarantee that for every test case, there will be only one correct answer.</p>



## 소스코드

[소스코드 보기](Logo%202.py)