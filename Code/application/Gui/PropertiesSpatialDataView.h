/*
 * The information in this file is
 * Copyright(c) 2007 Ball Aerospace & Technologies Corporation
 * and is subject to the terms and conditions of the
 * GNU Lesser General Public License Version 2.1
 * The license text is available from   
 * http://www.gnu.org/licenses/lgpl.html
 */

#ifndef PROPERTIESSPATIALDATAVIEW_H
#define PROPERTIESSPATIALDATAVIEW_H

#include <QtGui/QCheckBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QSpinBox>

#include "LabeledSectionGroup.h"

#include <string>

class PanLimitTypeComboBox;
class SessionItem;
class SpatialDataView;

class PropertiesSpatialDataView : public LabeledSectionGroup
{
public:
   PropertiesSpatialDataView();
   ~PropertiesSpatialDataView();

   bool initialize(SessionItem* pSessionItem);
   bool applyChanges();

   static const std::string& getName();
   static const std::string& getPropertiesName();
   static const std::string& getDescription();
   static const std::string& getShortDescription();
   static const std::string& getCreator();
   static const std::string& getCopyright();
   static const std::string& getVersion();
   static const std::string& getDescriptorId();
   static bool isProduction();

private:
   PropertiesSpatialDataView(const PropertiesSpatialDataView& rhs);
   PropertiesSpatialDataView& operator=(const PropertiesSpatialDataView& rhs);
   SpatialDataView* mpView;

   // Pan and zoom
   PanLimitTypeComboBox* mpPanLimitCombo;
   QDoubleSpinBox* mpMinZoomSpin;
   QSpinBox* mpMaxZoomSpin;

   // Image
   QCheckBox* mpSmoothCheck;
};

#endif
