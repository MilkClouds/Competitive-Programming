# PS Library

이 라이브러리는 MilkClouds가 PS를 하기 위해 개인적으로 만든 PS 라이브러리입니다. 대부분 해당 알고리즘 구현했을 때 "기본적인" 정도의 시간복잡도를 따릅니다.    

fft_conv, dijkstra는 kks227님이 구현하신 소스코드를 변형했습니다.  

+ cpp_base.cpp: C++ 기본 양식
+ combinatorics.cpp: nCr, 팩토리얼, 팩토리얼 인버스, 인버스, 빠른 거듭제곱 계산
+ DSU.cpp: Disjoint Set Union, 서로소 집합 구현  
+ eratos.cpp: 에라토스테네스의 체(N까지의 소수 구하기)  
+ FenwickTree.cpp: 펜윅 트리
+ fft_conv.cpp: FFT와 FFT를 이용한 이산 합성곱    
+ dijkstra.cpp: 최대 거리 구하는 다익스트라(인접 리스트 adj 필요)   
+ scc_graph.cpp: SCC(인접 리스트 adj 필요)  