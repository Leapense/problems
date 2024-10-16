# 7213번: Akmuo, popierius, žirklės - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7213)


<p>Vilius ir Adomas žaidžia žaidimą „Akmuo, popierius, žirklės“. Žaidėjai kartu skaičiuoja „vienas… du… trys…“ ir tuo pačiu metu mojuoja kumščiais. Sakant „trys“ kiekvienas žaidėjas viena ranka parodo vieną iš trijų ženklų: akmenį, žirkles ar popierių. Laimėtojas nustatomas taip:</p>

<ul>
<li>Akmuo laimi prieš žirkles (akmuo bukina ar laužo žirkles)</li>
<li>Žirklės laimi prieš popierių (žirklės karpo popierių)</li>
<li>Popierius laimi prieš akmenį (popierius uždengią akmenį)</li>
<li>Jei žaidėjai parodo vienodus ženklus, tai laikoma lygiosiomis</li>
</ul>

<p>Vilius ir Adomas žais žaidimą daug kartų, tad sugalvojo tokią taškų sistemą:</p>

<ul>
<li>Abu žaidėjai pradeda su 0 taškų</li>
<li>Laimėjusio žaidėjo taškų skaičius padidėja vienetu</li>
<li>Pralaimėjusio žaidėjo taškų skaičius sumažėja vienetu</li>
<li>Lygiųjų atveju taškų skaičius nesikeičia</li>
</ul>

<p>Vilius ir Adomas sužaidė jau nemažai žaidimų, bet pamiršo savo turimų taškų kiekį! Kiekvienas jų prisimena, kiek kartų kokį ženklą (akmenį, popierių ir žirkles) rodė, bet neprisimena kokia tvarka. Padėkite jiems nustatyti, kiek daugiausiai bei kiek mažiausiai taškų gali turėti Vilius (žinodami Viliaus taškų kiekį, Adomo taškus suskaičiuos patys).</p>

<p>Nustatykite, kiek daugiausiai bei kiek mažiausiai taškų gali turėti Vilius.</p>



## 입력


<p>Pirmoje eilutėje pateikti 3 sveikieji skaičiai a<sub>1</sub>, p<sub>1</sub>, z<sub>1</sub>, nurodantys, kiek kartų Vilius parodė atitinkamai akmenį, popierių bei žirkles. Antroje eilutėje ta pačia tvarka pateikti Adomo parodytų ženklų kiekiai a<sub>2</sub>, p<sub>2</sub>, z<sub>2</sub>.</p>



## 출력


<p>Pirmoje eilutėje išveskite didžiausią galimą, o antroje – mažiausią galimą Viliaus turimų taškų kiekį.</p>



## 소스코드

[소스코드 보기](Akmuo,%20popierius,%20žirklės.cpp)