# 8959번: Stuttering Strings - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8959)


<p>The residents of a remote Himalayan monastery believe that strings of repeated syllables in their language have mystic power, particularly if they can produce chants containing all possible strings of a given length. Because outsiders are not even allowed to know the syllables, they have replaced them with single characters such that the resulting strings can be converted into chants easily. They have developed the following rules.</p>

<ol>
<li>there are only two characters ‘*’ and ‘!’.</li>
<li>In any given situation there is a fixed length of word.</li>
<li>To impose some structure on the sequences there can never be more than some number of each character in succession.</li>
<li>For completeness, we need all the possible sequences of characters that will match these rules.</li>
</ol>

<p>Write a program that will read in the length of the sequence and the maximum number of adjacent ‘*’s and ‘!’s and produce all acceptable sequences. These should be in lexicographic sequence, where, for this problem, ‘*’ is deemed to precede ‘!’.</p>



## 입력


<p>Input consists of sequence of lines each containing 3 integers: n (1 ≤ n ≤ 10), nstar and nbang, and is terminated by a line containing 3 zeroes (0 0 0).</p>



## 출력


<p>Output consists of, for each problem in the set, a header line starting with ‘Sequence set ‘, followed by a running number starting at 1, followed by the ordered list of such sequences, i.e. those with no more than nstar consecutive ‘*’s and no more than nbang consecutive ‘!’s, one per line, followed by a blank line.</p>



## 소스코드

[소스코드 보기](Stuttering%20Strings.cpp)