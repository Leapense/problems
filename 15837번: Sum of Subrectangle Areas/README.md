# 15837번: Sum of Subrectangle Areas - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/15837)


<p>The following code snippet calculates the sum of the areas of all the sub rectangular grid in a rectangular grid from (0,0) to (N,N). Find an efficient way to compute that.</p>

<pre>sum = 0
for r1 = 0 to N-1
  for c1 = 0 to N-1
    for r2 = r1+1 to N
      for c2 = r2+1 to N
        sum = sum + (r2-r1)*(c2-c1)
print(sum)</pre>



## 입력


<p>Input starts with T the number of test cases. Each test case consists of a single integer N.</p>



## 출력


<p>For each test output the sum (as computed above). Please note that even though N will fit into 64 bit integer, the sum may not be.</p>



## 소스코드

[소스코드 보기](Sum%20of%20Subrectangle%20Areas.cpp)