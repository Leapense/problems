# 12277번: Read Phone Number (Large) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12277)


<p>Do you know how to read the phone numbers in English? Now let me tell you.</p>

<p>For example, In China, the phone numbers are 11 digits, like: 15012233444. Someone divides the numbers into 3-4-4 format, i.e. 150 1223 3444. While someone divides the numbers into 3-3-5 format, i.e. 150 122 33444. Different formats lead to different ways to read these numbers:</p>

<p>150 1223 3444 reads one five zero one double two three three triple four.</p>

<p>150 122 33444 reads one five zero one double two double three triple four.</p>

<p>Here comes the problem:</p>

<p>Given a list of phone numbers and the dividing formats, output the right ways to read these numbers.</p>

<p>Rules:</p>

<p>Single numbers just read them separately.</p>

<p>2 successive numbers use double.</p>

<p>3 successive numbers use triple.</p>

<p>4 successive numbers use quadruple.</p>

<p>5 successive numbers use quintuple.</p>

<p>6 successive numbers use sextuple.</p>

<p>7 successive numbers use septuple.</p>

<p>8 successive numbers use octuple.</p>

<p>9 successive numbers use nonuple.</p>

<p>10 successive numbers use decuple.</p>

<p>More than 10 successive numbers read them all separately.</p>



## 입력


<p>The first line of the input gives the number of test cases, <strong>T</strong>. <strong>T</strong> lines|test cases follow. Each line contains a phone number <strong>N</strong> and the dividing format <strong>F</strong>, one or more positive integers separated by dashes (-), without leading zeros and whose sum always equals the number of digits in the phone number.</p>

<p>Limits</p>

<ul>
<li>1 ≤ <strong>T</strong> ≤ 100.</li>
<li>1 ≤ <strong>length of N</strong> ≤ 100.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the reading sentence in English whose words are separated by a space.</p>



## 소스코드

[소스코드 보기](Read%20Phone%20Number%20(Large).cpp)