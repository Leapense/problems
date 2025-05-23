# 26907번: TV-tittande - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26907)


<p>Johan älskar att titta på TV hela dagarna, men klarar inte av reklampauser. När det blir en reklampaus i programmet han tittar på byter han till nästa kanal, och upprepar detta ända tills han hittar en kanal utan reklam. Om han tittar på den sista kanalen när detta händer så börjar han istället om på den första kanalen. Sedan tittar han på denna kanal tills det blir reklam, och så vidare.</p>

<p>Johan undrar i efterhand hur mycket han faktiskt tittade på varje kanal under en dag. Givet mellan vilka tider det var reklampauser på varje kanal, räkna ut detta åt honom. Han tittade mellan tiderna <code>00:00</code> och ett dygn framåt, och började titta på den första kanalen. Du kan anta att ett kanalbyte tar 1 minut, och att under kanalbytet sker inget tv-tittande (för varje kanalbyte så försvinner alltså en minut av tv-tittande).</p>



## 입력


<p>Indata börjar med ett heltal $N$ ($1 \leq N \leq 1000$), antalet kanaler.</p>

<p>Sedan följer en rad per kanal: varje rad börjar med ett heltal $r_i$, antalet reklampauser på kanalen. Sedan följer i kronologisk ordning $r_i$ ($0 \leq r_i \leq 1440$) reklampauser på samma rad, separerade av mellanslag. Varje reklampaus anges med sluttid och starttid på formen <code>HH:MM-HH:MM</code>, t.ex. betyder <code>05:24-22:23</code> att kanalen hade reklampaus från <code>05:24</code> fram till och med <code>22:23</code>, och den var exakt 17 timmar lång. Observera att under minut <code>22:23</code> så fortsätter reklamen, och den är slut först <code>22:24</code>. En reklampaus börjar tidigast vid midnatt och slutar senast vid midnatt (<code>00:00</code> och <code>23:59</code>, respektive). Inga reklampauser överlappar varandra på samma kanal.</p>



## 출력


<p>Skriv ut $N$ rader. För varje rad $1 \leq k_i \leq N$ så ska du skriva ut ett enda heltal: antalet minuter Johan tittade på kanal $k_i$.</p>



## 소스코드

[소스코드 보기](TV-tittande.cpp)