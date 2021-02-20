#ifndef FRMDISCIPLINA_H
#define FRMDISCIPLINA_H

#include <QDialog>
#include"disciplinas.h"

namespace Ui {
class FrmDisciplina;
}

class FrmDisciplina : public QDialog
{
    Q_OBJECT

public:
    explicit FrmDisciplina(QWidget *parent = nullptr);
    ~FrmDisciplina();
    static bool Executar(Disciplina &d, bool readOnly=false);

private:
    Ui::FrmDisciplina *ui;
    void acao(bool confirmar);
    bool confirmou;
    void atualizarTela(Disciplina &d);
    void atualizarObjeto(Disciplina &d);
};

#endif // FRMDISCIPLINA_H
