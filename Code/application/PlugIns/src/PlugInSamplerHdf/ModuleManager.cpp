/*
 * The information in this file is
 * Copyright(c) 2007 Ball Aerospace & Technologies Corporation
 * and is subject to the terms and conditions of the
 * GNU Lesser General Public License Version 2.1
 * The license text is available from   
 * http://www.gnu.org/licenses/lgpl.html
 */

#include "AppConfig.h"
#include "ModuleManager.h"

#if defined(HDF4_SUPPORT)
#include "SampleHdf4Importer.h"
#endif

const char* ModuleManager::mspName = "Plug-In Sampler Hdf";
const char* ModuleManager::mspVersion = "1.0";
const char* ModuleManager::mspDescription = "Sample plug-ins that test various components in the published interfaces.";
const char* ModuleManager::mspValidationKey = "none";
const char* ModuleManager::mspUniqueId = "{D1F56217-05AA-4554-93B8-6950B8E24E93}";

unsigned int ModuleManager::getTotalPlugIns()
{
#if defined(HDF4_SUPPORT)
   return 1;
#else
   return 0;
#endif
}

PlugIn* ModuleManager::getPlugIn(unsigned int plugInNumber)
{
   PlugIn* pPlugIn = NULL;
   switch (plugInNumber)
   {
#if defined(HDF4_SUPPORT)
      case 0:
         pPlugIn = new SampleHdf4Importer();
         break;
#endif

      default:
         break;
   }

   return pPlugIn;
}