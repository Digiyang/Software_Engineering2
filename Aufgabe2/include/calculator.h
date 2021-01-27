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

#pragma once

#include <QWidget>
#include "button.h"
#include "engine.h"
#include "calculation.h"

class QLineEdit;

// The given calculator
// Mixes GUI and application logic
class Calculator : public QWidget
{
  Q_OBJECT

public:
  // TODO: Diesen Constructor benutzen und main.cpp entsprechend anpassen
  Calculator(Engine * engine, QWidget *parent = 0);
  // An pointer pointing to an instance of our derived class is passed in the constructor.
  Engine * engine_;

private slots:

  // These are called in reaction to button presses

  void digitClicked();

  void unaryOperatorClicked();

  void binaryOperatorClicked();

  void equalClicked();

  void pointClicked();

  void backspaceClicked();

  void clear();
  void clearAll();
  void clearMemory();
  void readMemory();
  void setMemory();


private:

  Button *createButton(const QString &text, const Operator, const char *member);    // Helper for creating buttons
  void calculateBinaryOperator();   // Does calculations with accumulator and given operand and operator
  void abortOperation();    // Called in case of problems, e.g. division by zero

  bool waitingForOperand_;  // calculator waits for input of a number

  QLineEdit *display_;  // Display of current input

  const static unsigned int NUM_DIGIT_BUTTONS = 10;
  Button *digitButtons_[NUM_DIGIT_BUTTONS]; // The ten digit buttons
};
