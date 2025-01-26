# 24919번: Inversions Organize - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24919)


<p>After the troubles with printing advertising for IO two years ago, the marketing team of the conference decided to use an interactive installation. It consists of a matrix of $2N$&nbsp;rows and&nbsp;$2N$&nbsp;columns of touchscreens. Each touchscreen can display either an uppercase&nbsp;<code>I</code>&nbsp;or an uppercase&nbsp;<code>O</code>. When one of the screens is touched, it switches the letter it displays to the one it was not displaying right before the touch occurred.</p>

<p>You are looking at one of those installations, and find it to be disorganized. You want to change some of the letters such that the top&nbsp;$N$&nbsp;rows show the same number of letter&nbsp;<code>I</code>⁠'s as the bottom&nbsp;$N$&nbsp;rows, and at the same time, the leftmost&nbsp;$N$&nbsp;columns show the same number of letter&nbsp;<code>I</code>⁠'s in total as the rightmost&nbsp;$N$&nbsp;columns.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/dbeb40b7-87b8-4344-a907-c91cfda190a6/-/preview/"></p>

<p>For example, in the left picture above, $N=2$. The top&nbsp;$2$&nbsp;rows show&nbsp;$3$&nbsp;letter&nbsp;<code>I</code>⁠'s in total, while the bottom&nbsp;$2$&nbsp;rows show&nbsp;$5$. On the other hand, both the leftmost&nbsp;$2$&nbsp;columns and the rightmost&nbsp;$2$&nbsp;columns show&nbsp;$4$&nbsp;letter&nbsp;<code>I</code>⁠'s. By touching the two highlighted screens we can change the state to that shown in the right picture, which shows&nbsp;$4$&nbsp;letter&nbsp;<code>I</code>⁠'s in the top&nbsp;$2$ columns and in the bottom&nbsp;$2$&nbsp;columns, and also maintains the balance between the left and right sides.</p>

<p>Given the state of the installation, can you find the minimum number of letter changes needed to achieve your organizational goal?</p>



## 입력


<p>The first line of the input gives the number of test cases, $T$.&nbsp;$T$&nbsp;test cases follow. Each test case starts with a line containing a single integer&nbsp;$N$, half the number of rows and columns of the matrix. Then,&nbsp;$2N$&nbsp;lines follow. The&nbsp;$i$-th of these contains a string of&nbsp;$2N$&nbsp;characters&nbsp;$C_{i,1}C_{i,2}\cdots C_{i,2N}$.&nbsp;$C_{i,j}$&nbsp;is the letter currently displayed in the screen in the&nbsp;$i$-th row and&nbsp;$j$-th column of the matrix.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where $x$&nbsp;is the test case number (starting from 1) and&nbsp;$y$&nbsp;is the minimum number of touches required to make the installation simultaneously display the same number of letter&nbsp;<code>I</code>⁠'s in its top and bottom halves, and the same number of letter&nbsp;<code>I</code>⁠'s in its left and right halves.</p>



## 소스코드

[소스코드 보기](Inversions%20Organize.py)