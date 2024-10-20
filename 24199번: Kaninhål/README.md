# 24199번: Kaninhål

## 문제 설명


<p>I den nyss avslutade tävlingen Databävern <a href="http://www.databavern.se/">(se hemsida)</a>&nbsp;fick eleverna se ett exempel på djurens märkliga samspel:</p>

<p>En grupp med $N$ bävrar ska gå på promenad i skogen. De går på ett led efter varandra, den ena bävern efter den andra. Men de busiga kaninerna har grävt en massa hål utefter stigen som bävrarna går på.</p>

<p>Hålen är tillräckligt djupa för att ett visst antal bävrar ska falla i dem. När hålet väl är fullt med bävrar kan de bakomvarande bävrarna passera ovanpå bävrarna i hålet, tills slutligen den sista bävern i raden drar upp bävrarna ur hålet, den översta först och den understa sist. Alltså, om vi har fem bävrar (5 4 3 2 1) som vandrar åt höger (nummer 1 går alltså först och nummer 5 sist i ledet), och de kommer till ett hål där tre bävrar får plats, så skulle följande hända:</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/060274a5-c3ba-4642-a64b-ba7955c0eec1/-/preview/" style="width: 493px; height: 140px;"></p>

<p style="text-align: center;">En illustration av ett kanin hål och hur bävrarna vandrar över hålet.</p>

<p>Tänk dig nu att kaninerna har gjort tre hål på vägen (vardera med ett djup mellan $1$ och $N-1$). Skriv ett program som, givet hur raden ser ut efter att bävrarna passerat alla hålen, beräknar djupet för varje hål.</p>



## 입력 형식


<p>På första raden står ett heltal $N$, antalet bävrar, där $2 \leq N &lt; 10$. På andra raden står $N$ olika heltal, vardera mellan 1 och N. Dessa beskriver ordningen på bävrarna när de passerat de tre kaninhålen. Från början är ordningen $N$, $N-1$, $N-2,\ldots,1$. Observera att de vandrar åt höger, så bäver $1$ går först i ledet.</p>



## 출력 형식


<p>Tre heltal mellan $1$ och $N-1$, djupet på det första, andra respektive tredje kaninhålet. Du kan förutsätta att det finns exakt en lösning för varje givet testfall.</p>



## 예제

### 예제 입력 1

```
5
3 4 2 1 5

```

### 예제 출력 1

```
1 1 2

```
          

### 예제 입력 2

```
7
3 2 1 4 6 7 5

```

### 예제 출력 2

```
5 4 4

```
          




## 추가 테스트 케이스

추가로 테스트 하고 싶은 케이스를 적고 정리해 보세요.

### 추가 입력 1

```
<입력값>
```

### 추가 출력 1

```
<출력값>
```

### 추가 입력 2

```
<입력값>
```

### 추가 출력 2

```
<출력값>
```
  