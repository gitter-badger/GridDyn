/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil;  eval: (c-set-offset 'innamespace 0); -*- */
/*
 * LLNS Copyright Start
 * Copyright (c) 2016, Lawrence Livermore National Security
 * This work was performed under the auspices of the U.S. Department
 * of Energy by Lawrence Livermore National Laboratory in part under
 * Contract W-7405-Eng-48 and in part under Contract DE-AC52-07NA27344.
 * Produced at the Lawrence Livermore National Laboratory.
 * All rights reserved.
 * For details, see the LICENSE file.
 * LLNS Copyright End
*/

#ifndef GRIDLOADOPT_H_
#define GRIDLOADOPT_H_


// headers
#include "basicDefs.h"
#include "gridOptObjects.h"
// forward classes


class gridBusOpt;
class gridLoad;

class gridLoadOpt : public gridOptObject
{

public:
protected:
  gridBusOpt *bus;

  gridLoad *load = nullptr;


public:
  gridLoadOpt (const std::string &objName = "");
  gridLoadOpt (gridCoreObject *obj, const std::string &objName = "");

  ~gridLoadOpt ();

  virtual gridCoreObject * clone (gridCoreObject *obj = nullptr) const override;

  virtual int add (gridCoreObject *obj) override;
  virtual count_t objSize (const optimMode &oMode);
  virtual count_t contObjSize (const optimMode &oMode);
  virtual count_t intObjSize (const optimMode &oMode);
  virtual count_t constraintSize (const optimMode &oMode);

  virtual void objectInitializeA (unsigned long flags) override;

  virtual void setValues (const optimData *oD, const optimMode &oMode) override;
  //for saving the state
  virtual void guess (double ttime, double val[], const optimMode &oMode) override;
  virtual void getTols (double tols[], const optimMode &oMode) override;
  virtual void getVariableType (double sdata[], const optimMode &oMode) override;

  virtual void valueBounds (double ttime, double upLimit[], double lowerLimit[], const optimMode &oMode) override;

  virtual void linearObj (const optimData *oD, vectData *linObj, const optimMode &oMode) override;
  virtual void quadraticObj (const optimData *oD, vectData *linObj, vectData *quadObj, const optimMode &oMode) override;

  virtual double objValue (const optimData *oD, const optimMode &oMode) override;
  virtual void derivative (const optimData *oD, double deriv[], const optimMode &oMode) override;
  virtual void jacobianElements (const optimData *oD, arrayData<double> *ad, const optimMode &oMode) override;
  virtual void getConstraints (const optimData *oD, arrayData<double> *cons, double upperLimit[], double lowerLimit[], const optimMode &oMode) override;
  virtual void constraintValue (const optimData *oD, double cVals[], const optimMode &oMode) override;
  virtual void constraintJacobianElements (const optimData *oD, arrayData<double> *ad, const optimMode &oMode) override;
  virtual void getObjName (stringVec &objNames, const optimMode &oMode, const std::string &prefix = "") override;


  virtual int set (const std::string &param,  const std::string &val) override;
  virtual int set (const std::string &param, double val, gridUnits::units_t unitType = gridUnits::defUnit) override;
  // parameter get functions
  virtual double get (const std::string &param, gridUnits::units_t unitType = gridUnits::defUnit) const override;


  virtual gridOptObject * getBus (index_t index) const override;
  virtual gridOptObject * getArea (index_t index) const override;
protected:
};

#endif
