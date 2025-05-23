# 15427번: Greeting Card - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15427)


<p>Quido plans to send a New Year greeting to his friend Hugo. He has recently acquired access to an advanced high-precision plotter and he is planning to print the greeting card on the plotter.</p>

<p>Here’s how the plotter operates. In step one, the plotter plots an intricate pattern of n dots on the paper. In step two, the picture in the greeting emerges when the plotter connects by a straight segment each pair of dots that are exactly 2 018 length units apart.</p>

<p>The plotter uses a special holographic ink, which has a limited supply. Quido wants to know the number of all plotted segments in the picture to be sure that there is enough ink to complete the job.</p>



## 입력


<p>The first line of input contains a positive integer n specifying the number of plotted points. The following n lines each contain a pair of space-separated integer coordinates indicating one plotted point. Each coordinate is non-negative and less than 2<sup>31</sup>. There are at most 10<sup>5</sup> points, all of them are distinct.</p>

<p>In this problem, all coordinates and distances are expressed in plotter length units, the length of the unit in the x-direction and in the y-direction is the same.</p>



## 출력


<p>The output contains a single integer equal to the number of pairs of points which are exactly 2 018 length units apart.</p>



## 소스코드

[소스코드 보기](Greeting%20Card.cpp)