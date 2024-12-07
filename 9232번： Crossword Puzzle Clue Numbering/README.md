# 9232번: Crossword Puzzle Clue Numbering - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9232)


<p>Professor Logophile is the local crossword puzzle setter. He has a very idiosyncratic way of working — he writes the words into a blank grid and then fills in the unused squares. That is the easy bit, but he has trouble doing the next bit — numbering the puzzle and preparing the the clues.&nbsp;</p>

<p>This is where you come in. Given a completed crossword, print out a form on which the clues can be written (showing word lengths). Note that he always prepares a true crossword, i.e. there is always at least one word in each direction and there is always at least one shared letter. All words contain three or more letters.</p>



## 입력


<p>Input will be a series of crosswords. The first line of each crossword will be a pair of integers (r and c, 3 ≤ r c ≤ 20) giving the number of rows and columns of the crossword. This will be followed r rows each containing c characters. Each character will be either an uppercase letter or a ‘@’ representing a black square. The file will be terminated by a pair of zeroes (0 0).</p>



## 출력


<p>For each crossword, the output will start with a line containing “Crossword puzzle &lt;cwnum&gt;” where &lt;cwnum&gt; is a running number starting at 1, followed by a form showing the clue number and length for both across and down clues. Each form begins with the word ‘Across’ or ‘Down’ as appropriate, followed by a line for each across or down word that appears in the crossword. Each line begins with the word number with no preceding spaces followed by a full stop, two spaces, an open parenthesis (‘(‘), the length of the word with no preceding spaces and a closing parenthesis (‘)’). Leave one blank line between the ‘Across’ and ‘Down’ parts and between successive crosswords.</p>



## 소스코드

[소스코드 보기](Crossword%20Puzzle%20Clue%20Numbering.cpp)