#include "StrongFieldQuantumNumberTest.hh"

int StrongFieldQuantumNumberTest::TestCase1() const
{
  StrongFieldQuantumNumbers myQuantumNumbers(5, 3, 2, 1);
  if(!myQuantumNumbers.ValidateConsistency())
	return 1;
  if(myQuantumNumbers.GetN() != 5)
	return 2;
  if(myQuantumNumbers.GetL() != 3)
	return 3;
  if(myQuantumNumbers.GetML() != 2)
	return 4;
  if(myQuantumNumbers.GetTwoMS() != 1)
	return 5;
  myQuantumNumbers.SetN(20);
  myQuantumNumbers.SetL(19);
  myQuantumNumbers.SetML(4);
  myQuantumNumbers.SetTwoMS(-1);
  if(myQuantumNumbers.GetN() != 20)
	return 6;
  if(myQuantumNumbers.GetL() != 19)
	return 7;
  if(myQuantumNumbers.GetML() != 4)
	return 8;
  if(myQuantumNumbers.GetTwoMS() != -1)
	return 9;
  if(!myQuantumNumbers.ValidateConsistency())
	return 10;
  myQuantumNumbers.SetL(22);
  if(myQuantumNumbers.ValidateConsistency())
	return 11;
  myQuantumNumbers.SetL(15);
  myQuantumNumbers.SetML(-15);
  if(!myQuantumNumbers.ValidateConsistency())
	return 12;
  if(myQuantumNumbers.GetML() != -15)
	return 13;
  if(myQuantumNumbers != StrongFieldQuantumNumbers(20, 15, -15, -1))
	return 14;
  myQuantumNumbers.SetStrongFieldQuantumNumbers(StrongFieldQuantumNumbers(1, 0, 0, -1));
  if(!myQuantumNumbers.ValidateConsistency())
	return 15;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 51;
  if(myQuantumNumbers != StrongFieldQuantumNumbers(1, 0, 0, 1))
	return 16;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 52;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(2, 0, 0, -1))
	return 17;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 53;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(2, 0, 0, 1))
	return 18;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 54;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(2, 1, -1, -1))
	return 19;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 55;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(2, 1, -1, 1))
	return 20;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 56;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(2, 1, 0, -1))
	return 21;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 57;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(2, 1, 0, 1))
	return 22;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 58;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(2, 1, 1, -1))
	return 23;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 59;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(2, 1, 1, 1))
	return 24;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 60;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 0, 0, -1))
	return 25;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 61;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 0, 0, 1))
	return 26;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 62;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 1, -1, -1))
	return 27;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 63;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 1, -1, 1))
	return 28;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 64;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 1, 0, -1))
	return 29;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 65;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 1, 0, 1))
	return 30;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 66;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 1, 1, -1))
	return 31;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 67;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 1, 1, 1))
	return 32;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 68;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 2, -2, -1))
	return 33;
  ++myQuantumNumbers;
  if(!myQuantumNumbers.ValidateConsistency())
	return 69;

  if(myQuantumNumbers != StrongFieldQuantumNumbers(3, 2, -2, 1))
	return 34;



  return 0;
}

int StrongFieldQuantumNumberTest::RunTests() const
{
  int retCode;

  retCode = TestCase1();
  if(retCode)
	return retCode;

  return 0;
}

string StrongFieldQuantumNumberTest::ToString() const
{
  return "StrongFieldQuantumNumbers";
}
