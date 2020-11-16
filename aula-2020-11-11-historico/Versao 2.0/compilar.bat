gcc -c disciplinas.c -o disciplinas.obj
gcc -c principal.c -o principal.obj
gcc -c guiconsole.c -o guiconsole.obj
gcc -c guiwin.c -o guiwin.obj

rem gcc -c frmmenu.c -o frmmenu.obj  
rem gcc -c frmdisc.c -o frmdisc.obj
rem gcc -c frmlistar.c -o frmlistar.obj

gcc disciplinas.obj principal.obj guiconsole.obj -o historicoConsole.exe 

gcc disciplinas.obj principal.obj guiwin.obj -o historicoWin.exe -liupcontrols -liupcd -lcd -lfreetype6 -lz -liup -lgdi32 -lcomdlg32 -lcomctl32 -luuid -loleaut32 -lole32
