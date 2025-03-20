# 19253번: Don't Split The Atom! - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/19253)


<p>Two mad (and evil) scientists, Professor Zoom and Doctor Horrible, have just obtained $n$ atoms of a very rare element, which they want to share between themselves. They have decided to play the following game:</p>

<p>First, Professor divides the atoms into two non-empty groups. Next, Doctor takes one group and uses it for his evil purposes, and splits the other into two non-empty parts. Then, Professor takes one of the parts, and divides the other one again into two, returning it to Doctor. The game goes on -- with every turn, a scientist taking one of the parts, and splitting the other -- until one of the players is forced to split a single atom. This results in an explosion, and the unlucky splitter loses the game (probably with his life).</p>

<p>Knowing the number of atoms $n$ determine which one of the villains survives the game.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/cab782bd-9d12-4933-80a1-954b33d11acc/-/preview/" style="width: 333px; height: 264px;"></p>



## 입력


<p>The first line of input contains the number of test cases $z$ ($1 \leq z \leq 50$). The descriptions of the test cases follow.</p>

<p>Every test case consists of one integer $n$ ($1 \leq n \leq 1\,000\,000$) -- the initial number of atoms.</p>



## 출력


<p>For each test case output a line containing a single character: '<code>A</code>' if Professor wins the game, '<code>B</code>' if Doctor wins.</p>



## 소스코드

[소스코드 보기](Don't%20Split%20The%20Atom!.cpp)