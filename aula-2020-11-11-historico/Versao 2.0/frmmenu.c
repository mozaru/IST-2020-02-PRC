#include <stdlib.h>
#include <stdio.h>
#include <iup.h>

int opc=-1;

int callbackAcao( Ihandle *self )
{
    char *vl = IupGetAttribute(self, "TITLE");
    if (strcmp(vl,"Inserir")==0)
        opc=1;
    else if (strcmp(vl,"Remover")==0)
        opc=2;
    else if (strcmp(vl,"Alterar")==0)
        opc=3;
    else if (strcmp(vl,"Listar")==0)
        opc=4;
    else
        opc=5;
    return IUP_CLOSE;
}

Ihandle *CriarBotao(char Nome[])
{
  Ihandle *btn = IupButton(Nome, NULL);
  IupSetCallback(btn, "ACTION", (Icallback) callbackAcao);
  //IupSetAttribute(btn, "USERSIZE", "200x30");
  IupSetAttribute(btn, "EXPAND", "HORIZONTAL");
  //IupSetAttribute(btn, "PADDING", "10x2");
  //IupSetAttribute(btn, "MARGIN", "10x2");
  return btn;
}

int menu()
{
  Ihandle *dlg, *label, *vbox, *sep; 
  label =  IupLabel("Historico");
  IupSetAttribute(label, "BGCOLOR", "0 0 255");
  IupSetAttribute(label, "PADDING", "0x10");
   
  sep = IupFlatSeparator();
  IupSetAttribute(sep, "STYLE", "FILL");
  IupSetAttribute(sep, "ORIENTATION", "HORIZONTAL");
  IupSetAttribute(sep, "COLOR", "0 0 200");

  vbox = IupVbox(
    label,
    sep,
    NULL);
  IupSetAttribute(vbox, "ALIGNMENT", "ACENTER");
  IupSetAttribute(vbox, "GAP", "8");
  IupSetAttribute(vbox, "MARGIN", "40x2");

  IupAppend(vbox, CriarBotao("Inserir")); 
  IupAppend(vbox, CriarBotao("Remover"));
  IupAppend(vbox, CriarBotao("Alterar"));
  IupAppend(vbox, CriarBotao("Listar"));
  IupAppend(vbox, CriarBotao("Sair"));

  dlg = IupDialog(vbox);

  IupSetAttribute(dlg, "TITLE", "Programa de Historico");
  IupSetAttribute(dlg, "RESIZE", "YES");
  IupSetAttribute(dlg, "SIZE", NULL);
  IupSetAttribute(dlg, "USERSIZE", "600x450");
  IupSetAttribute(dlg, "FONTSIZE", "25");

  IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
  IupMainLoop();

  IupDestroy(dlg);
  return opc;
}
