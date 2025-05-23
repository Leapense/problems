# 17882번: Tired Terry - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/17882)


<p>Terry is feeling tired and he suspects it is because of a lack of sleep. He created a device that records his sleeping pattern over a period of time measured in seconds.</p>

<p>Assuming that the recorded sleeping pattern keeps repeating, help Terry by letting him know how often he is tired during each of the repeating time periods.</p>

<p>More precisely, for integers p and d, we say that Terry is tired at second i if from second i − p + 1 to second i (inclusive) he has slept for less than d seconds.</p>



## 입력


<p>The first line of input contains three integers n (1 ≤ n ≤ 86 400), the length of Terry’s sleep pattern, p (1 ≤ p ≤ N), and D (1 ≤ d ≤ p) as described above.</p>

<p>The second line of input contains a single string of length n which describes the period of time that is recorded. The i<sup>th</sup> such character is a W if Terry is awake at the i<sup>th</sup> second, or is a Z if Terry is asleep at the i<sup>th</sup> second.</p>



## 출력


<p>Display a single integer which represents the number of seconds that Terry is tired during each of the repeating time periods.</p>



## 소스코드

[소스코드 보기](Tired%20Terry.cpp)