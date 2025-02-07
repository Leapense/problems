# 30571번: Naming Wine Bottles - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30571)


<p>Wine is a sophisticated business. Bottling alone encompasses the art of label design, the physics of vacuum sealing, the craft of glassforming, and the calculus of volumetric shapes.</p>

<p>Today we will deal with literature: every size of wine bottle has a name. You may know that a “Standard” bottle holds 0.75L. Did you also know that a 15L bottle is a “Nebuchadnezzar”, and a 12L is a mighty “Balthazar”?</p>

<p>Usually wine bottle sizes come in multiples of 1.5L. You have some other bottles in non-standard sizes and you will need to create impressive names for them as well. Note that any two bottles of the same size must have consistent names.</p>



## 입력


<ul>
<li>On the first line, the number of bottles $n$ ($1 \le n \le 10\,000$)</li>
<li>On each of the following $n$ lines, the volume of a bottle $v$ ($0.0 \le v_i \le 10^4$) with up to $10$ digits after the decimal point, followed by an uppercase letter "L"</li>
</ul>



## 출력


<p>For each given line, output one lower-case word, with Latin letters only, giving a name for this size of bottle.</p>



## 소스코드

[소스코드 보기](Main.java)