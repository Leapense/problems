# 3969번: My brother’s diary - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3969)


<p>Nowadays, people who want to communicate in a secure way use asymmetric encryption algorithms such as RSA. However, my older brother uses another, simpler encryption method for his diary entries. He uses a substitution cipher where each letter in the plaintext is substituted by another letter from the alphabet. The distance between the plaintext letter and the encrypted letter is fixed. If we would define this fixed distance d to 5, A would be replaced by F, B by G, C by H, ..., Y by D, Z by E.</p>

<p>With a fixed and known distance d the decryption would be somewhat simple. But my brother uses random distances for each of his diary entries. To decrypt his diary I have to guess the distance d for each entry. Thus, I use the well known phenomenon that the letter E is used more often in English words than other letters.</p>

<p>Can you write a program for me that calculates the distance d based on the fact that the most used letter in the encrypted text corresponds to the letter E in plaintext? Of course, I am interested in the decrypted text, too.</p>



## 입력


<p>The input consists of several test cases c that follow (1 ≤ c ≤ 100). Each test case is given in exactly one line containing one diary entry. Diary entries only use upper case letters (A-Z) and spaces. Each diary entry consists of at most 1 000 encrypted letters (including spaces).</p>



## 출력


<p>For each test case, print one line containing the smallest possible distance d (0 ≤ d ≤ 25) and the decrypted text. If the decryption is not possible because there are multiple distances conforming to the rules above, print “NOT POSSIBLE” instead. Spaces are not encrypted.</p>



## 소스코드

[소스코드 보기](My%20brother’s%20diary.py)