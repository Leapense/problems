# 30075번: Sveikas, Pasauli! - <img src="https://static.solved.ac/tier_small/4.svg" style="height:20px" /> Bronze II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30075)


<p>Paulius sukonstravo mini kompiuterį, prie kurio prijungtas ekranas bus pakabintas gerai matomoje vietoje ir rodys draugų žinutes iš socialinių tinklų.</p>

<p>Dabar vaikinas programuoja išvedimo į ekraną komandą SPAUSDINTI, kuri turi ekrane parodyti pateiktą tekstą ir suprasti vieną specialią instrukciją \n – tęsti iš naujos eilutės.</p>

<p><em>Komandos</em> SPAUSDINTI <em>sintaksė</em>. Komanda pradedama didžiosiomis raidėmis užrašytu raktažodžiu SPAUSDINTI. Po vieno tarpo pateikiamas kabutėmis (") apgaubtas tekstas, kurį reikia išvesti į ekraną. Kabučių išvesti nereikia.</p>

<p>Išvedamame tekste gali būti tokių simbolių:</p>

<ul>
<li>lotyniškų didžiųjų ir mažųjų raidžių;</li>
<li>skaičių;</li>
<li>, ./ &lt;&gt;?; : []{}|()− = _ + @! ∗ %$&amp;#</li>
</ul>

<p>Tarpų išvedamame tekste nebus. Jei tarp kabučių yra naujos eilutės komanda (du iš eilės einantys simboliai \n), šie simboliai nėra išvedami, o suprantami kaip instrukcija tolimesnį tekstą išvesti naujoje eilutėje.</p>

<p>Komanda SPAUSDINTI išveda tekstą į tą pačią eilutę, kur baigė prieš tai vykdyta komanda, ir tik \n instrukcija nurodo, kad reikia tęsti naujoje eilutėje.</p>

<p>Pateikta programa sudaryta tik iš komandų SPAUSDINTI. Parašykite programą, kuri interpretuotų pateiktas komandas ir išvestų jų rezultatą.</p>



## 입력


<p>Pirmojoje pradinių duomenų eilutėje nurodytas programą sudarančių komandų SPAUSDINTI skaičius $N$. Kitose $N$ eilučių pateiktos komandos po vieną eilutėje. Programa yra sintaksiškai teisinga ir jos eilutės yra neilgesnės nei $250$ simbolių.</p>



## 출력


<p>Išveskite tekstą, kurį atspausdintų duotoji programa.</p>



## 소스코드

[소스코드 보기](Sveikas,%20Pasauli!.cpp)