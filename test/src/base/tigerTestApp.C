//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "tigerTestApp.h"
#include "tigerApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
tigerTestApp::validParams()
{
  InputParameters params = tigerApp::validParams();
  return params;
}

tigerTestApp::tigerTestApp(InputParameters parameters) : MooseApp(parameters)
{
  tigerTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

tigerTestApp::~tigerTestApp() {}

void
tigerTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  tigerApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"tigerTestApp"});
    Registry::registerActionsTo(af, {"tigerTestApp"});
  }
}

void
tigerTestApp::registerApps()
{
  registerApp(tigerApp);
  registerApp(tigerTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
tigerTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  tigerTestApp::registerAll(f, af, s);
}
extern "C" void
tigerTestApp__registerApps()
{
  tigerTestApp::registerApps();
}
