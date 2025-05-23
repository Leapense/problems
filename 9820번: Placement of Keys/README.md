# 9820번: Placement of Keys - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9820)


<p>Assume that there are n (3 ≤ n ≤&nbsp;200) boxes identified by A<sub>1</sub>, A<sub>2</sub>,..., A<sub>n</sub>, and each box A<sub>i</sub> is configured a lock which is different from the others. Now put n keys to the n locks into the n boxes, each box can only hold a key. After locking all the boxes, unclench the boxes named A<sub>1</sub>, A<sub>2</sub> and fetch out the keys in them to unlock the locked boxes. If the two keys can open some box, fetch out the key in the box to unlock other locked boxes again. If we can open all the boxes finally, we call the placement of the n keys good placement. How many are there different good placements of the n keys?</p>



## 입력


<p>The input file, ending with -1, contains several data, each of which holds a line.</p>



## 출력


<p>According to every input datum, compute the number of different good placements. Each output data hold two lines, the first line is held by the input datum, followed by a colon, which follows an equal mark before which is an N; the second is held by the number of different good placement of the n keys.</p>



## 소스코드

[소스코드 보기](Placement%20of%20Keys.cpp)