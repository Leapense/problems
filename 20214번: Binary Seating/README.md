# 20214번: Binary Seating - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20214)


<p>By accident, two rooms (room $0$ and room $1$) got booked for the theoretical exam of the B++ Applied Programming Course and both were communicated to the students. Now students might go to either of the rooms, and as a student assistant your job is to supervise room $1$. Since you assisted all these students during the course, you know how much time each student will need to finish the exam. Already before the exam you are eager to go home, but you can only leave when all of the students in your examination room have finished. You assume that every student chooses one of the exam rooms with equal probability, independent of the other students. After how much time do you expect to be able to leave?</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>A line with an integer $n$ ($1 \leq n \leq 40$), the number of students.</li>
<li>A line with $n$ integers $t_1, \ldots, t_n$ ($1 \leq t_i \leq 1000$): $t_i$ is the time it takes for the $i$th student to finish the exam and leave.</li>
</ul>



## 출력


<p>Output the expected time before you can leave. Your answer should have an absolute or relative error of at most $10^{-6}$.</p>



## 소스코드

[소스코드 보기](Binary%20Seating.cpp)