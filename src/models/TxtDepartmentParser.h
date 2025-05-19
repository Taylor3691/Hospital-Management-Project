#ifndef TXT_DEPARTMENT_PARSER_H
#define TXT_DEPARTMENT_PARSER_H

#include <sstream>
#include "DepartmentParser.h"
#include "Department.h"

class TxtDepartmentParser : public DepartmentParser {
private:
    char _delim;

public:
    TxtDepartmentParser(char delim = '|');

public:
    Object* parse(const std::string& str) const override;
};

#endif // !TXT_DEPARTMENT_PARSER_H
