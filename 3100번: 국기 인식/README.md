# 3100번: 국기 인식 - <img src="https://static.solved.ac/tier_small/8.svg" style="height:20px" /> Silver III

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/3100)


<p>희원이는 국기 인식 시스템을 만들었다. 이 알고리즘은 국기를 6*9크기의 행렬로 필터링 시킨 뒤, 인식한다. 행렬에는 색을 나타내는 알파벳 대문자가 있다.</p>

<p>이 시스템은 아직 개발 초기 단계이기 때문에, 아래와 같이 간단한 형태만 인식할 수 있다.</p>

<pre>CCCCCCCCC     CCCCCCCCC     ZZZBBBCCC     ZZZAAAZZZ
CCCCCCCCC     CCCCCCCCC     ZZZBBBCCC     ZZZAAAZZZ
BBBBBBBBB     BBBBBBBBB     ZZZBBBCCC     ZZZAAAZZZ
BBBBBBBBB     BBBBBBBBB     ZZZBBBCCC     ZZZAAAZZZ
PPPPPPPPP     CCCCCCCCC     ZZZBBBCCC     ZZZAAAZZZ
PPPPPPPPP     CCCCCCCCC     ZZZBBBCCC     ZZZAAAZZZ</pre>

<p>즉, 위와 같이 삼등분 된 국기만 인식할 수 있다. 가운데 줄의 색상은 다른 두 줄과는 달라야 한다.</p>

<p>인식한 국기가 주어졌을 때, 간단한 형태가 되기 위해 바꿔야 하는 문자의 최소 개수를 구하는 프로그램을 작성하시오.</p>



## 입력


<p>총 6개줄에 걸쳐 9개 알파벳 대문자가 주어진다.</p>



## 출력


<p>첫째 줄에 간단한 형태가 되기 위해 바꿔야 하는 문자의 최소 개수를 출력한다.</p>



## 소스코드

[소스코드 보기](국기%20인식.py)