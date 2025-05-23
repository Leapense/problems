# 11370번: Spawn of Ungoliant - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11370)


<p>The spider children of Ungoliant are spreading through Mirkwood. Each of the giant spiders cannot move from the tree which it inhabits; however, each can lay eggs in the trees adjacent to it. Each egg will rapidly hatch and grow into another spider, who will then lay their own eggs.</p>

<p>Given a map of Mirkwood, indicating where spider-filled and spider-free trees are, determine how far the spider infestation will spread.</p>

<p>For this problem, adjacency is one of the four cardinal directions (north, south, east, and west); two trees connected via a diagonal are not considered adjacent.</p>



## 입력


<p>The first line of an input case is of the form W H, where W is the width of the map and H is the height. The next H lines contain strings of length W specifying the layout of Mirkwood. An S character represents a spider-infested tree, and an T character represents a spider-free tree. A . (period) signifies open space on the forest floor, where there is no tree.</p>

<p>The end of input is signified by two zero’s, which is a case that should not be processed.</p>



## 출력


<p>For each test case, print out the map of Mirkwood once the spiders have spread as far as possible. There should be no blank lines between maps.</p>



## 소스코드

[소스코드 보기](Main.java)