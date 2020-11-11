#include <stdlib.h>
#include <stdio.h>
#include <iup.h>

#include "disciplinas.h"

int opcDisc=-1;

int callbackAcaoDisc( Ihandle *self )
{
    char *vl = IupGetAttribute(self, "TITLE");
    if (strcmp(vl,"Ok")==0)
        opcDisc = 1;
    else if (strcmp(vl,"Cancelar")==0)
        opcDisc = 2;
    return IUP_CLOSE;
}

Ihandle *CriarBotaoDisc(char Nome[])
{
  Ihandle *btn = IupButton(Nome, NULL);
  IupSetCallback(btn, "ACTION", (Icallback) callbackAcaoDisc);
  IupSetAttribute(btn, "USERSIZE", "180x60");
  return btn;
}

Ihandle *CriarEntrada(char Nome[], int Qtd, char valor[])
{
  Ihandle *lbl = IupLabel(Nome);
  IupSetAttribute(lbl, "USERSIZE",  "150x");
  Ihandle *txt = IupText(NULL);
  char tam[10];
  sprintf(tam, "%dx", Qtd*20);
  IupSetAttribute(txt, "USERSIZE",  tam);

  IupSetfAttribute(txt, "VALUE",  "%s",valor);

  Ihandle *pnl = IupHbox( lbl,txt, NULL);
//  IupSetAttribute(lbl, "USERSIZE", "180x60");
 // IupSetAttribute(lbl, "USERSIZE", "180x60");

  return pnl;
}

char *ftoa(float vl, char aux[])
{
  sprintf(aux, "%5.2f", vl);
  return aux;
}

int frmDisciplina(Disciplina *d)
{
  Ihandle *dlg, *label, *vbox, *sep, *pnlBotoes, *pnlDados; 
  Ihandle *tbxCodigo,*tbxNome, *tbxCreditos,*tbxSemestre,*tbxAno,*tbxNota1,*tbxNota2,*tbxProfessor;
  char aux[30]; 

  label =  IupLabel("Disciplina");
  IupSetAttribute(label, "BGCOLOR", "0 0 255");
  IupSetAttribute(label, "PADDING", "0x10");
   
  sep = IupFlatSeparator();
  IupSetAttribute(sep, "STYLE", "FILL");
  IupSetAttribute(sep, "ORIENTATION", "HORIZONTAL");
  IupSetAttribute(sep, "COLOR", "0 0 200");

  pnlBotoes = IupHbox(
    CriarBotaoDisc("Ok"),
    CriarBotaoDisc("Cancelar"),
    NULL);
  IupSetAttribute(pnlBotoes, "GAP", "50");
  IupSetAttribute(pnlBotoes, "MARGIN", "0x20");

  pnlDados = IupMultiBox(NULL);
  
  IupAppend(pnlDados, tbxCodigo=CriarEntrada("Codigo", 10, itoa((*d).codigo, aux, 10))); 
  IupAppend(pnlDados, tbxNome=CriarEntrada("Nome", 35, (*d).nome)); 
  IupAppend(pnlDados, tbxCreditos=CriarEntrada("Creditos", 4, itoa((*d).creditos, aux, 10))); 
  IupAppend(pnlDados, tbxSemestre=CriarEntrada("Semestre", 2, itoa((*d).semestre, aux, 10))); 
  IupAppend(pnlDados, tbxAno=CriarEntrada("Ano", 5, itoa((*d).ano, aux, 10))); 
  IupAppend(pnlDados, tbxNota1=CriarEntrada("Nota1", 5, ftoa((*d).nota1, aux))); 
  IupAppend(pnlDados, tbxNota2=CriarEntrada("Nota2", 5, ftoa((*d).nota2, aux))); 
  IupAppend(pnlDados, tbxProfessor=CriarEntrada("Professor", 35,(*d).professor)); 

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

  IupSetAttribute(dlg, "TITLE", "Dados Disciplina");
  IupSetAttribute(dlg, "RESIZE", "YES");
  IupSetAttribute(dlg, "SIZE", NULL);
  IupSetAttribute(dlg, "USERSIZE", "950x540");
  IupSetAttribute(dlg, "FONTSIZE", "25");

  IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

  IupMainLoop();

  if (opcDisc==1)
  {
      (*d).codigo = IupGetInt(tbxCodigo, "VALUE");
      //strcpy((*d).nome,IupGetAttribute(tbxNome, "VALUE"));
      (*d).creditos = IupGetInt(tbxCreditos, "VALUE");
      (*d).semestre = IupGetInt(tbxSemestre, "VALUE");
      (*d).ano = IupGetInt(tbxAno, "VALUE");
      (*d).nota1 = IupGetFloat(tbxNota1, "VALUE");
      (*d).nota2 = IupGetFloat(tbxNota2, "VALUE");
      //strcpy((*d).professor,IupGetAttribute(tbxProfessor, "VALUE"));
      mostrarDisciplina(*d);
      system("pause");
  }
  
  IupDestroy(dlg);
  return opcDisc==1;
}