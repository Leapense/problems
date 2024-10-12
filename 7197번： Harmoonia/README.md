# 7197번: Harmoonia - <img src="https://static.solved.ac/tier_small/5.svg" style="height:20px" /> Bronze I

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/7197)


<p>Klassikalise harmooniateooria kohaselt tuleks mitmehäälset seadet kirjutades vältida niinimetatud paralleelkvinte, see tähendab olukorda, kus kahe hääle vaheline kaugus pooltoonides annab jagamisel kaheteistkümnega jäägi seitse, seejärel mõlemas hääles helikõrgus muutub ning nende vaheline kaugus pooltoonides annab jälle kaheteistkümnega jagades jäägi seitse.<sup>1</sup></p>

<p>Paralleelkvindid esinevad ainult siis, kui mõlemas hääles helikõrgus muutub. See tähendab, et kui kahel järjestikusel noodil annab kahe hääle vaheline kaugus 12-ga jagades jäägi 7, kuid kas ühes või kummaski hääles helikõrgus ei muutu, siis ei ole tegemist paralleelkvintidega.</p>

<p>Kirjutada programm, mis tuvastab K-häälses seades paralleelkvintide olemasolu.</p>

<p>Helikõrgusi esitatakse sisendfailis täisarvudena. Arv 0 tähistab esimese oktavi C nooti ning positiivne täisarv k sellest k pooltooni võrra kõrgemat ja negatiivne täisarv vastavalt madalamat heli. Näiteks arv 4 vastab esimese oktavi E noodile ja arv −3 väikse oktavi A noodile.<sup>2</sup></p>

<hr>
<p><sup>1</sup> Märkus muusikateooriast rohkem huvitatuile: vahel loetakse paralleelkvintideks mitte ainult kaht järjestikust puhast kvinti, vaid ka näiteks järjestikuseid puhast ja vähendatud kvinti (vastavalt seitse ja kuus pooltooni); selles ülesandes loeme paralleelkvintideks vaid kaht järjestikust puhast kvinti.</p>

<p><sup>2</sup> Ülesande lahendamiseks ei ole oluline nootide nimetusi mõista.</p>



## 입력


<p>Tekstifaili esimesel real on kaks tühikutega eraldatud täisarvu N ja K (0 ≤ N ≤ 100 000, 2 ≤ K ≤ 10) — igas hääles esinevate nootide arv N ja häälte arv K. Järgmisel N real on igauhel K tühikutega eraldatud täisarvu A<sub>1,i</sub> . . . A<sub>K,i</sub>, kus A<sub>j,i</sub> on i. noodi kõrgus j. hääles (−100 ≤ A<sub>K,i</sub> ≤ . . . ≤ A<sub>1,i</sub> ≤ 100, i ∈ 1 . . . N). Ühel real antud noodid kõlavad samaaegselt ning järjestikustel ridadel olevad noodid kõlavad vahetult üksteise järel.</p>



## 출력


<p>Kui seades paralleelkvinte ei esine, väljastada tekstifaili ainsale reale sõna <code>POLE</code>. Kui seades esinevad paralleelkvindid, toimida järgmiselt. Kui paralleelkvindid tekivad noodiridade i ja i + 1 vahel häälte s ja t vahel (s &lt; t), väljastada faili eraldi reale kolm tühikutega eraldatud täisarvu i, s ja t. Väljastada kõik palas esinevad paralleelkvindid i kasvamise järjekorras. Kui kahel väljundfaili real on sama i, siis järjestada nad s kasvamise järjekorras, ning kui kahel real on sama i ja s, siis järjestada nad t kasvamise järjekorras.</p>



## 소스코드

[소스코드 보기](Harmoonia.py)