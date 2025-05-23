# 25276번: Sperhling - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25276)


<p>On her spare time Caitlin loves to do speed typing. Unfortunately Caitlyn was never good at spelling. So what often happens is that Catelin makes a mistake spelling a word, and has to go back and fix her typo. One word in particular that Caitlynn has a hard time spelling is the word <code>mischievous</code>. Catelyn usually spells it <code>mischevious</code> instead. In order to fix this typo, Caytlin needs to do 12 key presses.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/fcd02930-a3b3-492a-97f3-232ea78710b8/-/preview/" style="width: 150px; height: 270px;"></p>

<p>Katelin thinks that no matter how much time she puts into speed typing, she will always make mistakes. But maybe she can get better at quickly fixing her mistakes. Katelyn would like you to help her with this.</p>

<p>Suppose that Caytlyn has just written the word $S_1$, but that she should have written $S_2$. Assume that the cursor is initially at the end of $S_1$, and that after fixing the typo, Caitlin needs to place the cursor at the end of $S_2$. Output the fewest number of key presses needed to make $S_1$ into $S_2$.</p>

<p>The keys you are allowed to use are</p>

<ul>
<li>the left and right arrow keys.</li>
<li>the back space key.</li>
<li>the keys $<code>a</code>, \ldots, <code>z</code>$.</li>
</ul>

<p>You are not allowed to press back space or the left arrow key when the cursor is all the way to the left. You are also not allowed to press the right arrow key when the cursor is all the way to the right. </p>



## 입력


<p>The first two lines contain the strings $S_1$ respectively $S_2$. Both $S_1$ and $S_2$ consist only of lowercase English letters, and are between $1$ and $100$ characters long.</p>



## 출력


<p>Output a single line with the fewest number of key presses needed to make $S_1$ into $S_2$.</p>



## 소스코드

[소스코드 보기](Sperhling.cpp)