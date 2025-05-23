# 4394번: Snap - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4394)


<p>Snap is a 2-player card game. The deck of cards contains several of each type of card. Initially each player has one half of the deck, in some random sequence, face down in a pile, and plays them in sequence from top to bottom, placing each card face-up in another pile. When the face-down pile is exhausted, the face-up pile is turned over to become the face-down pile and play continues.</p>

<p>The two players play their cards concurrently and synchronously. That is, each places a card face up at exactly the same time. If two cards turned up at the same time are the same type, each player calls "Snap!" and the player who calls first takes the other's face-up pile and places it on top of his or her own.</p>

<p>Play proceeds until one player has all the cards. This player is the winner.</p>

<p>Your job is to simulate a game of snap to determine whether it will end within 1000 turns and, if so, to determine the winner.</p>



## 입력


<p>Each type of card is denoted by a single letter or digit. The first line of input Jane's initial pile of cards, from top to bottom. The second line of input is John's initial pile. Jane and John start with the same number of cards; not more than 50 each.</p>

<p>&nbsp;</p>



## 출력


<p>During play, whenever it comes time to call "Snap!" the builtin function "random" is used to determine who calls first: if the expression</p>

<pre>&nbsp; &nbsp;random()/141%2 &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; {in C or C++}
&nbsp; &nbsp;random div 141 mod 2 &nbsp; &nbsp; {in Pascal; see note below}</pre>

<p>yields 0, Jane calls first; otherwise John calls first. Whenever Jane calls first, print "Snap! for Jane: " followed by Jane's face-up pile, from top to bottom. Whenever John calls first, print "Snap! for John: " followed by John's face-up pile. If the game ends, print "John wins." or "Jane wins.", whichever is appropriate. If the game does not end when each player has turned over 1000 cards, print "Keeps going and going ..."</p>



## 소스코드

[소스코드 보기](Snap.cpp)