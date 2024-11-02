# 28373번: Eszett - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/28373)


<p>For those trying to learn German, the letter 'ß', called <em>Eszett</em> or <em>sharp S</em>, is usually a source of great confusion. This letter is unique to the German language and it looks similar to a 'b' but is pronounced like an 's'.</p>

<p>Adding to the confusion is the fact that, until a few years ago, only a lowercase version of 'ß' existed in standard German orthography. Wherever an uppercase 'ß' was needed, for example in legal documents and shop signs, it was (and usually still is) replaced by capital double letters 'SS'. In 2017, the capital 'ẞ' was officially introduced into the German language and may now be used in those scenarios, instead.</p>

<p>Other than being confusing for foreigners, the practice of replacing 'ß' with 'SS' also introduces some ambiguity because a given uppercase word featuring one or more occurrences of 'SS' may correspond to multiple different lowercase words, depending on whether each 'SS' is a capitalized 'ß' or 'ss'.</p>

<p>Given one uppercase word, find all the lowercase words that it could be derived from. As the letter 'ß' is not part of the ASCII range, please write an uppercase 'B', instead.</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>One line with a string $s$ ($1 \le |s| \le 20$) consisting of uppercase letters.</li>
</ul>

<p>It is guaranteed that the letter <code>S</code> occurs at most three times in $s$. Note that $s$ need not be an actual German word.</p>



## 출력


<p>Output all the possible lowercase strings corresponding to $s$. Any order will be accepted, but each string must occur exactly once.</p>



## 소스코드

[소스코드 보기](Eszett.py)