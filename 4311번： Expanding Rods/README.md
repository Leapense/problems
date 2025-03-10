# 4311번: Expanding Rods - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4311)


<p><img alt="" src="https://www.acmicpc.net/upload/images3/rods.jpg" style="float:right; height:209px; width:270px">When a thin rod of length L is heated n degrees, it expands to a new length L'=(1+n*C)*L, where C is the coefficient of heat expansion.</p>

<p>When a thin rod is mounted on two solid walls and then heated, it expands and takes the shape of a circular segment, the original rod being the chord of the segment.</p>

<p>Your task is to compute the distance by which the center of the rod is displaced.</p>



## 입력


<p>The input contains multiple lines. Each line of input contains three non-negative numbers: the initial lenth of the rod in millimeters, the temperature change in degrees and the coefficient of heat expansion of the material. Input data guarantee that no rod expands by more than one half of its original length. The last line of input contains three negative numbers and it should not be processed.</p>



## 출력


<p>For each line of input, output one line with the displacement of the center of the rod in millimeters with 3 digits of precision.</p>



## 소스코드

[소스코드 보기](Expanding%20Rods.cpp)