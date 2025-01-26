# 24815번: Good Messages - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24815)


<p>Boris works at a secret communication station for the government training new employees on how to encode messages. Messages at this station are encoded with a rotation ("Caesar") cipher that replaces each letter with one at a set offset in the alphabet, e.g., for offset $2$ an '<code>a</code>' is replaced by a '<code>c</code>' and '<code>y</code>' is replaced by '<code>a</code>'. In order to encode a message, this cipher may be applied more than once. Each such application counts as a step in the encoding process. Boris teaches the new employees to encode messages by demonstrating each step of the encoding individually. However, Boris does not does not like seeing messages that contain at least half as many vowels as consonants after applying an encoding step. (Boris considers '<code>a</code>', '<code>e</code>', '<code>i</code>', '<code>o</code>', '<code>u</code>', and '<code>y</code>' as vowels). He grows annoyed and more and more unhappy with each step where this situation occurs.</p>

<p>Your job is to encode a given message and determine whether Boris will see fewer steps that annoy him than ones that don't. &nbsp;Since Boris wants to be happy in his job he will give a message that annoys him too much to a colleague.</p>



## 입력


<p>The input consists of a single test case. The first line of the input contains a single integer $O$ ($1 \le O \le 25$) that represent the offset used for the rotation cipher. The second line contains the message to encode, which consists entirely of lowercase English characters. The length of the message is between $1$ and $80$ characters. The third line will contain an integer $N$ ($1 \le N \le 26$), the number of times the cipher must be applied.</p>



## 출력


<p>Output '<code>Boris</code>' if strictly more steps sound good than bad, and '<code>Colleague</code>' otherwise.</p>



## 소스코드

[소스코드 보기](Good%20Messages.py)