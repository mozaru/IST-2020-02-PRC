/********************************************************************************
** Form generated from reading UI file 'frmMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMMENU_H
#define UI_FRMMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrmMenu
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnInserir;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btnRemover;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btnAlterar;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btnHistorico;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnSair;
    QSpacerItem *horizontalSpacer_10;

    void setupUi(QDialog *FrmMenu)
    {
        if (FrmMenu->objectName().isEmpty())
            FrmMenu->setObjectName(QString::fromUtf8("FrmMenu"));
        FrmMenu->resize(473, 492);
        QFont font;
        font.setPointSize(20);
        FrmMenu->setFont(font);
        verticalLayout_2 = new QVBoxLayout(FrmMenu);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(-1, 50, -1, 50);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnInserir = new QPushButton(FrmMenu);
        btnInserir->setObjectName(QString::fromUtf8("btnInserir"));
        btnInserir->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(btnInserir);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btnRemover = new QPushButton(FrmMenu);
        btnRemover->setObjectName(QString::fromUtf8("btnRemover"));
        btnRemover->setMinimumSize(QSize(200, 0));

        horizontalLayout_2->addWidget(btnRemover);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btnAlterar = new QPushButton(FrmMenu);
        btnAlterar->setObjectName(QString::fromUtf8("btnAlterar"));
        btnAlterar->setMinimumSize(QSize(200, 0));

        horizontalLayout_3->addWidget(btnAlterar);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        btnHistorico = new QPushButton(FrmMenu);
        btnHistorico->setObjectName(QString::fromUtf8("btnHistorico"));
        btnHistorico->setMinimumSize(QSize(200, 0));

        horizontalLayout_4->addWidget(btnHistorico);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_9);

        btnSair = new QPushButton(FrmMenu);
        btnSair->setObjectName(QString::fromUtf8("btnSair"));
        btnSair->setMinimumSize(QSize(200, 0));

        horizontalLayout_5->addWidget(btnSair);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FrmMenu);

        QMetaObject::connectSlotsByName(FrmMenu);
    } // setupUi

    void retranslateUi(QDialog *FrmMenu)
    {
        FrmMenu->setWindowTitle(QCoreApplication::translate("FrmMenu", "FrmMenu", nullptr));
        btnInserir->setText(QCoreApplication::translate("FrmMenu", "Inserir", nullptr));
        btnRemover->setText(QCoreApplication::translate("FrmMenu", "Remover", nullptr));
        btnAlterar->setText(QCoreApplication::translate("FrmMenu", "Alterar", nullptr));
        btnHistorico->setText(QCoreApplication::translate("FrmMenu", "Historico", nullptr));
        btnSair->setText(QCoreApplication::translate("FrmMenu", "Sair", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmMenu: public Ui_FrmMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMMENU_H
