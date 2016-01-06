/********************************************************************************
** Form generated from reading UI file 'toetictac.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOETICTAC_H
#define UI_TOETICTAC_H

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

class Ui_ToetictacClass
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
    QLineEdit *fServerMsg;
    QPushButton *fServerSend;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ToetictacClass)
    {
        if (ToetictacClass->objectName().isEmpty())
            ToetictacClass->setObjectName(QStringLiteral("ToetictacClass"));
        ToetictacClass->resize(621, 482);
        centralWidget = new QWidget(ToetictacClass);
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
        spinBox->setGeometry(QRect(500, 70, 81, 22));
        spinBox->setMinimum(1111);
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
        fServerMsg = new QLineEdit(centralWidget);
        fServerMsg->setObjectName(QStringLiteral("fServerMsg"));
        fServerMsg->setGeometry(QRect(20, 130, 211, 20));
        fServerSend = new QPushButton(centralWidget);
        fServerSend->setObjectName(QStringLiteral("fServerSend"));
        fServerSend->setGeometry(QRect(20, 160, 211, 31));
        ToetictacClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ToetictacClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 621, 21));
        ToetictacClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ToetictacClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ToetictacClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ToetictacClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ToetictacClass->setStatusBar(statusBar);

        retranslateUi(ToetictacClass);

        QMetaObject::connectSlotsByName(ToetictacClass);
    } // setupUi

    void retranslateUi(QMainWindow *ToetictacClass)
    {
        ToetictacClass->setWindowTitle(QApplication::translate("ToetictacClass", "Toetictac", 0));
        pushButton->setText(QApplication::translate("ToetictacClass", "Utw\303\263rz serwer", 0));
        lineEdit->setText(QApplication::translate("ToetictacClass", "localhost", 0));
        label->setText(QApplication::translate("ToetictacClass", "Host address", 0));
        label_2->setText(QApplication::translate("ToetictacClass", "Port", 0));
        fJoinToServ->setText(QApplication::translate("ToetictacClass", "Do\305\202\304\205cz do serwera", 0));
        label_3->setText(QApplication::translate("ToetictacClass", "SERVER", 0));
        label_4->setText(QApplication::translate("ToetictacClass", "CLIENT", 0));
        fClientSend->setText(QApplication::translate("ToetictacClass", "Wy\305\233lij wiadomo\305\233\304\207 do serwera", 0));
        fServerSend->setText(QApplication::translate("ToetictacClass", "Wy\305\233lij wiadomo\305\233\304\207 do klienta", 0));
    } // retranslateUi

};

namespace Ui {
    class ToetictacClass: public Ui_ToetictacClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOETICTAC_H
