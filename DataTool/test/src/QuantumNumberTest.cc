#include "QuantumNumberTest.hh"

int QuantumNumberTest::TestCase1() const
{
  ///Verify some cases of consistency.
  QuantumNumbers myQuantumNumbers(5, 2, 5, 5);
  if(!myQuantumNumbers.ValidateConsistency())
	return 1;
  if(myQuantumNumbers.GetN() != 5)
	return 2;
  if(myQuantumNumbers.GetL() != 2)
	return 3;
  if(myQuantumNumbers.GetTwoJ() != 5)
	return 4;
  if(myQuantumNumbers.GetTwoMJ() != 5)
	return 5;
  myQuantumNumbers.SetTwoMJ(-3);
  if(myQuantumNumbers.GetTwoMJ() != -3)
	return 6;

  myQuantumNumbers.SetN(20);
  myQuantumNumbers.SetL(19);
  myQuantumNumbers.SetTwoJ(19*2-1);
  if(!myQuantumNumbers.ValidateConsistency())
	return 7;
  if(myQuantumNumbers.GetN() != 20)
	return 8;
  if(myQuantumNumbers.GetL() != 19)
	return 9;
  if(myQuantumNumbers.GetTwoJ() != 2*19-1)
	return 10;
  if(myQuantumNumbers.GetTwoMJ() != -3 )
	return 11;
  myQuantumNumbers.SetTwoMJ(-50);
  if(myQuantumNumbers.ValidateConsistency())
	return 12;
  myQuantumNumbers.SetTwoMJ(-3);
  if(myQuantumNumbers != QuantumNumbers(20, 19, 19*2-1, -3))
	return 13;
  if(++myQuantumNumbers != QuantumNumbers(20, 19, 19*2-1, -1))
	return 14;
  if(myQuantumNumbers == QuantumNumbers(20, 19, 19*2-1, -3))
	return 15;
  myQuantumNumbers.SetQuantumNumbers(QuantumNumbers(1, 0, 1, 1));
  if(myQuantumNumbers != QuantumNumbers(1, 0, 1, 1))
	return 16;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(2, 0, 1, -1))
	return 17;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(2, 0, 1, 1))
	return 18;
  ++myQuantumNumbers;

  if(myQuantumNumbers != QuantumNumbers(2, 1, 1, -1))
	return 19;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(2, 1, 1, 1))
	return 20;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(2, 1, 3, -3))
	return 21;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(2, 1, 3, -1))
	return 22;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(2, 1, 3, 1))
	return 23;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(2, 1, 3, 3))
	return 24;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(3, 0, 1, -1))
	return 25;
  ++myQuantumNumbers;
  if(myQuantumNumbers != QuantumNumbers(3, 0, 1, 1))
	return 26;
  ///and so on...

  return 0;
}

int QuantumNumberTest::RunTests() const
{
  int retCode;

  retCode = TestCase1();
  if(retCode)
	return retCode;
  

  return 0;
}

string QuantumNumberTest::ToString() const
{
  return "QuantumNumbers";
}
