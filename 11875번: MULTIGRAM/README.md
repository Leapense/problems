# 11875번: MULTIGRAM - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11875)


<p>Pero is a passionate lover of riddles. The newest type of riddles he has come across requires the solver to check whether the given word is a multigram.</p>

<p>A multigram is a word that consists of concatenating two or more words that are all mutually anagrams. The first of these words is called the root of the multigram. For instance, the word bbabab is a multigram with the root bba because it consists of anagrams bba and bab.</p>

<p>Help Pero solve the riddle by determining whether his word is a multigram and determining its root in case it is. If there are multiple possible roots of the multigram, output the shortest.</p>

<p>Please note: Two words are mutually anagrams if one of them can be obtained from the other by changing the letter order.</p>



## 입력


<p>The first and only line of input contains a word of length at most 100 000 lowercase English characters.</p>



## 출력


<p>If the given word is not a multigram, output −1.</p>

<p>Otherwise, output the shortest root of the given word in one line.</p>



## 소스코드

[소스코드 보기](MULTIGRAM.py)