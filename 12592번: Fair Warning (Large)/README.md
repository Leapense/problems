# 12592번: Fair Warning (Large) - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/12592)


<p><em>On our planet, Jamcode IX, three Great Events occurred. They happened 26000, 11000 and 6000 slarboseconds ago. In 4000 slarboseconds, the amount of time since all of those events will be multiples of 5000 slarboseconds, the largest possible amount... and the apocalypse will come.</em></p>

<p>Luckily for you, you live on Jamcode X! The apocalypse came on Jamcode IX less than a year ago. But Jamcode X has a worrying prophecy: "After the moment of reckoning, on the first&nbsp;<em>optimum anniversary</em>&nbsp;of the&nbsp;<strong>N</strong>&nbsp;Great Events, the apocalypse will come. 64 bits will not save you. You have been warned."</p>

<p>The people of Jamcode X are very concerned by this prophecy. All of the Great Events have already happened, and their times have been measured to the nearest slarbosecond; but nobody knows when their&nbsp;<em>optimum anniversary</em>&nbsp;will occur. After studying the diary of a scientist from Jamcode IX, scientists working on the problem have come up with a theory:</p>

<p>The&nbsp;<em>moment of reckoning</em>&nbsp;is now, the moment you solve this problem. At some time&nbsp;<strong>y ≥ 0</strong>slarboseconds from now, the number of slarboseconds since each of the Great Events will be divisible by some maximum number&nbsp;<strong>T</strong>. If you can find the smallest value of&nbsp;<strong>y</strong>&nbsp;that gives this largest possible&nbsp;<strong>T</strong>, that will give you the&nbsp;<em>optimum anniversary</em>&nbsp;when the apocalypse will come.</p>

<p>On Jamcode IX, for example, there were 3 Great Events and they happened 26000, 11000 and 6000 slarboseconds before the moment of reckoning. 4000 slarboseconds later, the amount of time since each event was a multiple of T=5000 slarboseconds, and the apocalypse came.</p>

<p>Your job is to compute the amount of time until the apocalypse comes. But remember the prophecy: even though the people of Jamcode X have been solving problems for two years, and 64-bit integers have always been enough, they might not always be enough now or in the future.</p>



## 입력


<p>The first line of the input gives the number of test cases,&nbsp;<strong>C</strong>.&nbsp;&nbsp;<strong>C</strong>&nbsp;lines follow. Each starts with a single integer&nbsp;<strong>N</strong>, which is followed by a space and then&nbsp;<strong>N</strong>&nbsp;space-separated integers&nbsp;<strong>t<sub>i</sub></strong>, the number of slarboseconds since Great Event&nbsp;<strong>i</strong>&nbsp;occurred.</p>

<h3>Limits</h3>

<ul>
<li>1 ≤&nbsp;<strong>C</strong>&nbsp;≤ 100.</li>
<li><strong>t<sub>i</sub></strong>&nbsp;≠&nbsp;<strong>t<sub>j</sub></strong>&nbsp;for some&nbsp;<strong>i</strong>,&nbsp;<strong>j</strong>.</li>
<li>2 ≤&nbsp;<strong>N</strong>&nbsp;≤ 1000.</li>
<li>1 ≤&nbsp;<strong>t<sub>i</sub></strong>&nbsp;≤ 10<sup>50</sup>.</li>
</ul>



## 출력


<p>For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and&nbsp;<strong>y</strong>&nbsp;is the minimum number of slarboseconds until&nbsp;<strong>t<sub>i</sub></strong>&nbsp;+&nbsp;<strong>y</strong>&nbsp;is a multiple of the largest possible integer factor&nbsp;<strong>T</strong>&nbsp;for all&nbsp;<strong>i</strong>.</p>



## 소스코드

[소스코드 보기](Fair%20Warning%20(Large).cpp)