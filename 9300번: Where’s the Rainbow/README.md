# 9300번: Where’s the Rainbow - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9300)


<p>After a long day of working on HSPC problems, you see a rainbow in the sky and want to figure out how far you have to walk to get your pot of gold. You are given a 2D plane and a semi-circle (rainbow) of height h placed with the center somewhere along the x-axis. You are also given an angle of inclination to view the top of the rainbow from the origin. Find how far away the closest point on the rainbow is to you by using the picture below to solve for d, the distance between you and the closest point on the rainbow. You can ignore the height/width of the person; treat them as a point.</p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/9300/1.png" style="height:253px; width:641px"></p>



## 입력


<p>The first line of input is the number of test cases that follow. Each successive line represents a single test case, and will be composed of two floating point numbers, separated by a single space. The first value is h (1 ≤ h ≤ 10<sup>5</sup>), the height of the rainbow at its highest point. The second is the angle of inclination θ (0 &lt; θ &lt; 90).&nbsp;These real numbers will consist of decimal digits and at most one decimal point.</p>



## 출력


<p>For each case output the line “Case x:” where x is the case number, on a single line, followed by d, the distance from you to the rainbow,&nbsp;with an absolute or relative error of at most 10<sup>−6</sup>.</p>

<p>If you and the rainbow are infinitely far way from each other, print "Infinity".</p>



## 소스코드

[소스코드 보기](Where’s%20the%20Rainbow.cpp)