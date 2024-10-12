# 21367번: Vaccin - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/21367)


<p>Fredrika och hennes vänner går och väntar på deras covid-19-vaccin. De undrar så innerligt när de ska få sitt vaccin att de har ordnat fram klassificerad information från staten om vaccineringen. Närmare bestämt vet de att det är $n_i$ personer innan vän $i$ i kön, och de vet hur många som får vaccin varje dag. Hjälp dem att räkna ut när Fredrika och var och en av hennes vänner blir vaccinerade.&nbsp;</p>



## 입력


<p>Den första raden innehåller två heltal $N$ och $Q$ ($1 \le N,Q \le 100\,000$) -- &nbsp;antalet dagar de vet hur många som får vaccin på och antalet vänner, inklusive Fredrika, som vill veta när de får sitt vaccin. Nästa rader innehåller $N$ heltal $0 \le k_j \le 15$ -- antalet personer som får vaccin dag $j$ ($1 \le j \le N$). Därefter följer en rad med $Q$ heltal $0 \le p_i \le 10^6$ -- antalet personer framför $i$ i kön.</p>



## 출력


<p>Skriv ut $Q$ rader där dagen då person $i$ får sitt vaccin på skrivs ut på rad $i$. Om någon är så långt bak i kön att du inte vet när de får sitt vaccin, skriv ut $-1$.</p>



## 소스코드

[소스코드 보기](Vaccin.cpp)