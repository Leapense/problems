# 26902번: IP-adresser - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26902)


<p>En IPv4-address består av fyra heltal mellan $0$ och $255$ (som vardera inte får ha några inledande nollor), separerade av punkter. T.ex. är <code>1.0.3.255</code> en giltig address, medan <code>1.0.03.255</code>, <code>1.0.3.256</code> och <code>1.0.3</code> inte är giltiga addresser. Givet en sekvens av siffror, hitta alla giltiga IPv4-adresser som kan skapas genom insättning av tre punkter i sekvensen.</p>



## 입력


<p>På första raden står en sträng med minst $4$ och max $12$ siffror.</p>



## 출력


<p>Skriv ut ett heltal: antalet giltiga IP-adresser som kan bildas genom att sätta in 3 punkter.</p>



## 소스코드

[소스코드 보기](IP-adresser.py)