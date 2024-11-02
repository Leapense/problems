# 15017번: Best Relay Team

## 문제 설명


<p>You are the coach of the national athletics team and need to select which sprinters should represent your country in the 4 × 100 m relay in the upcoming championships.</p>

<p>As the name of the event implies, such a sprint relay consist of 4 legs, 100 meters each. One would think that the best team would simply consist of the 4 fastest 100 m runners in the nation, but there is an important detail to take into account: flying start. In the 2nd, 3rd and 4th leg, the runner is already running when the baton is handed over. This means that some runners – those that have a slow acceleration phase – can perform relatively better in a relay if they are on the 2nd, 3rd or 4th leg.</p>

<p>You have a pool of runners to choose from. Given how fast each runner in the pool is, decide which four runners should represent your national team and which leg they should run. You are given two times for each runner – the time the runner would run the 1st leg, and the time the runner would run any of the other legs. A runner in a team can only run one leg.</p>



## 입력 형식


<p>The first line of input contains an integer n, the number of runners to choose from (4 ≤ n ≤ 500). Then follow n lines describing the runners. The i’th of these lines contains the name of the i’th runner, the time a<sub>i</sub> for the runner to run the 1st leg, and the time b<sub>i</sub> for the runner to run any of the other legs (8 ≤ b<sub>i</sub> ≤ a<sub>i</sub> &lt; 20). The names consist of between 2 and 20 (inclusive) uppercase letters ‘A’-‘Z’, and no two runners have the same name. The times are given in seconds with exactly two digits after the decimal point.</p>



## 출력 형식


<p>First, output a line containing the time of the best team. The precise formatting of the time is not important. Then output four lines containing the names of the runners in that team. The first of these lines should contain the runner you have picked for the 1st leg, the second line the runner you have picked for the 2nd leg, and so on. Any solution that results in the fastest team is acceptable.</p>



## 예제

### 예제 입력 1

```
6
ASHMEADE 9.90 8.85
BLAKE 9.69 8.72
BOLT 9.58 8.43
CARTER 9.78 8.93
FRATER 9.88 8.92
POWELL 9.72 8.61

```

### 예제 출력 1

```
35.54
CARTER
BOLT
POWELL
BLAKE

```
          

### 예제 입력 2

```
9
AUSTRIN 15.60 14.92
DRANGE 15.14 14.19
DREGI 15.00 14.99
LAAKSONEN 16.39 14.97
LUNDSTROM 15.83 15.35
MARDELL 13.36 13.20
POLACEK 13.05 12.55
SANNEMO 15.23 14.74
SODERMAN 13.99 12.57

```

### 예제 출력 2

```
52.670000
MARDELL
POLACEK
SODERMAN
DRANGE

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
  