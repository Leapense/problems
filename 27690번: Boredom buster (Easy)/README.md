# 27690번: Boredom buster (Easy) - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/27690)


<p>Gillian is normally a very lively child. Most of the time she plays with her friends and tries to indulge in some mischief. But today is diﬀerent, today Gillian woke up with the ﬂu so she has to stay in bed – still and bored. To entertain her, her brother came up with the following game.</p>

<p>When Gillian has an integer x greater than 1, she can split it up into two positive integers y and z such that x = y + z. After performing this operation, her brother gives her y ⋅ z hazelnuts. However, not all pairs of y,z are valid – there are some rules Gillian must comply with. These rules diﬀer between the easy and hard subproblems; they are listed in the problem speciﬁcation section.</p>

<p>Numbers that are obtained as a result of this operation can be also split up. At the beginning of the game, Gillian starts with a single integer n. She performs a series of operations described above until she is left with n copies of number 1. What is the maximum number of hazelnuts she can win if she chooses her moves wisely?</p>

<p>For any x &gt; 1 there is exactly one valid way of splitting:</p>

<ul>
<li>if x is divisible by 3, then y = x∕3 and z = 2x∕3;</li>
<li>if x is divisible by 2 (but not by 3), then y = z = x∕2;</li>
<li>otherwise, y = 1 and z = x − 1.</li>
</ul>



## 입력


<p>The ﬁrst line of the input ﬁle contains an integer t ≤ 1000 specifying the number of test cases. Each test case is preceded by a blank line.</p>

<p>Each test case contains a single line with Gillian’s initial integer n &gt; 1. You may assume that n ≤ 10<sup>6</sup>.</p>



## 출력


<p>For each test case, output a single line with the maximum number of hazelnuts.</p>



## 소스코드

[소스코드 보기](Boredom%20buster%20(Easy).py)