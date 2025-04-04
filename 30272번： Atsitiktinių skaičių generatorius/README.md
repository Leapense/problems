# 30272번: Atsitiktinių skaičių generatorius - <img src="https://static.solved.ac/tier_small/3.svg" style="height:20px" /> Bronze III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30272)


<p>Justas nusipirko atsitiktinių skaičių generatorių, kuris gali sugeneruoti bet kokį teigiamą sveikąjį skaičių su lygiai N skaitmenų. Deja, generatoriaus ekranas yra labai mažas ir sugeneruotas skaičius į jį netelpa. Todėl šis skaičius yra išvedamas paeiliui parodant jo skaitmenis.</p>

<p>Kiekvieno skaitmens atvaizdas yra 9 × 8 matmenų paveikslėlis, sudarytas iš baltų ir juodų pikselių. Jei baltus pikselius vaizduotume taškais (<code>.</code>), o juodus – grotelėmis (<code>#</code>), tai skaitmenys atrodytų taip:</p>

<pre style="text-align: center;">..#####..  ....##...  .#######.  .#######.  ##.......
.##...##.  ..####...  ##.....##  ##.....##  ##....##.
##.....##  ....##...  .......##  .......##  ##....##.
##.....##  ....##...  .#######.  .#######.  ##....##.
##.....##  ....##...  ##.......  .......##  #########
.##...##.  ....##...  ##.......  ##.....##  ......##.
..#####..  ..######.  #########  .#######.  ......##.
.........  .........  .........  .........  .........
.########  .#######.  .########  .#######.  .#######.
.##......  ##.....##  .##....##  ##.....##  ##.....##
.##......  ##.......  .....##..  ##.....##  ##.....##
.#######.  ########.  ....##...  .#######.  .########
.......##  ##.....##  ...##....  ##.....##  .......##
.##....##  ##.....##  ...##....  ##.....##  ##.....##
..######.  .#######.  ...##....  .#######.  .#######.
.........  .........  .........  .........  .........
</pre>

<p>Gavę N skaitmenų, atvaizduotų aukščiau nurodytu būdu, apskaičiuokite, kokį skaičių tie skaitmenys sudaro. Skaitmenys bus pateikiami paeiliui nuo kairiausio iki dešiniausio.</p>



## 입력


<p>Pirmojoje eilutėje pateikiamas skaitmenų kiekis N. Toliau pateikiama 8N eilučių, aprašančių skaitmenis (vieną skaitmenį aprašo aštuonios eilutės). Kiekvieną eilutę sudaro devyni simboliai (<code>.</code> ir <code>#</code>).</p>

<p>Pirmasis skaitmuo nebus nulis.</p>



## 출력


<p>Išveskite skaičių, kuris susidaro iš pateiktų skaitmenų</p>



## 소스코드

[소스코드 보기](Atsitiktinių%20skaičių%20generatorius.py)