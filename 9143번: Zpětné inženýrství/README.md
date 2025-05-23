# 9143번: Zpětné inženýrství - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/9143)


<p>Policistům se nedávno podařilo zachytit fragment zdrojového kódu, který si mezi sebou předávaly anarchistické skupiny&nbsp;<em>MCA</em>&nbsp;a&nbsp;<em>MBI</em>. Tento fragment můžete vidět níže, pro přehlednost je kromě původního jazyka (anarchisté používají zásadně&nbsp;<em>C</em>) uveden také přepis do jazyka&nbsp;<em>Pascal</em>.</p>

<pre class="brush:c++;">int main()
{ int u,v,k,t ;
  scanf("%d %d",&amp;u,&amp;v) ;
  for (k=0;!(u%2)&amp;&amp;!(v%2);k++)
    { u/=2 ; v/=2 ; }
  if (u%2) t=-v ; 
  else t=u/2 ;
  while(t) {
    while(!(t%2)) t/=2 ;
    if (t&gt;0) u=t ; else v=-t ;
    t=u-v ; 
  }
  while(k--&gt;0) u*=2 ; 
  printf("%d\n",u) ;
  return 0 ;
}
</pre>

<pre class="brush:pascal;">program zahada;
var u,v,k,t:integer;
begin
  readln(u,v); k:=0;
  while(u mod 2=0)and(v mod 2=0) do
    begin u:=u div 2; v:=v div 2; k:=k+1; end;
  if(u mod 2&lt;&gt;0) then t:=-v
  else t:=u div 2;
  while(t&lt;&gt;0) do begin
    while(t mod 2=0) do t:=t div 2;
    if(t&gt;0) then u:=t else v:=-t;
    t:=u-v;
  end;
  while(k&gt;0) do begin u:=u*2; k:=k-1; end;
  writeln(u:1);
end.
</pre>

<p>Na první pohled je zřejmé, že program čte ze vstupu dvě čísla, pro která spočítá nějaký výsledek. Bohužel se však dosud nepodařilo proniknout do tajů výpočetního procesu, a tak nevíme přesně, jaká je souvislost mezi vstupem a výstupem. Pro přehlednost si však realizovanou funkci označíme jako&nbsp;<var>f</var>. Definičním oborem této funkce bude množina celých kladných čísel. Nechť&nbsp;<var>f</var>(<var>a</var>,<var>b</var>) je hodnota, kterou program vypíše, pokud na jeho vstup zadáme celá čísla&nbsp;<var>a</var>&nbsp;a&nbsp;<var>b</var>. Jestliže program neskončí nebo skončí s&nbsp;chybou, není hodnota&nbsp;<var>f</var>(<var>a</var>,<var>b</var>) pro příslušný vstup definována. Abychom mohli chování funkce lépe sledovat, je třeba vytvořit funkci inverzní, tedy nalézt taková čísla&nbsp;<var>a</var>&nbsp;a&nbsp;<var>b</var>, pro která je&nbsp;<var>f</var>(<var>a</var>,<var>b</var>) rovno předem dané hodnotě.</p>



## 입력


<p>První řádek vstupního souboru obsahuje celé kladné číslo&nbsp;<var>Z</var>, za kterým následuje postupně&nbsp;<var>Z</var>zadání. Každé zadání je tvořeno jediným řádkem obsahujícím dvě celá čísla&nbsp;<var>N</var>&nbsp;a&nbsp;<var>M</var>, 0 &lt;&nbsp;<var>N</var>,<var>M</var>&lt;= 1000000. Čísla jsou oddělena mezerou.</p>



## 출력


<p>Pro každé zadání vypíše program na výstup jediný řádek se dvěma čísly&nbsp;<var>U</var>&nbsp;a&nbsp;<var>V</var>&nbsp;oddělenými mezerou. Tato čísla musí splňovat podmínku 1 &lt;=&nbsp;<var>V</var>&nbsp;&lt;&nbsp;<var>U</var>&nbsp;&lt;&nbsp;<var>N</var>. Jestliže existuje více dvojic vyhovujících zadání, vypište ten případ, kdy je&nbsp;<var>U</var>&nbsp;maximální. Pokud existuje více řešení se stejným maximálním&nbsp;<var>U</var>, vypište to, kdy je maximální&nbsp;<var>V</var>. Jestliže neexistuje žádná dvojice čísel, která by zadání vyhověla, vypište na řádek větu "<code>Reseni neexistuje.</code>".</p>



## 소스코드

[소스코드 보기](Zpětné%20inženýrství.cpp)