# 10465번: Rolling Encryption - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/10465)


<p><img alt="" src="https://www.acmicpc.net/upload/images2/snowball.jpg" style="float:right; height:139px; width:300px">You have a sequence of lowercase characters that you want to encrypt.</p>

<p>The first <em>k</em> characters will be encoded as plain-text. All characters after the first <em>k</em> characters will be shifted by the most frequently occuring character that appeared in the previous <em>k</em> characters, with ties broken by the character which occurs first in the alphabet. By "shifted by", we mean that if <code>c</code> was the most frequently occuring character, the character would be shifted ahead by 3 positions (since <code>c</code> is the third letter of the alphabet), modulo 26 (e.g., <code>b</code> becomes <code>e</code>, and <code>z</code> becomes <code>c</code>).</p>



## 입력


<p>On the first line of input contains <em>k</em> (1 ≤ <em>k</em> ≤ 10 000). The next line contains <em>c</em> characters (1 ≤ <em>c</em> ≤ 100 000).</p>



## 출력


<p>One line, containing the encrypted version of the <em>c</em> characters from the input.</p>



## 소스코드

[소스코드 보기](Rolling%20Encryption.cpp)