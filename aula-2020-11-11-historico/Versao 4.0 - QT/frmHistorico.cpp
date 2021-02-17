#include "frmHistorico.h"
#include "ui_frmhistorico.h"

#include "disciplinas.h"

HistModel::HistModel(QObject *parent)
{
    Q_UNUSED(parent);
}

void HistModel::populateData(Historico *h)
{
    lista = h;
}

int HistModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return lista==NULL ? 0 : lista->qtd;
}

int HistModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 9;
}

QVariant HistModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole || lista==NULL)
        return QVariant();

     Disciplina d = lista->vet[index.row()];
     switch(index.column())
     {
        case 0: return d.codigo;
        case 1: return d.nome;
        case 2: return d.professor;
        case 3: return d.creditos;
        case 4: return d.ano;
        case 5: return d.semestre;
        case 6: return d.nota1;
        case 7: return d.nota2;
        case 8: return mediaDisciplina(d);
        default: return QVariant();
     }
}

QVariant HistModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    const char _NOMES_[][20] = {"Código", "Nome", "Professor", "Créditos", "Ano", "Semestre", "Nota 1", "Nota 2", "Media"};
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            return QString(_NOMES_[section]);
    }
    return QVariant();
}


FrmHistorico::FrmHistorico(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrmHistorico)
{
    ui->setupUi(this);
    connect(ui->btnOk, &QPushButton::clicked, [=](){ close(); });


    ui->tblInfo->setModel(&model);

}

FrmHistorico::~FrmHistorico()
{
    delete ui;
}



void FrmHistorico::Executar(Historico h){
   static FrmHistorico instancia;
   instancia.model.populateData(&h);
   instancia.ui->tblInfo->setModel(NULL);
   instancia.ui->tblInfo->setModel(&instancia.model);
   instancia.ui->tblInfo->resizeColumnsToContents();
   instancia.exec();
}
