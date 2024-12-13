# 9715번: Surface Area - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9715)


<p>The solid in the picture below is made up of 1x1x1 cubes in a 3D grid. In this problem, we'll limit ourselves to solids that are made up of columns rooted on the ground (a column consists of one or several 1x1x1 cubes stacked on top of each other). Such solids can be described as a matrix of digits, where each digit corresponds to the height of a column in the 2D grid that makes up the ground. A zero means there is no column at all in that position.</p>

<p><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/9715/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-10-04%20%EC%98%A4%ED%9B%84%204.03.33.png" style="height:241px; width:190px"></p>

<p>The corresponding matrix for the above solid will be  </p>

<pre>4231
2101
0001</pre>

<p>The volume of such a solid is simple enough to calculate, but what we're interested here in the total surface area including the floor (that is, the number of 1x1 "squares" non hidden on the outer surface). You are given the information of the solid as a matrix. Your task is to compute the surface area of the given solid. You can assume that the solid is always connected, i.e the columns will be attached to each other in the four cardinal directions.</p>



## 입력


<p>First line of the input contains T, the number of test cases.  Each test case starts with a line containing R and C denoting the number of rows and columns of the solid. Each of the next R lines contains C digits. Each digits are between 0 to 9 inclusive. R and C will be between 1 and 50 inclusive.  </p>



## 출력


<p>For each test case, output the total surface area of the given solid, including the floor area.</p>



## 소스코드

[소스코드 보기](Surface%20Area.cpp)