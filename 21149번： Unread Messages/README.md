# 21149번: Unread Messages - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21149)


<p>There is a group of people in an internet email message group. Messages are sent to all members of the group, and no two messages are sent at the same time.</p>

<p>Immediately before a person sends a message, they read all their unread messages up to that point. Each sender also reads their own message the moment it is sent. Therefore, a person’s unread messages are exactly the set of messages sent after that person’s last message.</p>

<p>Each time a message is sent, compute the total number of unread messages over all group members.</p>



## 입력


<p>The first line of input contains two integers $n$ ($1 \le n \le 10^9$) and $m$ ($1 \le m \le 1,000$), where $n$ is the number of people in the group, and $m$ is the number of messages sent. The group members are identified by number, $1$ through $n$.</p>

<p>Each of the next $m$ lines contains a single integer $s$ ($1 \le s \le n$), which is the sender of that message. These lines are in chronological order.</p>



## 출력


<p>Output $m$ lines, each with a single integer, indicating the total number of unread messages over all group members, immediately after each message is sent.</p>



## 소스코드

[소스코드 보기](Unread%20Messages.py)