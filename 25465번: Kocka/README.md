# 25465번: Kocka - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/25465)

<p>Zamisli kocku. Kocku dimenzije $N$ koja se sastoji od $N \times N \times N$ jediničnih kockica. Svaka jedinična kockica u kocki je u početku bezbojna tj. prozirna i vidi se kroz nju, a tijekom vremena na naš zahtjev cijela može promijeniti boju.</p>

<p>Zamisli da ta kocka stoji na staklenoj rotirajućoj podlozi. Znamo da kocka ima šest strana: prednju, stražnju, lijevu, desnu, gornju i donju. U početku, prednja strana kocke je okrenuta prema tebi, stoji u razini očiju i gledaš u nju. Kroz prozirne kockice vidi se sve do prve obojene kockice.</p>

<p>E sada, neka je dano $Q$ upita, a $i$-ti od njih je jednog od sljedećeg oblika:</p>

<ul>
<li>$1$ $X_i$ $Y_i$ $Z_i$ $C_i$ - jedinična kockica koja se nalazi u $X_i$-tom redu (brojeći od gornje strane prema donjoj), $Y_i$-tom stupcu (brojeći od lijeve strane prema desnoj) i na dubini $Z_i$ (brojeći od prednje strane prema stražnjoj) poprima boju $C_i$. Pazi, kocka je okrenuta prednjom stranom prema tebi.</li>
<li>$2$ $S_i$ - zarotiraj kocku tako da strana $S_i$ dođe na prednju stranu (ispred tvojih očiju) te ispiši tablicu dimenzija $N \times N$ boja koje sada vidiš. Ako se na nekom mjestu u potpunosti vidi kroz kocku, za to mjesto ispiši $0$. Vrati kocku u početni položaj, tj. da je prednja strana opet okrenuta prema tebi.</li>
</ul>

## 입력

<p>U prvom su retku prirodni brojevi $N$ i $Q$ ($2 ≤ N ≤ 100$, $1 ≤ Q ≤ 2\,000$), brojevi iz teksta zadatka.</p>

<p>U $i$-tom od sljedećih $Q$ redaka nalazi se po jedan upit prve ili druge vrste.</p>

<ul>
<li>ako je prvi broj u upitu $1$, onda su u tom upitu još prirodni brojevi $X_i$ $Y_i$ $Z_i$ $C_i$ ($1 ≤ X_i ≤ N$, $1 ≤ Y_i ≤ N$, $1 ≤ Z_i ≤ N$, $1 ≤ C_i ≤ 1\,000\,000\,000$), iz teksta zadatka;</li>
<li>ako je prvi broj u upitu $2$ onda u tom upitu još dolazi niz znakova $S_i$ ($S_i$ bit će jedna od sljedećih riječi: “prednja”, “straznja”, “lijeva”, “desna” i označava stranu koju treba zarotirati pred sebe, tamo gdje je do tada bila prednja), iz teksta zadatka.</li>
</ul>

## 출력

<p>Za svaki upit druge vrste ispiši tablicu veličine $N \times N$, odgovor na taj upit.</p>

## 소스코드

[소스코드 보기](Kocka.py)