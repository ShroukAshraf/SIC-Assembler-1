//
// Created by amor2 on 5/2/2017.
//

#ifndef SIC_ASSEMBLER_STATEMENT_H
#define SIC_ASSEMBLER_STATEMENT_H


class Statement {
public:
    Statement(Label *label, Mnemonic *mnemonic, Operand *operand, Comment *comment);

    bool isComment();
    int validate(params in pass1ctrl);
    bool operandIsNewLabel();
    bool operandHasLabel();
    FancyObject *getFancyObject();

private:
    Label *label;
    Mnemonic *mnemonic;
    Operand *operand;
    Comment *comment;

};


#endif //SIC_ASSEMBLER_STATEMENT_H
