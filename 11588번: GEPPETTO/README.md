# 11588번: GEPPETTO - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/11588)


<p>Everyone’s favorite character and puppet-maker Geppetto has opened a new pizza place, the best in town. Geppetto is trying to make the best pizza possible, but at the same time he doesn’t want to have a small selection of pizzas.</p>

<p>He makes his pizzas out of N ingredients marked with numbers from 1 to N. All that would be simple if he could mix any ingredient with every ingredient on the pizza, but unfortunately, that is not the case. Sometimes some ingredients cannot mix and that creates additional complications for our pizza master.</p>

<p>There are M pairs of ingredients that cannot be on the same pizza at the same time. Given these restrictions, Geppetto wants to know how many different pizzas he can make. Help him answer this question. Two pizzas are considered different if there is an ingredient of index i that is on one pizza, but not on the other.</p>



## 입력


<p>The first line of input contains two integers N and M (1 ≤ N ≤ 20, 1 ≤ M ≤ 400). Each of the following M lines contains two different numbers a i b, they represent the prohibition of mixing ingredients marked with a and b on the pizza. (1 ≤ a, b ≤ N). All pairs of ingredients are not necessarily distinct, some pair could occur multiple times.</p>



## 출력


<p>The first and only line of output must contain the number of different pizzas given the restrictions in the task.</p>



## 소스코드

[소스코드 보기](GEPPETTO.cpp)