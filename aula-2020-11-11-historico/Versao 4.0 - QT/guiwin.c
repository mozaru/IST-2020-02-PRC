#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iup.h>
#include <iupcontrols.h>

#include "disciplinas.h"

int opc = -1;
char *ftoa(float vl, char aux[])
{
    sprintf(aux, "%5.2f", vl);
    return aux;
}

void inicializarInterface(int argc, char *argv[])
{
    IupOpen(&argc, &argv);
    IupControlsOpen();
    IupImageLibOpen();
    IupSetGlobal("IMAGESTOCKSIZE","48");
     
}

void finalizarInterface(int argc, char *argv[])
{
    IupClose();
}

int callbackAcao(Ihandle *self)
{
    char *vl = IupGetAttribute(self, "TITLE");
    if (strcmp(vl, "Inserir") == 0 || strcmp(vl, "Ok") == 0 || strcmp(vl, "Fechar") == 0)
        opc = 1;
    else if (strcmp(vl, "Remover") == 0)
        opc = 2;
    else if (strcmp(vl, "Alterar") == 0)
        opc = 3;
    else if (strcmp(vl, "Listar") == 0)
        opc = 4;
    else
        opc = 5;
    return IUP_CLOSE;
}

Ihandle *criarBotaoMenu(char Nome[])
{
    Ihandle *btn = IupButton(Nome, NULL);
    IupSetCallback(btn, "ACTION", (Icallback)callbackAcao);
    IupSetAttribute(btn, "EXPAND", "HORIZONTAL");
    return btn;
}

Ihandle *criarBotaoDlg(char Nome[])
{
    Ihandle *btn = IupButton(Nome, NULL);
    IupSetCallback(btn, "ACTION", (Icallback)callbackAcao);
    IupSetAttribute(btn, "USERSIZE", "180x60");
    return btn;
}

void adicionarAcao(Ihandle* menu, Ihandle* toolBar, char Nome[], char Image[], char tooltip[])
{
    if (toolBar!=NULL) {
        if (Nome == NULL)
            IupAppend(toolBar, IupSetAttributes(IupLabel(NULL), "SEPARATOR=VERTICAL"));
        else {
            Ihandle *btn = IupButton(Nome, NULL);
            IupSetCallback(btn, "ACTION", (Icallback)callbackAcao);
            IupSetAttribute(btn, "USERSIZE", "180x60");
            IupSetAttribute(btn, "FLAT", "Yes");
            //IupSetAttribute(btn, "CANFOCUS", "No")        
            if(Image!=NULL)
                IupSetAttribute(btn, "IMAGE", Image);
            if (tooltip!=NULL)
                IupSetAttribute(btn, "TIP", tooltip);
            IupAppend(toolBar, btn);
        }
    }
    if (menu!=NULL){
        if (Nome==NULL)
           IupAppend(menu, IupSeparator());
        else{
            Ihandle *item = IupSubmenu(Nome,NULL);
            //IupSetCallback(item, "ACTION", (Icallback)callbackAcao);
            IupAppend(menu, item);
            //if(Image!=NULL)
            //    IupSetAttribute(item, "IMAGE", Image);
            //if (tooltip!=NULL)
            //    IupSetAttribute(item, "TIP", tooltip);
        }
    }
}


Ihandle *adicionarEntrada(Ihandle *pnlDados, char Nome[], int Qtd, char valor[])
{
    Ihandle *lbl = IupLabel(Nome);
    IupSetAttribute(lbl, "USERSIZE", "150x");
    Ihandle *txt = IupText(NULL);
    char tam[10];
    sprintf(tam, "%dx", Qtd * 20);
    IupSetAttribute(txt, "USERSIZE", tam);

    IupSetfAttribute(txt, "VALUE", "%s", valor);

    Ihandle *pnl = IupHbox(lbl, txt, NULL);
    //  IupSetAttribute(lbl, "USERSIZE", "180x60");
    // IupSetAttribute(lbl, "USERSIZE", "180x60");
    IupAppend(pnlDados, pnl);
    return txt;
}

