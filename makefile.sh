rm log.log
touch log.log

gcc -c -Wall main.c -o main.o &&
gcc -c -Wall loop.c -o loop.o &&
gcc -c -Wall app_data.c -o app_data.o &&
gcc -c -Wall events.c -o events.o &&
gcc -c -Wall actions.c -o actions.o &&

gcc  -Wall *.o -o main.elf -lncurses &&

rm *.o #&&

#valgrind ./main.elf &> output.log

