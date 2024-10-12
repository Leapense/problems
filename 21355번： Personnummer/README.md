# 21355번: Personnummer - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21355)


<p>Svenska personnummer skrivs oftast med tio siffror på formatet <code>ÅÅMMDD-XXXX</code>. De sex första siffrorna utgör personens födelsedatum, så en person med personnummer 781113-3285 är t.ex.&nbsp;född den 13:e november 1978. En detalj som många inte känner till är att hundraplussare får ett plustecken istället för bindestreck i sitt personnummer. Detta är för att man inte ska blanda ihop dem med personer som föddes exakt $100$ år senare. Till exempel kan någon som föddes år 1912 ha personnummret 121212+1212, medan 121212-1212 tillhör någon som föddes 2012.&nbsp;</p>

<p>Skriv ett program som läser in ett personnummer på formatet ovan, och skriver ut det på <em>tolvsiffrigt</em> format, d.v.s.&nbsp;<code>ÅÅÅÅMMDDXXXX</code>. Du kan anta att personerna i indatan föddes mellan 1840 och 2019. För enkelhets skull kommer det inte heller finnas några personer som föddes 1920.&nbsp;</p>



## 입력


<p>En sträng bestående av siffror, bindestreck och plustecken, på formatet ovan.</p>



## 출력


<p>Skriv ut en sträng, personnumret i indatan omvandlat till tolvsiffrigt format.</p>



## 소스코드

[소스코드 보기](Personnummer.py)