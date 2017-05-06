//
// Created by Walid on 5/5/2017.
//

#ifndef SIC_ASSEMBLER_LABELVALIDATIONSTATE_H
#define SIC_ASSEMBLER_LABELVALIDATIONSTATE_H


#include <string>
#include <map>
#include "../statement/Instruction.h"
#include "../directive/Directive.h"

class LabelValidationState {
public:
    void validate(const std::map<std::string, Instruction *> &instructionTable,
//                 const std::map<std::string, Directive *> &directiveTable,
                 const std::map<std::string, int> &symbolTable, const int &start, const int &end,
                 const int &locationCounter, Statement *statement);
};


#endif //SIC_ASSEMBLER_LABELVALIDATIONSTATE_H
