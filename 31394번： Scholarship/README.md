# 31394번: Scholarship - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31394)


<p>At last the first term at the University came to its finish. Android Vasya has already passed all the exams and wants to know if he gets a scholarship. There is the following practice of giving scholarship to students at the University:</p>

<ul>
<li>if a student has got satisfactory marks, the scholarship is not given,</li>
<li>if a student has passed through the examination period with only excellent marks, he gets a personal scholarship,</li>
<li>if a student doesn't get a personal scholarship and his average mark is not less than $4.5$, he gets a high scholarship,</li>
<li>if a student gets neither high nor personal scholarship and doesn't have satisfactory marks, he gets a common scholarship.</li>
</ul>

<p>A satisfactory mark corresponds to value 3, a good mark corresponds to value 4, and an excellent mark corresponds to value 5. An average mark for a student is the average value of all the marks this student got in his exams.</p>

<p>Help Vasya find out which scholarship he gets.</p>



## 입력


<p>The first line contains an integer $n$ --- the number of exams ($1 \leq n \leq 10$). In the $i$-th of the next $n$ lines there is an integer $m_i$ --- value of Vasya's mark in $i$-th exam ($3 \leq m_i \leq 5$).</p>



## 출력


<p>If Vasya doesn't get any scholarship output <code>None</code>. If he gets a common scholarship output <code>Common</code>, if he gets a high scholarship output <code>High</code>, if he gets a personal one output <code>Named</code>.</p>



## 소스코드

[소스코드 보기](Scholarship.py)