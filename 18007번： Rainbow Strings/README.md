# 18007번: Rainbow Strings - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18007)


<p>Define a <em>Rainbow String</em> as a string where every letter in the string is distinct. The empty string is a <em>Rainbow String</em>.</p>

<p>Given a string of lower-case letters, compute the number of different subsequences which are <em>Rainbow Strings</em>. Two subsequences are different if letter at a <em>specific position</em> is included in one subsequence but not the other. Thus, two different subsequences may result in the same string.</p>

<p>For example, consider the string <code>aab</code>. The following six subsequences (in bold and underlined) are the only Rainbow Strings in <code>aab</code>:</p>

<p style="text-align: center;"><code><u><strong>a</strong></u>ab a<u><strong>a</strong></u>b aa<u><strong>b</strong></u> <u><strong>a</strong></u>a<u><strong>b</strong></u> a<u><strong>ab</strong></u> <u><strong>&lt;empty&gt;</strong></u></code></p>

<p>The answer may be large, so output the answer modulo 11092019.</p>



## 입력


<p>The single line of input contains a string <em>s</em> (1 ≤ |<em>s</em>| ≤ 10<sup>5</sup>) which consists only of lower-case letters.</p>



## 출력


<p>Output a single integer, which is the number of subsequences of <em>s</em> which are <em>Rainbow Strings</em>.</p>



## 소스코드

[소스코드 보기](Rainbow%20Strings.cpp)