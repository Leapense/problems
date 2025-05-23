# 13761번: Banking II - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13761)


<p>A month ago at the South Pacific Divisional Contest, each of you (or one of your teammates) solved a problem about authenticating users. To refresh your memory:</p>

<p>The Actuarial Commerce Merchant bank has a scheme where, when you login, you are provided with a “pattern word”, containing only upper and lower case letters. You must use this pattern word to extract and sum digits from your PIN as follows.</p>

<p>Letters in the pattern word are to be interpreted as numbers, with a (or A) = 1, b (or B) = 2, . . . , z (or Z) = 26. A lower case letter specifies a count of digits to extract from the PIN while an upper case letter specifies a count of digits to be skipped. The letters in the pattern word are processed from left to right resulting in a sequence of extracted digits, which are added together to yield a number. You then enter that number into a field on the web page form to authenticate yourself. For example, if your PIN was 1093373, and the pattern provided to you was aBcA you would extract one digit (namely 1) skip two digits (09), extract 3 digits (337) and then skip 1 digit (3), before totalling the extracted digits (1337) and entering 14 into the field on the web page form.</p>

<p>The bank allows you to have a PIN containing up to 256 digits and they provide a pattern word in which the letters, when interpreted as numbers, sum to the length of the PIN.</p>

<p>Between the Divisional contest and now, something terrible has happened: someone has hacked into the bank’s database and deleted all of the capital letters from every pattern word! In a panic, the bank has called you and requires your help again! For a given partial PIN, they would like to know the maximum value that could have been output from the algorithm mentioned above over all possible placements of capital letters such that the length of the pattern (when interpreted as numbers) matches the length of the PIN. The order of the lowercase letters may not be changed.</p>



## 입력


<p>The input will contain a single test case.</p>

<p>The first line of input will contain an n-digit PIN (6 ≤ n ≤ 256). The second line will contain an m-digit pattern word containing only lower case letters (0 ≤ m ≤ n).</p>



## 출력


<p>Output the maximum possible sum of extracted digits from the PIN. You may assume that at least one valid pattern exists (the bank had removed all of the bad cases after your help at Divisionals).</p>



## 소스코드

[소스코드 보기](Banking%20II.cpp)