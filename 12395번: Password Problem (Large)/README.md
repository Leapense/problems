# 12395번: Password Problem (Large) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12395)


<p>I have a really long password, and sometimes I make a mistake when I type it. Right now I've typed part of my password, but I might have made some mistakes. In particular, I might have pressed the wrong key while typing one or more of the previous characters. Given how likely I was to get each character right, what should I do?</p>

<p>I have three options:</p>

<ol>
<li>Finish typing the password, then press "enter". I know I'll type the rest of the characters perfectly. If it turns out that one of the earlier characters was wrong, I'll have to retype the whole thing and hit "enter" again -- but I know I'll get it right the second time.</li>
<li>Hit "backspace" some number of times, deleting the last character(s) I typed, and then complete the password and press "enter" as in option 1. If one of the characters I didn't delete was wrong, I'll have to retype the whole thing and press "enter", knowing I'll get it right the second time.</li>
<li>Give up by pressing "enter", retyping the password from the start, and pressing "enter" again. I know I'll get it right this time.</li>
</ol>

<p>&nbsp;</p>

<p>I want to minimize the&nbsp;<em>expected</em>&nbsp;number of keystrokes needed. Each character in the password costs 1 keystroke; each "backspace" costs 1 keystroke; pressing "enter" to complete an attempt or to give up costs 1 keystroke.</p>

<p><em>Note:</em>&nbsp;The "expected" number of keystrokes is the average number of keystrokes that would be needed if the same situation occurred a very large number of times. See the example below.</p>

<h3>Example</h3>

<p>Suppose my password is "guest" and I have already typed the first two characters, but I had a 40% chance of&nbsp;<em>making a mistake</em>&nbsp;when typing each of them. Then there are four cases:</p>

<ul>
<li>I typed "<code>gu</code>" without error. This occurs with probability 0.6 * 0.6 = 0.36.</li>
<li>I typed the 'g' correctly but I made a mistake typing the 'u'. Then I have two letters typed still, but the second one is wrong: "<code>gX</code>". (Here, the 'X' character represents a mistyped letter.) This occurs with probability 0.6 * 0.4 = 0.24.</li>
<li>I typed the 'u' correctly but I made a mistake typing the 'g': "<code>Xu</code>". This occurs with probability 0.4 * 0.6 = 0.24.</li>
<li>I made a mistake typing both letters, so I have two incorrect letters: "<code>XX</code>". This occurs with probability 0.4 * 0.4 = 0.16.</li>
</ul>

<p>&nbsp;</p>

<p>I don't know how many mistakes I actually made, but for any strategy, I can calculate the&nbsp;<em>expected</em>&nbsp;number of keys required to use it. This is shown in the table below:</p>

<p>&nbsp;</p>

<table cellspacing="0" style="border-collapse:collapse; border-width:0pt; color:#000000; font-family:arial,sans-serif; font-size:small; margin:0px; padding:0px; vertical-align:top">
<tbody>
<tr>
<td style="vertical-align:top">&nbsp;</td>
<td style="vertical-align:top">"<code>gu</code>"&nbsp;&nbsp;&nbsp;</td>
<td style="vertical-align:top">"<code>gX</code>"&nbsp;&nbsp;&nbsp;</td>
<td style="vertical-align:top">"<code>Xu</code>"&nbsp;&nbsp;&nbsp;</td>
<td style="vertical-align:top">"<code>XX</code>"&nbsp;&nbsp;&nbsp;</td>
<td style="vertical-align:top">Expected</td>
</tr>
<tr>
<td style="vertical-align:top">Probability</td>
<td style="vertical-align:top">0.36</td>
<td style="vertical-align:top">0.24</td>
<td style="vertical-align:top">0.24</td>
<td style="vertical-align:top">0.16</td>
<td style="vertical-align:top">-</td>
</tr>
<tr>
<td style="vertical-align:top">Keystrokes if I keep typing</td>
<td style="vertical-align:top">4</td>
<td style="vertical-align:top">10</td>
<td style="vertical-align:top">10</td>
<td style="vertical-align:top">10</td>
<td style="vertical-align:top">7.84</td>
</tr>
<tr>
<td style="vertical-align:top">Keystrokes if I press backspace once</td>
<td style="vertical-align:top">6</td>
<td style="vertical-align:top">6</td>
<td style="vertical-align:top">12</td>
<td style="vertical-align:top">12</td>
<td style="vertical-align:top">8.4</td>
</tr>
<tr>
<td style="vertical-align:top">Keystrokes if I press backspace twice&nbsp;&nbsp;</td>
<td style="vertical-align:top">8</td>
<td style="vertical-align:top">8</td>
<td style="vertical-align:top">8</td>
<td style="vertical-align:top">8</td>
<td style="vertical-align:top">8</td>
</tr>
<tr>
<td style="vertical-align:top">Keystrokes if I press enter right away</td>
<td style="vertical-align:top">7</td>
<td style="vertical-align:top">7</td>
<td style="vertical-align:top">7</td>
<td style="vertical-align:top">7</td>
<td style="vertical-align:top">7</td>
</tr>
</tbody>
</table>

<p>&nbsp;</p>

<p>If I keep typing, then there is an 0.36 probability that I will need 4 keystrokes, and an 0.64 probability that I will need 10 keystrokes. If I repeated the trial many times, then I would use 4 keystrokes 36% of the time, and 10 keystrokes the remaining 64% of the time, so the average number of keystrokes needed would be 0.36 * 4 + 0.64 * 10 = 7.84. In this case however, it is better to just press enter right away, which requires 7 keystrokes.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>T</strong>.&nbsp;<strong>T</strong>&nbsp;test cases follow. Each test case begins with a line containing two integers,&nbsp;<strong>A</strong>&nbsp;and&nbsp;<strong>B</strong>.&nbsp;<strong>A</strong>&nbsp;is the number of characters that I have already typed, and&nbsp;<strong>B</strong>&nbsp;is the total number of characters in my password.</p>

<p>This is followed by a line containing&nbsp;<strong>A</strong>&nbsp;real numbers: p<sub>1</sub>, p<sub>2</sub>, ..., p<sub><strong>A</strong></sub>. p<sub>i</sub>&nbsp;represents the probability that I&nbsp;<em>correctly</em>&nbsp;typed the i<sup>th</sup>&nbsp;letter in my password. These real numbers will consist of decimal digits and at most one decimal point. The decimal point will never be the first or the last character in a number.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>T</strong>&nbsp;≤ 20.</li>
<li>0 ≤ p<sub>i</sub>&nbsp;≤ 1 for all i.</li>
<li>1 ≤&nbsp;<strong>A</strong>&nbsp;≤ 99999.</li>
<li><strong>A</strong>&nbsp;&lt;&nbsp;<strong>B</strong>&nbsp;≤ 100000.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the expected number of additional keystrokes I need, not counting the letters I have typed so far, and assuming I choose the optimal strategy. y must be correct to within an absolute or relative error of 10<sup>-6</sup>.</p>



## 소스코드

[소스코드 보기](Password%20Problem%20(Large).cpp)