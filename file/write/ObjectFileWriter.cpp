//
// Created by SalmaAhmed on 01/05/2017.
//

#include <fstream>
#include "ObjectFileWriter.h"

// string separator="^";
int fieldLength=6;
ofstream outFile;

string fillSpaces(string word,int size);

string fillZeros(string word,int size);

ObjectFileWriter::ObjectFileWriter(string objectCodeFile) {

    this ->objectCodeFile=objectCodeFile;
    outFile.open (objectCodeFile);
    this->hexadecimalConverter=new Hexadecimal();

}
void ObjectFileWriter::writeHeader(string sourceName, string startAddress,int length) {

    outFile<<"H"<<"^";
    sourceName=fillSpaces(sourceName,fieldLength);
    //write the program name.
    outFile<<sourceName<<"^";
    startAddress=fillZeros(startAddress,fieldLength);
    //write the hexadecimal start address.
    outFile<<startAddress<<"^";
    //convert the length of the program from integer to hexadecimal.
    outFile<<hexadecimalConverter->intToHex(length);

}
void ObjectFileWriter::writeToTextRecord( string objectCode, string recordLength) {


}

void ObjectFileWriter::newTextRecord(string startAddress) {
  outFile<<"\n"<<"T"<<"^"<< ;

}

void ObjectFileWriter::writeModRecord() {

}

void ObjectFileWriter::writeEndRecord(string startAddress) {
    outFile<<"E"<<"^";
    startAddress=fillZeros(startAddress,fieldLength);
    //write address of first executable statement in the program.
    outFile<<startAddress;
    outFile.close();

}

string fillSpaces(string word,int size){
    while(word.length()<size) {
        word+=" ";
    }
    return word;
}
string fillZeros(string word,int size){
    while(word.length()<size) {
        word="0"+word;
    }
    return word;
}