/********************************************************************************
** Form generated from reading UI file 'dropbasket.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROPBASKET_H
#define UI_DROPBASKET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DropBasketClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBox;
    QPushButton *fJoinToServ;
    QTextEdit *textEdit;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *fClientMsg;
    QPushButton *fClientSend;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DropBasketClass)
    {
        if (DropBasketClass->objectName().isEmpty())
            DropBasketClass->setObjectName(QStringLiteral("DropBasketClass"));
        DropBasketClass->resize(621, 482);
        centralWidget = new QWidget(DropBasketClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 50, 211, 31));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(380, 70, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(380, 50, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(510, 50, 47, 13));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(510, 70, 81, 22));
        spinBox->setMinimum(1000);
        spinBox->setMaximum(9999);
        fJoinToServ = new QPushButton(centralWidget);
        fJoinToServ->setObjectName(QStringLiteral("fJoinToServ"));
        fJoinToServ->setGeometry(QRect(380, 100, 211, 31));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 230, 561, 191));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(100, 10, 81, 21));
        QFont font;
        font.setPointSize(16);
        label_3->setFont(font);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(440, 10, 81, 21));
        label_4->setFont(font);
        fClientMsg = new QLineEdit(centralWidget);
        fClientMsg->setObjectName(QStringLiteral("fClientMsg"));
        fClientMsg->setGeometry(QRect(380, 150, 211, 20));
        fClientSend = new QPushButton(centralWidget);
        fClientSend->setObjectName(QStringLiteral("fClientSend"));
        fClientSend->setGeometry(QRect(380, 180, 211, 31));
        DropBasketClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DropBasketClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 621, 21));
        DropBasketClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DropBasketClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DropBasketClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DropBasketClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DropBasketClass->setStatusBar(statusBar);

        retranslateUi(DropBasketClass);

        QMetaObject::connectSlotsByName(DropBasketClass);
    } // setupUi

    void retranslateUi(QMainWindow *DropBasketClass)
    {
        DropBasketClass->setWindowTitle(QApplication::translate("DropBasketClass", "DropBasket", 0));
        pushButton->setText(QApplication::translate("DropBasketClass", "Utw\303\263rz serwer", 0));
        label->setText(QApplication::translate("DropBasketClass", "Host address", 0));
        label_2->setText(QApplication::translate("DropBasketClass", "Port", 0));
        fJoinToServ->setText(QApplication::translate("DropBasketClass", "Do\305\202\304\205cz do serwera", 0));
        label_3->setText(QApplication::translate("DropBasketClass", "SERVER", 0));
        label_4->setText(QApplication::translate("DropBasketClass", "CLIENT", 0));
        fClientSend->setText(QApplication::translate("DropBasketClass", "Do\305\202\304\205cz do serwera", 0));
    } // retranslateUi

};

namespace Ui {
    class DropBasketClass: public Ui_DropBasketClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROPBASKET_H
