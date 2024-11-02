# 7124번: Sarnased kolmnurgad - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7124)


<p>Juku õpib koolis kolmnurkade sarnasust ja saab teada, et kolmnurgad on sarnased, kui nende vastavate nurkade suurused on võrdsed ja vastavate külgede pikkused võrdelised. Sarnased kolmnurgad võivad olla omavahel pööratud, peegeldatud ja nihutatud. Sarnaste kolmnurkade vastavate külgede pikkuste jagatist nimetatakse nende sarnasusteguriks.</p>

<p>Kodutööna saab ta hulga kolmnurki, mille sarnasustegureid on vaja määrata. Kuna 21. sajandil sobivad arvutamiseks rohkem arvutid kui inimesed, aita Jukul kirjutada programm, mis selle töö tema eest ära teeb.</p>



## 입력


<p>Tekstifaili esimesel real on kuus täisarvu lõigust $-10^9$ kuni $10^9$: esimese kolmnurga tippude x- ja y-koordinaadid. Teisel real on samuti kuus arvu: teise kolmnurga tippude koordinaadid. Tipud võivad olla antud nii päripäeva kui vastupäeva järjekorras. Antud punktid moodustavad alati kolmnurga (pole ühtelangevaid punkte ega sirgnurki).</p>



## 출력


<p>Kui kolmnurgad on sarnased, siis kirjutada tekstifaili täpselt üks reaalarv (täpsusega vähemalt $0{,}0001$), mis näitab, mitu korda on esimene kolmnurk suurem kui teine (kui esimene kolmnurk on väiksem, on ka vastus väiksem kui $1$). Kui kolmnurgad ei ole sarnased, kirjutada väljundfaili $-1$.</p>



## 소스코드

[소스코드 보기](Sarnased%20kolmnurgad.py)