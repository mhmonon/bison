//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "bisonTestApp.h"
#include "bisonApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<bisonTestApp>()
{
  InputParameters params = validParams<bisonApp>();
  return params;
}

bisonTestApp::bisonTestApp(InputParameters parameters) : MooseApp(parameters)
{
  bisonTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

bisonTestApp::~bisonTestApp() {}

void
bisonTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  bisonApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"bisonTestApp"});
    Registry::registerActionsTo(af, {"bisonTestApp"});
  }
}

void
bisonTestApp::registerApps()
{
  registerApp(bisonApp);
  registerApp(bisonTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
bisonTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  bisonTestApp::registerAll(f, af, s);
}
extern "C" void
bisonTestApp__registerApps()
{
  bisonTestApp::registerApps();
}
