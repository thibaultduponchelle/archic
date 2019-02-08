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

#gcc -o main_based_on_dynamic_lib_no_missing_symbol main.o -Wl,--unresolved-symbols=ignore-all
#gcc -o main_based_on_dynamic_lib_no_missing_symbol main.o -Wl,--unresolved-symbols=ignore-all -Dfoo=atexit -Dbar=atexit -Dbaz=atexit # Segfault
#gcc -fpic -fpie -o main_based_on_dynamic_lib_no_missing_symbol main.o -Wl,--unresolved-symbols=ignore-all -Dfoo=atexit -Dbar=atexit -Dbaz=atexit
#gcc -o main_based_on_dynamic_lib_no_missing_symbol main.o -Wl,--wrap=foo -Wl,--wrap=bar -Wl,--wrap=baz # Need to know name + define func
#gcc -o main_based_on_dynamic_lib_no_missing_symbol main.o -lfoo -L`pwd` -Wl,--unresolved-symbols=ignore-all # Error while loading shared lib libbar
#gcc -o main_based_on_dynamic_lib main.o
