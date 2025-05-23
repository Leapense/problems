# 9956번: Reversing Words - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9956)


<p>“Oh no, not another reversing problem! We did those in Programming 101, years ago”, I hear you cry. Well yes, but this problem is just a little different, in that you have to reverse individual words, not entire sentences. Furthermore, only the letters are to be reversed — spaces, punctuation and case are unaffected.</p>

<p>For this problem a word is defined to be a sequence of characters containing at least two letters and delimited by whitespace. The letters in the word must be written in reverse order (so 'the' becomes 'eht'), but the other characters in the word remain in their original sequence. Furthermore, if a character in the original word is upper-case, the letter in the same position in the new word must also be uppercase, thus 'Smith-Jones' becomes 'Senoj-Htims'. The position of the word in the line must be unaltered, and the position of every non-letter must also be unaltered (so double blanks remain as double blanks).</p>



## 입력


<p>Input will be a series of lines, terminated by a line consisting of a single '#'. No line will have more than 80 characters.</p>



## 출력


<p>Output will consist of a series of lines, one for each line in the input, with the letters in each word reversed as described above.</p>



## 소스코드

[소스코드 보기](Reversing%20Words.cpp)