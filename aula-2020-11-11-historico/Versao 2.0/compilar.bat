gcc -c disciplinas.c -o disciplinas.obj 
gcc -c principal.c -o principal.obj 
gcc -c guiconsole.c -o guiconsole.obj 
gcc -c guiwin.c -o guiwin.obj -Iiup/include

gcc disciplinas.obj principal.obj guiconsole.obj -o historicoConsole.exe 

gcc disciplinas.obj principal.obj guiwin.obj -Liup/lib -o historicoWin.exe -liupcontrols -liupcd -lcd -lfreetype6 -lz -liup -lgdi32 -lcomdlg32 -lcomctl32 -luuid -loleaut32 -lole32 
