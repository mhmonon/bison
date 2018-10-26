#include "bisonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<bisonApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

bisonApp::bisonApp(InputParameters parameters) : MooseApp(parameters)
{
  bisonApp::registerAll(_factory, _action_factory, _syntax);
}

bisonApp::~bisonApp() {}

void
bisonApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"bisonApp"});
  Registry::registerActionsTo(af, {"bisonApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
bisonApp::registerApps()
{
  registerApp(bisonApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
bisonApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bisonApp::registerAll(f, af, s);
}
extern "C" void
bisonApp__registerApps()
{
  bisonApp::registerApps();
}
