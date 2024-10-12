# 18810번: Amazing Sushi - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18810)


<p>Mary and Marty were playing with their Marvelous Marble Machine and have become hungry. So, they decided to order some sushi. There are several types of sushi. The sushi platter comes with pieces of various types (possibly many of each type).</p>

<p>Both Mary and Marty know a range of the total number of pieces of sushi they can eat. They would like to know if there is a way to distribute their sushi such that neither of them eats too little or too much sushi and no sushi goes uneaten. To be fair, Mary and Marty each want to eat half of the pieces of each type. If there is an odd number of pieces for a given type, either one of them can eat the extra piece.</p>

<p>Does there exist a way for Mary and Marty to properly distribute their sushi?</p>



## 입력


<p>The first line contains a single integer n (1 ≤ n ≤ 100), which is the number of types of sushi.</p>

<p>The second line describes the number of pieces of sushi Mary can eat. This line contains two integers, x1 (0 ≤ x1 ≤ 100 000) and y1 (x1 ≤ y1 ≤ 100 000). Mary must eat at least x1 pieces and at most y1 pieces.</p>

<p>The third line describes the number of pieces of sushi Marty can eat. This line contains two integers, x2 (0 ≤ x2 ≤ 100 000) and y2 (x2 ≤ y2 ≤ 100 000). Marty must eat at least x2 pieces and at most y2 pieces.</p>

<p>The next n lines describe the n different types of sushi in Mary and Marty’s platter. Each line contains a single integer m (1 ≤ m ≤ 1 000), which is the number of pieces of sushi of this type.</p>



## 출력


<p>If there exists a way for Mary and Marty to properly distribute their sushi, display Yes. Otherwise, display No.</p>



## 소스코드

[소스코드 보기](Amazing%20Sushi.cpp)