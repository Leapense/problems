# 3932번: Unreliable Messengers - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3932)


<p>The King of a little Kingdom on a little island in the Pacific Ocean frequently has childish ideas. One day he said, “You shall make use of a message relaying game when you inform me of something.” In response to the King’s statement, six servants were selected as messengers whose names were Mr. J, Miss C, Mr. E, Mr. A, Dr. P, and Mr. M. They had to relay a message to the next messenger until the message got to the King.</p>

<p>Messages addressed to the King consist of digits (‘0’–‘9’) and alphabet characters (‘a’–‘z’, ‘A’– ‘Z’). Capital and small letters are distinguished in messages. For example, “ke3E9Aa” is a message.</p>

<p>Contrary to King’s expectations, he always received wrong messages, because each messenger changed messages a bit before passing them to the next messenger. Since it irritated the King, he told you who are the Minister of the Science and Technology Agency of the Kingdom, “We don’t want such a wrong message any more. You shall develop software to correct it!” In response to the King’s new statement, you analyzed the messengers’ mistakes with all technologies in the Kingdom, and acquired the following features of mistakes of each messenger. A surprising point was that each messenger made the same mistake whenever relaying a message. The following facts were observed.</p>

<p>Mr. J rotates all characters of the message to the left by one. For example, he transforms “aB23d” to “B23da”.</p>

<p>Miss C rotates all characters of the message to the right by one. For example, she transforms “aB23d” to “daB23”.</p>

<p>Mr. E swaps the left half of the message with the right half. If the message has an odd number of characters, the middle one does not move. For example, he transforms “e3ac” to “ace3”, and “aB23d” to “3d2aB”.</p>

<p>Mr. A reverses the message. For example, he transforms “aB23d” to “d32Ba”.</p>

<p>Dr. P increments by one all the digits in the message. If a digit is ‘9’, it becomes ‘0’. The alphabet characters do not change. For example, he transforms “aB23d” to “aB34d”, and “e9ac” to “e0ac”.</p>

<p>Mr. M decrements by one all the digits in the message. If a digit is ‘0’, it becomes ‘9’. The alphabet characters do not change. For example, he transforms “aB23d” to “aB12d”, and “e0ac” to “e9ac”.</p>

<p>The software you must develop is to infer the original message from the final message, given the order of the messengers. For example, if the order of the messengers is A→J→M→P and the message given to the King is “aB23d”, what is the original message? According to the features of the messengers’ mistakes, the sequence leading to the final message is</p>

<p>\[32Bad\xrightarrow [ A ]{ &nbsp;} daB23\xrightarrow [ J ]{ &nbsp;} aB23d \xrightarrow [ M ]{ &nbsp;} aB12d\xrightarrow [ P ]{ &nbsp;} aB23d\]</p>

<p>As a result, the original message should be “32Bad”.</p>



## 입력


<p>The input format is as follows.</p>

<pre>n
The order of messengers
The message given to the King
...
The order of messengers
The message given to the King
</pre>

<p>The first line of the input contains a positive integer n, which denotes the number of data sets. Each data set is a pair of the order of messengers and the message given to the King. The number of messengers relaying a message is between 1 and 6 inclusive. The same person may not appear more than once in the order of messengers. The length of a message is between 1 and 25 inclusive.</p>



## 출력


<p>The inferred messages are printed each on a separate line.</p>



## 소스코드

[소스코드 보기](Main.java)