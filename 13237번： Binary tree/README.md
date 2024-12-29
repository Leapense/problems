# 13237번: Binary tree - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/13237)


<p>A binary tree is a mathematical structure made of nodes where each node can have up to two children nodes. One child node will be called left child and the other right child. ch If node B is a child node of A, then we say that A is the parent node of B. In a binary tree, there is only one node that has no parent and we call this node the root of the tree. We call the height of a node &nbsp;N to the distance in nodes between the node N and the root node. The root node’s height is 0.</p>

<p>In this problem, you’ll have to compute the heights of every node of the tree. Each node will be identified by an integer from 1 to the number of nodes n.</p>

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13237/1.png" style="float:right; height:169px; width:250px">Check the following tree:</p>

<p>The root of the tree is 1. The left child of 1 is 2, the right child of 1 is 3.</p>

<p>The nodes 4, 5, 6 and 7 do not have any child.</p>

<p>The heights of the nodes are:</p>

<ul>
<li>Node 1: 0</li>
<li>Nodes 2 and 3: 1</li>
<li>Nodes 4, 5, 6 and 7: 2</li>
</ul>

<p><img alt="" src="https://onlinejudgeimages.s3-ap-northeast-1.amazonaws.com/problem/13237/2.png" style="float:right; height:250px; width:228px">The following tree is a bit different:</p>

<p>Node 1 is still the root and has 2 and 3 as left and right children but 3 only have right child. On the contrary, node 4 only has left child (5).</p>

<p>The heights:</p>

<ul>
<li>Node 1: 0</li>
<li>Nodes 2 and 3: 1</li>
<li>Node 4: 2</li>
<li>Node 5: 3</li>
</ul>



## 입력


<p>The first line of the input will contain the number of nodes n. (1 ≤ n ≤ 20)</p>

<p>The following n lines will contain one integer each representing the parent of a node. That is, the second line of the input will contain the parent of node 1, the third line the parent of node 2, etc.</p>

<p>The root node will be identified by -1. Remember that node 1 won’t always be the root node.</p>



## 출력


<p>Print n lines. The first line should be the height of node 1, the second should be the height of node 2, and so on.</p>



## 소스코드

[소스코드 보기](Binary%20tree.cpp)