//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MgCorrosionTestApp.h"
#include "MgCorrosionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
MgCorrosionTestApp::validParams()
{
  InputParameters params = MgCorrosionApp::validParams();
  return params;
}

MgCorrosionTestApp::MgCorrosionTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MgCorrosionTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MgCorrosionTestApp::~MgCorrosionTestApp() {}

void
MgCorrosionTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MgCorrosionApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MgCorrosionTestApp"});
    Registry::registerActionsTo(af, {"MgCorrosionTestApp"});
  }
}

void
MgCorrosionTestApp::registerApps()
{
  registerApp(MgCorrosionApp);
  registerApp(MgCorrosionTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MgCorrosionTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MgCorrosionTestApp::registerAll(f, af, s);
}
extern "C" void
MgCorrosionTestApp__registerApps()
{
  MgCorrosionTestApp::registerApps();
}
