# 11488번: Nimionese - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11488)


<p>Nimions speak a funny form of language.</p>

<p>Whichever word they are trying to say, from which ever language, it doesn’t quite come out the same. There are several rules for converting words, from any language, to nimionese.</p>

<p>For any word:</p>

<ul>
<li>All nimion words start with ‘hard’ consonants — [b, c, d, g, k, n, p, t], so you must replace each first letter with the nearest one (choose the option nearest to ‘A’ if there is a tie).
<ul>
<li>“Each” becomes “Dach”.</li>
</ul>
</li>
<li>Any hard consonant in subsequent syllables after the first one is remarkably better if it is replaced with the same consonant as the one at the start of the word.
<ul>
<li>“Hip-po” becomes “Gip-go”.</li>
</ul>
</li>
<li>No word ends in a hard consonant. You must add an ‘ah’, ‘oh’ or ‘uh’ at the end, whichever is nearest, rounding toward ‘A’ in the case of a tie, to the last hard consonant in the word.
<ul>
<li>“Dog” becomes “Dogah”</li>
<li>“Hip” becomes “Gipoh”.</li>
</ul>
</li>
</ul>



## 입력


<p>The only line of input contains a sentence of between 1 and 50 words and up to 10<sup>4</sup> symbols, including single whitespace characters (‘ ’) between words and the dashes (‘-’) between each syllable.</p>

<p>Apart from dashes, the sentence will contain solely lower-and-upper-case Latin letters — and only the first letters of words can be upper-case.</p>



## 출력


<p>Write to standard output the same sentence from the input, translated to nimionese. Remove any dashes before printing.</p>

<p>It is guaranteed that the output will fit within 5 · 10<sup>4</sup> characters</p>



## 소스코드

[소스코드 보기](Main.java)