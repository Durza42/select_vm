rm log.log
touch log.log

gcc -c main.c -o main.o &&
gcc -c loop.c -o loop.o &&
gcc -c app_datas.c -o app_datas.o &&

gcc *.o -o main.elf -lncurses &&

rm *.o #&&

#valgrind ./main.elf &> output.log

