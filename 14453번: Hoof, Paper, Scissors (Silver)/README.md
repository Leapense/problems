# 14453번: Hoof, Paper, Scissors (Silver) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/14453)


<p>You have probably heard of the game "Rock, Paper, Scissors". The cows like to play a similar game they call "Hoof, Paper, Scissors".</p>

<p>The rules of "Hoof, Paper, Scissors" are simple. Two cows play against each-other. They both count to three and then each simultaneously makes a gesture that represents either a hoof, a piece of paper, or a pair of scissors. Hoof beats scissors (since a hoof can smash a pair of scissors), scissors beats paper (since scissors can cut paper), and paper beats hoof (since the hoof can get a papercut). For example, if the first cow makes a "hoof" gesture and the second a "paper" gesture, then the second cow wins. Of course, it is also possible to tie, if both cows make the same gesture.</p>

<p>Farmer John wants to play against his prize cow, Bessie, at&nbsp;N&nbsp;games of "Hoof, Paper, Scissors" (1 ≤ N ≤ 100,000). Bessie, being an expert at the game, can predict each of FJ's gestures before he makes it. Unfortunately, Bessie, being a cow, is also very lazy. As a result, she tends to play the same gesture multiple times in a row. In fact, she is only willing to switch gestures at most once over the entire set of games. For example, she might play "hoof" for the first&nbsp;x&nbsp;games, then switch to "paper" for the remaining&nbsp;N−x games.</p>

<p>Given the sequence of gestures FJ will be playing, please determine the maximum number of games that Bessie can win.</p>



## 입력


<p>The first line of the input file contains&nbsp;N.</p>

<p>The remaining&nbsp;N&nbsp;lines contains FJ's gestures, each either H, P, or S.</p>

<p>&nbsp;</p>



## 출력


<p>Print the maximum number of games Bessie can win, given that she can only change gestures at most once.</p>



## 소스코드

[소스코드 보기](Hoof,%20Paper,%20Scissors%20(Silver).cpp)