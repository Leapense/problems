# 25449번: Eurokulen

## 문제 설명


<p>Na izboru za najbolji kulen Europe sudjeluje $N$ malih obiteljskih gospodarstava (OPG) označenih brojevima od jedan do $N$. Nakon predstavljanja i degustacije kulena, pristupa se glasanju. Svaki OPG-e rangira preostalih $N-1$ OPG-ova na način da najboljem kulenu po njihovom izboru dodijeli N-1 bodova, donajboljem $N-2$ bodova i tako sve do zadnjeg kojem dodjeljuje samo jedan bod.</p>

<p><strong>Pitanje #1</strong>: Odredi i ispiši oznake OPG-ova čiji su kuleni zauzeli prvo, drugo i treće mjesto. Ako više kulena ima isti broj bodova, prednost ima onaj s manjom oznakom.</p>

<p>Međutim, europski povjerenik za kulen, izvjesni K.M. iz Zagreba, dodatno pregledava ishod glasanja. Naime, Europa ne voli kada OPG-ovi razmjenjuju bodove, tj. kada OPG A da X bodova OPG-u B, a OPG B da X bodova OPG-u A. Kada povjerenik otkrije takvu situaciju, glasovi OPG-a A i OPG-a B se brišu i ne broje se u određivanju nove liste najboljih kulena. Njihovi kuleni ostaju na listi, samo se njihovi glasovi brišu.</p>

<p><strong>Pitanje #2</strong>: Odredi i ispiši oznake OPG-ova čiji su kuleni zauzeli prvo, drugo i treće mjesto nakon brisanja bodova OPG-ova koji su razmjenjivali bodove. Ako više kulena ima isti broj bodova, prednost ima onaj s manjom oznakom.</p>



## 입력 형식


<p>U prvom je retku prirodan broj $N$ ($3 ≤ N ≤ 1000$), broj iz teksta zadatka.</p>

<p>U $i$-tom od sljedećih $N$ redaka je $N-1$ prirodnih brojeva $K_j$ ($1 ≤ K_j ≤ N-1$, $K_j ≠ i$), oznake kulena onim redom kako ih je OPG oznake $i$ rangirao.</p>



## 출력 형식


<p>U prvi redak ispiši tražene tri oznake OPG-ova, odgovor na prvo pitanje iz teksta zadatka.</p>

<p>U drugi redak ispiši tražene tri oznake OPG-ova, odgovor na drugo pitanje iz teksta zadatka.</p>



## 예제

### 예제 입력 1

```
3
3 2
3 1
2 1

```

### 예제 출력 1

```
3 2 1
1 2 3

```
          

### 예제 입력 2

```
4
2 3 4
3 4 1
2 4 1
2 1 3

```

### 예제 출력 2

```
2 3 4
2 3 1

```
          

### 예제 입력 3

```
5
5 3 2 4
1 4 5 3
4 2 5 1
3 5 2 1
1 4 3 2

```

### 예제 출력 3

```
4 5 1
1 4 5

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
  