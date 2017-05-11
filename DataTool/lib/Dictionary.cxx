// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME libdIDictionary

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "include/EnergyLevel.hh"
#include "include/QuantumNumbers.hh"
#include "include/StrongFieldQuantumNumbers.hh"
#include "include/rfacEssentialData.hh"
#include "include/rfacSpecificLevelData.hh"
#include "include/rfacInterpolatorContainer.hh"
#include "include/rfacQuantumNumberLister.hh"
#include "include/rfacLevelPicker.hh"
#include "include/rfacInterpolation.hh"
#include "include/rfacInterpolatorPicker.hh"
#include "include/rfacException.hh"
#include "include/rfacLinearInterpolation.hh"
#include "include/rfacFieldGridPicker.hh"
#include "include/rfacFieldGridPoint.hh"
#include "include/rfacFieldGridContainer.hh"
#include "include/rfacQuantumNumberContainer.hh"
#include "include/rfacLevelContainer.hh"
#include "include/rfacDecayableObject.hh"
#include "include/rfacFieldRegimeTranslator.hh"
#include "include/GeneralQuantumNumbers.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static void *new_EnergyLevel(void *p = 0);
   static void *newArray_EnergyLevel(Long_t size, void *p);
   static void delete_EnergyLevel(void *p);
   static void deleteArray_EnergyLevel(void *p);
   static void destruct_EnergyLevel(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::EnergyLevel*)
   {
      ::EnergyLevel *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::EnergyLevel >(0);
      static ::ROOT::TGenericClassInfo 
         instance("EnergyLevel", ::EnergyLevel::Class_Version(), "EnergyLevel.hh", 14,
                  typeid(::EnergyLevel), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::EnergyLevel::Dictionary, isa_proxy, 4,
                  sizeof(::EnergyLevel) );
      instance.SetNew(&new_EnergyLevel);
      instance.SetNewArray(&newArray_EnergyLevel);
      instance.SetDelete(&delete_EnergyLevel);
      instance.SetDeleteArray(&deleteArray_EnergyLevel);
      instance.SetDestructor(&destruct_EnergyLevel);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::EnergyLevel*)
   {
      return GenerateInitInstanceLocal((::EnergyLevel*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::EnergyLevel*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_QuantumNumbers(void *p = 0);
   static void *newArray_QuantumNumbers(Long_t size, void *p);
   static void delete_QuantumNumbers(void *p);
   static void deleteArray_QuantumNumbers(void *p);
   static void destruct_QuantumNumbers(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::QuantumNumbers*)
   {
      ::QuantumNumbers *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::QuantumNumbers >(0);
      static ::ROOT::TGenericClassInfo 
         instance("QuantumNumbers", ::QuantumNumbers::Class_Version(), "QuantumNumbers.hh", 22,
                  typeid(::QuantumNumbers), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::QuantumNumbers::Dictionary, isa_proxy, 4,
                  sizeof(::QuantumNumbers) );
      instance.SetNew(&new_QuantumNumbers);
      instance.SetNewArray(&newArray_QuantumNumbers);
      instance.SetDelete(&delete_QuantumNumbers);
      instance.SetDeleteArray(&deleteArray_QuantumNumbers);
      instance.SetDestructor(&destruct_QuantumNumbers);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::QuantumNumbers*)
   {
      return GenerateInitInstanceLocal((::QuantumNumbers*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::QuantumNumbers*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_StrongFieldQuantumNumbers(void *p = 0);
   static void *newArray_StrongFieldQuantumNumbers(Long_t size, void *p);
   static void delete_StrongFieldQuantumNumbers(void *p);
   static void deleteArray_StrongFieldQuantumNumbers(void *p);
   static void destruct_StrongFieldQuantumNumbers(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::StrongFieldQuantumNumbers*)
   {
      ::StrongFieldQuantumNumbers *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::StrongFieldQuantumNumbers >(0);
      static ::ROOT::TGenericClassInfo 
         instance("StrongFieldQuantumNumbers", ::StrongFieldQuantumNumbers::Class_Version(), "StrongFieldQuantumNumbers.hh", 20,
                  typeid(::StrongFieldQuantumNumbers), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::StrongFieldQuantumNumbers::Dictionary, isa_proxy, 4,
                  sizeof(::StrongFieldQuantumNumbers) );
      instance.SetNew(&new_StrongFieldQuantumNumbers);
      instance.SetNewArray(&newArray_StrongFieldQuantumNumbers);
      instance.SetDelete(&delete_StrongFieldQuantumNumbers);
      instance.SetDeleteArray(&deleteArray_StrongFieldQuantumNumbers);
      instance.SetDestructor(&destruct_StrongFieldQuantumNumbers);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::StrongFieldQuantumNumbers*)
   {
      return GenerateInitInstanceLocal((::StrongFieldQuantumNumbers*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::StrongFieldQuantumNumbers*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacEssentialData(void *p = 0);
   static void *newArray_rfacEssentialData(Long_t size, void *p);
   static void delete_rfacEssentialData(void *p);
   static void deleteArray_rfacEssentialData(void *p);
   static void destruct_rfacEssentialData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacEssentialData*)
   {
      ::rfacEssentialData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacEssentialData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacEssentialData", ::rfacEssentialData::Class_Version(), "rfacEssentialData.hh", 16,
                  typeid(::rfacEssentialData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacEssentialData::Dictionary, isa_proxy, 4,
                  sizeof(::rfacEssentialData) );
      instance.SetNew(&new_rfacEssentialData);
      instance.SetNewArray(&newArray_rfacEssentialData);
      instance.SetDelete(&delete_rfacEssentialData);
      instance.SetDeleteArray(&deleteArray_rfacEssentialData);
      instance.SetDestructor(&destruct_rfacEssentialData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacEssentialData*)
   {
      return GenerateInitInstanceLocal((::rfacEssentialData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacEssentialData*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacSpecificLevelData(void *p = 0);
   static void *newArray_rfacSpecificLevelData(Long_t size, void *p);
   static void delete_rfacSpecificLevelData(void *p);
   static void deleteArray_rfacSpecificLevelData(void *p);
   static void destruct_rfacSpecificLevelData(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacSpecificLevelData*)
   {
      ::rfacSpecificLevelData *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacSpecificLevelData >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacSpecificLevelData", ::rfacSpecificLevelData::Class_Version(), "rfacSpecificLevelData.hh", 16,
                  typeid(::rfacSpecificLevelData), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacSpecificLevelData::Dictionary, isa_proxy, 4,
                  sizeof(::rfacSpecificLevelData) );
      instance.SetNew(&new_rfacSpecificLevelData);
      instance.SetNewArray(&newArray_rfacSpecificLevelData);
      instance.SetDelete(&delete_rfacSpecificLevelData);
      instance.SetDeleteArray(&deleteArray_rfacSpecificLevelData);
      instance.SetDestructor(&destruct_rfacSpecificLevelData);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacSpecificLevelData*)
   {
      return GenerateInitInstanceLocal((::rfacSpecificLevelData*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacSpecificLevelData*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacQuantumNumberLister(void *p = 0);
   static void *newArray_rfacQuantumNumberLister(Long_t size, void *p);
   static void delete_rfacQuantumNumberLister(void *p);
   static void deleteArray_rfacQuantumNumberLister(void *p);
   static void destruct_rfacQuantumNumberLister(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacQuantumNumberLister*)
   {
      ::rfacQuantumNumberLister *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacQuantumNumberLister >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacQuantumNumberLister", ::rfacQuantumNumberLister::Class_Version(), "rfacQuantumNumberLister.hh", 25,
                  typeid(::rfacQuantumNumberLister), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacQuantumNumberLister::Dictionary, isa_proxy, 4,
                  sizeof(::rfacQuantumNumberLister) );
      instance.SetNew(&new_rfacQuantumNumberLister);
      instance.SetNewArray(&newArray_rfacQuantumNumberLister);
      instance.SetDelete(&delete_rfacQuantumNumberLister);
      instance.SetDeleteArray(&deleteArray_rfacQuantumNumberLister);
      instance.SetDestructor(&destruct_rfacQuantumNumberLister);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacQuantumNumberLister*)
   {
      return GenerateInitInstanceLocal((::rfacQuantumNumberLister*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacQuantumNumberLister*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacLevelPicker(void *p = 0);
   static void *newArray_rfacLevelPicker(Long_t size, void *p);
   static void delete_rfacLevelPicker(void *p);
   static void deleteArray_rfacLevelPicker(void *p);
   static void destruct_rfacLevelPicker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacLevelPicker*)
   {
      ::rfacLevelPicker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacLevelPicker >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacLevelPicker", ::rfacLevelPicker::Class_Version(), "rfacLevelPicker.hh", 23,
                  typeid(::rfacLevelPicker), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacLevelPicker::Dictionary, isa_proxy, 4,
                  sizeof(::rfacLevelPicker) );
      instance.SetNew(&new_rfacLevelPicker);
      instance.SetNewArray(&newArray_rfacLevelPicker);
      instance.SetDelete(&delete_rfacLevelPicker);
      instance.SetDeleteArray(&deleteArray_rfacLevelPicker);
      instance.SetDestructor(&destruct_rfacLevelPicker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacLevelPicker*)
   {
      return GenerateInitInstanceLocal((::rfacLevelPicker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacLevelPicker*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacException(void *p = 0);
   static void *newArray_rfacException(Long_t size, void *p);
   static void delete_rfacException(void *p);
   static void deleteArray_rfacException(void *p);
   static void destruct_rfacException(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacException*)
   {
      ::rfacException *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacException >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacException", ::rfacException::Class_Version(), "rfacException.hh", 11,
                  typeid(::rfacException), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacException::Dictionary, isa_proxy, 4,
                  sizeof(::rfacException) );
      instance.SetNew(&new_rfacException);
      instance.SetNewArray(&newArray_rfacException);
      instance.SetDelete(&delete_rfacException);
      instance.SetDeleteArray(&deleteArray_rfacException);
      instance.SetDestructor(&destruct_rfacException);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacException*)
   {
      return GenerateInitInstanceLocal((::rfacException*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacException*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacInterpolation(void *p = 0);
   static void *newArray_rfacInterpolation(Long_t size, void *p);
   static void delete_rfacInterpolation(void *p);
   static void deleteArray_rfacInterpolation(void *p);
   static void destruct_rfacInterpolation(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacInterpolation*)
   {
      ::rfacInterpolation *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacInterpolation >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacInterpolation", ::rfacInterpolation::Class_Version(), "rfacInterpolation.hh", 40,
                  typeid(::rfacInterpolation), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacInterpolation::Dictionary, isa_proxy, 4,
                  sizeof(::rfacInterpolation) );
      instance.SetNew(&new_rfacInterpolation);
      instance.SetNewArray(&newArray_rfacInterpolation);
      instance.SetDelete(&delete_rfacInterpolation);
      instance.SetDeleteArray(&deleteArray_rfacInterpolation);
      instance.SetDestructor(&destruct_rfacInterpolation);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacInterpolation*)
   {
      return GenerateInitInstanceLocal((::rfacInterpolation*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacInterpolation*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfac3DInterpolation(void *p = 0);
   static void *newArray_rfac3DInterpolation(Long_t size, void *p);
   static void delete_rfac3DInterpolation(void *p);
   static void deleteArray_rfac3DInterpolation(void *p);
   static void destruct_rfac3DInterpolation(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfac3DInterpolation*)
   {
      ::rfac3DInterpolation *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfac3DInterpolation >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfac3DInterpolation", ::rfac3DInterpolation::Class_Version(), "rfac3DInterpolation.hh", 22,
                  typeid(::rfac3DInterpolation), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfac3DInterpolation::Dictionary, isa_proxy, 4,
                  sizeof(::rfac3DInterpolation) );
      instance.SetNew(&new_rfac3DInterpolation);
      instance.SetNewArray(&newArray_rfac3DInterpolation);
      instance.SetDelete(&delete_rfac3DInterpolation);
      instance.SetDeleteArray(&deleteArray_rfac3DInterpolation);
      instance.SetDestructor(&destruct_rfac3DInterpolation);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfac3DInterpolation*)
   {
      return GenerateInitInstanceLocal((::rfac3DInterpolation*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfac3DInterpolation*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_Quadruple(void *p = 0);
   static void *newArray_Quadruple(Long_t size, void *p);
   static void delete_Quadruple(void *p);
   static void deleteArray_Quadruple(void *p);
   static void destruct_Quadruple(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Quadruple*)
   {
      ::Quadruple *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::Quadruple >(0);
      static ::ROOT::TGenericClassInfo 
         instance("Quadruple", ::Quadruple::Class_Version(), "Quadruple.hh", 12,
                  typeid(::Quadruple), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::Quadruple::Dictionary, isa_proxy, 4,
                  sizeof(::Quadruple) );
      instance.SetNew(&new_Quadruple);
      instance.SetNewArray(&newArray_Quadruple);
      instance.SetDelete(&delete_Quadruple);
      instance.SetDeleteArray(&deleteArray_Quadruple);
      instance.SetDestructor(&destruct_Quadruple);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Quadruple*)
   {
      return GenerateInitInstanceLocal((::Quadruple*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::Quadruple*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacInterpolatorContainer(void *p = 0);
   static void *newArray_rfacInterpolatorContainer(Long_t size, void *p);
   static void delete_rfacInterpolatorContainer(void *p);
   static void deleteArray_rfacInterpolatorContainer(void *p);
   static void destruct_rfacInterpolatorContainer(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacInterpolatorContainer*)
   {
      ::rfacInterpolatorContainer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacInterpolatorContainer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacInterpolatorContainer", ::rfacInterpolatorContainer::Class_Version(), "rfacInterpolatorContainer.hh", 28,
                  typeid(::rfacInterpolatorContainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacInterpolatorContainer::Dictionary, isa_proxy, 4,
                  sizeof(::rfacInterpolatorContainer) );
      instance.SetNew(&new_rfacInterpolatorContainer);
      instance.SetNewArray(&newArray_rfacInterpolatorContainer);
      instance.SetDelete(&delete_rfacInterpolatorContainer);
      instance.SetDeleteArray(&deleteArray_rfacInterpolatorContainer);
      instance.SetDestructor(&destruct_rfacInterpolatorContainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacInterpolatorContainer*)
   {
      return GenerateInitInstanceLocal((::rfacInterpolatorContainer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacInterpolatorContainer*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacInterpolatorPicker(void *p = 0);
   static void *newArray_rfacInterpolatorPicker(Long_t size, void *p);
   static void delete_rfacInterpolatorPicker(void *p);
   static void deleteArray_rfacInterpolatorPicker(void *p);
   static void destruct_rfacInterpolatorPicker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacInterpolatorPicker*)
   {
      ::rfacInterpolatorPicker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacInterpolatorPicker >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacInterpolatorPicker", ::rfacInterpolatorPicker::Class_Version(), "rfacInterpolatorPicker.hh", 27,
                  typeid(::rfacInterpolatorPicker), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacInterpolatorPicker::Dictionary, isa_proxy, 4,
                  sizeof(::rfacInterpolatorPicker) );
      instance.SetNew(&new_rfacInterpolatorPicker);
      instance.SetNewArray(&newArray_rfacInterpolatorPicker);
      instance.SetDelete(&delete_rfacInterpolatorPicker);
      instance.SetDeleteArray(&deleteArray_rfacInterpolatorPicker);
      instance.SetDestructor(&destruct_rfacInterpolatorPicker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacInterpolatorPicker*)
   {
      return GenerateInitInstanceLocal((::rfacInterpolatorPicker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacInterpolatorPicker*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacLinearInterpolation(void *p = 0);
   static void *newArray_rfacLinearInterpolation(Long_t size, void *p);
   static void delete_rfacLinearInterpolation(void *p);
   static void deleteArray_rfacLinearInterpolation(void *p);
   static void destruct_rfacLinearInterpolation(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacLinearInterpolation*)
   {
      ::rfacLinearInterpolation *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacLinearInterpolation >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacLinearInterpolation", ::rfacLinearInterpolation::Class_Version(), "rfacLinearInterpolation.hh", 22,
                  typeid(::rfacLinearInterpolation), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacLinearInterpolation::Dictionary, isa_proxy, 4,
                  sizeof(::rfacLinearInterpolation) );
      instance.SetNew(&new_rfacLinearInterpolation);
      instance.SetNewArray(&newArray_rfacLinearInterpolation);
      instance.SetDelete(&delete_rfacLinearInterpolation);
      instance.SetDeleteArray(&deleteArray_rfacLinearInterpolation);
      instance.SetDestructor(&destruct_rfacLinearInterpolation);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacLinearInterpolation*)
   {
      return GenerateInitInstanceLocal((::rfacLinearInterpolation*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacLinearInterpolation*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacFieldGridPicker(void *p = 0);
   static void *newArray_rfacFieldGridPicker(Long_t size, void *p);
   static void delete_rfacFieldGridPicker(void *p);
   static void deleteArray_rfacFieldGridPicker(void *p);
   static void destruct_rfacFieldGridPicker(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacFieldGridPicker*)
   {
      ::rfacFieldGridPicker *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacFieldGridPicker >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacFieldGridPicker", ::rfacFieldGridPicker::Class_Version(), "rfacFieldGridPicker.hh", 25,
                  typeid(::rfacFieldGridPicker), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacFieldGridPicker::Dictionary, isa_proxy, 4,
                  sizeof(::rfacFieldGridPicker) );
      instance.SetNew(&new_rfacFieldGridPicker);
      instance.SetNewArray(&newArray_rfacFieldGridPicker);
      instance.SetDelete(&delete_rfacFieldGridPicker);
      instance.SetDeleteArray(&deleteArray_rfacFieldGridPicker);
      instance.SetDestructor(&destruct_rfacFieldGridPicker);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacFieldGridPicker*)
   {
      return GenerateInitInstanceLocal((::rfacFieldGridPicker*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacFieldGridPicker*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacFieldGridPoint(void *p = 0);
   static void *newArray_rfacFieldGridPoint(Long_t size, void *p);
   static void delete_rfacFieldGridPoint(void *p);
   static void deleteArray_rfacFieldGridPoint(void *p);
   static void destruct_rfacFieldGridPoint(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacFieldGridPoint*)
   {
      ::rfacFieldGridPoint *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacFieldGridPoint >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacFieldGridPoint", ::rfacFieldGridPoint::Class_Version(), "rfacFieldGridPoint.hh", 17,
                  typeid(::rfacFieldGridPoint), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacFieldGridPoint::Dictionary, isa_proxy, 4,
                  sizeof(::rfacFieldGridPoint) );
      instance.SetNew(&new_rfacFieldGridPoint);
      instance.SetNewArray(&newArray_rfacFieldGridPoint);
      instance.SetDelete(&delete_rfacFieldGridPoint);
      instance.SetDeleteArray(&deleteArray_rfacFieldGridPoint);
      instance.SetDestructor(&destruct_rfacFieldGridPoint);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacFieldGridPoint*)
   {
      return GenerateInitInstanceLocal((::rfacFieldGridPoint*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacFieldGridPoint*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacFieldGridContainer(void *p = 0);
   static void *newArray_rfacFieldGridContainer(Long_t size, void *p);
   static void delete_rfacFieldGridContainer(void *p);
   static void deleteArray_rfacFieldGridContainer(void *p);
   static void destruct_rfacFieldGridContainer(void *p);
   static Long64_t merge_rfacFieldGridContainer(void *obj, TCollection *coll,TFileMergeInfo *info);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacFieldGridContainer*)
   {
      ::rfacFieldGridContainer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacFieldGridContainer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacFieldGridContainer", ::rfacFieldGridContainer::Class_Version(), "rfacFieldGridContainer.hh", 19,
                  typeid(::rfacFieldGridContainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacFieldGridContainer::Dictionary, isa_proxy, 4,
                  sizeof(::rfacFieldGridContainer) );
      instance.SetNew(&new_rfacFieldGridContainer);
      instance.SetNewArray(&newArray_rfacFieldGridContainer);
      instance.SetDelete(&delete_rfacFieldGridContainer);
      instance.SetDeleteArray(&deleteArray_rfacFieldGridContainer);
      instance.SetDestructor(&destruct_rfacFieldGridContainer);
      instance.SetMerge(&merge_rfacFieldGridContainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacFieldGridContainer*)
   {
      return GenerateInitInstanceLocal((::rfacFieldGridContainer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacFieldGridContainer*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacQuantumNumberContainer(void *p = 0);
   static void *newArray_rfacQuantumNumberContainer(Long_t size, void *p);
   static void delete_rfacQuantumNumberContainer(void *p);
   static void deleteArray_rfacQuantumNumberContainer(void *p);
   static void destruct_rfacQuantumNumberContainer(void *p);
   static Long64_t merge_rfacQuantumNumberContainer(void *obj, TCollection *coll,TFileMergeInfo *info);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacQuantumNumberContainer*)
   {
      ::rfacQuantumNumberContainer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacQuantumNumberContainer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacQuantumNumberContainer", ::rfacQuantumNumberContainer::Class_Version(), "rfacQuantumNumberContainer.hh", 20,
                  typeid(::rfacQuantumNumberContainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacQuantumNumberContainer::Dictionary, isa_proxy, 4,
                  sizeof(::rfacQuantumNumberContainer) );
      instance.SetNew(&new_rfacQuantumNumberContainer);
      instance.SetNewArray(&newArray_rfacQuantumNumberContainer);
      instance.SetDelete(&delete_rfacQuantumNumberContainer);
      instance.SetDeleteArray(&deleteArray_rfacQuantumNumberContainer);
      instance.SetDestructor(&destruct_rfacQuantumNumberContainer);
      instance.SetMerge(&merge_rfacQuantumNumberContainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacQuantumNumberContainer*)
   {
      return GenerateInitInstanceLocal((::rfacQuantumNumberContainer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacQuantumNumberContainer*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacLevelContainer(void *p = 0);
   static void *newArray_rfacLevelContainer(Long_t size, void *p);
   static void delete_rfacLevelContainer(void *p);
   static void deleteArray_rfacLevelContainer(void *p);
   static void destruct_rfacLevelContainer(void *p);
   static Long64_t merge_rfacLevelContainer(void *obj, TCollection *coll,TFileMergeInfo *info);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacLevelContainer*)
   {
      ::rfacLevelContainer *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacLevelContainer >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacLevelContainer", ::rfacLevelContainer::Class_Version(), "rfacLevelContainer.hh", 16,
                  typeid(::rfacLevelContainer), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacLevelContainer::Dictionary, isa_proxy, 4,
                  sizeof(::rfacLevelContainer) );
      instance.SetNew(&new_rfacLevelContainer);
      instance.SetNewArray(&newArray_rfacLevelContainer);
      instance.SetDelete(&delete_rfacLevelContainer);
      instance.SetDeleteArray(&deleteArray_rfacLevelContainer);
      instance.SetDestructor(&destruct_rfacLevelContainer);
      instance.SetMerge(&merge_rfacLevelContainer);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacLevelContainer*)
   {
      return GenerateInitInstanceLocal((::rfacLevelContainer*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacLevelContainer*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacDecayableObject(void *p = 0);
   static void *newArray_rfacDecayableObject(Long_t size, void *p);
   static void delete_rfacDecayableObject(void *p);
   static void deleteArray_rfacDecayableObject(void *p);
   static void destruct_rfacDecayableObject(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacDecayableObject*)
   {
      ::rfacDecayableObject *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacDecayableObject >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacDecayableObject", ::rfacDecayableObject::Class_Version(), "rfacDecayableObject.hh", 25,
                  typeid(::rfacDecayableObject), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacDecayableObject::Dictionary, isa_proxy, 4,
                  sizeof(::rfacDecayableObject) );
      instance.SetNew(&new_rfacDecayableObject);
      instance.SetNewArray(&newArray_rfacDecayableObject);
      instance.SetDelete(&delete_rfacDecayableObject);
      instance.SetDeleteArray(&deleteArray_rfacDecayableObject);
      instance.SetDestructor(&destruct_rfacDecayableObject);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacDecayableObject*)
   {
      return GenerateInitInstanceLocal((::rfacDecayableObject*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacDecayableObject*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void *new_rfacFieldRegimeTranslator(void *p = 0);
   static void *newArray_rfacFieldRegimeTranslator(Long_t size, void *p);
   static void delete_rfacFieldRegimeTranslator(void *p);
   static void deleteArray_rfacFieldRegimeTranslator(void *p);
   static void destruct_rfacFieldRegimeTranslator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::rfacFieldRegimeTranslator*)
   {
      ::rfacFieldRegimeTranslator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::rfacFieldRegimeTranslator >(0);
      static ::ROOT::TGenericClassInfo 
         instance("rfacFieldRegimeTranslator", ::rfacFieldRegimeTranslator::Class_Version(), "rfacFieldRegimeTranslator.hh", 31,
                  typeid(::rfacFieldRegimeTranslator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::rfacFieldRegimeTranslator::Dictionary, isa_proxy, 4,
                  sizeof(::rfacFieldRegimeTranslator) );
      instance.SetNew(&new_rfacFieldRegimeTranslator);
      instance.SetNewArray(&newArray_rfacFieldRegimeTranslator);
      instance.SetDelete(&delete_rfacFieldRegimeTranslator);
      instance.SetDeleteArray(&deleteArray_rfacFieldRegimeTranslator);
      instance.SetDestructor(&destruct_rfacFieldRegimeTranslator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::rfacFieldRegimeTranslator*)
   {
      return GenerateInitInstanceLocal((::rfacFieldRegimeTranslator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::rfacFieldRegimeTranslator*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_CGTranslator(void *p);
   static void deleteArray_CGTranslator(void *p);
   static void destruct_CGTranslator(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::CGTranslator*)
   {
      ::CGTranslator *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::CGTranslator >(0);
      static ::ROOT::TGenericClassInfo 
         instance("CGTranslator", ::CGTranslator::Class_Version(), "CGTranslator.hh", 24,
                  typeid(::CGTranslator), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::CGTranslator::Dictionary, isa_proxy, 4,
                  sizeof(::CGTranslator) );
      instance.SetDelete(&delete_CGTranslator);
      instance.SetDeleteArray(&deleteArray_CGTranslator);
      instance.SetDestructor(&destruct_CGTranslator);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::CGTranslator*)
   {
      return GenerateInitInstanceLocal((::CGTranslator*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::CGTranslator*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static void delete_GeneralQuantumNumbers(void *p);
   static void deleteArray_GeneralQuantumNumbers(void *p);
   static void destruct_GeneralQuantumNumbers(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::GeneralQuantumNumbers*)
   {
      ::GeneralQuantumNumbers *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TInstrumentedIsAProxy< ::GeneralQuantumNumbers >(0);
      static ::ROOT::TGenericClassInfo 
         instance("GeneralQuantumNumbers", ::GeneralQuantumNumbers::Class_Version(), "GeneralQuantumNumbers.hh", 12,
                  typeid(::GeneralQuantumNumbers), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &::GeneralQuantumNumbers::Dictionary, isa_proxy, 4,
                  sizeof(::GeneralQuantumNumbers) );
      instance.SetDelete(&delete_GeneralQuantumNumbers);
      instance.SetDeleteArray(&deleteArray_GeneralQuantumNumbers);
      instance.SetDestructor(&destruct_GeneralQuantumNumbers);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::GeneralQuantumNumbers*)
   {
      return GenerateInitInstanceLocal((::GeneralQuantumNumbers*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::GeneralQuantumNumbers*)0x0); R__UseDummy(_R__UNIQUE_(Init));
} // end of namespace ROOT

namespace ROOT {
   static TClass *_Rb_tree_const_iteratorlErfacFieldGridPointgR_Dictionary();
   static void _Rb_tree_const_iteratorlErfacFieldGridPointgR_TClassManip(TClass*);
   static void *new__Rb_tree_const_iteratorlErfacFieldGridPointgR(void *p = 0);
   static void *newArray__Rb_tree_const_iteratorlErfacFieldGridPointgR(Long_t size, void *p);
   static void delete__Rb_tree_const_iteratorlErfacFieldGridPointgR(void *p);
   static void deleteArray__Rb_tree_const_iteratorlErfacFieldGridPointgR(void *p);
   static void destruct__Rb_tree_const_iteratorlErfacFieldGridPointgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_Rb_tree_const_iterator<rfacFieldGridPoint>*)
   {
      ::_Rb_tree_const_iterator<rfacFieldGridPoint> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::_Rb_tree_const_iterator<rfacFieldGridPoint>));
      static ::ROOT::TGenericClassInfo 
         instance("_Rb_tree_const_iterator<rfacFieldGridPoint>", "map", 228,
                  typeid(::_Rb_tree_const_iterator<rfacFieldGridPoint>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &_Rb_tree_const_iteratorlErfacFieldGridPointgR_Dictionary, isa_proxy, 4,
                  sizeof(::_Rb_tree_const_iterator<rfacFieldGridPoint>) );
      instance.SetNew(&new__Rb_tree_const_iteratorlErfacFieldGridPointgR);
      instance.SetNewArray(&newArray__Rb_tree_const_iteratorlErfacFieldGridPointgR);
      instance.SetDelete(&delete__Rb_tree_const_iteratorlErfacFieldGridPointgR);
      instance.SetDeleteArray(&deleteArray__Rb_tree_const_iteratorlErfacFieldGridPointgR);
      instance.SetDestructor(&destruct__Rb_tree_const_iteratorlErfacFieldGridPointgR);

      ::ROOT::AddClassAlternate("_Rb_tree_const_iterator<rfacFieldGridPoint>","set<rfacFieldGridPoint>::iterator");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_Rb_tree_const_iterator<rfacFieldGridPoint>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *_Rb_tree_const_iteratorlErfacFieldGridPointgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::_Rb_tree_const_iterator<rfacFieldGridPoint>*)0x0)->GetClass();
      _Rb_tree_const_iteratorlErfacFieldGridPointgR_TClassManip(theClass);
   return theClass;
   }

   static void _Rb_tree_const_iteratorlErfacFieldGridPointgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlEQuantumNumberscOdoublegR_Dictionary();
   static void pairlEQuantumNumberscOdoublegR_TClassManip(TClass*);
   static void *new_pairlEQuantumNumberscOdoublegR(void *p = 0);
   static void *newArray_pairlEQuantumNumberscOdoublegR(Long_t size, void *p);
   static void delete_pairlEQuantumNumberscOdoublegR(void *p);
   static void deleteArray_pairlEQuantumNumberscOdoublegR(void *p);
   static void destruct_pairlEQuantumNumberscOdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<QuantumNumbers,double>*)
   {
      pair<QuantumNumbers,double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<QuantumNumbers,double>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<QuantumNumbers,double>", "string", 96,
                  typeid(pair<QuantumNumbers,double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &pairlEQuantumNumberscOdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(pair<QuantumNumbers,double>) );
      instance.SetNew(&new_pairlEQuantumNumberscOdoublegR);
      instance.SetNewArray(&newArray_pairlEQuantumNumberscOdoublegR);
      instance.SetDelete(&delete_pairlEQuantumNumberscOdoublegR);
      instance.SetDeleteArray(&deleteArray_pairlEQuantumNumberscOdoublegR);
      instance.SetDestructor(&destruct_pairlEQuantumNumberscOdoublegR);

      ::ROOT::AddClassAlternate("pair<QuantumNumbers,double>","pair<QuantumNumbers,Double_t>");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<QuantumNumbers,double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEQuantumNumberscOdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<QuantumNumbers,double>*)0x0)->GetClass();
      pairlEQuantumNumberscOdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEQuantumNumberscOdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlEQuantumNumberscOEnergyLevelgR_Dictionary();
   static void pairlEQuantumNumberscOEnergyLevelgR_TClassManip(TClass*);
   static void *new_pairlEQuantumNumberscOEnergyLevelgR(void *p = 0);
   static void *newArray_pairlEQuantumNumberscOEnergyLevelgR(Long_t size, void *p);
   static void delete_pairlEQuantumNumberscOEnergyLevelgR(void *p);
   static void deleteArray_pairlEQuantumNumberscOEnergyLevelgR(void *p);
   static void destruct_pairlEQuantumNumberscOEnergyLevelgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<QuantumNumbers,EnergyLevel>*)
   {
      pair<QuantumNumbers,EnergyLevel> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<QuantumNumbers,EnergyLevel>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<QuantumNumbers,EnergyLevel>", "string", 96,
                  typeid(pair<QuantumNumbers,EnergyLevel>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &pairlEQuantumNumberscOEnergyLevelgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<QuantumNumbers,EnergyLevel>) );
      instance.SetNew(&new_pairlEQuantumNumberscOEnergyLevelgR);
      instance.SetNewArray(&newArray_pairlEQuantumNumberscOEnergyLevelgR);
      instance.SetDelete(&delete_pairlEQuantumNumberscOEnergyLevelgR);
      instance.SetDeleteArray(&deleteArray_pairlEQuantumNumberscOEnergyLevelgR);
      instance.SetDestructor(&destruct_pairlEQuantumNumberscOEnergyLevelgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<QuantumNumbers,EnergyLevel>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEQuantumNumberscOEnergyLevelgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<QuantumNumbers,EnergyLevel>*)0x0)->GetClass();
      pairlEQuantumNumberscOEnergyLevelgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEQuantumNumberscOEnergyLevelgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlEQuantumNumberscOrfacLinearInterpolationgR_Dictionary();
   static void pairlEQuantumNumberscOrfacLinearInterpolationgR_TClassManip(TClass*);
   static void *new_pairlEQuantumNumberscOrfacLinearInterpolationgR(void *p = 0);
   static void *newArray_pairlEQuantumNumberscOrfacLinearInterpolationgR(Long_t size, void *p);
   static void delete_pairlEQuantumNumberscOrfacLinearInterpolationgR(void *p);
   static void deleteArray_pairlEQuantumNumberscOrfacLinearInterpolationgR(void *p);
   static void destruct_pairlEQuantumNumberscOrfacLinearInterpolationgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<QuantumNumbers,rfacLinearInterpolation>*)
   {
      pair<QuantumNumbers,rfacLinearInterpolation> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<QuantumNumbers,rfacLinearInterpolation>));
      static ::ROOT::TGenericClassInfo 
         instance("pair<QuantumNumbers,rfacLinearInterpolation>", "string", 96,
                  typeid(pair<QuantumNumbers,rfacLinearInterpolation>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &pairlEQuantumNumberscOrfacLinearInterpolationgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<QuantumNumbers,rfacLinearInterpolation>) );
      instance.SetNew(&new_pairlEQuantumNumberscOrfacLinearInterpolationgR);
      instance.SetNewArray(&newArray_pairlEQuantumNumberscOrfacLinearInterpolationgR);
      instance.SetDelete(&delete_pairlEQuantumNumberscOrfacLinearInterpolationgR);
      instance.SetDeleteArray(&deleteArray_pairlEQuantumNumberscOrfacLinearInterpolationgR);
      instance.SetDestructor(&destruct_pairlEQuantumNumberscOrfacLinearInterpolationgR);
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<QuantumNumbers,rfacLinearInterpolation>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEQuantumNumberscOrfacLinearInterpolationgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<QuantumNumbers,rfacLinearInterpolation>*)0x0)->GetClass();
      pairlEQuantumNumberscOrfacLinearInterpolationgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEQuantumNumberscOrfacLinearInterpolationgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *_Rb_tree_const_iteratorlEQuantumNumbersgR_Dictionary();
   static void _Rb_tree_const_iteratorlEQuantumNumbersgR_TClassManip(TClass*);
   static void *new__Rb_tree_const_iteratorlEQuantumNumbersgR(void *p = 0);
   static void *newArray__Rb_tree_const_iteratorlEQuantumNumbersgR(Long_t size, void *p);
   static void delete__Rb_tree_const_iteratorlEQuantumNumbersgR(void *p);
   static void deleteArray__Rb_tree_const_iteratorlEQuantumNumbersgR(void *p);
   static void destruct__Rb_tree_const_iteratorlEQuantumNumbersgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::_Rb_tree_const_iterator<QuantumNumbers>*)
   {
      ::_Rb_tree_const_iterator<QuantumNumbers> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::_Rb_tree_const_iterator<QuantumNumbers>));
      static ::ROOT::TGenericClassInfo 
         instance("_Rb_tree_const_iterator<QuantumNumbers>", "map", 228,
                  typeid(::_Rb_tree_const_iterator<QuantumNumbers>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &_Rb_tree_const_iteratorlEQuantumNumbersgR_Dictionary, isa_proxy, 4,
                  sizeof(::_Rb_tree_const_iterator<QuantumNumbers>) );
      instance.SetNew(&new__Rb_tree_const_iteratorlEQuantumNumbersgR);
      instance.SetNewArray(&newArray__Rb_tree_const_iteratorlEQuantumNumbersgR);
      instance.SetDelete(&delete__Rb_tree_const_iteratorlEQuantumNumbersgR);
      instance.SetDeleteArray(&deleteArray__Rb_tree_const_iteratorlEQuantumNumbersgR);
      instance.SetDestructor(&destruct__Rb_tree_const_iteratorlEQuantumNumbersgR);

      ::ROOT::AddClassAlternate("_Rb_tree_const_iterator<QuantumNumbers>","set<QuantumNumbers>::iterator");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::_Rb_tree_const_iterator<QuantumNumbers>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *_Rb_tree_const_iteratorlEQuantumNumbersgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::_Rb_tree_const_iterator<QuantumNumbers>*)0x0)->GetClass();
      _Rb_tree_const_iteratorlEQuantumNumbersgR_TClassManip(theClass);
   return theClass;
   }

   static void _Rb_tree_const_iteratorlEQuantumNumbersgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *__gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR_Dictionary();
   static void __gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR_TClassManip(TClass*);
   static void *new___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(void *p = 0);
   static void *newArray___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(Long_t size, void *p);
   static void delete___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(void *p);
   static void deleteArray___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(void *p);
   static void destruct___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >*)
   {
      ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >));
      static ::ROOT::TGenericClassInfo 
         instance("__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >", "string", 708,
                  typeid(::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &__gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >) );
      instance.SetNew(&new___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR);
      instance.SetNewArray(&newArray___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR);
      instance.SetDelete(&delete___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR);
      instance.SetDeleteArray(&deleteArray___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR);
      instance.SetDestructor(&destruct___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR);

      ::ROOT::AddClassAlternate("__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >","vector<QuantumNumbers>::iterator");
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >*)
   {
      return GenerateInitInstanceLocal((::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *__gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >*)0x0)->GetClass();
      __gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void __gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *pairlEdoublecOvectorlEdoublegRsPgR_Dictionary();
   static void pairlEdoublecOvectorlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_pairlEdoublecOvectorlEdoublegRsPgR(void *p = 0);
   static void *newArray_pairlEdoublecOvectorlEdoublegRsPgR(Long_t size, void *p);
   static void delete_pairlEdoublecOvectorlEdoublegRsPgR(void *p);
   static void deleteArray_pairlEdoublecOvectorlEdoublegRsPgR(void *p);
   static void destruct_pairlEdoublecOvectorlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const pair<double,vector<double> >*)
   {
      pair<double,vector<double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(pair<double,vector<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("pair<double,vector<double> >", "string", 96,
                  typeid(pair<double,vector<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &pairlEdoublecOvectorlEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(pair<double,vector<double> >) );
      instance.SetNew(&new_pairlEdoublecOvectorlEdoublegRsPgR);
      instance.SetNewArray(&newArray_pairlEdoublecOvectorlEdoublegRsPgR);
      instance.SetDelete(&delete_pairlEdoublecOvectorlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_pairlEdoublecOvectorlEdoublegRsPgR);
      instance.SetDestructor(&destruct_pairlEdoublecOvectorlEdoublegRsPgR);

      ::ROOT::AddClassAlternate("pair<double,vector<double> >","pair<Double_t,vector<Double_t> >");
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const pair<double,vector<double> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *pairlEdoublecOvectorlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const pair<double,vector<double> >*)0x0)->GetClass();
      pairlEdoublecOvectorlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void pairlEdoublecOvectorlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

//______________________________________________________________________________
atomic_TClass_ptr EnergyLevel::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *EnergyLevel::Class_Name()
{
   return "EnergyLevel";
}

//______________________________________________________________________________
const char *EnergyLevel::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EnergyLevel*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int EnergyLevel::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::EnergyLevel*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *EnergyLevel::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EnergyLevel*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *EnergyLevel::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::EnergyLevel*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr QuantumNumbers::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *QuantumNumbers::Class_Name()
{
   return "QuantumNumbers";
}

//______________________________________________________________________________
const char *QuantumNumbers::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::QuantumNumbers*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int QuantumNumbers::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::QuantumNumbers*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *QuantumNumbers::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::QuantumNumbers*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *QuantumNumbers::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::QuantumNumbers*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr StrongFieldQuantumNumbers::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *StrongFieldQuantumNumbers::Class_Name()
{
   return "StrongFieldQuantumNumbers";
}

//______________________________________________________________________________
const char *StrongFieldQuantumNumbers::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::StrongFieldQuantumNumbers*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int StrongFieldQuantumNumbers::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::StrongFieldQuantumNumbers*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *StrongFieldQuantumNumbers::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::StrongFieldQuantumNumbers*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *StrongFieldQuantumNumbers::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::StrongFieldQuantumNumbers*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacEssentialData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacEssentialData::Class_Name()
{
   return "rfacEssentialData";
}

//______________________________________________________________________________
const char *rfacEssentialData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacEssentialData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacEssentialData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacEssentialData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacEssentialData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacEssentialData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacEssentialData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacEssentialData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacSpecificLevelData::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacSpecificLevelData::Class_Name()
{
   return "rfacSpecificLevelData";
}

//______________________________________________________________________________
const char *rfacSpecificLevelData::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacSpecificLevelData*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacSpecificLevelData::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacSpecificLevelData*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacSpecificLevelData::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacSpecificLevelData*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacSpecificLevelData::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacSpecificLevelData*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacQuantumNumberLister::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacQuantumNumberLister::Class_Name()
{
   return "rfacQuantumNumberLister";
}

//______________________________________________________________________________
const char *rfacQuantumNumberLister::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacQuantumNumberLister*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacQuantumNumberLister::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacQuantumNumberLister*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacQuantumNumberLister::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacQuantumNumberLister*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacQuantumNumberLister::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacQuantumNumberLister*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacLevelPicker::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacLevelPicker::Class_Name()
{
   return "rfacLevelPicker";
}

//______________________________________________________________________________
const char *rfacLevelPicker::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacLevelPicker*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacLevelPicker::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacLevelPicker*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacLevelPicker::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacLevelPicker*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacLevelPicker::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacLevelPicker*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacException::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacException::Class_Name()
{
   return "rfacException";
}

//______________________________________________________________________________
const char *rfacException::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacException*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacException::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacException*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacException::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacException*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacException::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacException*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacInterpolation::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacInterpolation::Class_Name()
{
   return "rfacInterpolation";
}

//______________________________________________________________________________
const char *rfacInterpolation::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolation*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacInterpolation::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolation*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacInterpolation::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolation*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacInterpolation::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolation*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfac3DInterpolation::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfac3DInterpolation::Class_Name()
{
   return "rfac3DInterpolation";
}

//______________________________________________________________________________
const char *rfac3DInterpolation::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfac3DInterpolation*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfac3DInterpolation::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfac3DInterpolation*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfac3DInterpolation::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfac3DInterpolation*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfac3DInterpolation::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfac3DInterpolation*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr Quadruple::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *Quadruple::Class_Name()
{
   return "Quadruple";
}

//______________________________________________________________________________
const char *Quadruple::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Quadruple*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int Quadruple::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::Quadruple*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *Quadruple::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Quadruple*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *Quadruple::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::Quadruple*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacInterpolatorContainer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacInterpolatorContainer::Class_Name()
{
   return "rfacInterpolatorContainer";
}

//______________________________________________________________________________
const char *rfacInterpolatorContainer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolatorContainer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacInterpolatorContainer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolatorContainer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacInterpolatorContainer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolatorContainer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacInterpolatorContainer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolatorContainer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacInterpolatorPicker::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacInterpolatorPicker::Class_Name()
{
   return "rfacInterpolatorPicker";
}

//______________________________________________________________________________
const char *rfacInterpolatorPicker::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolatorPicker*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacInterpolatorPicker::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolatorPicker*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacInterpolatorPicker::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolatorPicker*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacInterpolatorPicker::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacInterpolatorPicker*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacLinearInterpolation::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacLinearInterpolation::Class_Name()
{
   return "rfacLinearInterpolation";
}

//______________________________________________________________________________
const char *rfacLinearInterpolation::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacLinearInterpolation*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacLinearInterpolation::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacLinearInterpolation*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacLinearInterpolation::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacLinearInterpolation*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacLinearInterpolation::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacLinearInterpolation*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacFieldGridPicker::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacFieldGridPicker::Class_Name()
{
   return "rfacFieldGridPicker";
}

//______________________________________________________________________________
const char *rfacFieldGridPicker::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridPicker*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacFieldGridPicker::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridPicker*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacFieldGridPicker::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridPicker*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacFieldGridPicker::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridPicker*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacFieldGridPoint::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacFieldGridPoint::Class_Name()
{
   return "rfacFieldGridPoint";
}

//______________________________________________________________________________
const char *rfacFieldGridPoint::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridPoint*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacFieldGridPoint::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridPoint*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacFieldGridPoint::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridPoint*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacFieldGridPoint::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridPoint*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacFieldGridContainer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacFieldGridContainer::Class_Name()
{
   return "rfacFieldGridContainer";
}

//______________________________________________________________________________
const char *rfacFieldGridContainer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridContainer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacFieldGridContainer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridContainer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacFieldGridContainer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridContainer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacFieldGridContainer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldGridContainer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacQuantumNumberContainer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacQuantumNumberContainer::Class_Name()
{
   return "rfacQuantumNumberContainer";
}

//______________________________________________________________________________
const char *rfacQuantumNumberContainer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacQuantumNumberContainer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacQuantumNumberContainer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacQuantumNumberContainer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacQuantumNumberContainer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacQuantumNumberContainer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacQuantumNumberContainer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacQuantumNumberContainer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacLevelContainer::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacLevelContainer::Class_Name()
{
   return "rfacLevelContainer";
}

//______________________________________________________________________________
const char *rfacLevelContainer::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacLevelContainer*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacLevelContainer::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacLevelContainer*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacLevelContainer::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacLevelContainer*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacLevelContainer::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacLevelContainer*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacDecayableObject::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacDecayableObject::Class_Name()
{
   return "rfacDecayableObject";
}

//______________________________________________________________________________
const char *rfacDecayableObject::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacDecayableObject*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacDecayableObject::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacDecayableObject*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacDecayableObject::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacDecayableObject*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacDecayableObject::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacDecayableObject*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr rfacFieldRegimeTranslator::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *rfacFieldRegimeTranslator::Class_Name()
{
   return "rfacFieldRegimeTranslator";
}

//______________________________________________________________________________
const char *rfacFieldRegimeTranslator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldRegimeTranslator*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int rfacFieldRegimeTranslator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldRegimeTranslator*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *rfacFieldRegimeTranslator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldRegimeTranslator*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *rfacFieldRegimeTranslator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::rfacFieldRegimeTranslator*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr CGTranslator::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *CGTranslator::Class_Name()
{
   return "CGTranslator";
}

//______________________________________________________________________________
const char *CGTranslator::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CGTranslator*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int CGTranslator::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::CGTranslator*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *CGTranslator::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CGTranslator*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *CGTranslator::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::CGTranslator*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
atomic_TClass_ptr GeneralQuantumNumbers::fgIsA(0);  // static to hold class pointer

//______________________________________________________________________________
const char *GeneralQuantumNumbers::Class_Name()
{
   return "GeneralQuantumNumbers";
}

//______________________________________________________________________________
const char *GeneralQuantumNumbers::ImplFileName()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GeneralQuantumNumbers*)0x0)->GetImplFileName();
}

//______________________________________________________________________________
int GeneralQuantumNumbers::ImplFileLine()
{
   return ::ROOT::GenerateInitInstanceLocal((const ::GeneralQuantumNumbers*)0x0)->GetImplFileLine();
}

//______________________________________________________________________________
TClass *GeneralQuantumNumbers::Dictionary()
{
   fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GeneralQuantumNumbers*)0x0)->GetClass();
   return fgIsA;
}

//______________________________________________________________________________
TClass *GeneralQuantumNumbers::Class()
{
   if (!fgIsA.load()) { R__LOCKGUARD2(gInterpreterMutex); fgIsA = ::ROOT::GenerateInitInstanceLocal((const ::GeneralQuantumNumbers*)0x0)->GetClass(); }
   return fgIsA;
}

//______________________________________________________________________________
void EnergyLevel::Streamer(TBuffer &R__b)
{
   // Stream an object of class EnergyLevel.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(EnergyLevel::Class(),this);
   } else {
      R__b.WriteClassBuffer(EnergyLevel::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_EnergyLevel(void *p) {
      return  p ? new(p) ::EnergyLevel : new ::EnergyLevel;
   }
   static void *newArray_EnergyLevel(Long_t nElements, void *p) {
      return p ? new(p) ::EnergyLevel[nElements] : new ::EnergyLevel[nElements];
   }
   // Wrapper around operator delete
   static void delete_EnergyLevel(void *p) {
      delete ((::EnergyLevel*)p);
   }
   static void deleteArray_EnergyLevel(void *p) {
      delete [] ((::EnergyLevel*)p);
   }
   static void destruct_EnergyLevel(void *p) {
      typedef ::EnergyLevel current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::EnergyLevel

//______________________________________________________________________________
void QuantumNumbers::Streamer(TBuffer &R__b)
{
   // Stream an object of class QuantumNumbers.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(QuantumNumbers::Class(),this);
   } else {
      R__b.WriteClassBuffer(QuantumNumbers::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_QuantumNumbers(void *p) {
      return  p ? new(p) ::QuantumNumbers : new ::QuantumNumbers;
   }
   static void *newArray_QuantumNumbers(Long_t nElements, void *p) {
      return p ? new(p) ::QuantumNumbers[nElements] : new ::QuantumNumbers[nElements];
   }
   // Wrapper around operator delete
   static void delete_QuantumNumbers(void *p) {
      delete ((::QuantumNumbers*)p);
   }
   static void deleteArray_QuantumNumbers(void *p) {
      delete [] ((::QuantumNumbers*)p);
   }
   static void destruct_QuantumNumbers(void *p) {
      typedef ::QuantumNumbers current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::QuantumNumbers

//______________________________________________________________________________
void StrongFieldQuantumNumbers::Streamer(TBuffer &R__b)
{
   // Stream an object of class StrongFieldQuantumNumbers.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(StrongFieldQuantumNumbers::Class(),this);
   } else {
      R__b.WriteClassBuffer(StrongFieldQuantumNumbers::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_StrongFieldQuantumNumbers(void *p) {
      return  p ? new(p) ::StrongFieldQuantumNumbers : new ::StrongFieldQuantumNumbers;
   }
   static void *newArray_StrongFieldQuantumNumbers(Long_t nElements, void *p) {
      return p ? new(p) ::StrongFieldQuantumNumbers[nElements] : new ::StrongFieldQuantumNumbers[nElements];
   }
   // Wrapper around operator delete
   static void delete_StrongFieldQuantumNumbers(void *p) {
      delete ((::StrongFieldQuantumNumbers*)p);
   }
   static void deleteArray_StrongFieldQuantumNumbers(void *p) {
      delete [] ((::StrongFieldQuantumNumbers*)p);
   }
   static void destruct_StrongFieldQuantumNumbers(void *p) {
      typedef ::StrongFieldQuantumNumbers current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::StrongFieldQuantumNumbers

//______________________________________________________________________________
void rfacEssentialData::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacEssentialData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacEssentialData::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacEssentialData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacEssentialData(void *p) {
      return  p ? new(p) ::rfacEssentialData : new ::rfacEssentialData;
   }
   static void *newArray_rfacEssentialData(Long_t nElements, void *p) {
      return p ? new(p) ::rfacEssentialData[nElements] : new ::rfacEssentialData[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacEssentialData(void *p) {
      delete ((::rfacEssentialData*)p);
   }
   static void deleteArray_rfacEssentialData(void *p) {
      delete [] ((::rfacEssentialData*)p);
   }
   static void destruct_rfacEssentialData(void *p) {
      typedef ::rfacEssentialData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacEssentialData

//______________________________________________________________________________
void rfacSpecificLevelData::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacSpecificLevelData.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacSpecificLevelData::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacSpecificLevelData::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacSpecificLevelData(void *p) {
      return  p ? new(p) ::rfacSpecificLevelData : new ::rfacSpecificLevelData;
   }
   static void *newArray_rfacSpecificLevelData(Long_t nElements, void *p) {
      return p ? new(p) ::rfacSpecificLevelData[nElements] : new ::rfacSpecificLevelData[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacSpecificLevelData(void *p) {
      delete ((::rfacSpecificLevelData*)p);
   }
   static void deleteArray_rfacSpecificLevelData(void *p) {
      delete [] ((::rfacSpecificLevelData*)p);
   }
   static void destruct_rfacSpecificLevelData(void *p) {
      typedef ::rfacSpecificLevelData current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacSpecificLevelData

//______________________________________________________________________________
void rfacQuantumNumberLister::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacQuantumNumberLister.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacQuantumNumberLister::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacQuantumNumberLister::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacQuantumNumberLister(void *p) {
      return  p ? new(p) ::rfacQuantumNumberLister : new ::rfacQuantumNumberLister;
   }
   static void *newArray_rfacQuantumNumberLister(Long_t nElements, void *p) {
      return p ? new(p) ::rfacQuantumNumberLister[nElements] : new ::rfacQuantumNumberLister[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacQuantumNumberLister(void *p) {
      delete ((::rfacQuantumNumberLister*)p);
   }
   static void deleteArray_rfacQuantumNumberLister(void *p) {
      delete [] ((::rfacQuantumNumberLister*)p);
   }
   static void destruct_rfacQuantumNumberLister(void *p) {
      typedef ::rfacQuantumNumberLister current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacQuantumNumberLister

//______________________________________________________________________________
void rfacLevelPicker::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacLevelPicker.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacLevelPicker::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacLevelPicker::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacLevelPicker(void *p) {
      return  p ? new(p) ::rfacLevelPicker : new ::rfacLevelPicker;
   }
   static void *newArray_rfacLevelPicker(Long_t nElements, void *p) {
      return p ? new(p) ::rfacLevelPicker[nElements] : new ::rfacLevelPicker[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacLevelPicker(void *p) {
      delete ((::rfacLevelPicker*)p);
   }
   static void deleteArray_rfacLevelPicker(void *p) {
      delete [] ((::rfacLevelPicker*)p);
   }
   static void destruct_rfacLevelPicker(void *p) {
      typedef ::rfacLevelPicker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacLevelPicker

//______________________________________________________________________________
void rfacException::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacException.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacException::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacException::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacException(void *p) {
      return  p ? new(p) ::rfacException : new ::rfacException;
   }
   static void *newArray_rfacException(Long_t nElements, void *p) {
      return p ? new(p) ::rfacException[nElements] : new ::rfacException[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacException(void *p) {
      delete ((::rfacException*)p);
   }
   static void deleteArray_rfacException(void *p) {
      delete [] ((::rfacException*)p);
   }
   static void destruct_rfacException(void *p) {
      typedef ::rfacException current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacException

//______________________________________________________________________________
void rfacInterpolation::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacInterpolation.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacInterpolation::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacInterpolation::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacInterpolation(void *p) {
      return  p ? new(p) ::rfacInterpolation : new ::rfacInterpolation;
   }
   static void *newArray_rfacInterpolation(Long_t nElements, void *p) {
      return p ? new(p) ::rfacInterpolation[nElements] : new ::rfacInterpolation[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacInterpolation(void *p) {
      delete ((::rfacInterpolation*)p);
   }
   static void deleteArray_rfacInterpolation(void *p) {
      delete [] ((::rfacInterpolation*)p);
   }
   static void destruct_rfacInterpolation(void *p) {
      typedef ::rfacInterpolation current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacInterpolation

//______________________________________________________________________________
void rfac3DInterpolation::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfac3DInterpolation.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfac3DInterpolation::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfac3DInterpolation::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfac3DInterpolation(void *p) {
      return  p ? new(p) ::rfac3DInterpolation : new ::rfac3DInterpolation;
   }
   static void *newArray_rfac3DInterpolation(Long_t nElements, void *p) {
      return p ? new(p) ::rfac3DInterpolation[nElements] : new ::rfac3DInterpolation[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfac3DInterpolation(void *p) {
      delete ((::rfac3DInterpolation*)p);
   }
   static void deleteArray_rfac3DInterpolation(void *p) {
      delete [] ((::rfac3DInterpolation*)p);
   }
   static void destruct_rfac3DInterpolation(void *p) {
      typedef ::rfac3DInterpolation current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfac3DInterpolation

//______________________________________________________________________________
void Quadruple::Streamer(TBuffer &R__b)
{
   // Stream an object of class Quadruple.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(Quadruple::Class(),this);
   } else {
      R__b.WriteClassBuffer(Quadruple::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_Quadruple(void *p) {
      return  p ? new(p) ::Quadruple : new ::Quadruple;
   }
   static void *newArray_Quadruple(Long_t nElements, void *p) {
      return p ? new(p) ::Quadruple[nElements] : new ::Quadruple[nElements];
   }
   // Wrapper around operator delete
   static void delete_Quadruple(void *p) {
      delete ((::Quadruple*)p);
   }
   static void deleteArray_Quadruple(void *p) {
      delete [] ((::Quadruple*)p);
   }
   static void destruct_Quadruple(void *p) {
      typedef ::Quadruple current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Quadruple

//______________________________________________________________________________
void rfacInterpolatorContainer::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacInterpolatorContainer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacInterpolatorContainer::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacInterpolatorContainer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacInterpolatorContainer(void *p) {
      return  p ? new(p) ::rfacInterpolatorContainer : new ::rfacInterpolatorContainer;
   }
   static void *newArray_rfacInterpolatorContainer(Long_t nElements, void *p) {
      return p ? new(p) ::rfacInterpolatorContainer[nElements] : new ::rfacInterpolatorContainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacInterpolatorContainer(void *p) {
      delete ((::rfacInterpolatorContainer*)p);
   }
   static void deleteArray_rfacInterpolatorContainer(void *p) {
      delete [] ((::rfacInterpolatorContainer*)p);
   }
   static void destruct_rfacInterpolatorContainer(void *p) {
      typedef ::rfacInterpolatorContainer current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacInterpolatorContainer

//______________________________________________________________________________
void rfacInterpolatorPicker::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacInterpolatorPicker.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacInterpolatorPicker::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacInterpolatorPicker::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacInterpolatorPicker(void *p) {
      return  p ? new(p) ::rfacInterpolatorPicker : new ::rfacInterpolatorPicker;
   }
   static void *newArray_rfacInterpolatorPicker(Long_t nElements, void *p) {
      return p ? new(p) ::rfacInterpolatorPicker[nElements] : new ::rfacInterpolatorPicker[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacInterpolatorPicker(void *p) {
      delete ((::rfacInterpolatorPicker*)p);
   }
   static void deleteArray_rfacInterpolatorPicker(void *p) {
      delete [] ((::rfacInterpolatorPicker*)p);
   }
   static void destruct_rfacInterpolatorPicker(void *p) {
      typedef ::rfacInterpolatorPicker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacInterpolatorPicker

//______________________________________________________________________________
void rfacLinearInterpolation::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacLinearInterpolation.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacLinearInterpolation::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacLinearInterpolation::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacLinearInterpolation(void *p) {
      return  p ? new(p) ::rfacLinearInterpolation : new ::rfacLinearInterpolation;
   }
   static void *newArray_rfacLinearInterpolation(Long_t nElements, void *p) {
      return p ? new(p) ::rfacLinearInterpolation[nElements] : new ::rfacLinearInterpolation[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacLinearInterpolation(void *p) {
      delete ((::rfacLinearInterpolation*)p);
   }
   static void deleteArray_rfacLinearInterpolation(void *p) {
      delete [] ((::rfacLinearInterpolation*)p);
   }
   static void destruct_rfacLinearInterpolation(void *p) {
      typedef ::rfacLinearInterpolation current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacLinearInterpolation

//______________________________________________________________________________
void rfacFieldGridPicker::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacFieldGridPicker.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacFieldGridPicker::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacFieldGridPicker::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacFieldGridPicker(void *p) {
      return  p ? new(p) ::rfacFieldGridPicker : new ::rfacFieldGridPicker;
   }
   static void *newArray_rfacFieldGridPicker(Long_t nElements, void *p) {
      return p ? new(p) ::rfacFieldGridPicker[nElements] : new ::rfacFieldGridPicker[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacFieldGridPicker(void *p) {
      delete ((::rfacFieldGridPicker*)p);
   }
   static void deleteArray_rfacFieldGridPicker(void *p) {
      delete [] ((::rfacFieldGridPicker*)p);
   }
   static void destruct_rfacFieldGridPicker(void *p) {
      typedef ::rfacFieldGridPicker current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacFieldGridPicker

//______________________________________________________________________________
void rfacFieldGridPoint::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacFieldGridPoint.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacFieldGridPoint::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacFieldGridPoint::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacFieldGridPoint(void *p) {
      return  p ? new(p) ::rfacFieldGridPoint : new ::rfacFieldGridPoint;
   }
   static void *newArray_rfacFieldGridPoint(Long_t nElements, void *p) {
      return p ? new(p) ::rfacFieldGridPoint[nElements] : new ::rfacFieldGridPoint[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacFieldGridPoint(void *p) {
      delete ((::rfacFieldGridPoint*)p);
   }
   static void deleteArray_rfacFieldGridPoint(void *p) {
      delete [] ((::rfacFieldGridPoint*)p);
   }
   static void destruct_rfacFieldGridPoint(void *p) {
      typedef ::rfacFieldGridPoint current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacFieldGridPoint

//______________________________________________________________________________
void rfacFieldGridContainer::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacFieldGridContainer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacFieldGridContainer::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacFieldGridContainer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacFieldGridContainer(void *p) {
      return  p ? new(p) ::rfacFieldGridContainer : new ::rfacFieldGridContainer;
   }
   static void *newArray_rfacFieldGridContainer(Long_t nElements, void *p) {
      return p ? new(p) ::rfacFieldGridContainer[nElements] : new ::rfacFieldGridContainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacFieldGridContainer(void *p) {
      delete ((::rfacFieldGridContainer*)p);
   }
   static void deleteArray_rfacFieldGridContainer(void *p) {
      delete [] ((::rfacFieldGridContainer*)p);
   }
   static void destruct_rfacFieldGridContainer(void *p) {
      typedef ::rfacFieldGridContainer current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around the merge function.
   static Long64_t  merge_rfacFieldGridContainer(void *obj,TCollection *coll,TFileMergeInfo *) {
      return ((::rfacFieldGridContainer*)obj)->Merge(coll);
   }
} // end of namespace ROOT for class ::rfacFieldGridContainer

//______________________________________________________________________________
void rfacQuantumNumberContainer::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacQuantumNumberContainer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacQuantumNumberContainer::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacQuantumNumberContainer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacQuantumNumberContainer(void *p) {
      return  p ? new(p) ::rfacQuantumNumberContainer : new ::rfacQuantumNumberContainer;
   }
   static void *newArray_rfacQuantumNumberContainer(Long_t nElements, void *p) {
      return p ? new(p) ::rfacQuantumNumberContainer[nElements] : new ::rfacQuantumNumberContainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacQuantumNumberContainer(void *p) {
      delete ((::rfacQuantumNumberContainer*)p);
   }
   static void deleteArray_rfacQuantumNumberContainer(void *p) {
      delete [] ((::rfacQuantumNumberContainer*)p);
   }
   static void destruct_rfacQuantumNumberContainer(void *p) {
      typedef ::rfacQuantumNumberContainer current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around the merge function.
   static Long64_t  merge_rfacQuantumNumberContainer(void *obj,TCollection *coll,TFileMergeInfo *) {
      return ((::rfacQuantumNumberContainer*)obj)->Merge(coll);
   }
} // end of namespace ROOT for class ::rfacQuantumNumberContainer

//______________________________________________________________________________
void rfacLevelContainer::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacLevelContainer.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacLevelContainer::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacLevelContainer::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacLevelContainer(void *p) {
      return  p ? new(p) ::rfacLevelContainer : new ::rfacLevelContainer;
   }
   static void *newArray_rfacLevelContainer(Long_t nElements, void *p) {
      return p ? new(p) ::rfacLevelContainer[nElements] : new ::rfacLevelContainer[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacLevelContainer(void *p) {
      delete ((::rfacLevelContainer*)p);
   }
   static void deleteArray_rfacLevelContainer(void *p) {
      delete [] ((::rfacLevelContainer*)p);
   }
   static void destruct_rfacLevelContainer(void *p) {
      typedef ::rfacLevelContainer current_t;
      ((current_t*)p)->~current_t();
   }
   // Wrapper around the merge function.
   static Long64_t  merge_rfacLevelContainer(void *obj,TCollection *coll,TFileMergeInfo *) {
      return ((::rfacLevelContainer*)obj)->Merge(coll);
   }
} // end of namespace ROOT for class ::rfacLevelContainer

//______________________________________________________________________________
void rfacDecayableObject::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacDecayableObject.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacDecayableObject::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacDecayableObject::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacDecayableObject(void *p) {
      return  p ? new(p) ::rfacDecayableObject : new ::rfacDecayableObject;
   }
   static void *newArray_rfacDecayableObject(Long_t nElements, void *p) {
      return p ? new(p) ::rfacDecayableObject[nElements] : new ::rfacDecayableObject[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacDecayableObject(void *p) {
      delete ((::rfacDecayableObject*)p);
   }
   static void deleteArray_rfacDecayableObject(void *p) {
      delete [] ((::rfacDecayableObject*)p);
   }
   static void destruct_rfacDecayableObject(void *p) {
      typedef ::rfacDecayableObject current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacDecayableObject

//______________________________________________________________________________
void rfacFieldRegimeTranslator::Streamer(TBuffer &R__b)
{
   // Stream an object of class rfacFieldRegimeTranslator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(rfacFieldRegimeTranslator::Class(),this);
   } else {
      R__b.WriteClassBuffer(rfacFieldRegimeTranslator::Class(),this);
   }
}

namespace ROOT {
   // Wrappers around operator new
   static void *new_rfacFieldRegimeTranslator(void *p) {
      return  p ? new(p) ::rfacFieldRegimeTranslator : new ::rfacFieldRegimeTranslator;
   }
   static void *newArray_rfacFieldRegimeTranslator(Long_t nElements, void *p) {
      return p ? new(p) ::rfacFieldRegimeTranslator[nElements] : new ::rfacFieldRegimeTranslator[nElements];
   }
   // Wrapper around operator delete
   static void delete_rfacFieldRegimeTranslator(void *p) {
      delete ((::rfacFieldRegimeTranslator*)p);
   }
   static void deleteArray_rfacFieldRegimeTranslator(void *p) {
      delete [] ((::rfacFieldRegimeTranslator*)p);
   }
   static void destruct_rfacFieldRegimeTranslator(void *p) {
      typedef ::rfacFieldRegimeTranslator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::rfacFieldRegimeTranslator

//______________________________________________________________________________
void CGTranslator::Streamer(TBuffer &R__b)
{
   // Stream an object of class CGTranslator.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(CGTranslator::Class(),this);
   } else {
      R__b.WriteClassBuffer(CGTranslator::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_CGTranslator(void *p) {
      delete ((::CGTranslator*)p);
   }
   static void deleteArray_CGTranslator(void *p) {
      delete [] ((::CGTranslator*)p);
   }
   static void destruct_CGTranslator(void *p) {
      typedef ::CGTranslator current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::CGTranslator

//______________________________________________________________________________
void GeneralQuantumNumbers::Streamer(TBuffer &R__b)
{
   // Stream an object of class GeneralQuantumNumbers.

   if (R__b.IsReading()) {
      R__b.ReadClassBuffer(GeneralQuantumNumbers::Class(),this);
   } else {
      R__b.WriteClassBuffer(GeneralQuantumNumbers::Class(),this);
   }
}

namespace ROOT {
   // Wrapper around operator delete
   static void delete_GeneralQuantumNumbers(void *p) {
      delete ((::GeneralQuantumNumbers*)p);
   }
   static void deleteArray_GeneralQuantumNumbers(void *p) {
      delete [] ((::GeneralQuantumNumbers*)p);
   }
   static void destruct_GeneralQuantumNumbers(void *p) {
      typedef ::GeneralQuantumNumbers current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::GeneralQuantumNumbers

namespace ROOT {
   // Wrappers around operator new
   static void *new__Rb_tree_const_iteratorlErfacFieldGridPointgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::_Rb_tree_const_iterator<rfacFieldGridPoint> : new ::_Rb_tree_const_iterator<rfacFieldGridPoint>;
   }
   static void *newArray__Rb_tree_const_iteratorlErfacFieldGridPointgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::_Rb_tree_const_iterator<rfacFieldGridPoint>[nElements] : new ::_Rb_tree_const_iterator<rfacFieldGridPoint>[nElements];
   }
   // Wrapper around operator delete
   static void delete__Rb_tree_const_iteratorlErfacFieldGridPointgR(void *p) {
      delete ((::_Rb_tree_const_iterator<rfacFieldGridPoint>*)p);
   }
   static void deleteArray__Rb_tree_const_iteratorlErfacFieldGridPointgR(void *p) {
      delete [] ((::_Rb_tree_const_iterator<rfacFieldGridPoint>*)p);
   }
   static void destruct__Rb_tree_const_iteratorlErfacFieldGridPointgR(void *p) {
      typedef ::_Rb_tree_const_iterator<rfacFieldGridPoint> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_Rb_tree_const_iterator<rfacFieldGridPoint>

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEQuantumNumberscOdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<QuantumNumbers,double> : new pair<QuantumNumbers,double>;
   }
   static void *newArray_pairlEQuantumNumberscOdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<QuantumNumbers,double>[nElements] : new pair<QuantumNumbers,double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEQuantumNumberscOdoublegR(void *p) {
      delete ((pair<QuantumNumbers,double>*)p);
   }
   static void deleteArray_pairlEQuantumNumberscOdoublegR(void *p) {
      delete [] ((pair<QuantumNumbers,double>*)p);
   }
   static void destruct_pairlEQuantumNumberscOdoublegR(void *p) {
      typedef pair<QuantumNumbers,double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<QuantumNumbers,double>

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEQuantumNumberscOEnergyLevelgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<QuantumNumbers,EnergyLevel> : new pair<QuantumNumbers,EnergyLevel>;
   }
   static void *newArray_pairlEQuantumNumberscOEnergyLevelgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<QuantumNumbers,EnergyLevel>[nElements] : new pair<QuantumNumbers,EnergyLevel>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEQuantumNumberscOEnergyLevelgR(void *p) {
      delete ((pair<QuantumNumbers,EnergyLevel>*)p);
   }
   static void deleteArray_pairlEQuantumNumberscOEnergyLevelgR(void *p) {
      delete [] ((pair<QuantumNumbers,EnergyLevel>*)p);
   }
   static void destruct_pairlEQuantumNumberscOEnergyLevelgR(void *p) {
      typedef pair<QuantumNumbers,EnergyLevel> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<QuantumNumbers,EnergyLevel>

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEQuantumNumberscOrfacLinearInterpolationgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<QuantumNumbers,rfacLinearInterpolation> : new pair<QuantumNumbers,rfacLinearInterpolation>;
   }
   static void *newArray_pairlEQuantumNumberscOrfacLinearInterpolationgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<QuantumNumbers,rfacLinearInterpolation>[nElements] : new pair<QuantumNumbers,rfacLinearInterpolation>[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEQuantumNumberscOrfacLinearInterpolationgR(void *p) {
      delete ((pair<QuantumNumbers,rfacLinearInterpolation>*)p);
   }
   static void deleteArray_pairlEQuantumNumberscOrfacLinearInterpolationgR(void *p) {
      delete [] ((pair<QuantumNumbers,rfacLinearInterpolation>*)p);
   }
   static void destruct_pairlEQuantumNumberscOrfacLinearInterpolationgR(void *p) {
      typedef pair<QuantumNumbers,rfacLinearInterpolation> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<QuantumNumbers,rfacLinearInterpolation>

namespace ROOT {
   // Wrappers around operator new
   static void *new__Rb_tree_const_iteratorlEQuantumNumbersgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::_Rb_tree_const_iterator<QuantumNumbers> : new ::_Rb_tree_const_iterator<QuantumNumbers>;
   }
   static void *newArray__Rb_tree_const_iteratorlEQuantumNumbersgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::_Rb_tree_const_iterator<QuantumNumbers>[nElements] : new ::_Rb_tree_const_iterator<QuantumNumbers>[nElements];
   }
   // Wrapper around operator delete
   static void delete__Rb_tree_const_iteratorlEQuantumNumbersgR(void *p) {
      delete ((::_Rb_tree_const_iterator<QuantumNumbers>*)p);
   }
   static void deleteArray__Rb_tree_const_iteratorlEQuantumNumbersgR(void *p) {
      delete [] ((::_Rb_tree_const_iterator<QuantumNumbers>*)p);
   }
   static void destruct__Rb_tree_const_iteratorlEQuantumNumbersgR(void *p) {
      typedef ::_Rb_tree_const_iterator<QuantumNumbers> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::_Rb_tree_const_iterator<QuantumNumbers>

namespace ROOT {
   // Wrappers around operator new
   static void *new___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> > : new ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >;
   }
   static void *newArray___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >[nElements] : new ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >[nElements];
   }
   // Wrapper around operator delete
   static void delete___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(void *p) {
      delete ((::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >*)p);
   }
   static void deleteArray___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(void *p) {
      delete [] ((::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >*)p);
   }
   static void destruct___gnu_cxxcLcL__normal_iteratorlEQuantumNumbersmUcOvectorlEQuantumNumbersgRsPgR(void *p) {
      typedef ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >

namespace ROOT {
   // Wrappers around operator new
   static void *new_pairlEdoublecOvectorlEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<double,vector<double> > : new pair<double,vector<double> >;
   }
   static void *newArray_pairlEdoublecOvectorlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) pair<double,vector<double> >[nElements] : new pair<double,vector<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_pairlEdoublecOvectorlEdoublegRsPgR(void *p) {
      delete ((pair<double,vector<double> >*)p);
   }
   static void deleteArray_pairlEdoublecOvectorlEdoublegRsPgR(void *p) {
      delete [] ((pair<double,vector<double> >*)p);
   }
   static void destruct_pairlEdoublecOvectorlEdoublegRsPgR(void *p) {
      typedef pair<double,vector<double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class pair<double,vector<double> >

namespace ROOT {
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary();
   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p);
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<double> >*)
   {
      vector<vector<double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<double> >", -2, "vector", 210,
                  typeid(vector<vector<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<vector<double> >) );
      instance.SetNew(&new_vectorlEvectorlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<double> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<double> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<double> >*)0x0)->GetClass();
      vectorlEvectorlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<double> > : new vector<vector<double> >;
   }
   static void *newArray_vectorlEvectorlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<double> >[nElements] : new vector<vector<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete ((vector<vector<double> >*)p);
   }
   static void deleteArray_vectorlEvectorlEdoublegRsPgR(void *p) {
      delete [] ((vector<vector<double> >*)p);
   }
   static void destruct_vectorlEvectorlEdoublegRsPgR(void *p) {
      typedef vector<vector<double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<double> >

namespace ROOT {
   static TClass *vectorlErfacSpecificLevelDatagR_Dictionary();
   static void vectorlErfacSpecificLevelDatagR_TClassManip(TClass*);
   static void *new_vectorlErfacSpecificLevelDatagR(void *p = 0);
   static void *newArray_vectorlErfacSpecificLevelDatagR(Long_t size, void *p);
   static void delete_vectorlErfacSpecificLevelDatagR(void *p);
   static void deleteArray_vectorlErfacSpecificLevelDatagR(void *p);
   static void destruct_vectorlErfacSpecificLevelDatagR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<rfacSpecificLevelData>*)
   {
      vector<rfacSpecificLevelData> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<rfacSpecificLevelData>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<rfacSpecificLevelData>", -2, "vector", 210,
                  typeid(vector<rfacSpecificLevelData>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlErfacSpecificLevelDatagR_Dictionary, isa_proxy, 4,
                  sizeof(vector<rfacSpecificLevelData>) );
      instance.SetNew(&new_vectorlErfacSpecificLevelDatagR);
      instance.SetNewArray(&newArray_vectorlErfacSpecificLevelDatagR);
      instance.SetDelete(&delete_vectorlErfacSpecificLevelDatagR);
      instance.SetDeleteArray(&deleteArray_vectorlErfacSpecificLevelDatagR);
      instance.SetDestructor(&destruct_vectorlErfacSpecificLevelDatagR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<rfacSpecificLevelData> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<rfacSpecificLevelData>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlErfacSpecificLevelDatagR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<rfacSpecificLevelData>*)0x0)->GetClass();
      vectorlErfacSpecificLevelDatagR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlErfacSpecificLevelDatagR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlErfacSpecificLevelDatagR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<rfacSpecificLevelData> : new vector<rfacSpecificLevelData>;
   }
   static void *newArray_vectorlErfacSpecificLevelDatagR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<rfacSpecificLevelData>[nElements] : new vector<rfacSpecificLevelData>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlErfacSpecificLevelDatagR(void *p) {
      delete ((vector<rfacSpecificLevelData>*)p);
   }
   static void deleteArray_vectorlErfacSpecificLevelDatagR(void *p) {
      delete [] ((vector<rfacSpecificLevelData>*)p);
   }
   static void destruct_vectorlErfacSpecificLevelDatagR(void *p) {
      typedef vector<rfacSpecificLevelData> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<rfacSpecificLevelData>

namespace ROOT {
   static TClass *vectorlEpairlEdoublecOdoublegRsPgR_Dictionary();
   static void vectorlEpairlEdoublecOdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlEdoublecOdoublegRsPgR(void *p = 0);
   static void *newArray_vectorlEpairlEdoublecOdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlEdoublecOdoublegRsPgR(void *p);
   static void deleteArray_vectorlEpairlEdoublecOdoublegRsPgR(void *p);
   static void destruct_vectorlEpairlEdoublecOdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<double,double> >*)
   {
      vector<pair<double,double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<double,double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<double,double> >", -2, "vector", 210,
                  typeid(vector<pair<double,double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEpairlEdoublecOdoublegRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<pair<double,double> >) );
      instance.SetNew(&new_vectorlEpairlEdoublecOdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlEdoublecOdoublegRsPgR);
      instance.SetDelete(&delete_vectorlEpairlEdoublecOdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlEdoublecOdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlEdoublecOdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<double,double> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<pair<double,double> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlEdoublecOdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<pair<double,double> >*)0x0)->GetClass();
      vectorlEpairlEdoublecOdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlEdoublecOdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlEdoublecOdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<double,double> > : new vector<pair<double,double> >;
   }
   static void *newArray_vectorlEpairlEdoublecOdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<double,double> >[nElements] : new vector<pair<double,double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlEdoublecOdoublegRsPgR(void *p) {
      delete ((vector<pair<double,double> >*)p);
   }
   static void deleteArray_vectorlEpairlEdoublecOdoublegRsPgR(void *p) {
      delete [] ((vector<pair<double,double> >*)p);
   }
   static void destruct_vectorlEpairlEdoublecOdoublegRsPgR(void *p) {
      typedef vector<pair<double,double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<pair<double,double> >

namespace ROOT {
   static TClass *vectorlEdoublegR_Dictionary();
   static void vectorlEdoublegR_TClassManip(TClass*);
   static void *new_vectorlEdoublegR(void *p = 0);
   static void *newArray_vectorlEdoublegR(Long_t size, void *p);
   static void delete_vectorlEdoublegR(void *p);
   static void deleteArray_vectorlEdoublegR(void *p);
   static void destruct_vectorlEdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<double>*)
   {
      vector<double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<double>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<double>", -2, "vector", 210,
                  typeid(vector<double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(vector<double>) );
      instance.SetNew(&new_vectorlEdoublegR);
      instance.SetNewArray(&newArray_vectorlEdoublegR);
      instance.SetDelete(&delete_vectorlEdoublegR);
      instance.SetDeleteArray(&deleteArray_vectorlEdoublegR);
      instance.SetDestructor(&destruct_vectorlEdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<double>*)0x0)->GetClass();
      vectorlEdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double> : new vector<double>;
   }
   static void *newArray_vectorlEdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<double>[nElements] : new vector<double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEdoublegR(void *p) {
      delete ((vector<double>*)p);
   }
   static void deleteArray_vectorlEdoublegR(void *p) {
      delete [] ((vector<double>*)p);
   }
   static void destruct_vectorlEdoublegR(void *p) {
      typedef vector<double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<double>

namespace ROOT {
   static TClass *vectorlETVectorTlEdoublegRsPgR_Dictionary();
   static void vectorlETVectorTlEdoublegRsPgR_TClassManip(TClass*);
   static void *new_vectorlETVectorTlEdoublegRsPgR(void *p = 0);
   static void *newArray_vectorlETVectorTlEdoublegRsPgR(Long_t size, void *p);
   static void delete_vectorlETVectorTlEdoublegRsPgR(void *p);
   static void deleteArray_vectorlETVectorTlEdoublegRsPgR(void *p);
   static void destruct_vectorlETVectorTlEdoublegRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TVectorT<double> >*)
   {
      vector<TVectorT<double> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TVectorT<double> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TVectorT<double> >", -2, "vector", 210,
                  typeid(vector<TVectorT<double> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETVectorTlEdoublegRsPgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<TVectorT<double> >) );
      instance.SetNew(&new_vectorlETVectorTlEdoublegRsPgR);
      instance.SetNewArray(&newArray_vectorlETVectorTlEdoublegRsPgR);
      instance.SetDelete(&delete_vectorlETVectorTlEdoublegRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlETVectorTlEdoublegRsPgR);
      instance.SetDestructor(&destruct_vectorlETVectorTlEdoublegRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TVectorT<double> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<TVectorT<double> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETVectorTlEdoublegRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TVectorT<double> >*)0x0)->GetClass();
      vectorlETVectorTlEdoublegRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETVectorTlEdoublegRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETVectorTlEdoublegRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVectorT<double> > : new vector<TVectorT<double> >;
   }
   static void *newArray_vectorlETVectorTlEdoublegRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TVectorT<double> >[nElements] : new vector<TVectorT<double> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETVectorTlEdoublegRsPgR(void *p) {
      delete ((vector<TVectorT<double> >*)p);
   }
   static void deleteArray_vectorlETVectorTlEdoublegRsPgR(void *p) {
      delete [] ((vector<TVectorT<double> >*)p);
   }
   static void destruct_vectorlETVectorTlEdoublegRsPgR(void *p) {
      typedef vector<TVectorT<double> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TVectorT<double> >

namespace ROOT {
   static TClass *vectorlEQuantumNumbersgR_Dictionary();
   static void vectorlEQuantumNumbersgR_TClassManip(TClass*);
   static void *new_vectorlEQuantumNumbersgR(void *p = 0);
   static void *newArray_vectorlEQuantumNumbersgR(Long_t size, void *p);
   static void delete_vectorlEQuantumNumbersgR(void *p);
   static void deleteArray_vectorlEQuantumNumbersgR(void *p);
   static void destruct_vectorlEQuantumNumbersgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<QuantumNumbers>*)
   {
      vector<QuantumNumbers> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<QuantumNumbers>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<QuantumNumbers>", -2, "vector", 210,
                  typeid(vector<QuantumNumbers>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEQuantumNumbersgR_Dictionary, isa_proxy, 4,
                  sizeof(vector<QuantumNumbers>) );
      instance.SetNew(&new_vectorlEQuantumNumbersgR);
      instance.SetNewArray(&newArray_vectorlEQuantumNumbersgR);
      instance.SetDelete(&delete_vectorlEQuantumNumbersgR);
      instance.SetDeleteArray(&deleteArray_vectorlEQuantumNumbersgR);
      instance.SetDestructor(&destruct_vectorlEQuantumNumbersgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<QuantumNumbers> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<QuantumNumbers>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEQuantumNumbersgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<QuantumNumbers>*)0x0)->GetClass();
      vectorlEQuantumNumbersgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEQuantumNumbersgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEQuantumNumbersgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<QuantumNumbers> : new vector<QuantumNumbers>;
   }
   static void *newArray_vectorlEQuantumNumbersgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<QuantumNumbers>[nElements] : new vector<QuantumNumbers>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEQuantumNumbersgR(void *p) {
      delete ((vector<QuantumNumbers>*)p);
   }
   static void deleteArray_vectorlEQuantumNumbersgR(void *p) {
      delete [] ((vector<QuantumNumbers>*)p);
   }
   static void destruct_vectorlEQuantumNumbersgR(void *p) {
      typedef vector<QuantumNumbers> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<QuantumNumbers>

namespace ROOT {
   static TClass *vectorlEQuadruplegR_Dictionary();
   static void vectorlEQuadruplegR_TClassManip(TClass*);
   static void *new_vectorlEQuadruplegR(void *p = 0);
   static void *newArray_vectorlEQuadruplegR(Long_t size, void *p);
   static void delete_vectorlEQuadruplegR(void *p);
   static void deleteArray_vectorlEQuadruplegR(void *p);
   static void destruct_vectorlEQuadruplegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<Quadruple>*)
   {
      vector<Quadruple> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<Quadruple>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<Quadruple>", -2, "vector", 210,
                  typeid(vector<Quadruple>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEQuadruplegR_Dictionary, isa_proxy, 4,
                  sizeof(vector<Quadruple>) );
      instance.SetNew(&new_vectorlEQuadruplegR);
      instance.SetNewArray(&newArray_vectorlEQuadruplegR);
      instance.SetDelete(&delete_vectorlEQuadruplegR);
      instance.SetDeleteArray(&deleteArray_vectorlEQuadruplegR);
      instance.SetDestructor(&destruct_vectorlEQuadruplegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<Quadruple> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<Quadruple>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEQuadruplegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<Quadruple>*)0x0)->GetClass();
      vectorlEQuadruplegR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEQuadruplegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEQuadruplegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Quadruple> : new vector<Quadruple>;
   }
   static void *newArray_vectorlEQuadruplegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<Quadruple>[nElements] : new vector<Quadruple>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEQuadruplegR(void *p) {
      delete ((vector<Quadruple>*)p);
   }
   static void deleteArray_vectorlEQuadruplegR(void *p) {
      delete [] ((vector<Quadruple>*)p);
   }
   static void destruct_vectorlEQuadruplegR(void *p) {
      typedef vector<Quadruple> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<Quadruple>

namespace ROOT {
   static TClass *setlErfacFieldGridPointgR_Dictionary();
   static void setlErfacFieldGridPointgR_TClassManip(TClass*);
   static void *new_setlErfacFieldGridPointgR(void *p = 0);
   static void *newArray_setlErfacFieldGridPointgR(Long_t size, void *p);
   static void delete_setlErfacFieldGridPointgR(void *p);
   static void deleteArray_setlErfacFieldGridPointgR(void *p);
   static void destruct_setlErfacFieldGridPointgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<rfacFieldGridPoint>*)
   {
      set<rfacFieldGridPoint> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<rfacFieldGridPoint>));
      static ::ROOT::TGenericClassInfo 
         instance("set<rfacFieldGridPoint>", -2, "set", 90,
                  typeid(set<rfacFieldGridPoint>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlErfacFieldGridPointgR_Dictionary, isa_proxy, 4,
                  sizeof(set<rfacFieldGridPoint>) );
      instance.SetNew(&new_setlErfacFieldGridPointgR);
      instance.SetNewArray(&newArray_setlErfacFieldGridPointgR);
      instance.SetDelete(&delete_setlErfacFieldGridPointgR);
      instance.SetDeleteArray(&deleteArray_setlErfacFieldGridPointgR);
      instance.SetDestructor(&destruct_setlErfacFieldGridPointgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<rfacFieldGridPoint> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const set<rfacFieldGridPoint>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlErfacFieldGridPointgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const set<rfacFieldGridPoint>*)0x0)->GetClass();
      setlErfacFieldGridPointgR_TClassManip(theClass);
   return theClass;
   }

   static void setlErfacFieldGridPointgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlErfacFieldGridPointgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) set<rfacFieldGridPoint> : new set<rfacFieldGridPoint>;
   }
   static void *newArray_setlErfacFieldGridPointgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) set<rfacFieldGridPoint>[nElements] : new set<rfacFieldGridPoint>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlErfacFieldGridPointgR(void *p) {
      delete ((set<rfacFieldGridPoint>*)p);
   }
   static void deleteArray_setlErfacFieldGridPointgR(void *p) {
      delete [] ((set<rfacFieldGridPoint>*)p);
   }
   static void destruct_setlErfacFieldGridPointgR(void *p) {
      typedef set<rfacFieldGridPoint> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class set<rfacFieldGridPoint>

namespace ROOT {
   static TClass *setlEQuantumNumbersgR_Dictionary();
   static void setlEQuantumNumbersgR_TClassManip(TClass*);
   static void *new_setlEQuantumNumbersgR(void *p = 0);
   static void *newArray_setlEQuantumNumbersgR(Long_t size, void *p);
   static void delete_setlEQuantumNumbersgR(void *p);
   static void deleteArray_setlEQuantumNumbersgR(void *p);
   static void destruct_setlEQuantumNumbersgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const set<QuantumNumbers>*)
   {
      set<QuantumNumbers> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(set<QuantumNumbers>));
      static ::ROOT::TGenericClassInfo 
         instance("set<QuantumNumbers>", -2, "set", 90,
                  typeid(set<QuantumNumbers>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &setlEQuantumNumbersgR_Dictionary, isa_proxy, 4,
                  sizeof(set<QuantumNumbers>) );
      instance.SetNew(&new_setlEQuantumNumbersgR);
      instance.SetNewArray(&newArray_setlEQuantumNumbersgR);
      instance.SetDelete(&delete_setlEQuantumNumbersgR);
      instance.SetDeleteArray(&deleteArray_setlEQuantumNumbersgR);
      instance.SetDestructor(&destruct_setlEQuantumNumbersgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Insert< set<QuantumNumbers> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const set<QuantumNumbers>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *setlEQuantumNumbersgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const set<QuantumNumbers>*)0x0)->GetClass();
      setlEQuantumNumbersgR_TClassManip(theClass);
   return theClass;
   }

   static void setlEQuantumNumbersgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_setlEQuantumNumbersgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) set<QuantumNumbers> : new set<QuantumNumbers>;
   }
   static void *newArray_setlEQuantumNumbersgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) set<QuantumNumbers>[nElements] : new set<QuantumNumbers>[nElements];
   }
   // Wrapper around operator delete
   static void delete_setlEQuantumNumbersgR(void *p) {
      delete ((set<QuantumNumbers>*)p);
   }
   static void deleteArray_setlEQuantumNumbersgR(void *p) {
      delete [] ((set<QuantumNumbers>*)p);
   }
   static void destruct_setlEQuantumNumbersgR(void *p) {
      typedef set<QuantumNumbers> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class set<QuantumNumbers>

namespace ROOT {
   static TClass *maplEQuantumNumberscOrfacLinearInterpolationgR_Dictionary();
   static void maplEQuantumNumberscOrfacLinearInterpolationgR_TClassManip(TClass*);
   static void *new_maplEQuantumNumberscOrfacLinearInterpolationgR(void *p = 0);
   static void *newArray_maplEQuantumNumberscOrfacLinearInterpolationgR(Long_t size, void *p);
   static void delete_maplEQuantumNumberscOrfacLinearInterpolationgR(void *p);
   static void deleteArray_maplEQuantumNumberscOrfacLinearInterpolationgR(void *p);
   static void destruct_maplEQuantumNumberscOrfacLinearInterpolationgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<QuantumNumbers,rfacLinearInterpolation>*)
   {
      map<QuantumNumbers,rfacLinearInterpolation> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<QuantumNumbers,rfacLinearInterpolation>));
      static ::ROOT::TGenericClassInfo 
         instance("map<QuantumNumbers,rfacLinearInterpolation>", -2, "map", 96,
                  typeid(map<QuantumNumbers,rfacLinearInterpolation>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEQuantumNumberscOrfacLinearInterpolationgR_Dictionary, isa_proxy, 4,
                  sizeof(map<QuantumNumbers,rfacLinearInterpolation>) );
      instance.SetNew(&new_maplEQuantumNumberscOrfacLinearInterpolationgR);
      instance.SetNewArray(&newArray_maplEQuantumNumberscOrfacLinearInterpolationgR);
      instance.SetDelete(&delete_maplEQuantumNumberscOrfacLinearInterpolationgR);
      instance.SetDeleteArray(&deleteArray_maplEQuantumNumberscOrfacLinearInterpolationgR);
      instance.SetDestructor(&destruct_maplEQuantumNumberscOrfacLinearInterpolationgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<QuantumNumbers,rfacLinearInterpolation> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<QuantumNumbers,rfacLinearInterpolation>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEQuantumNumberscOrfacLinearInterpolationgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<QuantumNumbers,rfacLinearInterpolation>*)0x0)->GetClass();
      maplEQuantumNumberscOrfacLinearInterpolationgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEQuantumNumberscOrfacLinearInterpolationgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEQuantumNumberscOrfacLinearInterpolationgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,rfacLinearInterpolation> : new map<QuantumNumbers,rfacLinearInterpolation>;
   }
   static void *newArray_maplEQuantumNumberscOrfacLinearInterpolationgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,rfacLinearInterpolation>[nElements] : new map<QuantumNumbers,rfacLinearInterpolation>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEQuantumNumberscOrfacLinearInterpolationgR(void *p) {
      delete ((map<QuantumNumbers,rfacLinearInterpolation>*)p);
   }
   static void deleteArray_maplEQuantumNumberscOrfacLinearInterpolationgR(void *p) {
      delete [] ((map<QuantumNumbers,rfacLinearInterpolation>*)p);
   }
   static void destruct_maplEQuantumNumberscOrfacLinearInterpolationgR(void *p) {
      typedef map<QuantumNumbers,rfacLinearInterpolation> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<QuantumNumbers,rfacLinearInterpolation>

namespace ROOT {
   static TClass *maplEQuantumNumberscOrfacInterpolatorContainermUgR_Dictionary();
   static void maplEQuantumNumberscOrfacInterpolatorContainermUgR_TClassManip(TClass*);
   static void *new_maplEQuantumNumberscOrfacInterpolatorContainermUgR(void *p = 0);
   static void *newArray_maplEQuantumNumberscOrfacInterpolatorContainermUgR(Long_t size, void *p);
   static void delete_maplEQuantumNumberscOrfacInterpolatorContainermUgR(void *p);
   static void deleteArray_maplEQuantumNumberscOrfacInterpolatorContainermUgR(void *p);
   static void destruct_maplEQuantumNumberscOrfacInterpolatorContainermUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<QuantumNumbers,rfacInterpolatorContainer*>*)
   {
      map<QuantumNumbers,rfacInterpolatorContainer*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<QuantumNumbers,rfacInterpolatorContainer*>));
      static ::ROOT::TGenericClassInfo 
         instance("map<QuantumNumbers,rfacInterpolatorContainer*>", -2, "map", 96,
                  typeid(map<QuantumNumbers,rfacInterpolatorContainer*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEQuantumNumberscOrfacInterpolatorContainermUgR_Dictionary, isa_proxy, 0,
                  sizeof(map<QuantumNumbers,rfacInterpolatorContainer*>) );
      instance.SetNew(&new_maplEQuantumNumberscOrfacInterpolatorContainermUgR);
      instance.SetNewArray(&newArray_maplEQuantumNumberscOrfacInterpolatorContainermUgR);
      instance.SetDelete(&delete_maplEQuantumNumberscOrfacInterpolatorContainermUgR);
      instance.SetDeleteArray(&deleteArray_maplEQuantumNumberscOrfacInterpolatorContainermUgR);
      instance.SetDestructor(&destruct_maplEQuantumNumberscOrfacInterpolatorContainermUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<QuantumNumbers,rfacInterpolatorContainer*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<QuantumNumbers,rfacInterpolatorContainer*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEQuantumNumberscOrfacInterpolatorContainermUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<QuantumNumbers,rfacInterpolatorContainer*>*)0x0)->GetClass();
      maplEQuantumNumberscOrfacInterpolatorContainermUgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEQuantumNumberscOrfacInterpolatorContainermUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEQuantumNumberscOrfacInterpolatorContainermUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,rfacInterpolatorContainer*> : new map<QuantumNumbers,rfacInterpolatorContainer*>;
   }
   static void *newArray_maplEQuantumNumberscOrfacInterpolatorContainermUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,rfacInterpolatorContainer*>[nElements] : new map<QuantumNumbers,rfacInterpolatorContainer*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEQuantumNumberscOrfacInterpolatorContainermUgR(void *p) {
      delete ((map<QuantumNumbers,rfacInterpolatorContainer*>*)p);
   }
   static void deleteArray_maplEQuantumNumberscOrfacInterpolatorContainermUgR(void *p) {
      delete [] ((map<QuantumNumbers,rfacInterpolatorContainer*>*)p);
   }
   static void destruct_maplEQuantumNumberscOrfacInterpolatorContainermUgR(void *p) {
      typedef map<QuantumNumbers,rfacInterpolatorContainer*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<QuantumNumbers,rfacInterpolatorContainer*>

namespace ROOT {
   static TClass *maplEQuantumNumberscOrfac3DInterpolationgR_Dictionary();
   static void maplEQuantumNumberscOrfac3DInterpolationgR_TClassManip(TClass*);
   static void *new_maplEQuantumNumberscOrfac3DInterpolationgR(void *p = 0);
   static void *newArray_maplEQuantumNumberscOrfac3DInterpolationgR(Long_t size, void *p);
   static void delete_maplEQuantumNumberscOrfac3DInterpolationgR(void *p);
   static void deleteArray_maplEQuantumNumberscOrfac3DInterpolationgR(void *p);
   static void destruct_maplEQuantumNumberscOrfac3DInterpolationgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<QuantumNumbers,rfac3DInterpolation>*)
   {
      map<QuantumNumbers,rfac3DInterpolation> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<QuantumNumbers,rfac3DInterpolation>));
      static ::ROOT::TGenericClassInfo 
         instance("map<QuantumNumbers,rfac3DInterpolation>", -2, "map", 96,
                  typeid(map<QuantumNumbers,rfac3DInterpolation>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEQuantumNumberscOrfac3DInterpolationgR_Dictionary, isa_proxy, 0,
                  sizeof(map<QuantumNumbers,rfac3DInterpolation>) );
      instance.SetNew(&new_maplEQuantumNumberscOrfac3DInterpolationgR);
      instance.SetNewArray(&newArray_maplEQuantumNumberscOrfac3DInterpolationgR);
      instance.SetDelete(&delete_maplEQuantumNumberscOrfac3DInterpolationgR);
      instance.SetDeleteArray(&deleteArray_maplEQuantumNumberscOrfac3DInterpolationgR);
      instance.SetDestructor(&destruct_maplEQuantumNumberscOrfac3DInterpolationgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<QuantumNumbers,rfac3DInterpolation> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<QuantumNumbers,rfac3DInterpolation>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEQuantumNumberscOrfac3DInterpolationgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<QuantumNumbers,rfac3DInterpolation>*)0x0)->GetClass();
      maplEQuantumNumberscOrfac3DInterpolationgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEQuantumNumberscOrfac3DInterpolationgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEQuantumNumberscOrfac3DInterpolationgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,rfac3DInterpolation> : new map<QuantumNumbers,rfac3DInterpolation>;
   }
   static void *newArray_maplEQuantumNumberscOrfac3DInterpolationgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,rfac3DInterpolation>[nElements] : new map<QuantumNumbers,rfac3DInterpolation>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEQuantumNumberscOrfac3DInterpolationgR(void *p) {
      delete ((map<QuantumNumbers,rfac3DInterpolation>*)p);
   }
   static void deleteArray_maplEQuantumNumberscOrfac3DInterpolationgR(void *p) {
      delete [] ((map<QuantumNumbers,rfac3DInterpolation>*)p);
   }
   static void destruct_maplEQuantumNumberscOrfac3DInterpolationgR(void *p) {
      typedef map<QuantumNumbers,rfac3DInterpolation> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<QuantumNumbers,rfac3DInterpolation>

namespace ROOT {
   static TClass *maplEQuantumNumberscOdoublegR_Dictionary();
   static void maplEQuantumNumberscOdoublegR_TClassManip(TClass*);
   static void *new_maplEQuantumNumberscOdoublegR(void *p = 0);
   static void *newArray_maplEQuantumNumberscOdoublegR(Long_t size, void *p);
   static void delete_maplEQuantumNumberscOdoublegR(void *p);
   static void deleteArray_maplEQuantumNumberscOdoublegR(void *p);
   static void destruct_maplEQuantumNumberscOdoublegR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<QuantumNumbers,double>*)
   {
      map<QuantumNumbers,double> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<QuantumNumbers,double>));
      static ::ROOT::TGenericClassInfo 
         instance("map<QuantumNumbers,double>", -2, "map", 96,
                  typeid(map<QuantumNumbers,double>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEQuantumNumberscOdoublegR_Dictionary, isa_proxy, 4,
                  sizeof(map<QuantumNumbers,double>) );
      instance.SetNew(&new_maplEQuantumNumberscOdoublegR);
      instance.SetNewArray(&newArray_maplEQuantumNumberscOdoublegR);
      instance.SetDelete(&delete_maplEQuantumNumberscOdoublegR);
      instance.SetDeleteArray(&deleteArray_maplEQuantumNumberscOdoublegR);
      instance.SetDestructor(&destruct_maplEQuantumNumberscOdoublegR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<QuantumNumbers,double> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<QuantumNumbers,double>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEQuantumNumberscOdoublegR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<QuantumNumbers,double>*)0x0)->GetClass();
      maplEQuantumNumberscOdoublegR_TClassManip(theClass);
   return theClass;
   }

   static void maplEQuantumNumberscOdoublegR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEQuantumNumberscOdoublegR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,double> : new map<QuantumNumbers,double>;
   }
   static void *newArray_maplEQuantumNumberscOdoublegR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,double>[nElements] : new map<QuantumNumbers,double>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEQuantumNumberscOdoublegR(void *p) {
      delete ((map<QuantumNumbers,double>*)p);
   }
   static void deleteArray_maplEQuantumNumberscOdoublegR(void *p) {
      delete [] ((map<QuantumNumbers,double>*)p);
   }
   static void destruct_maplEQuantumNumberscOdoublegR(void *p) {
      typedef map<QuantumNumbers,double> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<QuantumNumbers,double>

namespace ROOT {
   static TClass *maplEQuantumNumberscOEnergyLevelgR_Dictionary();
   static void maplEQuantumNumberscOEnergyLevelgR_TClassManip(TClass*);
   static void *new_maplEQuantumNumberscOEnergyLevelgR(void *p = 0);
   static void *newArray_maplEQuantumNumberscOEnergyLevelgR(Long_t size, void *p);
   static void delete_maplEQuantumNumberscOEnergyLevelgR(void *p);
   static void deleteArray_maplEQuantumNumberscOEnergyLevelgR(void *p);
   static void destruct_maplEQuantumNumberscOEnergyLevelgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<QuantumNumbers,EnergyLevel>*)
   {
      map<QuantumNumbers,EnergyLevel> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<QuantumNumbers,EnergyLevel>));
      static ::ROOT::TGenericClassInfo 
         instance("map<QuantumNumbers,EnergyLevel>", -2, "map", 96,
                  typeid(map<QuantumNumbers,EnergyLevel>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEQuantumNumberscOEnergyLevelgR_Dictionary, isa_proxy, 4,
                  sizeof(map<QuantumNumbers,EnergyLevel>) );
      instance.SetNew(&new_maplEQuantumNumberscOEnergyLevelgR);
      instance.SetNewArray(&newArray_maplEQuantumNumberscOEnergyLevelgR);
      instance.SetDelete(&delete_maplEQuantumNumberscOEnergyLevelgR);
      instance.SetDeleteArray(&deleteArray_maplEQuantumNumberscOEnergyLevelgR);
      instance.SetDestructor(&destruct_maplEQuantumNumberscOEnergyLevelgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<QuantumNumbers,EnergyLevel> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<QuantumNumbers,EnergyLevel>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEQuantumNumberscOEnergyLevelgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<QuantumNumbers,EnergyLevel>*)0x0)->GetClass();
      maplEQuantumNumberscOEnergyLevelgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEQuantumNumberscOEnergyLevelgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEQuantumNumberscOEnergyLevelgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,EnergyLevel> : new map<QuantumNumbers,EnergyLevel>;
   }
   static void *newArray_maplEQuantumNumberscOEnergyLevelgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<QuantumNumbers,EnergyLevel>[nElements] : new map<QuantumNumbers,EnergyLevel>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEQuantumNumberscOEnergyLevelgR(void *p) {
      delete ((map<QuantumNumbers,EnergyLevel>*)p);
   }
   static void deleteArray_maplEQuantumNumberscOEnergyLevelgR(void *p) {
      delete [] ((map<QuantumNumbers,EnergyLevel>*)p);
   }
   static void destruct_maplEQuantumNumberscOEnergyLevelgR(void *p) {
      typedef map<QuantumNumbers,EnergyLevel> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<QuantumNumbers,EnergyLevel>

namespace {
  void TriggerDictionaryInitialization_Dictionary_Impl() {
    static const char* headers[] = {
"include/EnergyLevel.hh",
"include/QuantumNumbers.hh",
"include/StrongFieldQuantumNumbers.hh",
"include/rfacEssentialData.hh",
"include/rfacSpecificLevelData.hh",
"include/rfacInterpolatorContainer.hh",
"include/rfacQuantumNumberLister.hh",
"include/rfacLevelPicker.hh",
"include/rfacInterpolation.hh",
"include/rfacInterpolatorPicker.hh",
"include/rfacException.hh",
"include/rfacLinearInterpolation.hh",
"include/rfacFieldGridPicker.hh",
"include/rfacFieldGridPoint.hh",
"include/rfacFieldGridContainer.hh",
"include/rfacQuantumNumberContainer.hh",
"include/rfacLevelContainer.hh",
"include/rfacDecayableObject.hh",
"include/rfacFieldRegimeTranslator.hh",
"include/GeneralQuantumNumbers.hh",
0
    };
    static const char* includePaths[] = {
"lib",
"RLlib/include",
"/phys/root6/include",
"/phys/root-6.06.06/include",
"/home/markus/src/hbar_cfac_rikard/DataTool/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "Dictionary dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
class __attribute__((annotate(R"ATTRDUMP(/ Energy levels.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$rfacSpecificLevelData.hh")))  EnergyLevel;
class __attribute__((annotate("$clingAutoload$rfacSpecificLevelData.hh")))  QuantumNumbers;
class __attribute__((annotate("$clingAutoload$StrongFieldQuantumNumbers.hh")))  StrongFieldQuantumNumbers;
class __attribute__((annotate(R"ATTRDUMP(/ Essential level data.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$rfacEssentialData.hh")))  rfacEssentialData;
class __attribute__((annotate(R"ATTRDUMP(/ Essential level data.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$rfacSpecificLevelData.hh")))  rfacSpecificLevelData;
class __attribute__((annotate("$clingAutoload$rfacQuantumNumberLister.hh")))  rfacQuantumNumberLister;
class __attribute__((annotate("$clingAutoload$rfacLevelPicker.hh")))  rfacLevelPicker;
class __attribute__((annotate("$clingAutoload$rfacQuantumNumberLister.hh")))  rfacException;
class __attribute__((annotate("$clingAutoload$include/rfacInterpolation.hh")))  rfacInterpolation;
class __attribute__((annotate("$clingAutoload$rfacInterpolatorContainer.hh")))  rfac3DInterpolation;
class __attribute__((annotate("$clingAutoload$rfacInterpolatorContainer.hh")))  Quadruple;
class __attribute__((annotate(R"ATTRDUMP(/ Essential level data.)ATTRDUMP"))) __attribute__((annotate("$clingAutoload$rfacInterpolatorContainer.hh")))  rfacInterpolatorContainer;
class __attribute__((annotate("$clingAutoload$include/rfacInterpolation.hh")))  rfacInterpolatorPicker;
class __attribute__((annotate("$clingAutoload$rfacInterpolatorContainer.hh")))  rfacLinearInterpolation;
class __attribute__((annotate("$clingAutoload$rfacFieldGridPicker.hh")))  rfacFieldGridPicker;
class __attribute__((annotate("$clingAutoload$rfacInterpolatorContainer.hh")))  rfacFieldGridPoint;
class __attribute__((annotate("$clingAutoload$rfacInterpolatorContainer.hh")))  rfacFieldGridContainer;
class __attribute__((annotate("$clingAutoload$rfacQuantumNumberLister.hh")))  rfacQuantumNumberContainer;
class __attribute__((annotate("$clingAutoload$rfacLevelPicker.hh")))  rfacLevelContainer;
class __attribute__((annotate("$clingAutoload$include/rfacDecayableObject.hh")))  rfacDecayableObject;
class __attribute__((annotate("$clingAutoload$rfacFieldRegimeTranslator.hh")))  rfacFieldRegimeTranslator;
class __attribute__((annotate("$clingAutoload$rfacFieldRegimeTranslator.hh")))  CGTranslator;
class __attribute__((annotate("$clingAutoload$rfacSpecificLevelData.hh")))  GeneralQuantumNumbers;
namespace std{template <typename _Tp> class __attribute__((annotate("$clingAutoload$string")))  allocator;
}
namespace std{template <typename _Tp> struct __attribute__((annotate("$clingAutoload$string")))  less;
}
namespace std{template <typename _Tp> struct __attribute__((annotate("$clingAutoload$map")))  _Rb_tree_const_iterator;
}
namespace std{template <class _T1, class _T2> struct __attribute__((annotate("$clingAutoload$string")))  pair;
}
template <class Element> class __attribute__((annotate("$clingAutoload$TMultiDimFit.h")))  TVectorT;

)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "Dictionary dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif
#ifndef USE_ROOT
  #define USE_ROOT 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "include/EnergyLevel.hh"
#include "include/QuantumNumbers.hh"
#include "include/StrongFieldQuantumNumbers.hh"
#include "include/rfacEssentialData.hh"
#include "include/rfacSpecificLevelData.hh"
#include "include/rfacInterpolatorContainer.hh"
#include "include/rfacQuantumNumberLister.hh"
#include "include/rfacLevelPicker.hh"
#include "include/rfacInterpolation.hh"
#include "include/rfacInterpolatorPicker.hh"
#include "include/rfacException.hh"
#include "include/rfacLinearInterpolation.hh"
#include "include/rfacFieldGridPicker.hh"
#include "include/rfacFieldGridPoint.hh"
#include "include/rfacFieldGridContainer.hh"
#include "include/rfacQuantumNumberContainer.hh"
#include "include/rfacLevelContainer.hh"
#include "include/rfacDecayableObject.hh"
#include "include/rfacFieldRegimeTranslator.hh"
#include "include/GeneralQuantumNumbers.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"CGTranslator", payloadCode, "@",
"EnergyLevel", payloadCode, "@",
"GeneralQuantumNumbers", payloadCode, "@",
"Quadruple", payloadCode, "@",
"QuantumNumbers", payloadCode, "@",
"StrongFieldQuantumNumbers", payloadCode, "@",
"__gnu_cxx::__normal_iterator<QuantumNumbers*,vector<QuantumNumbers> >", payloadCode, "@",
"rfac3DInterpolation", payloadCode, "@",
"rfacDecayableObject", payloadCode, "@",
"rfacEssentialData", payloadCode, "@",
"rfacException", payloadCode, "@",
"rfacFieldGridContainer", payloadCode, "@",
"rfacFieldGridPicker", payloadCode, "@",
"rfacFieldGridPoint", payloadCode, "@",
"rfacFieldRegimeTranslator", payloadCode, "@",
"rfacInterpolation", payloadCode, "@",
"rfacInterpolatorContainer", payloadCode, "@",
"rfacInterpolatorPicker", payloadCode, "@",
"rfacLevelContainer", payloadCode, "@",
"rfacLevelPicker", payloadCode, "@",
"rfacLinearInterpolation", payloadCode, "@",
"rfacQuantumNumberContainer", payloadCode, "@",
"rfacQuantumNumberLister", payloadCode, "@",
"rfacSpecificLevelData", payloadCode, "@",
"vector<QuantumNumbers>::iterator", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("Dictionary",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_Dictionary_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_Dictionary_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_Dictionary() {
  TriggerDictionaryInitialization_Dictionary_Impl();
}
