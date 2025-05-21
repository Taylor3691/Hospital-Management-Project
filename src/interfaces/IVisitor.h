#ifndef IVISITOR_H
#define IVISITOR_H

class Doctor;
class Nurse;
class Receptionist;
class Department;
class Patient;

class IVisitor {
public:
    virtual ~IVisitor() = default;
};

#endif // !IVISITOR_H
