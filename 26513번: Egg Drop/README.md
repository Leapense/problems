# 26513번: Egg Drop - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26513)


<p>There is a classic riddle where you are given two eggs and a k-floor building and you want to know the highest floor from which you can drop the egg and not have it break.</p>

<p>It turns out that you have stumbled upon some logs detailing someone trying this experiment! The logs contain a series of floor numbers as well as the results of dropping the egg on those floors. You need to compute two quantities -- the lowest floor that you can drop the egg from where the egg could break, and the highest floor that you can drop the egg from where the egg might not break.</p>

<p>You know that the egg will not break if dropped from floor 1, and will break if dropped from floor k. You also know that the results of the experiment are consistent, so if an egg did not break from floor x, it will not break on any lower floors, and if an egg did break from floor y, it will break on all higher floors.</p>



## 입력


<p>The input is comprised of data sets. Each set starts with a line that contains two space-separated integers n and k (1 ≤ n ≤100, 3 ≤ k ≤100), the number of egg drops and the number of floors of the building, respectively. The next n lines contain a floor number and the result of the egg drop, separated by a single space. The floor number will be between 1 and k, and the result will be either SAFE or BROKEN. The end of input is signaled with two zeros on the last line.</p>



## 출력


<p>For each data set print, on a single line, two integers separated by a single space. The first integer should be the number of the lowest floor from which you can drop the egg and it could break and still be consistent with the results. The second integer should be the number of the highest floor from which you can drop the egg and it might not break.</p>



## 소스코드

[소스코드 보기](Egg%20Drop.py)