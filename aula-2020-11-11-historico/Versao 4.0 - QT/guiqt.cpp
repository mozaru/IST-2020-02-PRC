#include <stdio.h>
#include <string.h>

#include "disciplinas.h"

#include "frmMenu.h"
#include "frmDisciplina.h"
#include "frmHistorico.h"

#include <QApplication>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>

QApplication *app;

void inicializarInterface(int argc, char*argv[])
{
    app = new QApplication(argc, argv);
}

void finalizarInterface()
{
    //app->exec();
}

void mostrarMensagem(char msg[])
{
    QMessageBox msgBox;
    QFont font = msgBox.font();
    font.setPointSize(20);
    msgBox.setFont(font);
    msgBox.setText(msg);
    msgBox.exec();
}

int lerCodigo()
{
   int cod;
   QInputDialog msgBox;
   QFont font = msgBox.font();
   font.setPointSize(20);
   msgBox.setFont(font);
   msgBox.setLabelText("Entre com o código:");
   msgBox.exec();
   cod = msgBox.textValue().toInt();
   qDebug() << "codigo:" << cod;
   return cod;
}

int menu()
{
    int opc = FrmMenu::Executar();
    qDebug() << "Escolheu " << opc;
    return opc;
}


int lerDisciplina(Disciplina *d)
{
    qDebug() << d->nome;
   return FrmDisciplina::Executar(*d);
}

void mostrarDisciplina(Disciplina d)
{
    qDebug() << d.nome;
    FrmDisciplina::Executar(d, true);
}

void listarHistorico(Historico h)
{
   int i;
   for (i=0; i<h.qtd; i++)
   {
      Disciplina d = h.vet[i];
       qDebug() << d.codigo << "-" << d.nome;
      //printf("%-30s   %02i    %i  %04i %5.2f\n",
      //   d.nome, d.creditos, d.semestre, d.ano, 0);//mediaDisciplina(d));
   }
}

void mostrarHistorico(Historico h)
{
    FrmHistorico::Executar(h);
   //listarHistorico(h);
//   printf("Coeficiente de Rendimento (CR)=%.2f\n", CR(h));
//   pausar();
}
