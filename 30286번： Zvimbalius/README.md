# 30286번: Zvimbalius - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30286)


<p>Vytis turi naują žaislą – nuotoliniu būdu valdoma bepilotę skraidyklę, dar žinomą kaip dronas arba zvimbalius. Dronas yra bepilotis sragtasparnis, kuris skrenda vykdydamas jam duotas komandas.</p>

<p>Vyčio dronas supranta keturias komandas – S, P, R, V – kurios atitinkamai liepia jam skristi vieną metrą į šiaurę, pietus, rytus ar vakarus.</p>

<p>Vytis nusprendė išbandyti savo žaislą ir įvedė į jį N komandų, tačiau jas įvedęs suprato, kad dronas, įvykdęs tas komandas, gali nesugrįžti į pradinį tašką. Deja, komandas taisyti sunku, nes drono programinė įranga neleidžia nei pridėti, nei ištrinti jau įvestų komandų, o jas pakeisti galima tik po vieną. Vytis nori pakeisti kuo mažiau komandų taip, kad įvykdęs visas komandas dronas grįžtų į pradinį tašką.</p>

<p>Suskaičiuokite kiek mažiausiai komandų Vyčiui reikės pakeisti, kad dronas sugrįžtų į pradinį tašką.</p>



## 입력


<p>Pirmoje eilutėje yra pateiktas skaičius N – įvestų komandų kiekis. Antroje eilutėje yra pateiktas N komandų eilutė be tarpų k<sub>1</sub>k<sub>2</sub>...k<sub>N</sub>, kuriame k<sub>i</sub> yra i-toji komanda, užkoduota taip, kaip nurodyta sąlygoje.</p>



## 출력


<p>Išveskite vieną sveikąjį skaičių – kiek komandų reikia pakeisti, norint, kad dronas sugrįžtųį pradinį tašką.</p>

<p>Jei neįmanoma pakeisti komandų taip, kad dronas sugrįžtų į pradinį tašką, išveskite <code>NEGALIMA</code>.</p>



## 소스코드

[소스코드 보기](Main.java)