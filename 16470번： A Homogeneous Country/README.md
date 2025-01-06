# 16470번: A Homogeneous Country - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16470)


<p>Many Westerners think Korea is a mere Eastern country which hangs like a grapefruit next to China. However, Koreans have kept their unique ethnicity, struggling all the time not to be "a shrimp among whales"; Chinese to the west, Japanese to the east, "barbarian" tribes, and expanding Russia to the north. Bruce Cumings argued that a vast majority of Koreans look through the lens of race, thinking they have some essential quality making them and only them real Koreans, tracing a unique, homogeneous bloodline back some five thousand years, a story called Tan-gun mythology; 'Koreans do this, Koreans do that' in a shorthand. After a fratricidal war, it was divided into North and South Korea, creating Demilitarized Zone. South Korea had no friend in the region and became a de facto island. During the Cold War, Communist countries supported its enemy, North Korea, and Japan was the last candidate because of their colonial history. Its extremely low ethnic diversity(158<sup>th</sup> out of 159 countries; North Korea ranked 159<sup>th</sup>) and cultural diversity(152<sup>nd</sup>)&nbsp;is understandable given its experience of occupation and war.</p>

<p>Though the homogeneity of South Korea played a crucial role in the miracle of its economic development, it has also been a growing concern. A certain amount of diversity is necessary to encourage to understand different perspectives within the society and dispel negative stereotypes and personal biases about different groups. Learning about others helps to recognize and respect minorities, which we all are in some categories. Better understanding leads to the facilitation of collaboration and cooperation in the workplace.</p>

<p>The lack of other diversities left solely one inevitable diversity—gender—and called forth the recent fierce conflict between two traditional genders in South Korea, where only men are subject to two years of the savage conscription and its aftermath and women struggle with deeply imbued Confucianism, 37% of wage gap, and the paucity of sister politicians. Another recent case, Yemeni refugees, reveals a deeper nuance. In spite of the prevailing grievance over asylum seekers around the world, a polling estimates that between 49% and 56% of the general Korean population oppose granting asylum to the Yemeni refugees. But in a surprising result, the opposition among Korean youth in their 20s and 30s are considerably higher—70% and 60% respectively, despite the increased number of lawful foreigners in the country.<em><sup>&nbsp;</sup></em>The discord between men and women has contributed to avoiding marriage among youngsters, lowering overall fertility rate, a staggering figure of 0.96 in 2018. Now, for Koreans, embracing outsiders is not only a matter of morality or economic growth but also a matter of their survival in the future.</p>

<p>Jason, writing an essay about this issue, wants to exemplify the heterogeneity of the groups around him. You are asked to provide a program to calculate the heterogeneity of a group. He decided to use Gini-index. It is defined as, $1 - \sum_{j=1}^{n} p_j^2$, where $p_j$&nbsp;is the relative frequency of class $j$. Let's help him out.</p>



## 입력


<p>The class&nbsp;of an entity,&nbsp;$C_i$, is given line by line. For all $i$, $C_i$ consists only of alphabets and is case-sensitive,&nbsp;and its length is not longer than 10.</p>

<p>The number of entities, $m$,&nbsp;is not greater than 100,000.</p>



## 출력


<p>Print Gini-index of the given group. Its relative error or absolute error must be less than $10^{-6}$.</p>



## 소스코드

[소스코드 보기](Main.java)