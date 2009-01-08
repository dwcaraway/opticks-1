/*
 * The information in this file is
 * Copyright(c) 2007 Ball Aerospace & Technologies Corporation
 * and is subject to the terms and conditions of the
 * GNU Lesser General Public License Version 2.1
 * The license text is available from   
 * http://www.gnu.org/licenses/lgpl.html
 */

#include "GeoreferencePlugIn.h"
#include "GcpGeoreference.h"
#include "ModuleManager.h"

const char* ModuleManager::mspName = "Georeference";
const char* ModuleManager::mspVersion = "1.0.0";
const char* ModuleManager::mspDescription = "Georeference Module.";
const char* ModuleManager::mspValidationKey = "none";
const char* ModuleManager::mspUniqueId = "{6F08CA75-EA22-4d0c-A12D-2962399E56E6}";

unsigned int ModuleManager::getTotalPlugIns()
{
   return 2;
}

PlugIn* ModuleManager::getPlugIn(unsigned int plugInNumber)
{
   PlugIn* pPlugIn = NULL;
   switch (plugInNumber)
   {
      case 0:
         pPlugIn = new GeoreferencePlugIn();
         break;

      case 1:
         pPlugIn = new GcpGeoreference();
         break;

      default:
         break;
   }

   return pPlugIn;
}