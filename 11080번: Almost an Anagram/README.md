# 11080번: Almost an Anagram - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11080)


<p>Andy loves anagrams. For the uninitiated, an anagram is a word formed by rearranging the letters of another word, for example rasp can be rearranged to form spar. Andy is interested to know if two words are almost anagrams. A word is almost an anagram of another word if:</p>

<ul>
<li>one word is shorter than the other by one letter but otherwise contains the same letters in any order; or</li>
<li>the two words are the same length and their character multisets differ by one character only e.g. “aaa” and “aab”</li>
</ul>

<p>Your job is to help Andy to determine if two words are identical, anagrams, almost anagrams or nothing like each other.</p>



## 입력


<p>The input contains a single test case.</p>

<p>The input will be a single line of text containing a pair of words separated by a single space. The words will be in lower case and will contain alphabetic characters only. Words will contain between 1 and 1000 letters inclusive.</p>



## 출력


<p>Your program should produce one line of output as follows:</p>

<p>If the words are identical, output: word<sub>a</sub> is identical to word<sub>b</sub><br>
If the words are anagrams, output: word<sub>a</sub> is an anagram of word<sub>b</sub><br>
If the words are almost anagrams, output: word<sub>a</sub> is almost an anagram of word<sub>b</sub><br>
Otherwise, output: word<sub>a</sub> is nothing like word<sub>b</sub></p>

<p>In all cases the first word in the output sentence must be the shorter word or if the words are the same length the first word must be the lexicographically least.</p>



## 소스코드

[소스코드 보기](Almost%20an%20Anagram.cpp)