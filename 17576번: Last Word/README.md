# 17576번: Last Word - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17576)


<p>The <code>substring()</code> function is a commonly-used operation available in most programming languages that operates on strings. A start offset and a length are provided and used to construct a new string containing only the characters in a sequence of that length beginning from the offset.</p>

<p>One particular string has had this called a large number of times in sequence: we repeatedly used the standard library function <code>substring(s, start, length)</code> to chop it up until now a potentially much shorter string remains.</p>

<p>Find the value of the string produced by all of these operations.</p>



## 입력


<ul>
<li>The first line of input contains the string s (1 ≤ |s| ≤ 10<sup>6</sup>).</li>
<li>The second line of input contains the number of operations, n (1 ≤ n ≤ 10<sup>6</sup>).</li>
<li>Each of the following n lines contains the two integers start<sub>i</sub> and length<sub>i</sub> (0 ≤ start<sub>i</sub> &lt; length<sub>i−1</sub>; 1 ≤ start<sub>i</sub> + length<sub>i</sub> ≤ length<sub>i−1</sub>).</li>
</ul>



## 출력


<p>Output the string after all of the successive substring() operations.</p>



## 소스코드

[소스코드 보기](Last%20Word.py)