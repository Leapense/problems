# 24933번: Quadratic Dissonance - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/24933)


<p>Oh no! Both you and your lab partner forgot to complete one part of the latest assignment and it is due in an hour!</p>

<p>The purpose of this lab assignment was to have you analyze some experimental data, find a quadratic function that best describes the data, and report the minimum value that can be taken by this quadratic.</p>

<p>Both you and your partner have tried this part on your own, in order to double-check your answers. Unfortunately, you both found different quadratic functions!</p>

<p>You don’t have time to repeat the experiment. To try and maximize your chances of reporting a value that is close to the minimum (i.e. to get partial credit), you decide to find a value&nbsp;$x$&nbsp;that minimizes the maximum of your two quadratic functions.</p>

<p>More precisely, your task is the following. Given two quadratic functions&nbsp;$f(x)=x^2+A⋅x+B$&nbsp;and&nbsp;$g(x)=x^2+C⋅x+D$&nbsp;(here&nbsp;$A,B,C,D$&nbsp;will be given values), you should find a value&nbsp;$x^∗$&nbsp;minimizing the maximum of these two functions. That is,&nbsp;$x^∗$&nbsp;should be chosen to minimize the function&nbsp;$h(x)=\max{\{f(x),g(x)\}}$.</p>



## 입력


<p>Input consists of a single line containing four integers $A,B,C,D$, each lying in the range&nbsp;$[-1000,1000]$.</p>



## 출력


<p>Display two values&nbsp;$x^∗,h(x^∗)$&nbsp;on a single line where&nbsp;$x^∗$&nbsp;is the point that minimizes the function&nbsp;$h(x)=\max{\{x^2+A⋅x+B,x^2+C⋅x+D\}}$.</p>

<p>Your answer will be accepted if both values are within an absolute or relative error of&nbsp;$10^{-4}$ of the correct answer.</p>



## 소스코드

[소스코드 보기](Quadratic%20Dissonance.py)