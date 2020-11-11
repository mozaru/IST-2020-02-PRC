#include <stdlib.h>
#include <stdio.h>
#include <iup.h>
#include <iupcontrols.h>

int callbackAcao( Ihandle *self )
{
    char *vl = IupGetAttribute(self, "TITLE");
    if (strcmp(vl,"Inserir")==0)
        printf("inserir");
    else if (strcmp(vl,"Remover")==0)
        printf("remover");
    else if (strcmp(vl,"Alterar")==0)
        printf("alterar");
    else if (strcmp(vl,"Listar")==0)
        printf("listar");
    else
        return IUP_CLOSE;
}

Ihandle *CriarBotao(char Nome[])
{
  Ihandle *btn = IupButton(Nome, NULL);
  IupSetCallback(btn, "ACTION", (Icallback) callbackAcao);
  IupSetAttribute(btn, "USERSIZE", "180x60");
  return btn;
}




int main(int argc, char **argv)
{
  Ihandle *dlg, *label, *vbox, *sep, *pnlBotoes, *pnlDados; 
  int i;
  IupOpen(&argc, &argv);
  IupControlsOpen();


  label =  IupLabel("Disciplinas");
  IupSetAttribute(label, "BGCOLOR", "0 0 255");
  IupSetAttribute(label, "PADDING", "0x10");
   
  sep = IupFlatSeparator();
  IupSetAttribute(sep, "STYLE", "FILL");
  IupSetAttribute(sep, "ORIENTATION", "HORIZONTAL");
  IupSetAttribute(sep, "COLOR", "0 0 200");

  pnlBotoes = IupHbox(
    CriarBotao("Ok"),
    CriarBotao("Cancelar"),
    NULL);
  IupSetAttribute(pnlBotoes, "GAP", "50");
  IupSetAttribute(pnlBotoes, "MARGIN", "0x20");

  pnlDados = IupMatrix(NULL);
  
  IupSetAttribute(pnlDados, "NUMLIN", "10"); 
  IupSetAttribute(pnlDados, "NUMCOL", "9"); 
  IupSetAttribute(pnlDados, "RESIZEMATRIX", "YES"); 
  IupSetAttribute(pnlDados, "READONLY", "Yes");
  IupSetAttribute(pnlDados, "MARKMODE", "LIN");
  
  //IupSetAttribute(pnlDados, "NUMLIN_VISIBLE", "10");
  //IupSetAttribute(pnlDados, "NUMCOL_VISIBLE", "8");
//  IupSetAttribute(mat,"EDITNEXT","COLCR");
  IupSetAttribute(pnlDados, "NUMCOL_NOSCROLL", "2");
  //IupSetAttribute(pnlDados, "NUMLIN_NOSCROLL", "1");
  IupSetAttribute(pnlDados, "WIDTHDEF", "20");
  //IupSetAttribute(pnlDados, "MASK*:0", "000");
  IupSetAttribute(pnlDados, "0:1", "Codigo");
  IupSetAttributeId(pnlDados, "WIDTH", 1, "30");
  IupSetAttribute(pnlDados, "0:2", "Nome");
  IupSetAttributeId(pnlDados, "WIDTH", 2, "180");
  IupSetAttributeId(pnlDados, "ALIGNMENT", 2, "ALEFT");
  IupSetAttribute(pnlDados, "0:3", "Professor");
  IupSetAttributeId(pnlDados, "WIDTH", 3, "150");
  IupSetAttributeId(pnlDados, "ALIGNMENT", 3, "ALEFT");
  IupSetAttribute(pnlDados, "0:4", "Cred.");
  IupSetAttribute(pnlDados, "0:5", "Sem.");
  IupSetAttribute(pnlDados, "0:6", "Ano");
  IupSetAttribute(pnlDados, "0:7", "Nota1");
  //IupSetAttribute(pnlDados, "MASKFLOAT2:7", "0.00:10.00");
  IupSetAttribute(pnlDados, "0:8", "Nota2");
  //IupSetAttribute(pnlDados, "MASKFLOAT2:8", "0.00:10.00");
  IupSetAttribute(pnlDados, "0:9", "Media");
  //IupSetAttribute(pnlDados, "MASKFLOAT2:9", "0.00:10.00");
  IupSetAttribute(pnlDados,"RASTERSIZE","400x");
  
  for(i=1;i<10; i++)
  {
        //IupSetIntId2(pnlDados, "", i, 0, i+1);
        IupSetfAttributeId2(pnlDados, "", i, 0, "%03d", i+1);
        IupSetIntId2(pnlDados, "", i, 1, 123*i);
        IupSetAttributeId2(pnlDados, "", i, 2, "Joao");
        IupSetAttributeId2(pnlDados, "", i, 3, "Gerson");
        IupSetIntId2(pnlDados, "", i, 4, 4);
        IupSetIntId2(pnlDados, "", i, 5, 2);
        IupSetIntId2(pnlDados, "", i, 6, 2020);
        //IupSetDoubleId2(pnlDados, "", i, 7, 8.25);
        IupSetfAttributeId2(pnlDados, "", i, 7, "%5.2f", 8.25);
        //IupSetDoubleId2(pnlDados, "", i, 8, 10.00);
        IupSetfAttributeId2(pnlDados, "", i, 8, "%5.2f", 10.00);
        //IupSetDoubleId2(pnlDados, "", i, 9, 9.25);
        IupSetfAttributeId2(pnlDados, "", i, 9, "%5.2f", 9.2);
        
/*  IupSetAttribute(pnlDados, "0:2", "Nome");
  IupSetAttribute(pnlDados, "0:3", "Professor");
  IupSetAttribute(pnlDados, "0:4", "Creditos");
  IupSetAttribute(pnlDados, "0:5", "Sem");
  IupSetAttribute(pnlDados, "0:6", "Ano");
  IupSetAttribute(pnlDados, "0:7", "Nota1");
  IupSetAttribute(pnlDados, "0:8", "Nota2");
  IupSetAttribute(pnlDados, "0:9", "Media");*/
  }



  vbox = IupVbox(
    label,
    sep,
    pnlDados,
    pnlBotoes,
    NULL);
  IupSetAttribute(vbox, "ALIGNMENT", "ACENTER");
  IupSetAttribute(vbox, "GAP", "1");
  IupSetAttribute(vbox, "MARGIN", "10x2");

  dlg = IupDialog(vbox);

  IupSetAttribute(dlg, "TITLE", "Disciplinas");
  IupSetAttribute(dlg, "RESIZE", "YES");
  IupSetAttribute(dlg, "SIZE", NULL);
  IupSetAttribute(dlg, "USERSIZE", "1800x900");
  IupSetAttribute(dlg, "FONTSIZE", "25");

  IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

  IupMainLoop();

  IupClose();
  return EXIT_SUCCESS;
}