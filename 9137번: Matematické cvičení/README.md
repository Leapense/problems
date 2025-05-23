# 9137번: Matematické cvičení - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9137)


<p>Malí matfyzáčci se musí odmala cvičit v matematice. Protože ale látka jako řešení soustav diferenciálních rovnic či integrace ve vícerozměrných prostorech je pro ně ještě příliš obtížná, je potřeba vyučovat něco jednoduššího. Po dlouhých debatách se rozhodlo, že se bude vyučovat prosté sčítání; ovšem v&nbsp;různých soustavách. Vaším úkolem bude napsat program, který bude žáčky kontrolovat.</p>



## 입력


<p>Na vstupu je několik bloků. Každý blok mimo posledního začíná řádkem s&nbsp;kladným celým číslem <var>z</var>, <var>z</var>&nbsp;≤&nbsp;35, poslední blok začíná nulou a nemá být zpracováván. Na druhém řádku každého bloku se nachází dvě nezáporná čísla <var>x</var> a <var>y</var> oddělená mezerou, která jsou zapsána standardním způsobem v&nbsp;soustavě o základu <var>z</var>. U&nbsp;soustav o základu větším než 10 se pro cifry s&nbsp;hodnotou větší než 9 používá písmen <code>A</code>, <code>B</code>.... Pokud má soustava základ jedna, používá se pouze cifra jedna a a počet cifer je roven velikosti čísla (viz vzorový výstup); nula se v jedničkové soustavě zapisuje jako jednociferné číslo, jehož jediná cifra 0. Čísla, která váš program obdrží na vstupu, nebudou na svém začátku obsahovat přebytečné nuly. Čísla mají nejvýše 1&nbsp;000 cifer.</p>



## 출력


<p>Výstup má obsahovat pro každý blok na vstupu jeden řádek. Na řádku mají být vypsána čísla <var>x</var> a <var>y</var> oddělená mezerou, znakem <code>+</code> a mezerou. Za nimi má následovat mezera, znak <code>=</code>, mezera a číslo <var>x</var>+<var>y</var>. Všechna čísla mají být zapsána standardním způsobem v&nbsp;soustavě o základu <var>z</var>.</p>



## 소스코드

[소스코드 보기](Matematické%20cvičení.cpp)