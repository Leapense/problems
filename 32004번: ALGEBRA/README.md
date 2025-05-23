# 32004번: ALGEBRA - <img src="https://static.solved.ac/tier_small/6.svg" style="height:20px" /> Silver V

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/32004)


<p>Neka je zadano N nizova prirodnih brojeva. Za svaki niz unaprijed znamo koliko ima članova. Riješi sljedeće izazove.</p>

<p><strong>Izazov #1</strong></p>

<p>Kada bi sve zadane nizove napisali jedan iza drugog, koliko bi onda bilo napisanih brojeva?</p>

<p><strong>Izazov #2</strong></p>

<p>Koliki je zbroj brojeva koji se nalaze i u A-tom i u B-tom nizu? Brojevi koji se ponavljanju u nizovima zbrajaju se samo jednom.</p>

<p><strong>Izazov #3</strong></p>

<p>Dva niza spajamo u jedan na način da usporedimo vrijednosti članova na odgovarajućim pozicijama (prvoj, drugoj..) u nizovima koje spajamo te u novi spojen niz na tu poziciju stavimo veću od dvije promatrane vrijednosti. Ako u nekom od dva niza nema neke pozicije, tada se kao vrijednost novog niza na toj poziciji uzima vrijednost pozicije u nizu gdje ta pozicija postoji.</p>

<p>Zadanih N nizova spoji u jedan na način da redom nizove spajaš po parovima (prvi s drugim, treći s četvrtim..) i postupak ponavljaš sve dok ti ne ostane jedan niz.</p>



## 입력


<p>U prvom je retku prirodan broj N (1 ≤ N ≤ 128, N je potencija broja 2), broj iz teksta zadatka.</p>

<p>U drugom su retku prirodni brojevi A i B (1 ≤ A &lt; B ≤ N), brojevi iz teksta zadatka.</p>

<p>U sljedećih N redaka nalazi se po niz prirodnih brojeva, gdje prvi broj u nizu M (1 ≤ M ≤ 99) definira koliko u tom nizu ima brojeva tj. broj prirodnih brojeva Xi (1 ≤ Xi ≤ 99), koji slijedi u nastavku retka.</p>



## 출력


<p>U prvi redak ispiši prirodan broj, odgovor na prvi izazov iz teksta zadatka.</p>

<p>U drugi redak ispiši cijeli broj, odgovor na drugi izazov iz teksta zadatka.</p>

<p>U treći redak ispiši niz prirodnih brojeva, vrijednosti završnog spojenog niza na prvoj, drugoj,.. te zadnjoj poziciji.</p>



## 소스코드

[소스코드 보기](ALGEBRA.cpp)