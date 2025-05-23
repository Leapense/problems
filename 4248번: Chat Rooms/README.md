# 4248번: Chat Rooms - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4248)


<p>Suppose there are a number of good users using an Internet chat room, which is a shared text chat space. Now there are some bad guys in the Internet who would come to this room and would have no respect or interest in the topic of discussion in the group. They would start typing strings of garbage characters, start unsolicited advertisements of certain URLs or businesses, or paste same string again and again just to disturb others in the room.&nbsp;</p>

<p>When I asked about this problem to Prof Banku (naturally not as smart as Prof Shanku) he suggested the following scheme. Let us define consonants to be all letters in a-z and A-Z except a, e, i, o, u, y, A, E, I, O, U and Y.&nbsp;</p>

<p>A user should be able to send a line to the chat room unless&nbsp;</p>

<ul>
<li>the line has more than 5 consecutive consonants, or&nbsp;</li>
<li>the line contains at least one word which has more than 4 consecutive consonants and the user sent more than 2 such lines in last 10 lines sent, or&nbsp;</li>
<li>the user sent the same line more than once in last 10 sentences sent.&nbsp;</li>
</ul>



## 입력


<p>Input consists of several lines. The first line contains an integer n, which is the number of lines in the shared text space. Then follow n lines each consisting of not more than 255 ASCII characters.</p>

<p>&nbsp;</p>



## 출력


<p>For each line of input print y if the line is acceptable according to the criteria set above and n otherwise in separate lines. See the sample output for example.</p>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)