# 26206번: Multidimensional Hangman - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26206)


<p>The Multidimensional Hangman Game has very peculiar rules. In a way, it is like you are playing several games of the traditional Hangman game at the same time, with the difference that the words don’t have to exist in the dictionary. If you’ve never played Hangman, don’t worry: all the information you need is below.</p>

<p>In the multidimensional version of the game, there are several words on a board, initially unknown, all of the same length. At each turn in the game, you discover some characters from certain word positions (how these characters were discovered is not important for this problem). At a certain point, when only one unknown character remains in each word on the board, the game goes into the <em>all or nothing</em> phase. At this point, you must choose a word that maximizes the number of compatibilities with the words on the board. For a chosen word $P$, we say it is compatible with a word $T$ on the board if all known letters in $T$ occur in exactly the same positions in $P$.</p>

<p>Given the known information about the words on the board, you must determine which word to choose for all or nothing phase, which maximizes the number of compatibilities. If there is more than one solution, print the lexicographically smallest. We say that a word $P$ is lexicographically smaller than a word $Q$ if $P_i &lt; Q_i$ where $P_i$ is the $i$-th character of $P$, $Q_i$ is the $i$-th character of $Q$ and $i$ is the smallest index such that $P_i \ne Q_i$.</p>



## 입력


<p>The first line of the input contains two integers $N$ and $C$ satisfying $1 ≤ N ≤ 10^4$ and $1 ≤ C ≤ 12$, indicating the number of words on the board and the length of the words it contains. Each of the next $N$ lines contains a word of length $C$ composed only of characters from “<code>a</code>” to “<code>z</code>” except for one of its positions, which will contain a character “<code>*</code>” , indicating that the character at that position is still unknown.</p>



## 출력


<p>Print a single line, containing, in order, a word $T$, of length $C$, and an integer $M$, such that $M$ is the greatest number of compatibilities a word might have with the input words and $T$ is the lexicographically smallest amongst the words with compatibility $M$.</p>



## 소스코드

[소스코드 보기](Multidimensional%20Hangman.py)