# 15071번: The Key to Cryptography - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15071)


<p>Suppose you need to encrypt a top secret message like “SEND MORE MONKEYS". You could use a simple substitution cipher, where each letter in the alphabet is replaced with a different letter. However, these ciphers are easily broken by using the fact that certain letters of the alphabet (like ‘E’, ‘S’, and ‘A’) appear more frequently than others (like ‘Q’, ‘Z’, and ‘X’). A better encryption scheme would vary the substitutions used for each letter. One such system is the autokey cipher.</p>

<p>To encrypt a message, you first select a secret word – say “ACM" – and prepend it to the front of the message. This longer string is truncated to the length of the message and called the key, and the n th letter of the key is used to encrypt the n th letter of the original message. This encryption is done by treating each letter in the key as a cyclic shift value for the corresponding letter in the message, where ‘A’ indicates a shift of 0, ‘B’ a shift of 1, and so on. Using “ACM" as the secret word, we would encrypt our message as follows:</p>

<pre> SENDMOREMONKEYS (message)
 ACMSENDMOREMONK (key)
------------------------------
 SGZVQBUQAFRWSLC (ciphertext)</pre>

<p>Note that the letter ‘E’ in the message was encrypted as ‘G’ the first time it was encountered (since the corresponding letter in the key was ‘C’ indicating a shift of 2), but then as ‘Q’ and ‘S’ the next two times.</p>

<p>Your task is simple: given a ciphertext and the secret word, you must determine the original message.</p>



## 입력


<p>Input consists of two lines. The first contains the ciphertext and the second contains the secret word. Both lines contain only uppercase alphabetic letters.</p>



## 출력


<p>Display the original message that generated the given ciphertext using the given secret word.</p>



## 소스코드

[소스코드 보기](The%20Key%20to%20Cryptography.cpp)