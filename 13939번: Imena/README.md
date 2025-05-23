# 13939번: Imena - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13939)


<p>Little Mirko likes to type and often gets bored during class, which is why his teacher assigned him a task.</p>

<p>Mirko must retype a book​ that contains N space-separated sentences. In this book, a sentence​ is an array of one or more space-separated words, where only the last word’s character is a punctuation mark ( '.', '?' or '!' ). The rest of the words do not contain punctuation marks.</p>

<p>Words are arrays of characters​, either lowercase or uppercase letters of the English alphabet, or digits or, exceptionally, a punctuation mark at the end of the last word in the sentence.</p>

<p>Although he likes typing sentences, Mirko doesn’t like typing names. A name​ is a word that starts with an uppercase letter of the English alphabet, whereas the rest of the characters are lowercase letters of the English alphabet, except the last character, which can be the punctuation mark. Before he decides to retype the whole thing, Mirko wants to know how many names there are in each sentence of the book​. Write a programme to help him!&nbsp;</p>



## 입력


<p>The first line of input contains the integer N (1 ≤ N ≤ 5), the number from the task.</p>

<p>The second line contains N sentences from the book. The total number of characters in the book will not exceed 1000.&nbsp;</p>



## 출력


<p>You must output N lines. The i th line contains the number of names in the i th sentence.&nbsp;</p>



## 소스코드

[소스코드 보기](Imena.py)