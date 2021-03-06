//
// Created by Walid on 5/3/2017.
//

#include <iostream>
#include "IntermediateFileWriter.h"
#include "../../datatypes/Hexadecimal.h"

IntermediateFileWriter::IntermediateFileWriter(const std::string &fileName, const std::string fileExtension)
        : fileName(fileName), fileExtension(fileExtension) {
    IntermediateFileWriter::intermediateFileStream.open(std::string(fileName).append(fileExtension));
}

void IntermediateFileWriter::writeInitialLine() {
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;
    intermediateFileStream << StringUtil::fillSpaces("Line", LINE_FORMAT) << StringUtil::fillSpaces("Loc", LOC_FORAMT)
                           << "Source Statement" << std::endl;
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;

}

// Writes line to intermediate file "FIXED FORMAT APPLIED".

void IntermediateFileWriter::writeStatement(int lineNumber, Statement *statement) {
    std::string line = StringUtil::fillSpaces(StringUtil::toString(lineNumber), SPACE_BOUND);
    std::string locationCounter = StringUtil::fillSpaces(
            Hexadecimal::intToHex(statement->getStatementLocationPointer()),
            SPACE_BOUND);
    std::string label = StringUtil::fillSpaces(statement->getLabel()->getLabelField(), LABEL_BOUND);
    std::string mnemonic = StringUtil::fillSpaces(statement->getMnemonic()->getMnemonicField(), MNEMONIC_BOUND);
    std::string operand = StringUtil::fillSpaces(statement->getOperand()->getrawInput(), OPERAND_BOUND);
    std::string comment = statement->getComment()->getComment();
    intermediateFileStream << line << locationCounter << label << mnemonic << operand << comment << std::endl;
}

void IntermediateFileWriter::writeComment(int lineNumber, std::string line) {
    std::string lineNum = StringUtil::fillSpaces(StringUtil::toString(lineNumber), SPACE_BOUND);
    intermediateFileStream << lineNum << line << std::endl;
}


void IntermediateFileWriter::writeSymbolTable(std::map<std::string, int> &symbolTable) {


    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;
    intermediateFileStream << StringUtil::fillSpaces("Symbol", TABLE_BOUND);
    intermediateFileStream << "Assigned Address";
    intermediateFileStream << std::endl;
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;

    // Iterate over the map using iterator
    for (auto curr : symbolTable) {
        intermediateFileStream << StringUtil::fillSpaces(curr.first, TABLE_BOUND)
                               << Hexadecimal::intToHex(curr.second) << std::endl;
    }
}

void IntermediateFileWriter::writeLiteralTable(std::map<std::string, std::pair<Operand *, int>> &literalTable) {
    intermediateFileStream << StringUtil::drawLine(LINE_LENGTH) << std::endl;
    intermediateFileStream << StringUtil::fillSpaces("Literal", TABLE_BOUND)
                           << StringUtil::fillSpaces("Hex Value",TABLE_BOUND)
                           <<StringUtil::fillSpaces("Length",TABLE_BOUND)
                           <<"Address"<<std::endl;

    for (auto literal : literalTable) {
        intermediateFileStream <<StringUtil::fillSpaces(literal.second.first->getrawInput(), TABLE_BOUND);
        intermediateFileStream <<StringUtil::fillSpaces(literal.first, TABLE_BOUND);
        if (literal.second.first->isHexConstant() || literal.second.first->isStringConstant()) {
            intermediateFileStream << StringUtil::fillSpaces(StringUtil::toString(literal.
                    second.first->getLCIncrement()), TABLE_BOUND);
        } else {
            intermediateFileStream << StringUtil::fillSpaces("3", TABLE_BOUND);
        }
        intermediateFileStream << Hexadecimal::intToHex(literal.second.second);
        intermediateFileStream << std::endl;
    }
}

void IntermediateFileWriter::writeError(ErrorHandler::Error error) {
    intermediateFileStream << "ERROR: ";
    intermediateFileStream << ErrorHandler::errors[error] << std::endl;
}

