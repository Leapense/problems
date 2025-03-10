# 6011번: Selfish Grazing - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/6011)


<p>Each of Farmer John's N (1 &lt;= N &lt;= 50,000) cows likes to graze in a certain part of the pasture, which can be thought of as a large one-dimeensional number line. Cow i's favorite grazing range starts at location S_i and ends at location E_i (1 &lt;= S_i &lt; E_i; S_i &lt; E_i &lt;= 100,000,000).</p>

<p>Most folks know the cows are quite selfish; no cow wants to share any of its grazing area with another. Thus, two cows i and j can only graze at the same time if either S_i &gt;= E_j or E_i &lt;= S_j. FJ would like to know the maximum number of cows that can graze at the same time for a given set of cows and their preferences.</p>

<p>Consider a set of 5 cows with ranges shown below:</p>

<pre>  ... 1    2    3    4    5    6    7    8    9   10   11   12   13 ...
  ... |----|----|----|----|----|----|----|----|----|----|----|----|----
Cow 1:      &lt;===:===&gt;          :              :              :
Cow 2: &lt;========:==============:==============:=============&gt;:
Cow 3:          :     &lt;====&gt;   :              :              :
Cow 4:          :              :     &lt;========:===&gt;          :
Cow 5:          :              :     &lt;==&gt;     :              :</pre>

<p>These ranges represent (2, 4), (1, 12), (4, 5), (7, 10), and (7, 8), respectively.</p>

<p>For a solution, the first, third, and fourth (or fifth) cows can all graze at the same time. If the second cow grazed, no other cows could graze. Also, the fourth and fifth cows cannot graze together, so it is impossible for four or more cows to graze.</p>



## 입력


<ul>
<li>Line 1: A &nbsp;single integer: N</li>
<li>Lines 2..N+1: Line i+1 contains the two space-separated integers: S_i and E_i</li>
</ul>

<p>&nbsp;</p>



## 출력


<ul>
<li>Line 1: A single integer representing the maximum number of cows that can graze at once.</li>
</ul>

<p>&nbsp;</p>



## 소스코드

[소스코드 보기](Main.java)