# 26397번: Tramvaji - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26397)


<p>One magical night Patrik and Josip were talking about the number 42 and the meaning of life. They were interrupted by the famous lady voice in the tram: The next stop is Jordanovac. Patrik and Josip were distracted by this common sentence and started discussing:</p>

<p>Patrik: It is a very short ride between Joranovac and Maksimir, isn’t it?</p>

<p>Josip: It is, but the ride between Mašićeva and Kvatrić is way shorter.</p>

<p>Patrik: Really? I disagree.</p>

<p>Josip: I wonder, which is the shortest ride between all stations?</p>

<p>Paula, a big public traffic transport, was carefully listening to their conversation. The problem of finding the shortest ride interested her so much that she stayed in the tram longer than she intended just to listen to their conversation.</p>

<p>At each station (except for the first one, when they entered the tram) one of the following two things happened:</p>

<ul>
<li>Patrik said: t minutes have passed since we entered the tram</li>
<li>Josip said: From station y to this station t minutes have passed</li>
</ul>

<p>But before Paula could hear their conclusion about which ride was the shortest, they left the tram! Luckily, Paula remembers all their statements. Now she needs your help! Help her find the duration of the shortest ride and between which two stations the tram drove on that ride.</p>



## 입력


<p>The first line contains the integer n (2 ≤ n ≤ 1 000), the number of tram stations.</p>

<p>The i-th of the following n − 1 lines contains the information about station i + 1 in one of the following formats:</p>

<ul>
<li><code>Patrik</code> t<sub>i</sub> – Duration of the ride between station 1 and station i + 1 is t<sub>i</sub> (1 ≤ t<sub>i</sub> ≤ 10<sup>9</sup>)</li>
<li><code>Josip</code> y<sub>i</sub> t<sub>i</sub> – Duration of the ride between station y and station i + 1 is t<sub>i</sub> (y<sub>i</sub> &lt; i + 1, 1 ≤ t<sub>i</sub> ≤ 10<sup>9</sup>)</li>
</ul>

<p>Every station will be in a distinct position.</p>



## 출력


<p>In one line output three numbers: t, x<sub>1</sub>, x<sub>2</sub>, the duration of the shortest ride and the indices of the starting and ending stations of that ride.</p>

<p>If multiple solutions exist, print the one with the smallest indices of the stations.</p>



## 소스코드

[소스코드 보기](Tramvaji.cpp)