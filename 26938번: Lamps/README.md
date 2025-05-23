# 26938번: Lamps - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26938)


<p>Användningen av glödlampor är på väg att avskaffas inom EU, men redan nu kan det löna sig att använda lågenergilampor. Du ska skriva ett program som, givet hur mycket en lampa är tänd varje dag samt elpriset, beräknar efter hur många dagar totalkostnaden (inköp av lampor + elkostnad) för första gången är lägre för lågenergilampan än för glödlampan. Vi antar följande data:</p>

<table class="table table-bordered table-center-30 th-center td-center">
<tbody>
<tr>
<th> </th>
<th>Glödlampa</th>
<th>Lågenergilampa</th>
</tr>
<tr>
<th>Effekt (watt)</th>
<td>60</td>
<td>11</td>
</tr>
<tr>
<th>Livslängd (timmar)</th>
<td>1000</td>
<td>8000</td>
</tr>
<tr>
<th>Inköpspris (kronor)</th>
<td>5</td>
<td>60</td>
</tr>
</tbody>
</table>

<p>För enkelhets skull antar vi att alla exemplar har exakt den givna livslängden. Detta innebär alltså att för att ha lampan tänd i $1000$ timmar räcker det att köpa en glödlampa, men för att ha den tänd i $1001$ timmar måste man köpa ytterligare en glödlampa eftersom den första går sönder efter $1000$ timmar.</p>

<p>Elkostnaden $K$ för att ha lampan tänd i $H$ timmar kan beräknas med formeln $$ K = \frac{E \cdot H \cdot P}{100\,000} $$ där $E$ är lampans effekt i watt och $P$ är elpriset i öre/kWh.</p>

<p>I samtliga testfall kommer endast en lågenergilampa att behöva köpas (lågenergi blir alltså billigast redan innan man behöver byta lågenergilampan).</p>



## 입력


<p>Indatan består av två heltal på en rad: $h$ ($1 \le h \le 24$), antalet timmar per dag lampan är påslagen, och $P$ ($1 \le P \le 200$), elpriset.</p>



## 출력


<p>Skriv ut efter hur många dagar lågenergilampan är billigare än glödlampan.</p>



## 소스코드

[소스코드 보기](Lamps.cpp)