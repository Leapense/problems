# 6538번: Run Length Encoding - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6538)


<p>Your task is to write a program that performs a simple form of run-length encoding, as described by the rules below.</p>

<p>Any sequence of between 2 to 9 identical characters is encoded by two characters. The first character is the length of the sequence, represented by one of the characters <code>2</code> through <code>9</code>. The second character is the value of the repeated character. A sequence of more than 9 identical characters is dealt with by first encoding 9 characters, then the remaining ones.</p>

<p>Any sequence of characters that does not contain consecutive repetitions of any characters is represented by a <code>1</code> character followed by the sequence of characters, terminated with another <code>1</code>. If a <code>1</code> appears as part of the sequence, it is escaped with a <code>1</code>, thus two <code>1</code> characters are output.</p>



## 입력


<p>The input consists of letters (both upper- and lower-case), digits, spaces, and punctuation. Every line is terminated with a newline character and no other characters appear in the input.</p>



## 출력


<p>Each line in the input is encoded separately as described above. The newline at the end of each line is not encoded, but is passed directly to the output.</p>



## 소스코드

[소스코드 보기](Run%20Length%20Encoding.cpp)