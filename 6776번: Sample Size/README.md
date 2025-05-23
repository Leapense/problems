# 6776번: Sample Size - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6776)


<p>Someone whose name I don’t want to remember was reading an article in the newspaper that mentioned the results of a poll. Upon seeing that the percentages that appeared in the article were all 25%, 50% and 75%, they thought that maybe the poll only included 4 people, and was then not very good.</p>

<p>In this problem, your task is to come up with a program that would make a similar analysis. In particular, given the percentages that appear in a newspaper article, it is your task to determine the minimum number of people that must have been interviewed in order for those percentages to be possible, assuming that percentages are rounded to the closest integer, with .5 rounded up (so, 1 of 3 people corresponds to 33%, 2 of 3 people corresponds to 67%, and 155 of 1000 people corresponds to 16%).</p>



## 입력


<p>The first line of the input file will contain an integer M between 1 and 100000 (inclusive). This represents the number of percentages that appear in the newspaper article you are analyzing.</p>

<p>M lines will follow, each of them containing an integer percentage P, 0 ≤ P ≤ 100.</p>



## 출력


<p>An integer N ≥ 1, the minimum number of people that must be interviewed for all of the percentages in the input to correspond to a fraction of those people.</p>



## 소스코드

[소스코드 보기](Sample%20Size.cpp)