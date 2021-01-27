/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************
** Modified by Edzard Hoefig for the SE2 course at Beuth University Berlin.
****************************************************************************/

#include <QtWidgets>

#include "button.h"
#include "calculator.h"

Calculator::Calculator(Engine * engine, QWidget *parent)
  : QWidget(parent), engine_(engine)
{
  // Init state
  waitingForOperand_ = true;

  // Text display
  display_ = new QLineEdit("0");
  display_->setReadOnly(true);
  display_->setAlignment(Qt::AlignRight);
  display_->setMaxLength(15);

  QFont font = display_->font();
  font.setPointSize(font.pointSize() + 8);
  display_->setFont(font);

  // Digit buttons
  for (int i = 0; i < 10; ++i) {
      const Operator type = static_cast<enum Operator>(i);    // Yup, that is ugly but beats a 10-case switch statement.
      digitButtons_[i] = createButton(QString::number(i), type, SLOT(digitClicked()));
  }

  // All other buttons
  Button *pointButton = createButton(tr("."), Operator::tagPOINT, SLOT(pointClicked()));

  Button *backspaceButton = createButton(tr("Backspace"), Operator::BACK, SLOT(backspaceClicked()));
  Button *clearButton = createButton(tr("Clear"), Operator::CLEAR, SLOT(clear()));
  Button *clearAllButton = createButton(tr("Clear All"), Operator::CLEARALL, SLOT(clearAll()));

  Button *clearMemoryButton = createButton(tr("MC"), Operator::MC, SLOT(clearMemory()));
  Button *readMemoryButton = createButton(tr("MR"), Operator::MR, SLOT(readMemory()));
  Button *setMemoryButton = createButton(tr("MS"), Operator::MS, SLOT(setMemory()));

  Button *divisionButton = createButton(tr("\303\267"), Operator::DIV, SLOT(binaryOperatorClicked()));
  Button *multiplicationButton = createButton(tr("\303\227"), Operator::MUL, SLOT(binaryOperatorClicked()));
  Button *minusButton = createButton(tr("-"), Operator::SUB, SLOT(binaryOperatorClicked()));
  Button *plusButton = createButton(tr("+"), Operator::ADD, SLOT(binaryOperatorClicked()));

  Button *squareRootButton = createButton(tr("Sqrt"), Operator::SQRT, SLOT(unaryOperatorClicked()));
  Button *powerButton = createButton(tr("x\302\262"), Operator::SQUARE, SLOT(unaryOperatorClicked()));
  Button *reciprocalButton = createButton(tr("1/x"), Operator::RPROC, SLOT(unaryOperatorClicked()));
  Button *changeSignButton = createButton(tr("\302\261"), Operator::SIGN, SLOT(unaryOperatorClicked()));

  Button *equalButton = createButton(tr("="), Operator::EQ, SLOT(equalClicked()));

  // Layout is done in a 6x6 grid
  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->setSizeConstraint(QLayout::SetFixedSize);
  mainLayout->addWidget(display_, 0, 0, 1, 6);
  mainLayout->addWidget(backspaceButton, 1, 0, 1, 2);
  mainLayout->addWidget(clearButton, 1, 2, 1, 2);
  mainLayout->addWidget(clearAllButton, 1, 4, 1, 2);

  mainLayout->addWidget(clearMemoryButton, 2, 0);
  mainLayout->addWidget(readMemoryButton, 3, 0);
  mainLayout->addWidget(setMemoryButton, 4, 0);

  for (int i = 1; i < 10; ++i) {
      int row = ((9 - i) / 3) + 2;
      int column = ((i - 1) % 3) + 1;
      mainLayout->addWidget(digitButtons_[i], row, column);
  }

  mainLayout->addWidget(pointButton, 5, 3);
  mainLayout->addWidget(digitButtons_[0], 5, 2);
  mainLayout->addWidget(changeSignButton, 5, 1);

  mainLayout->addWidget(divisionButton, 2, 4);
  mainLayout->addWidget(multiplicationButton, 3, 4);
  mainLayout->addWidget(minusButton, 4, 4);
  mainLayout->addWidget(plusButton, 5, 4);

  mainLayout->addWidget(squareRootButton, 2, 5);
  mainLayout->addWidget(powerButton, 3, 5);
  mainLayout->addWidget(reciprocalButton, 4, 5);
  mainLayout->addWidget(equalButton, 5, 5);
  setLayout(mainLayout);

  setWindowTitle(tr("Calculator"));
}

// Add a digit to the input
void Calculator::digitClicked()
{
  Button *clickedButton = qobject_cast<Button *>(sender());
  int digitValue = clickedButton->text().toInt();
  if (display_->text() == "0" && digitValue == 0.0)
      return;

  if (waitingForOperand_) {
      display_->clear();
      waitingForOperand_ = false;
  }
  display_->setText(display_->text() + QString::number(digitValue));
}

// Calculates result for unary operators
void Calculator::unaryOperatorClicked()
{
  Button *clickedButton = qobject_cast<Button *>(sender());
  double operand = display_->text().toDouble();
  display_->setText(QString::number(engine_->evaluateUnary(clickedButton->type(), operand)));
  waitingForOperand_ = true;
  // cases in calculation class
}

// Calculates result for binary operators
void Calculator::calculateBinaryOperator() {

    double operand = display_->text().toDouble();
    display_->setText(QString::number(engine_->evaluateBinary(operand)));
    waitingForOperand_ = true;
    // cases in calculation class
}

// Stores a binary operator for calculation and evaluates if one is already pending
void Calculator::binaryOperatorClicked()
{
    calculateBinaryOperator();

    Button *clickedButton = qobject_cast<Button *>(sender());
    engine_->pending(clickedButton->type());
}

// Evaluates a pending operation and clears the accumulator
void Calculator::equalClicked()
{
  calculateBinaryOperator();


  engine_->clear();
}

// Adds a decimal point to input
void Calculator::pointClicked()
{
  if (waitingForOperand_)
      display_->setText("0");
  if (!display_->text().contains('.'))
      display_->setText(display_->text() + tr("."));
  waitingForOperand_ = false;
}

// Remove last digit from input
void Calculator::backspaceClicked()
{
  if (waitingForOperand_)
      return;

  QString text = display_->text();
  text.chop(1);
  if (text.isEmpty()) {
      text = "0";
      waitingForOperand_ = true;
  }
  display_->setText(text);
}

// Clear input
void Calculator::clear()
{
    if (waitingForOperand_)
      return;

    display_->setText("0");
    waitingForOperand_ = true;
}

// Clear accumulator and input
void Calculator::clearAll() {
  engine_->clear();
  display_->setText("0");
  waitingForOperand_ = true;
}

// Clear memory
void Calculator::clearMemory()
{
  engine_-> clearMemory();
}

// Recall memory into input
void Calculator::readMemory()
{
  display_->setText(QString::number(engine_->memory()));
  waitingForOperand_ = true;
}

// Commit current input to memory
void Calculator::setMemory()
{
  equalClicked();
  engine_->memory(display_->text().toDouble());
}

// Helper for creating standard buttons
Button *Calculator::createButton(const QString &text, const Operator type, const char *member)
{
  Button *button = new Button(text, type);
  connect(button, SIGNAL(clicked()), this, member);
  return button;
}

// Some error condition happened
void Calculator::abortOperation()
{
  clear();
  display_->setText(tr("####"));
}
