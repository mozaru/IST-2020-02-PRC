/********************************************************************************
** Form generated from reading UI file 'frmDisciplina.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMDISCIPLINA_H
#define UI_FRMDISCIPLINA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrmDisciplina
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *tbxCodigo;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *tbxNome;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *tbxProfessor;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *tbxCreditos;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QSpinBox *tbxAno_2;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_5;
    QSpinBox *tbxAno;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QDoubleSpinBox *tbxNota1;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_8;
    QDoubleSpinBox *tbxNota2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOk;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnCancelar;

    void setupUi(QDialog *FrmDisciplina)
    {
        if (FrmDisciplina->objectName().isEmpty())
            FrmDisciplina->setObjectName(QString::fromUtf8("FrmDisciplina"));
        FrmDisciplina->resize(749, 328);
        QFont font;
        font.setPointSize(20);
        FrmDisciplina->setFont(font);
        verticalLayout_2 = new QVBoxLayout(FrmDisciplina);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(FrmDisciplina);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        tbxCodigo = new QLineEdit(FrmDisciplina);
        tbxCodigo->setObjectName(QString::fromUtf8("tbxCodigo"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tbxCodigo->sizePolicy().hasHeightForWidth());
        tbxCodigo->setSizePolicy(sizePolicy);
        tbxCodigo->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(tbxCodigo);

        horizontalSpacer_2 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(FrmDisciplina);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        tbxNome = new QLineEdit(FrmDisciplina);
        tbxNome->setObjectName(QString::fromUtf8("tbxNome"));

        horizontalLayout_4->addWidget(tbxNome);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(FrmDisciplina);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        tbxProfessor = new QLineEdit(FrmDisciplina);
        tbxProfessor->setObjectName(QString::fromUtf8("tbxProfessor"));

        horizontalLayout_3->addWidget(tbxProfessor);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(FrmDisciplina);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        tbxCreditos = new QSpinBox(FrmDisciplina);
        tbxCreditos->setObjectName(QString::fromUtf8("tbxCreditos"));
        tbxCreditos->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tbxCreditos->setMinimum(1);
        tbxCreditos->setMaximum(20);

        horizontalLayout_2->addWidget(tbxCreditos);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_6 = new QLabel(FrmDisciplina);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_2->addWidget(label_6);

        tbxAno_2 = new QSpinBox(FrmDisciplina);
        tbxAno_2->setObjectName(QString::fromUtf8("tbxAno_2"));
        tbxAno_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tbxAno_2->setMinimum(1);
        tbxAno_2->setMaximum(2);

        horizontalLayout_2->addWidget(tbxAno_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_5 = new QLabel(FrmDisciplina);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        tbxAno = new QSpinBox(FrmDisciplina);
        tbxAno->setObjectName(QString::fromUtf8("tbxAno"));
        tbxAno->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tbxAno->setMinimum(2010);
        tbxAno->setMaximum(2080);

        horizontalLayout_2->addWidget(tbxAno);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(FrmDisciplina);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        tbxNota1 = new QDoubleSpinBox(FrmDisciplina);
        tbxNota1->setObjectName(QString::fromUtf8("tbxNota1"));
        tbxNota1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tbxNota1->setMaximum(10.000000000000000);

        horizontalLayout_6->addWidget(tbxNota1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        label_8 = new QLabel(FrmDisciplina);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_6->addWidget(label_8);

        tbxNota2 = new QDoubleSpinBox(FrmDisciplina);
        tbxNota2->setObjectName(QString::fromUtf8("tbxNota2"));
        tbxNota2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tbxNota2->setMaximum(10.000000000000000);

        horizontalLayout_6->addWidget(tbxNota2);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, 50, -1);
        btnOk = new QPushButton(FrmDisciplina);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(btnOk);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnCancelar = new QPushButton(FrmDisciplina);
        btnCancelar->setObjectName(QString::fromUtf8("btnCancelar"));
        btnCancelar->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(btnCancelar);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FrmDisciplina);

        QMetaObject::connectSlotsByName(FrmDisciplina);
    } // setupUi

    void retranslateUi(QDialog *FrmDisciplina)
    {
        FrmDisciplina->setWindowTitle(QCoreApplication::translate("FrmDisciplina", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("FrmDisciplina", "C\303\263digo", nullptr));
        label_2->setText(QCoreApplication::translate("FrmDisciplina", "Nome", nullptr));
        label_3->setText(QCoreApplication::translate("FrmDisciplina", "Professor", nullptr));
        label_4->setText(QCoreApplication::translate("FrmDisciplina", "Creditos", nullptr));
        label_6->setText(QCoreApplication::translate("FrmDisciplina", "Semestre", nullptr));
        label_5->setText(QCoreApplication::translate("FrmDisciplina", "Ano", nullptr));
        label_7->setText(QCoreApplication::translate("FrmDisciplina", "Nota 1", nullptr));
        label_8->setText(QCoreApplication::translate("FrmDisciplina", "Nota 2", nullptr));
        btnOk->setText(QCoreApplication::translate("FrmDisciplina", "Ok", nullptr));
        btnCancelar->setText(QCoreApplication::translate("FrmDisciplina", "Cancelar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmDisciplina: public Ui_FrmDisciplina {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMDISCIPLINA_H
