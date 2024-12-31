/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPlainTextEdit *history;
    QPushButton *clearBtn;
    QPushButton *OpenBtn;
    QLabel *timeLabel;
    QLabel *label;
    QComboBox *termListComboBox;
    QWidget *cfgWidgt;
    QLineEdit *lineEdit_2;
    QLineEdit *lightIds;
    QPushButton *testBtn_2;
    QPushButton *testBtn;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->setEnabled(true);
        Widget->resize(600, 270);
        history = new QPlainTextEdit(Widget);
        history->setObjectName("history");
        history->setGeometry(QRect(10, 27, 581, 211));
        history->setReadOnly(true);
        clearBtn = new QPushButton(Widget);
        clearBtn->setObjectName("clearBtn");
        clearBtn->setGeometry(QRect(540, 8, 51, 20));
        OpenBtn = new QPushButton(Widget);
        OpenBtn->setObjectName("OpenBtn");
        OpenBtn->setEnabled(true);
        OpenBtn->setGeometry(QRect(10, 240, 81, 20));
        timeLabel = new QLabel(Widget);
        timeLabel->setObjectName("timeLabel");
        timeLabel->setGeometry(QRect(440, 240, 150, 20));
        label = new QLabel(Widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 3, 90, 20));
        termListComboBox = new QComboBox(Widget);
        termListComboBox->setObjectName("termListComboBox");
        termListComboBox->setGeometry(QRect(100, 3, 380, 20));
        cfgWidgt = new QWidget(Widget);
        cfgWidgt->setObjectName("cfgWidgt");
        cfgWidgt->setGeometry(QRect(0, 0, 621, 271));
        cfgWidgt->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(cfgWidgt);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(10, 10, 481, 25));
        lightIds = new QLineEdit(cfgWidgt);
        lightIds->setObjectName("lightIds");
        lightIds->setGeometry(QRect(10, 40, 551, 25));
        testBtn_2 = new QPushButton(cfgWidgt);
        testBtn_2->setObjectName("testBtn_2");
        testBtn_2->setGeometry(QRect(510, 10, 51, 21));
        testBtn = new QPushButton(Widget);
        testBtn->setObjectName("testBtn");
        testBtn->setGeometry(QRect(540, 240, 51, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        clearBtn->setText(QCoreApplication::translate("Widget", "clear", nullptr));
        OpenBtn->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\346\234\215\345\212\241\345\231\250", nullptr));
        timeLabel->setText(QString());
        label->setText(QCoreApplication::translate("Widget", "<html><head/><body><p align=\"center\">\351\237\263\345\223\215\350\256\276\345\244\207\345\210\227\350\241\250</p></body></html>", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("Widget", "Controllers/LightId01", nullptr));
        lightIds->setPlaceholderText(QCoreApplication::translate("Widget", "1-10;254-254", nullptr));
        testBtn_2->setText(QCoreApplication::translate("Widget", "\345\206\231\345\205\245", nullptr));
        testBtn->setText(QCoreApplication::translate("Widget", "\351\205\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
