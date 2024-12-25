# 12038번: Polynesiaglot (Small2) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12038)


<p>Ursula is a big fan of constructing artificial languages. Today, she is starting to work on a language inspired by real Polynesian languages. The only rules she has established are:</p>

<ul>
<li>All words consist of letters. Letters are either consonants or vowels.</li>
<li>Any consonant in a word must be immediately followed by a vowel.</li>
</ul>

<p>For example, in a language in which&nbsp;<em>a</em>&nbsp;is the only vowel and&nbsp;<em>h</em>&nbsp;is the only consonant,&nbsp;<em>a</em>,&nbsp;<em>aa</em>,&nbsp;<em>aha</em>,&nbsp;<em>aaha</em>, and&nbsp;<em>haha</em>&nbsp;are valid words, whereas&nbsp;<em>h</em>,&nbsp;<em>ahh</em>,&nbsp;<em>ahah</em>, and&nbsp;<em>ahha</em>&nbsp;are not. Note that the rule about consonants disallows ending a word in a consonant as well as following a consonant with another consonant.</p>

<p>If Ursula's new language has&nbsp;<strong>C</strong>&nbsp;different consonants and&nbsp;<strong>V</strong>&nbsp;different vowels available to use, then how many different valid words of length&nbsp;<strong>L</strong>&nbsp;are there in her language? Since the output can be a really big number, we only ask you to output the remainder of dividing the result by the prime 10<sup>9</sup>+7 (1000000007).</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each consists of one line with three integers&nbsp;<strong>C</strong>,&nbsp;<strong>V</strong>, and&nbsp;<strong>L</strong>.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 100.</li>
<li>1 ≤&nbsp;<strong>C</strong>&nbsp;≤ 50.</li>
<li>1 ≤&nbsp;<strong>V</strong>&nbsp;≤ 50.</li>
<li>1 ≤&nbsp;<strong>L</strong>&nbsp;≤ 15.</li>
</ul>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x: y</code>, where&nbsp;<code>x</code>&nbsp;is the test case number (starting from 1) and&nbsp;<code>y</code>&nbsp;is the number of different valid words of length&nbsp;<strong>L</strong>&nbsp;in the language, modulo the prime 10<sup>9</sup>+7 (1000000007).</p>



## 소스코드

[소스코드 보기](Polynesiaglot%20(Small2).cpp)