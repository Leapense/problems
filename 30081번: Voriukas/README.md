# 30081번: Voriukas - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/30081)


<p>$K$-kojis voriukas visada dėvi $K$ vienodos rūšies kojinių. Kojines voriukas skalbia skalbimo mašinoje ir vienu skalbimu jis skalbia tik vienos rūšies kojines. Deja, po kiekvieno skalbimo, jis pameta dalį skalbtų kojinių.</p>

<p>Padėkite voriukui suskaičiuoti, kiek švarių kojinių komplektų (vieną komplektą sudaro $K$ tos pačios rūšies kojinių) jis turės po kiekvieno skalbimo.</p>



## 입력


<p>Pirmojoje eilutėje pateikti du sveikieji skaičiai: turimų kojinių skaičius $N$ ir voriuko kojų skaičius $K$.</p>

<p>Antrojoje eilutėje pateikti $N$ tarpu atskirtų sveikųjų skaičių $t_i$, nusakančių kiekvienos kojinės rūšį. Skaičius $t_i$ reiškia, kad atitinkama kojinė yra $t_i$ rūšies.</p>

<p>Trečiojoje eilutėje pateikiamas sveikasis skaičius $Q$ – plovimų skaičius.</p>

<p>Likusiose $Q$ eilučių pateikiama po du tarpu atskirtus sveikuosius skaičius $a_j$ ir $b_j$. Šie skaičiai nurodo, kad $j$-ojo skalbimo metu, voriukas skalbė $a_j$ rūšies kojines ir pametė $b_j$ kojinių.</p>



## 출력


<p>Išveskite $Q$ eilučių. Kiekvienoje jų turi būti sveikasis skaičius $c_k$ – kiek kojinių komplektų iš $K$ vienodos rūšies kojinių turi voriukas po $k$-ojo skalbimo ($1 ≤ k ≤ Q$).</p>



## 소스코드

[소스코드 보기](Main.java)