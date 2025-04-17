# 26497번: Park - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26497)

<p>You like looking at trees. A park has many trees. Therefore, you spend most of your waking hours at the park. You have an acute vision problem that severely limits your ability to look at these trees. The park has several paths that you can walk on. Each path is described by an infinite-length horizontal or vertical line in the 2D plane. No trees lie on a path. You want to know how many trees are visible in the park. Because of your vision problem, a tree is visible only if you can view it by standing on some path while facing in a direction perpendicular to that path. Of course all trees are equally wide, so if there is a second tree between the first tree and where you are currently standing, then you can’t see the first tree. Given location of all the trees and all the paths, determine how many trees you can view in the park.</p>

## 입력

<p>The first line in the data file is an integer that represents the number of data sets to follow. Each data set contains several lines. The first line contains two integers n and m, the number of trees and number of paths. The next n lines contains two integers x and y, which are the coordinates of the trees. The following m lines contains a line equation of the form x=a or y=a.</p>

## 출력

<p>Print the number of trees you can view.</p>

## 소스코드

[소스코드 보기](Park.cpp)