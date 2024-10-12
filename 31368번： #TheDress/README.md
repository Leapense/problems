# 31368번: #TheDress - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/31368)


<p>After landing on planet i1c5l people noticed that blue and black clothes are quite popular among the locals. Each aboriginal has at least one blue-and-black piece of clothing in their wardrobe. This makes no interest except one curious detail: the locals claimed that these colors weren’t blue and black but white and gold.</p>

<p>Thus a simple test was created to differ a human being from an alien. On one of the wedding parties people took a picture of the blue-and-black groom mother’s dress. This picture was shown to some respondents who were asked the color of the dress. If the answer contained &lt;&lt;blue&gt;&gt; and &lt;&lt;black&gt;&gt; then there was no doubt that the respondent was from the Earth. The answer containing &lt;&lt;white&gt;&gt; and &lt;&lt;gold&gt;&gt; pointed to the person of planet i1c5l origin. If the answer contained neither of word pairs then it was clear that the respondent was a creature from another planet.</p>

<p>You have the complete survey log from planet i1c5l. Your task is to determine the constitution of the planet’s population based on the survey.</p>



## 입력


<p>The first line contains single integer $N$ --- the number of respondents ($1 \le N \le 100$). The following $N$ lines contain the answers. No line is empty and no line is longer than 100 characters. The answer contains only lower-case Latin letters and spaces. It is guaranteed that no answer can contain &lt;&lt;blue&gt;&gt;, &lt;&lt;black&gt;&gt;, &lt;&lt;white&gt;&gt;, and &lt;&lt;gold&gt;&gt; simultaneously.</p>



## 출력


<p>Output three numbers that describe the planet’s population, each on separate line.</p>

<p>The first number --- percentage of earthlings in population.</p>

<p>The second number --- percentage of aboriginals in population.</p>

<p>The third number --- percentage of another planet creatures in population.</p>

<p>Output all numbers with $10^{-5}$ accuracy.</p>



## 소스코드

[소스코드 보기](#TheDress.py)