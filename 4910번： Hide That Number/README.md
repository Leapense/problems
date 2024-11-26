# 4910번: Hide That Number - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4910)


<p>According to Wikipedia, Cryptography is “the practice and study of hiding information” and this is exactly what Alex is looking for. Ever since he was a kid, Alex was paranoid over someone laying their hands on his phone book. He decided that he must write the numbers in some secret way that only he can decipher. At first he tried quite complex algorithms, but that slowed him down when he needed to dial a number fast. He finally came up with the following algorithm: Rather than writing down the number itself, Alex would shift the number one place to the left (as if multiplying it by 10,) then adding the shifted number to the original. For example, if the phone number was 123, Alex would add 1230 to it, resulting in 1353. To make what he writes looks as a regular phone number, Alex truncates the result (from the left,) so that it has as many digits as the original phone number. In this example, Alex writes 353 instead of 123 in his phone book.</p>

<p>Alex needs a program to print the original phone number given what is written in his phone book. Alex, who by the way is a good friend of Johnny, isn’t that good in arithmetic. It is quite possible that the numbers are messed up. The program should print "IMPOSSIBLE" (without the quotes) if the original number cannot be computed.</p>



## 입력


<p>Your program will be tested on one or more test cases. Each case is specified on a separate line and is made of a single positive number having less than 1,000,000 digits.</p>

<p>The last line of the input file is made of a single zero.</p>



## 출력


<p>For each test case, output the result on a single line using the following format:</p>

<p>k.␣result</p>

<p>Where k is the test case number (starting at 1) and ␣ is a single space.</p>



## 소스코드

[소스코드 보기](Hide%20That%20Number.cpp)