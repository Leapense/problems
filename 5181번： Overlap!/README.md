# 5181번: Overlap! - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/5181)


<p>One problem that seems to crop up fairly frequently in finals week is that students are supposed to be taking multiple final exams at the same time. Now, for some students, this may actually be feasible: they turn in their exams for the first class an hour early, and use the hour to take the other exam. However, for the rest of us ...</p>

<p>Now, this problem could be easily detected early, and automatically. The default times for each course are posted well in advance, and the courses a student is enrolled in are known early as well. So that we can collect statistics about overlaps in the future, you get to write a little tool that finds out just how many students have overlapping course finals.</p>



## 입력


<p>The first line contains a number K ≥ 1, which is the number of input data sets in the file. This is followed by K data sets of the following form:</p>

<p>The first line of a data set contains two numbers m,n between 1 and 1000. m is the number of courses offered, and n the number of students.</p>

<p>This is followed by m lines, each giving the name of a course, and the day and time of the final. The name of each course is a string of 4 upper-case characters (such as “CSCI”) followed by three digits (such as “402”). The day is denoted by “M”, “T”, “W”, “TH”, or “F”, in uppercase. The duration of the final is given in the format “hh:mm-hh:mm”, the starting and ending times. The hour is given between 00 and 23, the minute between 00 and 59. Each final exam will finish on the same day it starts. These strings will be separated by a single space each.</p>

<p>Next are n lines, each describing one student. Since we only care about statistics, not about names, each student is simply described by the list of courses he/she is taking. Each list is on one line, consisting of 1–10 of the course identifiers described above, separated by a single space each.</p>



## 출력


<p>For each data set, first output “Data Set x:” on a line by itself, where x is its number. Then, output the total number of students who have overlap between two or more of their final exams. If one exam ends at the exact time that another starts, that does not count as overlap.</p>



## 소스코드

[소스코드 보기](Main.java)