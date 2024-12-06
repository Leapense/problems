# 8734번: Akwarium - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/8734)


<p>Kozik dostał w prezencie na urodziny akwarium z mieczykami. Obserwowanie mieczyków szybko mu się znudziło, ponieważ według Kozika nigdy nie działo się nic nowego. Dlatego też mieczyki szybko sprzedał, a za zarobione pieniądze kupił w promocji pewne afrykańskie ryby.</p>

<p>Afrykańska ryba ma określoną masę i wiek oraz charakteryzuje się tym, że musi codziennie zaspokoić swój głód. Jeśli nie dostanie nic do jedzenia, to pożera inną, mniejszą rybę. Jeśli kilka ryb jest głodnych, to pierwszeństwo ma zawsze ryba o największej masie, która wybiera swoją ofiarę (w przypadku równych mas pierwszeństwo ma ryba starsza). Ofiarą będzie zawsze najmniejsza ryba znajdująca się w akwarium (jeśli kilka ryb ma taką samą masę, ofiarą z nich będzie najmłodsza ryba). Dodatkowo afrykańska ryba zwiększa swoją masę o połowę masy zjedzonej przez nią innej ryby. Jeśli afrykańska ryba nie zaspokoi swojego głodu w ciągu dnia, zdycha. Kilka ryb może mieć równe masy, natomiast wszystkie ryby są innego wieku.</p>

<p>Kozik zastanawia się, czy pewna ryba <em>r</em>, wybrana przez niego, będzie żyła za <em>x</em>&nbsp;dni.</p>



## 입력


<p>Pierwszy wiersz standardowego wejścia zawiera jedną liczbę całkowitą <em>n</em>&nbsp;(1 ≤ <em>n</em> ≤ 10<sup>6</sup>), oznaczającą liczbę ryb w akwarium. W&nbsp;<em>n</em>&nbsp;kolejnych wierszach znajdują się po dwie liczby całkowite <em>m<sub>i</sub></em>,&nbsp;<em>w<sub>i</sub></em>&nbsp;(1 ≤ <em>m<sub>i</sub></em>, <em>w<sub>i</sub></em> ≤ 10<sup>9</sup>), oznaczające odpowiednio masę i wiek <em>i</em>&nbsp;- tej ryby. W kolejnym wierszu znajduje się jedna całkowta <em>z</em>&nbsp;(1 ≤ <em>z</em> ≤ 10<sup>6</sup>), ozaczająca liczbę zapytań Kozika. W&nbsp;<em>z</em>&nbsp;następnych wierszach znajdują się po dwie liczby całkowite <em>r<sub>k</sub></em>,&nbsp;<em>x<sub>k</sub></em>&nbsp;(1 ≤ <em>r<sub>k</sub></em> ≤ <em>n</em>, 0 ≤ <em>x<sub>k</sub></em> ≤ 10<sup>9</sup>), oznaczjące pytanie: czy ryba&nbsp;<em>r<sub>k</sub></em>&nbsp;będzie żyła za&nbsp;<em>x<sub>k</sub></em>&nbsp;dni?.</p>



## 출력


<p>Dla każdego zapytania słowo TAK, jeśli ryba <em>r<sub>k</sub></em>&nbsp;będzie żyła za&nbsp;<em>x<sub>k</sub></em>&nbsp;dni, w przeciwnym wypadku słowo NIE.</p>



## 소스코드

[소스코드 보기](Akwarium.cpp)