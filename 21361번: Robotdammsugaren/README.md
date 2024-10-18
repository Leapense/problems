# 21361번: Robotdammsugaren

## 문제 설명


<p>En robotdammsugare städar i en rutnäts-formad lagerlokal, där tunga lådor ligger på vissa rutor. Dammsugaren styrs av en sekvens av kommandon: upp ("<code>^</code>"), höger ("<code>&gt;</code>"), ned ("<code>v</code>"), vänster ("<code>&lt;</code>"). När roboten får ett kommando åker den så långt den kan i den riktningen tills en låda är i vägen. Varje ruta robotdammsugaren någon gång befinner sig på städas, inklusive rutan den börjar på. Givet hur lagerlokalen ser ut, robotens startposition och en sekvens av kommandon, avgör hur många <strong>olika rutor</strong> som kommer ha städats när sekvensen är klar.</p>



## 입력 형식


<ul>
<li>Den första raden innehåller tre heltal: $R$ ($3 \le R \le 2000$) och $C$ ($3 \le C \le 2000$), antalet rader och kolumner i den rutnäts-formad lagerlokalen, samt $N$ ($1 \le N \le 2000$), längden på kommandosekvensen.</li>
<li>Den andra raden innehåller en $N$ lång sträng bestående av "<code>^</code>", "<code>&gt;</code>","<code>v</code>","<code>&lt;</code>", kommandosekvensen som skickas till roboten.</li>
<li>De följande $R$ raderna utgör en beskrivning av hur den rutnäts-formad lagerlokalen ser ut. Den $i$:te av dessa rader innehåller $C$ tecken som beskriver hur den $i$:te raden ser ut. Varje tecken är antingen en punkt "<code>.</code>" om en ruta är tom, en fyrkant "<code>#</code>" om rutan innehåller en låda eller "<code>O</code>" om rutan är robotens startposition. Det är garanterat att exakt en ruta innehåller "<code>O</code>". Dessutom är det garanterat att alla rutor längst kanten av rutnätet är "<code>#</code>".</li>
</ul>



## 출력 형식


<p>Skriv ut ett heltal -- antalet olika rutor som städas av roboten.</p>



## 예제

### 예제 입력 1

```
5 5 4
v&gt;^v
#####
#O#.#
#...#
##..#
#####

```

### 예제 출력 1

```
6

```
          

### 예제 입력 2

```
6 7 7
&gt;&gt;^&lt;v&gt;&lt;
#######
#.#.#.#
#.....#
#.....#
##O..##
#######

```

### 예제 출력 2

```
12

```
          

### 예제 입력 3

```
3 12 3
&lt;&lt;&lt;
############
#.#.....O.##
############

```

### 예제 출력 3

```
6

```
          

### 예제 입력 4

```
8 10 14
&lt;v&gt;^&lt;v&gt;v&lt;^^&gt;&lt;&gt;
##########
#.#......#
#....#...#
##......O#
#........#
#..#.....#
#....#...#
##########

```

### 예제 출력 4

```
33

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
  