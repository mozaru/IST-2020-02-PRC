#include "frmDisciplina.h"
#include "ui_frmDisciplina.h"

FrmDisciplina::FrmDisciplina(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmDisciplina)
{
    ui->setupUi(this);
    connect(ui->btnOk, &QPushButton::clicked, [=](){ acao(true); });
    connect(ui->btnCancelar, &QPushButton::clicked, [=](){ acao(false); });
}

FrmDisciplina::~FrmDisciplina()
{
    delete ui;
}

bool FrmDisciplina::Executar(Disciplina &d, bool readOnly)
{
    static FrmDisciplina instancia;
    instancia.atualizarTela(d);
    instancia.confirmou = false;
    instancia.exec();
    if (instancia.confirmou)
        instancia.atualizarObjeto(d);
    return instancia.confirmou;
}

void FrmDisciplina::acao(bool confirmar)
{
    this->confirmou = confirmar;
    close();
}

void FrmDisciplina::atualizarTela(Disciplina &d)
{
    ui->tbxCodigo->setText(QString::number(d.codigo));
    ui->tbxNome->setText(d.nome);
    ui->tbxProfessor->setText(d.professor);
    ui->tbxAno->setValue(d.ano);
    ui->tbxAno_2->setValue(d.semestre);
    ui->tbxCreditos->setValue(d.creditos);
    ui->tbxNota1->setValue(d.nota1);
    ui->tbxNota2->setValue(d.nota2);
}

void FrmDisciplina::atualizarObjeto(Disciplina &d)
{
    d.codigo = ui->tbxCodigo->text().toInt();
    strcpy(d.nome,ui->tbxNome->text().toStdString().c_str());
    strcpy(d.professor,ui->tbxProfessor->text().toStdString().c_str());
    d.ano = ui->tbxAno->value();
    d.semestre = ui->tbxAno_2->value();
    d.creditos = ui->tbxCreditos->value();
    d.nota1 = ui->tbxNota1->value();
    d.nota2 = ui->tbxNota2->value();
}
