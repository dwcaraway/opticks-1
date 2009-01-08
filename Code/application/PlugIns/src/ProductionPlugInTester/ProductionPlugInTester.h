/*
 * The information in this file is
 * Copyright(c) 2007 Ball Aerospace & Technologies Corporation
 * and is subject to the terms and conditions of the
 * GNU Lesser General Public License Version 2.1
 * The license text is available from   
 * http://www.gnu.org/licenses/lgpl.html
 */

#ifndef PRODUCTIONPLUGINTESTER_H
#define PRODUCTIONPLUGINTESTER_H

#include "AlgorithmShell.h"
#include "PlugInManagerServices.h"

class ProductionPlugInTester : public AlgorithmShell
{
public:
   ProductionPlugInTester();

   bool getInputSpecification(PlugInArgList*& pArgList);
   bool getOutputSpecification(PlugInArgList*& pArgList);

   bool execute(PlugInArgList* pInArgList, PlugInArgList* pOutArgList);
   bool setBatch();

private:
   Service<PlugInManagerServices> mpPlugMgr;
};

#endif