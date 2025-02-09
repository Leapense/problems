# 9951번: Word Extraction - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9951)


<p>I am trying to create a dictionary of all the words in common use by my students. To do this, I am planning to feed text from their work, discussion forum entries, and emails through a program that extracts the words.</p>

<p>To make it easy to check if a word has been seen before, I am formatting the text carefully. Firstly I put everything in lower case, then I strip out all punctuation leaving the words separated by single spaces. If the punctuation comes within a word (i.e. there is a letter on either side of it), it is removed. If a "word" consists only of digits, it is ignored. Finally, I sort the words into alphabetical order, removing duplicates.</p>



## 입력


<p>Input will consist of a number of lines, each line representing a piece of text to be analysed, and terminated by a single #. No line will contain more than 250 characters.</p>



## 출력


<p>Output will be the qualifying words extracted from the text, one per line, in alphabetical order within each set. Each set of words from a piece of text will be separated from the next set by a blank line.</p>



## 소스코드

[소스코드 보기](Word%20Extraction.cpp)