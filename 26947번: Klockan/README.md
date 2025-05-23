# 26947번: Klockan - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/26947)


<p>Om någon frågar hur mycket klockan är, svarar de flesta "kvart över fem", <code>15:29</code> eller något liknande. Vill man göra det lite svårare så kan man annars svara med vinkeln mellan tim- och minutvisaren, eftersom man ur denna information entydigt kan bestämma klockslaget. Dock är det många människor som är ovana vid detta sätt att ange tider, så det vore bra att ha ett datorprogram som översätter till ett mer normalt format. Du ska skriva ett sådant program.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/9037f234-5e7a-4151-86f0-94ea1d20e6f2/-/preview/" style="width: 706px; height: 300px;"></p>

<p style="text-align: center;">Klockan till vänster är <code>01:21</code> och den till höger är <code>03:08</code>.</p>

<p>Vi förutsätter att vår klocka saknar sekundvisare och endast visar ett helt antal minuter (det vill säga: båda visarna hoppar framåt bara på hel minut). Vinkeln avläses genom att utgå från timvisaren och sedan mäta hur många grader medurs minutvisaren ligger (se figuren). För att undvika decimaler anges vinkeln i tiondels grader (så att $85.5$ grader skrivs som $855$). Detta tal är alltid ett heltal mellan $0$ och $3595$ (inklusive) och är, som en följd av att endast hela minuter visas, alltid delbart med $5$.</p>



## 입력


<p>Indatan består av ett enda heltal mellan $0$ och $3595$ -- vinkel mellan de två visarna, i tiondels grader.</p>



## 출력


<p>Skriv ut det klockslag som vinkeln motsvarar, på formatet <code>hh:mm</code>. Om antalet timmar är ensiffrigt ska du ändå skriva ut en ledande nolla i svaret. Vi förutsätter att det är morgon, så alla tider ska dessutom ligga mellan <code>00:00</code> och <code>11:59</code> (inklusive).</p>



## 소스코드

[소스코드 보기](Klockan.cpp)