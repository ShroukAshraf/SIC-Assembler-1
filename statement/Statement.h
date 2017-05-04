//
// Created by Walid on 5/2/2017.
//

#ifndef SIC_ASSEMBLER_STATEMENT_H
#define SIC_ASSEMBLER_STATEMENT_H


#include "Label.h"
#include "Mnemonic.h"
#include "Operand.h"
#include "Comment.h"

class Statement {
public:
    Statement();
    Statement(Label *label, Mnemonic *mnemonic, Operand *operand, Comment *comment);

    bool isComment();
    //int validate(params in pass1ctrl);
    //bool operandIsNewLabel();
    //bool operandHasLabel();

    Label *getLabel() const;

    void setLabel(Label *label);

    Mnemonic *getMnemonic() const;

    void setMnemonic(Mnemonic *mnemonic);

    Operand *getOperand() const;

    void setOperand(Operand *operand);

    Comment *getComment() const;

    void setComment(Comment *comment);

    int getStatementLocationPointer() const;

    void setStatementLocationPointer(int statementLocationPointer);
private:
    Label *label;
    Mnemonic *mnemonic;
    Operand *operand;
    Comment *comment;
    int statementLocationPointer;
};

#endif //SIC_ASSEMBLER_STATEMENT_H
