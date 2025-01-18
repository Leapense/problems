# 20222번: Jam-packed - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20222)


<p>The fruit harvest has been good this year, which means that your jam-selling company, which produces the price-winning Berry Artisanal and Pure Compote, is shipping out jam left and right! A customer has recently placed a huge order of $n$ jars of jam. To ship these jars, you put them into boxes, each of which can hold up to $k$ jars.&nbsp;</p>

<p>As is always the case with fragile goods, the jars might break in the process of being delivered. You want to avoid the jars bouncing around in their boxes too much, as that significantly increases the chance that they break. To circumvent this, you want to avoid having boxes that are too empty: that would inevitably result in the uncontrolled bouncing around, and subsequently breaking, of the jars. In particular, you want the box with the least number of jars to be as full as possible. In order to estimate the risk you are taking with your precious jars, you would like to know: how many jars does this box contain?&nbsp;</p>



## 입력


<p>The input consists of:</p>

<ul>
<li>A line with two integers $n$ ($1\leq n\leq 10^{18}$), the number of jars that need to be packed, and $k$ ($1 \leq k \leq 10^{18}$), the number of jars a single box can hold.</li>
</ul>



## 출력


<p>Output the number of jars that the least filled box contains.</p>



## 소스코드

[소스코드 보기](Jam-packed.cpp)