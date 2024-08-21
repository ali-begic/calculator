/*
 * Copyright 2024 AliTech Works
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "mainwindow.h"
#include "qevent.h"
#include "ui_mainwindow.h"

#include <muParser.h>
#include <QApplication>
#include <QtCore>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Disabling keyboard input in input field (lineEdit)
    ui->inputField_lineEdit->setReadOnly(true);

    // Setting 0 as the starting value
    ui->inputField_lineEdit->setText("0");

    // Connecting all buttons to the same function
    connect(ui->backspace_pushButton, &QPushButton::clicked, this, &MainWindow::backspace);
    connect(ui->clear_pushButton, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->divide_pushButton, &QPushButton::clicked, this, [=]() { addValue("/"); });
    connect(ui->multiply_pushButton, &QPushButton::clicked, this, [=]() { addValue("*"); });

    connect(ui->button7, &QPushButton::clicked, this, [=]() { addValue("7"); });
    connect(ui->button8, &QPushButton::clicked, this, [=]() { addValue("8"); });
    connect(ui->button9, &QPushButton::clicked, this, [=]() { addValue("9"); });
    connect(ui->substractButton, &QPushButton::clicked, this, [=]() { addValue("-"); });

    connect(ui->button4, &QPushButton::clicked, this, [=]() { addValue("4"); });
    connect(ui->button5, &QPushButton::clicked, this, [=]() { addValue("5"); });
    connect(ui->button6, &QPushButton::clicked, this, [=]() { addValue("6"); });
    connect(ui->addButton, &QPushButton::clicked, this, [=]() { addValue("+"); });

    connect(ui->button1, &QPushButton::clicked, this, [=]() { addValue("1"); });
    connect(ui->button2, &QPushButton::clicked, this, [=]() { addValue("2"); });
    connect(ui->button3, &QPushButton::clicked, this, [=]() { addValue("3"); });
    connect(ui->equal_pushButton, &QPushButton::clicked, this, &MainWindow::equal);

    connect(ui->button0, &QPushButton::clicked, this, [=]() { addValue("0"); });
    connect(ui->point_pushButton, &QPushButton::clicked, this, [=]() { addValue("."); });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Backspace) {
        backspace();
    } else if (event->key() == Qt::Key_Delete) {
        clear();
    } else if (event->key() == Qt::Key_Slash) {
        addValue("/");
    } else if (event->key() == Qt::Key_Asterisk) {
        addValue("*");
    } else if (event->key() == Qt::Key_7) {
        addValue("7");
    } else if (event->key() == Qt::Key_8) {
        addValue("8");
    } else if (event->key() == Qt::Key_9) {
        addValue("9");
    } else if (event->key() == Qt::Key_Minus) {
        addValue("-");
    } else if (event->key() == Qt::Key_4) {
        addValue("4");
    } else if (event->key() == Qt::Key_5) {
        addValue("5");
    } else if (event->key() == Qt::Key_6) {
        addValue("6");
    } else if (event->key() == Qt::Key_Plus) {
        addValue("+");
    } else if (event->key() == Qt::Key_1) {
        addValue("1");
    } else if (event->key() == Qt::Key_2) {
        addValue("2");
    } else if (event->key() == Qt::Key_3) {
        addValue("3");
    } else if (event->key() == Qt::Key_Enter) {
        equal();
    } else if (event->key() == Qt::Key_0) {
        addValue("0");
    } else if (event->key() == Qt::Key_Period) {
        addValue(".");
    }
}

void MainWindow::addValue(QString value) {    
    QString currentValue = ui->inputField_lineEdit->text();
    QStringList operators = {"*", "/", "+", "-", "."};

    if (currentValue == "0" && !operators.contains(value)) {
        ui->inputField_lineEdit->setText("");
        currentValue = ui->inputField_lineEdit->text();
    }

    if (!currentValue.isEmpty()) {
        if (!operators.contains(currentValue.right(1)[0])) {
            // Making number to have only one point
            if (value == '.') {
                bool loopFinished = true;

                for (int i = 1; i < currentValue.length(); i++) {
                    if (operators.contains(currentValue.right(i)[0]) && currentValue.right(i)[0] != '.') {
                        break;
                    } else if (currentValue.right(i)[0] == '.') {
                        loopFinished = false;
                        break;
                    } else {
                        continue;
                    }
                }

                if (loopFinished) {
                    currentValue += value;
                    ui->inputField_lineEdit->setText(currentValue);
                }
            } else {
                currentValue += value;
                ui->inputField_lineEdit->setText(currentValue);
            }
        } else {
            if (!operators.contains(value)) {
                currentValue += value;
                ui->inputField_lineEdit->setText(currentValue);
            }
        }
    } else {
        if (!operators.contains(value) || value == '-') {
            currentValue += value;
            ui->inputField_lineEdit->setText(currentValue);
        }
    }
}

void MainWindow::backspace() {
    QString currentValue = ui->inputField_lineEdit->text();

    if (!currentValue.isEmpty() && currentValue != "0") {
        currentValue.chop(1);

        if (currentValue.length() != 0)
            ui->inputField_lineEdit->setText(currentValue);
        else
            ui->inputField_lineEdit->setText("0");
    }
}

void MainWindow::clear() {
    ui->inputField_lineEdit->setText("0");
}

void MainWindow::equal() {
    // Get the text from the input field (QLineEdit)
    QString expression = ui->inputField_lineEdit->text();

    // Convert QString to std::wstring
    std::wstring expressionStdWString = expression.toStdWString();

    // Convert std::wstring to mu::string_type
    mu::string_type expressionMuString(expressionStdWString.begin(), expressionStdWString.end());

    // Use mu::Parser with mu::string_type
    mu::Parser parser;
    parser.SetExpr(expressionMuString);

    try {
        double result = parser.Eval();

        // Convert the result to a QString
        QString resultString = QString::number(result);

        // Set the result back to the input field (QLineEdit)
        ui->inputField_lineEdit->setText(resultString);
    } catch (mu::Parser::exception_type) {
        qDebug() << "Error evaluating expression";
    }
}
