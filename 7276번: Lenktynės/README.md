# 7276번: Lenktynės - <img src="https://static.solved.ac/tier_small/7.svg" style="height:20px" /> Silver IV

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7276)


<p>Ralio lenktynėse dalyvavo N automobilių. Pasibaigus varžyboms, televizijos operatoriai nori sumontuoti visą nufilmuotą medžiagą. Svarbiausia – jie nori parodyti visus aplenkimus, kurie įvyko lenktynių metu. Tačiau bemontuodami medžiagą operatoriai susimaišė: kaip sužinoti, ar visus aplenkimus jie sumontavo teisinga tvarka?</p>

<p>Jums žinomos pradinės automobilių pozicijos, bei eilė automobilių aplenkimų. Parašykite programą, kuri nustatytų, ar duoti aplenkimai galėjo įvykti tokia tvarka.</p>



## 입력


<p>Pirmoje eilutėje įrašytas automobilių skaičius N, o antroje – automobilių numeriai, įrašyti tokia tvarka, kokia jie startavo (pirmasis startavęs automobilis įrašytas pirmas). Visi automobilių numeriai yra skirtingi sveikieji skaičiai nuo 1 iki N.</p>

<p>Tolimesnėje eilutėje įrašytas lenkimų skaičius L. Toliau pateikta L eilučių kuriose įrašyta po skaičių porą (a<sub>i</sub>, b<sub>i</sub>), žyminčią, kad automobilis a<sub>i</sub> aplenkė automobilį b<sub>i</sub>. Skaičių poros įrašytos tokia tvarka, kokia buvo sumontuota operatorių įraše. Galite būti tikri, kad lenktynių metu įvyko bent vienas lenkimas.</p>



## 출력


<p>Jei lenktynės galėjo vykti tokia eiga, kokia yra pateikta, pirmoje eilutėje išveskite žodį <code>TAIP</code>, o antroje – galutinę automobilių tvarką, tokiu pačiu formatu, kaip ir pradiniuose duomenyse.</p>

<p>Jei operatoriai padarė klaidą montuodami, pirmoje eilutėje išveskite žodį <code>NE</code>, o antroje numerį lenkimo, kuris yra neįmanomas (t.y. automobilis a<sub>i</sub> negalėjo aplenkti b<sub>i</sub> tuo metu).</p>



## 소스코드

[소스코드 보기](Lenktynės.cpp)