int menu()
{
    Ihandle *dlg, *label, *vbox, *sep;
    label = IupLabel("Historico");
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

    IupAppend(vbox, criarBotaoMenu("Inserir"));
    IupAppend(vbox, criarBotaoMenu("Remover"));
    IupAppend(vbox, criarBotaoMenu("Alterar"));
    IupAppend(vbox, criarBotaoMenu("Listar"));
    IupAppend(vbox, criarBotaoMenu("Sair"));

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

int lerCodigo()
{
    Ihandle *dlg, *label, *vbox, *sep, *pnlDados, *pnlBotoes, *msg, *tbxCod;
    label = IupLabel("Codigo");
    IupSetAttribute(label, "BGCOLOR", "0 0 255");
    IupSetAttribute(label, "PADDING", "0x10");

    sep = IupFlatSeparator();
    IupSetAttribute(sep, "STYLE", "FILL");
    IupSetAttribute(sep, "ORIENTATION", "HORIZONTAL");
    IupSetAttribute(sep, "COLOR", "0 0 200");

    msg = IupLabel("Entre com o código");
    IupSetAttribute(label, "PADDING", "0x10");

    pnlBotoes = IupHbox(
        criarBotaoDlg("Ok"),
        criarBotaoDlg("Cancelar"),
        NULL);
    IupSetAttribute(pnlBotoes, "GAP", "50");
    IupSetAttribute(pnlBotoes, "MARGIN", "0x20");

    pnlDados = IupMultiBox(msg,
                           tbxCod = adicionarEntrada(pnlDados, "Codigo", 10, "0"),
                           NULL);

    vbox = IupVbox(
        label,
        sep,
        pnlDados,
        pnlBotoes,
        NULL);
    IupSetAttribute(vbox, "ALIGNMENT", "ACENTER");
    IupSetAttribute(vbox, "GAP", "8");
    IupSetAttribute(vbox, "MARGIN", "40x2");

    dlg = IupDialog(vbox);

    IupSetAttribute(dlg, "TITLE", "Programa de Historico");
    IupSetAttribute(dlg, "RESIZE", "YES");
    IupSetAttribute(dlg, "SIZE", NULL);
    IupSetAttribute(dlg, "USERSIZE", "600x450");
    IupSetAttribute(dlg, "FONTSIZE", "25");

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
    IupMainLoop();

    IupDestroy(dlg);

    return (opc == 1) ? IupGetInt(tbxCod, "VALUE") : -1;
}

void mostrarMensagem(char mensagem[])
{
    Ihandle *dlg, *label, *vbox, *sep, *pnlDados, *pnlBotoes, *msg, *tbxCod;
    label = IupLabel("Aviso");
    IupSetAttribute(label, "BGCOLOR", "0 0 255");
    IupSetAttribute(label, "PADDING", "0x10");

    sep = IupFlatSeparator();
    IupSetAttribute(sep, "STYLE", "FILL");
    IupSetAttribute(sep, "ORIENTATION", "HORIZONTAL");
    IupSetAttribute(sep, "COLOR", "0 0 200");

    msg = IupLabel(mensagem);
    IupSetAttribute(label, "PADDING", "0x10");

    pnlBotoes = IupHbox(
        criarBotaoDlg("Ok"),
        criarBotaoDlg("Cancelar"),
        NULL);
    IupSetAttribute(pnlBotoes, "GAP", "50");
    IupSetAttribute(pnlBotoes, "MARGIN", "0x20");

    pnlDados = IupMultiBox(msg,
                           NULL);

    vbox = IupVbox(
        label,
        sep,
        pnlDados,
        pnlBotoes,
        NULL);
    IupSetAttribute(vbox, "ALIGNMENT", "ACENTER");
    IupSetAttribute(vbox, "GAP", "8");
    IupSetAttribute(vbox, "MARGIN", "40x2");

    dlg = IupDialog(vbox);

    IupSetAttribute(dlg, "TITLE", "Programa de Historico");
    IupSetAttribute(dlg, "RESIZE", "YES");
    IupSetAttribute(dlg, "SIZE", NULL);
    IupSetAttribute(dlg, "USERSIZE", "600x450");
    IupSetAttribute(dlg, "FONTSIZE", "25");

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
    IupMainLoop();

    IupDestroy(dlg);
}


void mostrarDisciplina(Disciplina d)
{
    Ihandle *dlg, *label, *vbox, *sep, *pnlBotoes, *pnlDados;
    Ihandle *tbxCodigo, *tbxNome, *tbxCreditos, *tbxSemestre, *tbxAno, *tbxNota1, *tbxNota2, *tbxProfessor;
    char aux[30];

    label = IupLabel("Disciplina");
    IupSetAttribute(label, "BGCOLOR", "0 0 255");
    IupSetAttribute(label, "PADDING", "0x10");

    sep = IupFlatSeparator();
    IupSetAttribute(sep, "STYLE", "FILL");
    IupSetAttribute(sep, "ORIENTATION", "HORIZONTAL");
    IupSetAttribute(sep, "COLOR", "0 0 200");

    pnlBotoes = IupHbox(
        criarBotaoDlg("Fechar"),
        NULL);
    IupSetAttribute(pnlBotoes, "GAP", "50");
    IupSetAttribute(pnlBotoes, "MARGIN", "0x20");

    pnlDados = IupMultiBox(NULL);

    tbxCodigo = adicionarEntrada(pnlDados, "Codigo", 10, itoa(d.codigo, aux, 10));
    tbxNome = adicionarEntrada(pnlDados, "Nome", 35, d.nome);
    tbxCreditos = adicionarEntrada(pnlDados, "Creditos", 4, itoa(d.creditos, aux, 10));
    tbxSemestre = adicionarEntrada(pnlDados, "Semestre", 2, itoa(d.semestre, aux, 10));
    tbxAno = adicionarEntrada(pnlDados, "Ano", 5, itoa(d.ano, aux, 10));
    tbxNota1 = adicionarEntrada(pnlDados, "Nota1", 5, ftoa(d.nota1, aux));
    tbxNota2 = adicionarEntrada(pnlDados, "Nota2", 5, ftoa(d.nota2, aux));
    tbxProfessor = adicionarEntrada(pnlDados, "Professor", 35, d.professor);

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

    IupDestroy(dlg);
}

int lerDisciplina(Disciplina *d)
{
    Ihandle *dlg, *label, *vbox, *sep, *pnlBotoes, *pnlDados;
    Ihandle *tbxCodigo, *tbxNome, *tbxCreditos, *tbxSemestre, *tbxAno, *tbxNota1, *tbxNota2, *tbxProfessor;
    char aux[30];

    label = IupLabel("Disciplina");
    IupSetAttribute(label, "BGCOLOR", "0 0 255");
    IupSetAttribute(label, "PADDING", "0x10");

    sep = IupFlatSeparator();
    IupSetAttribute(sep, "STYLE", "FILL");
    IupSetAttribute(sep, "ORIENTATION", "HORIZONTAL");
    IupSetAttribute(sep, "COLOR", "0 0 200");

    pnlBotoes = IupHbox(
        criarBotaoDlg("Ok"),
        criarBotaoDlg("Cancelar"),
        NULL);
    IupSetAttribute(pnlBotoes, "GAP", "50");
    IupSetAttribute(pnlBotoes, "MARGIN", "0x20");

    pnlDados = IupMultiBox(NULL);

    tbxCodigo = adicionarEntrada(pnlDados, "Codigo", 10, itoa((*d).codigo, aux, 10));
    tbxNome = adicionarEntrada(pnlDados, "Nome", 35, (*d).nome);
    tbxCreditos = adicionarEntrada(pnlDados, "Creditos", 4, itoa((*d).creditos, aux, 10));
    tbxSemestre = adicionarEntrada(pnlDados, "Semestre", 2, itoa((*d).semestre, aux, 10));
    tbxAno = adicionarEntrada(pnlDados, "Ano", 5, itoa((*d).ano, aux, 10));
    tbxNota1 = adicionarEntrada(pnlDados, "Nota1", 5, ftoa((*d).nota1, aux));
    tbxNota2 = adicionarEntrada(pnlDados, "Nota2", 5, ftoa((*d).nota2, aux));
    tbxProfessor = adicionarEntrada(pnlDados, "Professor", 35, (*d).professor);

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

    if (opc == 1)
    {
        (*d).codigo = IupGetInt(tbxCodigo, "VALUE");
        strcpy((*d).nome, IupGetAttribute(tbxNome, "VALUE"));
        (*d).creditos = IupGetInt(tbxCreditos, "VALUE");
        (*d).semestre = IupGetInt(tbxSemestre, "VALUE");
        (*d).ano = IupGetInt(tbxAno, "VALUE");
        (*d).nota1 = IupGetFloat(tbxNota1, "VALUE");
        (*d).nota2 = IupGetFloat(tbxNota2, "VALUE");
        strcpy((*d).professor, IupGetAttribute(tbxProfessor, "VALUE"));
    }

    IupDestroy(dlg);
    return opc == 1;
}

void mostrarHistorico(Historico h)
{
    Ihandle *dlg, *label, *vbox, *sep, *pnlBotoes, *pnlDados, *menu;
    int i;

    menu = IupMenu(
        IupSubmenu("Teste",NULL)
        ,NULL);
    label = IupLabel("Disciplinas");
    IupSetAttribute(label, "BGCOLOR", "0 0 255");
    IupSetAttribute(label, "PADDING", "0x10");

    sep = IupFlatSeparator();
    IupSetAttribute(sep, "STYLE", "FILL");
    IupSetAttribute(sep, "ORIENTATION", "HORIZONTAL");
    IupSetAttribute(sep, "COLOR", "0 0 200");

    pnlBotoes = IupHbox(NULL);
    IupSetAttribute(pnlBotoes, "GAP", "5");
    //IupSetAttribute(pnlBotoes, "MARGIN", "0x20");
    adicionarAcao(menu, pnlBotoes, "&Filtrar", "IUP_EditFind", "Filtrar a lista de disciplina");
    adicionarAcao(menu, pnlBotoes, "&Inserir", "IUP_FileNew", "Inserir Disciplina");
    adicionarAcao(menu, pnlBotoes, "&Remover", "IUP_EditErase", "Remover a disciplina selecionada");
    adicionarAcao(menu, pnlBotoes, "&Alterar", "IUP_FileProperties", "Alterar a disciplina selecionada");
    adicionarAcao(menu, pnlBotoes, NULL, NULL, NULL);
    adicionarAcao(menu, pnlBotoes, "&Sair", "IUP_ActionCancel", "Sair");
    
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
    IupSetAttribute(pnlDados, "RASTERSIZE", "400x");

    for (i = 1; i <= h.qtd; i++)
    {
        Disciplina d = h.vet[i - 1];
        mostrarDisciplina(d);
        IupSetfAttributeId2(pnlDados, "", i, 0, "%03d", i + 1);
        IupSetIntId2(pnlDados, "", i, 1, d.codigo);
        IupSetfAttributeId2(pnlDados, "", i, 2, "%s", d.nome);
        IupSetfAttributeId2(pnlDados, "", i, 3, d.professor);
        IupSetIntId2(pnlDados, "", i, 4, d.creditos);
        IupSetIntId2(pnlDados, "", i, 5, d.semestre);
        IupSetIntId2(pnlDados, "", i, 6, d.ano);
        IupSetDoubleId2(pnlDados, "", i, 7, 8.25);
        IupSetfAttributeId2(pnlDados, "", i, 7, "%5.2f", d.nota1);
        IupSetfAttributeId2(pnlDados, "", i, 8, "%5.2f", d.nota2);
        IupSetfAttributeId2(pnlDados, "", i, 9, "%5.2f", mediaDisciplina(d));
    }

    vbox = IupVbox(
        label,
        sep,
        pnlBotoes,
        pnlDados,
        NULL);
    IupSetAttribute(vbox, "ALIGNMENT", "ACENTER");
    IupSetAttribute(vbox, "GAP", "1");
    IupSetAttribute(vbox, "MARGIN", "10x2");

    dlg = IupDialog(vbox);
    IupSetAttributeHandle(dlg, "MENU", menu);
    IupSetAttribute(dlg, "TITLE", "Disciplinas1");
    IupSetAttribute(dlg, "RESIZE", "YES");
    IupSetAttribute(dlg, "SIZE", NULL);
    IupSetAttribute(dlg, "USERSIZE", "1800x900");
    IupSetAttribute(dlg, "FONTSIZE", "25");

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

    IupMainLoop();

    IupDestroy(dlg);
}
