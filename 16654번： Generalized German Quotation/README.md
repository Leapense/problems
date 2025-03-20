# 16654번: Generalized German Quotation - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/16654)


<p>German language uses conventional angular quote marks (‘«’ and ‘»’), so one may quote text in a «conventional» way. What is unconventional in German is that one may also quote text in a »reversed« way. In normal life these styles do not mix, since they are used in different German-speaking countries. But let us have some fun! If we merge these two typographical traditions and forget about rules for nested quotes (that is, if we allow unlimited nesting), we will receive Generalized German rules that allow us to write small quotation masterpieces like this:</p>

<p style="text-align: center;">«»Anf¨uhrungszeichen« means «quote marks» in German»</p>

<p>Informally we will say that a string is a correct quotation if it can be obtained by removing all non-quote characters from a correctly formed Generalized German text. Formally:</p>

<p style="text-align: center;">⟨G⟩ ::= ε | ⟨G⟩⟨G⟩ | ‘«’⟨G⟩‘»’ | ‘»’⟨G⟩‘«’</p>

<p>Thus, a correct quotation is an empty string, a concatenation of two correct quotations, or a correct quotation quoted in either a conventional or a reversed way. In the latter case, we will say that the quote mark to the left of ⟨G⟩ is a starting quote, and the quote mark to the right of ⟨G⟩ is an ending quote. For example, in quotation string ‘«»’ the quote mark ‘«’ is a starting quote, while in string ‘»«’ the same quote mark ‘«’ is an ending quote.</p>

<p>Your task is to check whether the given string is a correct quotation, and if it is, restore its structure — that is, replace all starting quote marks with ‘<code>[</code>’ and all ending quote marks with ‘<code>]</code>’.</p>



## 입력


<p>The first and only line of the input contains a single string with a sequence of quote marks. To limit ourselves to plain ASCII, the quote marks ‘«’ and ‘»’ are encoded as ‘<code>&lt;&lt;</code>’ and ‘<code>&gt;&gt;</code>’, respectively. The string does not contain any other characters. The string is not empty and is not longer than 254 ASCII characters.</p>



## 출력


<p>If the input string is a correct quotation, replace all starting quote marks with ‘<code>[</code>’, all ending quote marks with ‘<code>]</code>’, and output the result. If there is more than one possible solution, output any of them.</p>

<p>If the string is not a correct quotation, output “Keine Loesung”.</p>



## 소스코드

[소스코드 보기](Generalized%20German%20Quotation.cpp)