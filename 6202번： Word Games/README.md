# 6202번: Word Games - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6202)


<p>The cows are playing Scrabble but, sad to say, they do not have the vocabulary to play at the tournament level. Bessie wants your help for just the first move. Given her rack (a "rack" is a holder of Scrabble letters) of N (3 &lt;= N &lt;= 10) letters (which might or might not be unique and might include one or more blank "wild card" tiles) along with a scrabble dictionary of D (10 &lt;= D &lt;= 50000) words, print the words she might use (by searching the dictionary).</p>

<p>The 27 possible letters are upper-case 'A'..'Z' and the '#' symbol, which represents a "wildcard" and can stand for any letter. If two '#'s appear in one rack, each can represent a different letter when played.</p>

<p>The dictionary words can be read, one per line, from file whose name is 'scrbl.txt' (the file name is all lower case letters, unlike the file's contents). The letters in Bessie's rack can always be used to make at least one word. Each word in the dictionary is unique. Remember that you are running on Linux: each input line ends with a '\n' character; no 'return' characters are present.</p>



## 입력


<ul>
<li>Line 1: Two space-separated integers, N and D.</li>
<li>Line 2: N letters (with no intervening blanks) that are the letters in Bessie's Scrabble rack.</li>
</ul>



## 출력


<ul>
<li>Lines 1..??: Each line contains a single word that appears in the scrbl.txt dictionary. Print the output in the order the words appear in the dictionary.</li>
</ul>



## 소스코드

[소스코드 보기](Word%20Games.cpp)