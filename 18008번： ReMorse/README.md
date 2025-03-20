# 18008번: ReMorse - <img src="https://static.solved.ac/tier_small/9.svg" style="height:20px" /> Silver II

<!-- performance -->

<!-- 문제 제출 후 깃허브에 푸시를 했을 때 제출한 코드의 성능이 입력될 공간입니다.-->

<!-- end -->

## 문제

[문제 링크](https://boj.kr/18008)


<p>Morse code is an assignment of sequences of dot and dash symbols to alphabet characters. You are to reassign the sequences of Morse code so that it yields the shortest total length to a given message, and return that total length.</p>

<p>A dot symbol has length 1. A dash symbol has length 3. The gap between symbols within a character encoding has length 1. The gap between character encodings has length 3. Spaces, punctuation, and alphabetic case are ignored, so the text</p>

<p style="text-align: center;"><code><strong>The quick brown dog jumps over the lazy fox.</strong></code></p>

<p>is encoded as though it were</p>

<p style="text-align: center;"><strong><code>THEQUICKBROWNDOGJUMPSOVERTHELAZYFOX</code></strong></p>

<p>For instance, for the input <code><strong>ICPC</strong></code>, the answer is 17. Encode the <code><strong>C</strong></code>s with a single dot, the <code><strong>I</strong></code> with a dash, and the <code><strong>P</strong></code> with two dots, for an encoding of</p>

<p style="text-align: center;"><code>− ∙ ∙∙ ∙</code></p>

<p>which has length (3) + 3 + (1) + 3 + (1 + 1 + 1) + 3 + (1) = 17.</p>



## 입력


<p>The single line of input consists of a string <em>s</em> (1 ≤ |<em>s</em>| ≤ 32000) of upper-case or lower-case letters, spaces, commas, periods, exclamation points, and/or question marks. Everything but the letters should be ignored. The line will contain at least one letter.</p>



## 출력


<p>Output a single integer, which is the length of 𝒔 when encoded with an optimal reassignment of the sequences of Morse code.</p>



## 소스코드

[소스코드 보기](ReMorse.cpp)