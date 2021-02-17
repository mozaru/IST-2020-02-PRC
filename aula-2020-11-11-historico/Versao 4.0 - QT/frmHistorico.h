#ifndef FRMHISTORICO_H
#define FRMHISTORICO_H

#include <QDialog>
#include <QAbstractTableModel>
#include"disciplinas.h"


namespace Ui {
    class FrmHistorico;
}


class HistModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    HistModel(QObject *parent = 0);

    void populateData(Historico *h);

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

private:
    Historico* lista;
};

class FrmHistorico : public QDialog
{
    Q_OBJECT

public:
    explicit FrmHistorico(QWidget *parent = nullptr);
    ~FrmHistorico();
    static void Executar(Historico h);

private:
    Ui::FrmHistorico *ui;
    HistModel model;
};

#endif // FRMHISTORICO_H
