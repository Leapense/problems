# 26936번: Gourmeten - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26936)


<p>Den franska gourmeten Frank är en väl respekterad gourmet; hans yrke är att gå runt till olika restauranger, äta av deras mat och ge sitt omdöme om restaurangen. Men han bär på en hemlighet: han är egentligen bara intresserad av att äta så mycket som möjligt och i vilken ordning som helst!</p>

<p>Frank förstår dock att en äkta gourmet inte kan äta hur som helst, t.ex. börja med sin dessert och avsluta med en sallad. Därför ber han om din hjälp att ta fram en lista med alla olika sätt att ordna maträtterna under en bjudning, så han kan välja ut den ordning som är finast.</p>

<p>På bjudningen har Frank $M$ minuter på sig att äta. Restaurangen bjuder på $N$ olika rätter som han kan äta hur många portioner som helst av. Varje rätt $i$ tar ett visst givet antal minuter $T_i$ att äta. Frank vill äta kontinuerligt under alla de $M$ minuter han har på sig, och han vill hinna äta klart alla rätter han påbörjat. Han vill aldrig påbörja en ny rätt innan han ätit färdigt den förra. Din uppgift är att skriva ett program som räknar ut på hur många olika sätt han kan lägga upp middagen, givet dessa restriktioner.</p>



## 입력


<p>På första raden står ett heltal $M$, antalet minuter, där $1 \le M \le 1,000$.</p>

<p>På andra raden står ett heltal $N$, antalet rätter, där $1 \le N \le 30$.</p>

<p>Därefter följer $N$ rader med ett heltal $T_i$ på varje rad, tiden det tar att äta varje rätt, där $1 \le T_i \le 200$.</p>



## 출력


<p>Programmet ska skriva ut antalet möjliga sätt Frank kan äta under exakt $M$ minuter. Svaret kommer alltid understiga $2$ miljarder.</p>



## 소스코드

[소스코드 보기](Gourmeten.py)