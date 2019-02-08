 #!/usr/bin/bash

rm *.a
rm *.o
rm main_based_on_dynamic_lib 
rm main_based_on_static_lib 

gcc -fpic -c far/far/away/baz.c -o far/far/away/baz.o
gcc -shared -o far/far/away/libbaz.so far/far/away/baz.o

gcc -c main.c
gcc -fpic -c foo.c
gcc -shared -o libfoo.so foo.o 
gcc -fpic -c bar.c 
gcc -shared -o libbar.so bar.o 
gcc -o main_based_on_dynamic_lib main.o -lfoo -lbar -L`pwd` -lbaz -L`pwd`/far/far/away
export set LD_LIBRARY_PATH=`pwd`:`pwd`/far/far/away 
./main_based_on_dynamic_lib 


gcc -c foo.c
gcc -c bar.c
gcc -c far/far/away/baz.c -o far/far/away/baz.o
gcc -c main.c
ar -cvq foo.a foo.o 
#a - foo.o
ar -cvq bar.a bar.o
#a - bar.o
ar -cvq far/far/away/baz.a far/far/away/baz.o 
#ar - far/far/away/baz.a
gcc -o main_based_on_static_lib main.o foo.a bar.a far/far/away/baz.a

./main_based_on_static_lib 
#main
#foo
#bar


#tduponchelle@ncepspdev29:~/Code/shared> gcc -o main_o main.o foo.o
#foo.o: In function `foo':
#foo.c:(.text+0x16): undefined reference to `bar'
#collect2: ld returned 1 exit status
#tduponchelle@ncepspdev29:~/Code/shared> 
