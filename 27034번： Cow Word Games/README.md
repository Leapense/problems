# 27034번: Cow Word Games - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27034)


<p>Tired of being teased by the other farm animals for their poor vocabulary, Farmer John's cows have stolen a word game from FJ's house to use for practice.  In this particular word game, each cow receives a set of N (1 ≤ N ≤ 100) not necessarily unique uppercase letters (for example: 'V', 'B', 'O', 'E', 'I', 'N', 'O').  Each letter has a certain specified point value, and each cow's goal is to form a valid word using a subset of her letters worth the maximum number of points.  For example, if every letter is worth 1 point, the maximum number of points one can receive from the letters above is 6, using the word 'BOVINE'.</p>

<p>The cows have also managed to steal a dictionary containing M (1 ≤ M ≤ 10,000) words from FJ's house, so they can check whether or not certain words are valid.  Please help his cows compute the best possible words they can form based on the letters they receive.</p>



## 입력


<ul>
<li>Line 1: Two space-separated integers, N and M (1 ≤ M ≤ 10000).</li>
<li>Lines 2..27: Each of these 26 lines contains a positive integer giving the number of points for a letter of the alphabet. The first of these lines corresponds to 'A'; the last corresponds to 'Z'.</li>
<li>Lines 28..N+27: These N lines contain the letters received by a cow playing the game.   Each line contains a single uppercase letter.</li>
<li>Lines N+28..N+M+27: These M lines each contain a word from the dictionary.  Each word consists of at most N uppercase letters.</li>
</ul>



## 출력


<ul>
<li>Line 1: A single integer, specifying the maximum number of points we can  receive.  If no valid words in the dictionary can be formed, output -1.</li>
</ul>



## 소스코드

[소스코드 보기](Cow%20Word%20Games.py)