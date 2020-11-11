gcc -c disciplinas.c -o disciplinas.obj
gcc -c principal.c -o principal.obj

gcc disciplinas.obj principal.obj -o historico.exe

