# 15602번: Dunglish - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15602)


<p>A confused Dutchman trying to speak English could say “I am in the war”, even though there is no hostile activity going on. The confusion<sup>1</sup> here is that the English sentence “I am confused” is translated in Dutch as “Ik ben in de war”, which is phonetically (“sounding”) quite close to the first sentence. Such confusion leads to much enjoyment, but can complicate matters a bit.</p>

<p>Given a sentence in Dutch and a dictionary containing both correct translations as well as phonetic (incorrect) translations of individual words, find the translation of the sentence and indicate whether it is correct, or in case there is more than one find the total number of correct and incorrect translations. A sentence is correctly translated when each word of the sentence is correctly translated.</p>

<p><sup>1</sup>Pun intended.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with an integer n (1 ≤ n ≤ 20), the number of words in the Dutch sentence.</li>
<li>One line with n words, the Dutch sentence s.</li>
<li>One line with an integer m (1 ≤ m ≤ 10<sup>5</sup>), the number of words in the dictionary.</li>
<li>m lines, each with three strings d, e and c, a Dutch word, the English translation, and “correct” if this is the correct translation or “incorrect” otherwise.</li>
</ul>

<p>A word consists of between 1 and 20 lowercase letters. Each word in s appears at least once as a Dutch word in the dictionary, no word appears more than 8 times as a Dutch word in the dictionary, and each combination of a Dutch and English word appears at most once.</p>



## 출력


<p>In case there is only a single translation of s, output one line with the translation followed by one line with “correct” or “incorrect”. In case there is more than one translation, output one line with the number of possible correct translations followed by “correct”, and one line with the number of possible incorrect translations followed by “incorrect”.</p>



## 소스코드

[소스코드 보기](Dunglish.cpp)