#ifndef FRMMENU_H
#define FRMMENU_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class FrmMenu; }
QT_END_NAMESPACE

class FrmMenu : public QDialog
{
    Q_OBJECT

public:
    FrmMenu(QWidget *parent = nullptr);
    ~FrmMenu();
    static int Executar();

private:
    Ui::FrmMenu *ui;
    int opc;
    void acao(int opc);
};
#endif // FRMMENU_H
