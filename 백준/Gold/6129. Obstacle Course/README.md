# [Gold IV] Obstacle Course - 6129 

[문제 링크](https://www.acmicpc.net/problem/6129) 

### 성능 요약

메모리: 2212 KB, 시간: 0 ms

### 분류

0-1 너비 우선 탐색, 너비 우선 탐색, 데이크스트라, 그래프 이론, 그래프 탐색

### 문제 설명

<p>Consider an N x N (1 <= N <= 100) square field composed of 1 by 1 tiles. Some of these tiles are impassible by cows and are marked with an 'x' in this 5 by 5 field that is challenging to navigate:</p>

<pre>               . . B x .
               . x x A .
               . . . x .
               . x . . .
               . . x . .</pre>

<p>Bessie finds herself in one such field at location A and wants to move to location B in order to lick the salt block there.  Slow, lumbering creatures like cows do not like to turn and, of course, may only move parallel to the edges of the square field. For a given field, determine the minimum number of ninety degree turns in any path from A to B. The path may begin and end with Bessie facing in any direction. Bessie knows she can get to the salt lick.</p>

### 입력 

 <ul>
	<li>Line 1: A single integer: N</li>
	<li>Lines 2..N + 1: Line i+1 represents row i of the field with N characters as above (i.e., '.', 'x', 'A', and 'B'); no spaces are present on a line</li>
</ul>

<p> </p>

### 출력 

 <ul>
	<li>Line 1: A single integer, the minimum number of turns the cow must make in a traversal</li>
</ul>

