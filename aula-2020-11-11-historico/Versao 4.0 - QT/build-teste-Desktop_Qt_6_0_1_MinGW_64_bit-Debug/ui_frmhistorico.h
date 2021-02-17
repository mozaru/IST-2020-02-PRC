/********************************************************************************
** Form generated from reading UI file 'frmHistorico.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRMHISTORICO_H
#define UI_FRMHISTORICO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FrmHistorico
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *tblInfo;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnOk;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *FrmHistorico)
    {
        if (FrmHistorico->objectName().isEmpty())
            FrmHistorico->setObjectName(QString::fromUtf8("FrmHistorico"));
        FrmHistorico->resize(635, 300);
        QFont font;
        font.setPointSize(20);
        FrmHistorico->setFont(font);
        verticalLayout = new QVBoxLayout(FrmHistorico);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tblInfo = new QTableView(FrmHistorico);
        tblInfo->setObjectName(QString::fromUtf8("tblInfo"));
        tblInfo->setAlternatingRowColors(true);
        tblInfo->setSelectionMode(QAbstractItemView::SingleSelection);
        tblInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
        tblInfo->setSortingEnabled(false);
        tblInfo->horizontalHeader()->setStretchLastSection(false);
        tblInfo->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        tblInfo->verticalHeader()->setStretchLastSection(false);

        verticalLayout->addWidget(tblInfo);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(50, -1, 50, -1);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnOk = new QPushButton(FrmHistorico);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setMinimumSize(QSize(200, 0));

        horizontalLayout->addWidget(btnOk);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(FrmHistorico);

        QMetaObject::connectSlotsByName(FrmHistorico);
    } // setupUi

    void retranslateUi(QDialog *FrmHistorico)
    {
        FrmHistorico->setWindowTitle(QCoreApplication::translate("FrmHistorico", "Dialog", nullptr));
        btnOk->setText(QCoreApplication::translate("FrmHistorico", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FrmHistorico: public Ui_FrmHistorico {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMHISTORICO_H
