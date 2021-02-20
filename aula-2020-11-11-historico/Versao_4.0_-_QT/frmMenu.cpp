#include "frmMenu.h"
#include "ui_frmMenu.h"
#include<QScreen>

FrmMenu::FrmMenu(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FrmMenu)
{
    ui->setupUi(this);
    //connect(ui->btnInserir, &QPushButton::clicked, this, &FrmMenu::acao );
    connect(ui->btnInserir, &QPushButton::clicked, [=](){ acao(1); });
    connect(ui->btnRemover, &QPushButton::clicked, [=](){ acao(2); });
    connect(ui->btnAlterar, &QPushButton::clicked, [=](){ acao(3); });
    connect(ui->btnHistorico, &QPushButton::clicked, [=](){ acao(4); });
    connect(ui->btnSair, &QPushButton::clicked, [=](){ acao(5); });
    #ifdef Q_OS_ANDROID
        QScreen *screen = QApplication::screens().first();
        QRect rec = screen->availableGeometry();
        int height = rec.height();
        int width = rec.width();
        setGeometry(0,0,width, height);
    #endif

}

FrmMenu::~FrmMenu()
{
    delete ui;
}



int FrmMenu::Executar(){
   static FrmMenu instancia;
   instancia.opc = -1;
   instancia.exec();
   return instancia.opc;
}


void FrmMenu::acao(int opc){
    this->opc = opc;
    this->close();
}

