gcc -c disciplinas.c -o disciplinas.obj
gcc -c principal.c -o principal.obj

gcc -c frmmenu.c -o frmmenu.obj  
gcc -c frmdisc.c -o frmdisc.obj
rem gcc -c frmlistar.c -o frmlistar.obj

gcc disciplinas.obj principal.obj frmmenu.obj frmdisc.obj -o historico.exe -liupcontrols -liupcd -lcd -lfreetype6 -lz -liup -lgdi32 -lcomdlg32 -lcomctl32 -luuid -loleaut32 -lole32

rem  frmlistar.obj
