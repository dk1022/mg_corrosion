#include "MgCorrosionApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MgCorrosionApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

MgCorrosionApp::MgCorrosionApp(InputParameters parameters) : MooseApp(parameters)
{
  MgCorrosionApp::registerAll(_factory, _action_factory, _syntax);
}

MgCorrosionApp::~MgCorrosionApp() {}

void
MgCorrosionApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MgCorrosionApp"});
  Registry::registerActionsTo(af, {"MgCorrosionApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MgCorrosionApp::registerApps()
{
  registerApp(MgCorrosionApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MgCorrosionApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MgCorrosionApp::registerAll(f, af, s);
}
extern "C" void
MgCorrosionApp__registerApps()
{
  MgCorrosionApp::registerApps();
}
