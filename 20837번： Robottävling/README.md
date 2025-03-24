# 20837번: Robottävling - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/20837)


<p>Du har byggt en robot till en robottävling. En av uppgifterna som roboten ska lösa går ut på att räkna antalet kuber i ett kvadratiskt rutnät. Rutnätet har $N$ rader och $N$ kolumner, och i varje ruta finns en stapel med $1$ till $5$ identiska kuber. Tyvärr är din robot inte särskilt bra på att samla information. Det enda den kan göra är att hitta höjden på den högsta stapeln i varje rad och kolumn. Du hade tänkt kompensera för detta genom att göra roboten väldigt smart. Skriv ett program som, givet informationen roboten samlade in, räknar ut det minsta och det största möjliga antalet kuber i rutnätet.</p>



## 입력


<p>På första raden står ett heltal $N$, antalet rader och kolumner i rutnätet. På andra raden står $N$ heltal $r_i$ $(1 \leq r_i \leq 5)$, höjden av högsta stapeln i rad $i$. På tredje raden står $N$ heltal $c_i$ $(1 \leq c_i \leq 5)$, höjden av högsta stapeln i kolumn $i$. Det är garanterat att det inte finns några motsägelser i indatan, det vill säga det kommer alltid att finnas minst en giltig utplacering av kuber som ger de givna värdena.</p>



## 출력


<p>Programmet ska skriva ut två heltal: det minsta möjliga och det största möjliga totala antal kuber i rutnätet.</p>



## 소스코드

[소스코드 보기](Robottävling.cpp)