
#include <stdexcept>
#include <sstream>
#include <string>

#ifndef EXCEPTION_AST_H
#define EXCEPTION_AST_H


/**
 * An exception that occurs when a reference to an unknown label is found.
 */
class ReferenceError : public std::exception {
  std::string file;
  int line;
  int column;
  std::string reference;

public:
  ReferenceError(const std::string& file, int line, int column, const std::string& reference)
    : file(file), line(line), column(column), reference(reference) { }

  inline std::string getFile() const { return file; }
  inline int getLine() const { return line; }
  inline int getColumn() const { return column; }
  inline std::string getReference() const { return reference; }

  const char* what() const throw() {
    std::stringstream strm;

    strm << "Reference to unknown label in " << file << " at line " << line
      << ", column " << column << ": @" << reference;

    return strm.str().c_str();
  }
};


#endif /* end of include guard: EXCEPTION_AST_H */
