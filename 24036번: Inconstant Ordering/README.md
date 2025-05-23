# 24036번: Inconstant Ordering - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24036)


<p>We want to build a string with English alphabet uppercase letters in sorted order. However, we want the order to be sometimes strictly increasing and sometimes strictly decreasing.</p>

<p>The first letter of the string must be&nbsp;<code>A</code>. After that, the string must contain one or more blocks of letters. The $i$-th block must contain exactly&nbsp;$L_i$&nbsp;letters. Each letter in the&nbsp;$i$-th block must be later in the alphabet than its preceding letter in the string if&nbsp;$i$&nbsp;is odd and earlier in the alphabet than its preceding letter if&nbsp;$i$&nbsp;is even. Notice that for the first letter of a block, its preceding letter exists, even though it is not in the block. Strings that follow all of these rules are called valid. There can be multiple valid strings, and we want to find the alphabetically first one.</p>

<p>For example, if there are&nbsp;$2$&nbsp;blocks of sizes&nbsp;$L_1=2$&nbsp;and&nbsp;$L_2=3$, the string must have exactly&nbsp;$1+L_1+L_2=1+2+3=6$&nbsp;letters (the&nbsp;$1$&nbsp;is for the initial&nbsp;<code>A</code>). The strings&nbsp;<code>XYZYBA</code>,&nbsp;<code>AZYCBA</code>&nbsp;and&nbsp;<code>AYZYBB</code>&nbsp;are not valid for this case because they violate the required starting letter condition, and the ordering conditions in the first and second block, respectively. The string&nbsp;<code>AYZYBA</code>&nbsp;is valid. The string&nbsp;<code>ABDCBA</code>&nbsp;is also valid and, moreover, it is the alphabetically first valid string.</p>

<p>Given the sizes of the blocks, output the valid string that comes first in alphabetical order in the list of all valid strings. It can be shown that, for all inputs within the given limits, at least one valid string exists.</p>



## 입력


<p>The first line of the input gives the number of test cases, $T$.&nbsp;$T$&nbsp;test cases follow. Each test case is described with two lines. The first line of a test case contains a single integer&nbsp;$N$, the number of blocks. The second line contains&nbsp;$N$&nbsp;integers&nbsp;$L_1,L_2, \cdots ,L_N$, the number of letters each block must have, in order.</p>



## 출력


<p>For each test case, output one line containing&nbsp;<code>Case #x:&nbsp;y</code>, where $x$&nbsp;is the test case number (starting from 1) and&nbsp;$y$&nbsp;is the valid string that comes first in alphabetical order. It is guaranteed that at least one valid string exists.</p>



## 소스코드

[소스코드 보기](Inconstant%20Ordering.py)