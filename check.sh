#!/usr/bin bash
echo "-compile start-"

# Compile
# javac SortingTest.java
g++ E_Divide_Both.cpp

mkdir -p ./test/mo

start=$SECONDS

echo "-execute your program-"
for i in $(seq 1 10)
do
        # 무한루프를 방지하기 위해 input 당 시간제한 1초
	timeout 30 ./a.exe < ./test/in/$i.txt > ./test/mo/$i.txt
done

# testset의 실행에 소요된 시간
echo "Execution time : $((SECONDS-start)) seconds"

echo "-print wrong answers-"

for i in $(seq 1 10)
do
        #결과가 정답과 다를 경우 그 위치를 출력
        diff -c ./test/mo/$i.txt ./test/out/$i.txt

done
