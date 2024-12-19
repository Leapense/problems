# 10751번: COW - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10751)


<p>Bessie the cow has stumbled across an intriguing inscription carved into a large stone in the middle of her favorite grazing field. The text of the inscription appears to be from a cryptic ancient language involving an alphabet with only the three characters C, O, and W. Although Bessie cannot decipher the text, she does appreciate the fact that C, O, and W in sequence forms her favorite word, and she wonders how many times COW appears in the text.</p>

<p>Bessie doesn't mind if there are other characters interspersed within COW, only that the characters appear in the correct order. She also doesn't mind if different occurrences of COW share some letters. For instance, COW appears once in CWOW, twice in CCOW, and eight times in CCOOWW.</p>

<p>Given the text of the inscription, please help Bessie count how many times COW appears.</p>



## 입력


<p>The first line of input consists of a single integer N &lt;= 10^5. The second line contains of a string of N characters, where each character is either a C, O, or W.</p>



## 출력


<p>Output the number of times COW appears as a subsequence, not necessarily contiguous, of the input string.</p>

<p>Note that the answer can be very large, so make sure to use 64 bit integers ("long long" in C++, "long" in Java) to do your calculations.</p>



## 소스코드

[소스코드 보기](COW.cpp)