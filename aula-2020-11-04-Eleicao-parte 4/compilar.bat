mkdir obj
mkdir dist

gcc -c src\alunos.c -Iinclude -o obj\alunos.o
gcc -c src\candidatos.c -Iinclude -o obj\candidatos.o
gcc -c src\eleicao.c -Iinclude -o obj\eleicao.o
gcc -c src\principal.c -Iinclude -o obj\principal.o
gcc -c src\uteis.c -Iinclude -o obj\uteis.o 
gcc -c src\arqtxt.c -Iinclude -o obj\arqtxt.o 

gcc obj\alunos.o obj\candidatos.o obj\eleicao.o obj\principal.o  obj\uteis.o obj\arqtxt.o -o dist\eleicao.exe
