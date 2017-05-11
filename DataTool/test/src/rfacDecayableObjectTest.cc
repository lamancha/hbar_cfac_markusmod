#include "rfacDecayableObjectTest.hh"

bool rfacDecayableObjectTest::rfacDecayableObject_ConstructsCorrectly_AssertTrue() const
{
  rfacDecayableObject * myDecayableObject = new rfacDecayableObject();
  dynamic_cast<QuantumNumbers*>(myDecayableObject->GetQuantumNumbers())->SetQuantumNumbers(QuantumNumbers(5,3,5,5));
  myDecayableObject->SetStateFile("testsample/sample1.root");
  myDecayableObject->InitializeDecay();
  return true;
}

bool rfacDecayableObjectTest::rfacDecayableObject_DecaysWithoutException_AssertTrue() const
{
  rfacDecayableObject * myDecayableObject = new rfacDecayableObject();
  dynamic_cast<QuantumNumbers*>(myDecayableObject->GetQuantumNumbers())->SetQuantumNumbers(QuantumNumbers(7,1,1,1));
  myDecayableObject->SetStateFile("testsample/sample1.root");
  myDecayableObject->InitializeDecay();
  myDecayableObject->DoStepTime(1E-5); //since this is stocastic, don't check it.
  return true;
}


int rfacDecayableObjectTest::RunTests() const
{
  if(!rfacDecayableObject_ConstructsCorrectly_AssertTrue())
    return 1;
  if(!rfacDecayableObject_DecaysWithoutException_AssertTrue())
    return 2;
  return 0;
}

string rfacDecayableObjectTest::ToString() const
{
  return "rfacDecayableObject"; 
}
