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
    QPushButton *bTeam1;
    QPushButton *bTeam2;
    QPushButton *pushButton_9;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QLabel *numOfPlayers1;
    QLabel *numOfPlayers2;
    QPushButton *pushButton_11;
    QPushButton *pushButton_7;
    QLabel *label_7;
    QPushButton *pushButton_1;
    QLabel *label_9;
    QLabel *label_10;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ToetictacClass)
    {
        if (ToetictacClass->objectName().isEmpty())
            ToetictacClass->setObjectName(QStringLiteral("ToetictacClass"));
        ToetictacClass->resize(621, 551);
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
        fJoinToServ->setEnabled(false);
        fJoinToServ->setGeometry(QRect(380, 140, 211, 31));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(30, 260, 241, 211));
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
        fClientMsg->setGeometry(QRect(380, 190, 211, 20));
        fClientSend = new QPushButton(centralWidget);
        fClientSend->setObjectName(QStringLiteral("fClientSend"));
        fClientSend->setGeometry(QRect(380, 220, 211, 31));
        fServerMsg = new QLineEdit(centralWidget);
        fServerMsg->setObjectName(QStringLiteral("fServerMsg"));
        fServerMsg->setGeometry(QRect(30, 130, 211, 20));
        fServerSend = new QPushButton(centralWidget);
        fServerSend->setObjectName(QStringLiteral("fServerSend"));
        fServerSend->setGeometry(QRect(30, 160, 211, 31));
        bTeam1 = new QPushButton(centralWidget);
        bTeam1->setObjectName(QStringLiteral("bTeam1"));
        bTeam1->setGeometry(QRect(380, 110, 101, 23));
        bTeam2 = new QPushButton(centralWidget);
        bTeam2->setObjectName(QStringLiteral("bTeam2"));
        bTeam2->setGeometry(QRect(490, 110, 101, 23));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(400, 420, 50, 50));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(310, 290, 141, 20));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(300, 370, 50, 50));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(350, 370, 50, 50));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(400, 370, 50, 50));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(350, 420, 50, 50));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(400, 320, 50, 50));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 320, 50, 50));
        numOfPlayers1 = new QLabel(centralWidget);
        numOfPlayers1->setObjectName(QStringLiteral("numOfPlayers1"));
        numOfPlayers1->setGeometry(QRect(540, 350, 31, 21));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        numOfPlayers1->setFont(font1);
        numOfPlayers2 = new QLabel(centralWidget);
        numOfPlayers2->setObjectName(QStringLiteral("numOfPlayers2"));
        numOfPlayers2->setGeometry(QRect(540, 380, 31, 21));
        numOfPlayers2->setFont(font1);
        pushButton_11 = new QPushButton(centralWidget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(460, 440, 81, 23));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(300, 420, 50, 50));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(460, 350, 71, 21));
        QFont font2;
        font2.setPointSize(14);
        label_7->setFont(font2);
        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setGeometry(QRect(300, 320, 50, 50));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(480, 320, 61, 21));
        label_9->setFont(font2);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(460, 380, 71, 21));
        label_10->setFont(font2);
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
        bTeam1->setText(QApplication::translate("ToetictacClass", "Dru\305\274yna 1", 0));
        bTeam2->setText(QApplication::translate("ToetictacClass", "Dru\305\274yna 2", 0));
        pushButton_9->setText(QString());
        label_5->setText(QApplication::translate("ToetictacClass", "elo", 0));
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_6->setText(QString());
        pushButton_8->setText(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        numOfPlayers1->setText(QApplication::translate("ToetictacClass", "0", 0));
        numOfPlayers2->setText(QApplication::translate("ToetictacClass", "0", 0));
        pushButton_11->setText(QApplication::translate("ToetictacClass", "Restart game", 0));
        pushButton_7->setText(QString());
        label_7->setText(QApplication::translate("ToetictacClass", "Team 1:", 0));
        pushButton_1->setText(QString());
        label_9->setText(QApplication::translate("ToetictacClass", "SCORE", 0));
        label_10->setText(QApplication::translate("ToetictacClass", "Team 2:", 0));
    } // retranslateUi

};

namespace Ui {
    class ToetictacClass: public Ui_ToetictacClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOETICTAC_H
