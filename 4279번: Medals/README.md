# 4279번: Medals - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/4279)


<p>At the Olympic Games, countries are ranked according to the number of medals their athletes won. However, there is more than one possible way of ranking countries by their medals. In Europe, for example, countries are first ranked by the number of gold medals their athletes won. Ties are broken by looking at silver medals, and then at bronze medals. In Canada, however, because Canadian athletes do not win very many gold medals, countries are ranked by the overall number of medals won, giving the same weight to gold, silver, and bronze medals.&nbsp;</p>

<p>In general, a ranking scheme can be thought of as a vector of positive weights. This vector is multiplied with the vector of medals won by each country, and the scalar product of the two vectors defines the score of the respective country, which is then used to produce the ranking. In this general scheme, the European ranking technique corresponds to the weight vector (10<sup>20</sup>, 10<sup>10</sup>, 1), whereas the Canadian method corresponds to the vector (1, 1, 1).&nbsp;</p>

<p>In this problem, you will only need to consider weight vectors of the form (1/n<sup>j</sup>, 1/n<sup>k</sup>, 1/n<sup>l</sup>), where n is the total number of medals won by all athletes in the Olympic Games, and j, k, and l are integers.&nbsp;</p>

<p>Given a list of countries and the number of gold, silver, and bronze medals won by each country, print the line</p>

<pre>Canada wins!</pre>

<p>if there is a weight vector of the above form such that Canada ranks first according to the ranking scheme defined by that vector. Print the line</p>

<pre>Canada cannot win.</pre>

<p>if no such vector exists.&nbsp;</p>



## 입력


<p>The input contains multiple test cases. Each test case starts with an integer c, the number of countries to follow. Each of the following c lines contains the name of a country and three integers g, s, and b – the number of gold, silver, and bronze medals won by the country. The last test case has c = 0 and must not be processed. It is guaranteed that each test case contains at most 20 different countries and that the total number of medals smaller than 100. Country names do not contain whitespace characters.&nbsp;</p>



## 출력





## 소스코드

[소스코드 보기](Medals.cpp)