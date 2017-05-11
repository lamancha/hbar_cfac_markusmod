#ifndef GeneralQuantumNumbers_hh
#define GeneralQuantumNumbers_hh 1

#include <TObject.h>
#include <string>
using namespace std;


class QuantumNumbers;
class GeneralQuantumNumbers;

class GeneralQuantumNumbers
  : public TObject
{
public:
  virtual ~GeneralQuantumNumbers() {};
  virtual unsigned short GetN() const = 0;
  virtual unsigned short GetL() const = 0;
  virtual void SetN(unsigned short value) = 0;
  virtual void SetL(unsigned short value) = 0; 
  virtual string ToString() const = 0;
  virtual GeneralQuantumNumbers * CreateCopy() const = 0;
  virtual bool Equals(const GeneralQuantumNumbers * value) const = 0;
  ClassDef(GeneralQuantumNumbers, 1)
};

#endif
