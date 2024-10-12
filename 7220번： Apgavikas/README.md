# 7220번: Apgavikas - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7220)


<p>Martynas kartu su N draugų žaidžia kompiuterinį žaidimą „Apgavikas“. Veiksmas vyksta kosminiame laive, kurį sudaro M kambarių. Žaidimo pradžioje kiekvienas slaptai gauna rolę: vienas žaidėjas būna apgavikas, o kiti – įgulos nariai.</p>

<p>Įgulos tikslas yra išsiaiškinti apgaviką neapleidžiant laivo užduočių, o apgaviko – likti vieninteliam laive.</p>

<p>„Apgavikas“ žaidžiamas turais. Turo metu:</p>

<ol>
<li>Kiekvienas žaidėjas nueina į jam šiam turui paskirtą kambarį.</li>
<li>Įgulos nariai atlieka jiems paskirtas kosminio laivo priežiūros užduotis.</li>
<li>Apgavikas parenka auką, esančią tame pačiame kambaryje kaip ir jis, ir ją pašalina iš kosminio laivo. Apgavikui visada paskiriamas kambarys, kuriame jis bus ne vienas.</li>
<li>Visi, esantys kambaryje kartu su apgaviku, mato, kaip jis pašalina žaidėją. Taigi jie sužino, kuris žaidėjas yra apgavikas, ir žino tai visą likusį žaidimo laiką.</li>
<li>Po turo visi likę kosminiame laive žaidėjai išeina iš kambarių ir kiekvienas balsuoja spusteldamas raudoną arba geltoną mygtuką. Žinantys, kas yra apgavikas, spusteli raudoną mygtuką, nežinantys – geltoną.</li>
<li>Jei spustelėta daugiau raudonų mygtukų, nei geltonų – apgavikas demaskuojamas, jis pralaimi žaidimą ir žaidimas stabdomas.</li>
</ol>

<p>Apgavikas laimi žaidimą, jei pašalinami visi N žaidėjų, o jis (t.y. (N + 1)-asis žaidėjas) vienintelis lieka žaidime.</p>

<p>Pavyzdinę žaidimo eigą galite pamatyti žemiau pateiktame pavyzdyje.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/7e41c1db-a34b-4728-9981-97699fcad488/-/preview/" style="width: 310px; height: 317px;"></p>

<p>Martynas sužinojo, kad naujai žaidžiamame žaidime jis bus apgavikas, bei tai, kuris žaidėjas į kokį kambarį bus siunčiamas kiekvieno turo metu.</p>

<p>Martynas išanalizavo šiuos duomenis ir iš anksto suplanavo, kurį žaidėją pašalins kiekvieno turo metu.</p>

<p>Nustatykite, ar pavyks Martynui laimėti žaidimą, o jei nepavyks – kurio turo metu jis bus pašalintas iš žaidimo.</p>



## 입력


<p>Pirmojoje pradinių duomenų eilutėje pateikti du teigiami sveikieji skaičiai – žaidėjų, kurie nėra apgavikai, skaičius N, ir kambarių skaičius M.</p>

<p>Antrojoje eilutėje pateikti N skirtingų sveikųjų teigiamų skaičių p<sub>i</sub> – žaidėjų, kuriuos Martynas pašalins i-ojo turo metu, numeriai.</p>

<p>Toliau pateikta N eilučių po N sveikųjų teigiamų skaičių: i-oje eilutėje j-asis skaičius atitinka k<sub>i,j</sub> – į kurį kambarį i-ojo turo metu eis j-asis žaidėjas, jei dar nebus pašalintas iki to laiko.</p>



## 출력


<p>Išveskite vieną teigiamą sveikąjį skaičių: N, jei Martynas laimės žaidimą, kitu atveju – turo, kurio metu Martynas bus pašalintas, numerį.</p>



## 소스코드

[소스코드 보기](Apgavikas.cpp)