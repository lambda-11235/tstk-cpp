
#include <map>
#include <string>
#include <vector>

#ifndef AST_H
#define AST_H

typedef long int_type;

enum COMMAND : char {
  ADD, SUB, MUL, DIV,
  JMP, JEQ, JNQ, JGT, JLT,
  GET, SET,
  DUP, POP, PPOS, SIZE, SWAP, DBG,
  PRINT, CPRINT, READ, CREAD
};

/**
 * Stores either an instruction to push an integer or a command.
 */
struct Instruction {
  bool pushInt;

  union {
    int_type n;
    COMMAND com;
  } inst;
};


enum TOKENTYPE : char {LABEL, REFER, INST};

/**
 * Stores either a label with name, a reference to a label with name, or an
 * instruction inst.
 */
struct Token {
  TOKENTYPE type;

  std::string name;
  Instruction inst;
};


/**
 * Replaces all label references with their appropriate addresses, and removes
 * all labels.
 *
 * @param toks The tokens to replace the labels of.
 * @param startAddr The address of the first token in the list.
 *
 * @return The instruction set after all labels have been removed.
 */
std::vector<Instruction> removeLabels(std::vector<Token> toks,
                                      int_type startAddr);

/**
 * Gets a map of the names of labels to the addresses they point to.
 */
std::map<std::string, int_type> labelAddresses(std::vector<Token> toks,
                                               int_type startAddr);

void printInstruction(Instruction inst);
void printInstructions(std::vector<Instruction> insts);
void printTokens(std::vector<Token> toks);

#endif /* AST_H */
