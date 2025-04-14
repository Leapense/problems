# 25980번: Abbreviated Aliases - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25980)

<p>You are the owner of a large successful internet site with lots of users. All these users have chosen an alias of exactly $l$ characters for logging into the site. Recently, you noticed that you started running into disk space issues: storing all these aliases takes up a lot of data!</p>

<p>You do not have enough money to buy extra storage, so you are looking for ways to reduce the storage space needed. A friend gives you the following compression idea that might help: instead of storing the full alias for each user, you might get away with only storing a prefix of that alias, as long as no other alias has the same prefix. For example, if you just have the aliases <code>james</code> and <code>jacob</code>, you can store only <code>jam</code> and <code>jac</code> and still be able to identify them both.</p>

<p>This idea sounds quite interesting to you, and you are looking forward to finally having more space available on your disk again. You would like to find out how much space you need to store all aliases using this compression technique.</p>

## 입력

<p>The input consists of:</p>

<ul>
<li>One line with two integers $n$ and $l$ ($2 \le n \le 10^4$, $1 \le l \le 10^3$), the number of aliases and the length of each alias.</li>
<li>$n$ lines, each with an alias: a string consisting of exactly $l$ English lowercase characters (<code>a-z</code>). Each alias is unique.</li>
</ul>

## 출력

<p>Output the total number of characters you still need to store if you apply this compression technique.</p>

## 소스코드

[소스코드 보기](Abbreviated%20Aliases.cpp)