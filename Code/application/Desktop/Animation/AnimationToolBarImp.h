/*
 * The information in this file is
 * Copyright(c) 2007 Ball Aerospace & Technologies Corporation
 * and is subject to the terms and conditions of the
 * GNU Lesser General Public License Version 2.1
 * The license text is available from   
 * http://www.gnu.org/licenses/lgpl.html
 */

#ifndef ANIMATIONTOOLBARIMP_H
#define ANIMATIONTOOLBARIMP_H

#include <QtGui/QComboBox>
#include <QtGui/QLabel>
#include <QtGui/QMenu>
#include <QtGui/QSlider>
#include <QtCore/QString>

#include "ToolBarImp.h"

#include "PixmapGrid.h"
#include "PixmapGridButton.h"
#include "TypesFile.h"

#include <vector>

class AnimationController;
class AnimationCycleButton;

class AnimationToolBarImp : public ToolBarImp
{
   Q_OBJECT

public:
   AnimationToolBarImp(const std::string& id, QWidget* parent = 0);
   ~AnimationToolBarImp();

   using SessionItemImp::setIcon;

   const std::string& getObjectType() const;
   bool isKindOf(const std::string& className) const;

   void setAnimationController(AnimationController* pController);
   AnimationController* getAnimationController() const;

   void setHideTimestamp(bool hideTimestamp);
   bool getHideTimestamp() const;

   void cleanUpItems();

protected slots:
   // animation control buttons
   void speedUp();
   void slowDown();
   void changeDirection();
   void stop();
   void playPause();
   void stepForward();
   void stepBackward();

   void setCurrentFrame(int frameIndex);
   void sliderActionTriggered(int action);
   void setFrameSpeed();
   void setFrameSpeed(const QString& strSpeed);

   // Methods to update the widgets from the animation controller
   void updateAnimationState(AnimationState state);
   void updateFrameRange();
   void updateCurrentFrame(double frameValue);
   void updateFrameSpeed(double speed);
   void updateAnimationCycle(AnimationCycle cycle);

   void updateAnimationControls();

   void activateSlider();
   void releaseSlider();

   void setCanDropFrames(bool canDropFrames);

protected:
   void removeAnimationController(AnimationController* pController);

private:
   void setPlayButtonState(AnimationState state);
   void setChangeDirectionButtonState(AnimationState state);

   /**
    * WheelEventSlider is a subclass of QSlider to avoid
    * a bug in QSlider's mouse wheel event handling.
    */
   class WheelEventSlider : public QSlider
   {
   public:
      WheelEventSlider(Qt::Orientation orientation, QWidget *parent = 0);

   protected:
      /**
       * Since QSlider's wheelEvent() method does not
       * call triggerAction, we shall have to do it ourselves.
       */
      void wheelEvent(QWheelEvent *e);
   };

   QAction* mpChangeDirectionAction;   // button changes the direction in which the movie is playing
   QAction* mpStopAction;              // button to stop playing movie and return to beginning of movie
   QAction* mpPlayPauseAction;         // pause/play button
   QAction* mpSlowDownAction;          // button changes the speed to the previous value in the list
   QAction* mpSpeedUpAction;           // button changes the speed to the next value in the list
   QComboBox* mpFrameSpeedCombo;       // button changes the speed at which the movie is playing
   QAction* mpStepForwardAction;       // button steps the movie one frame forward
   QAction* mpStepBackwardAction;      // button steps the movie one frame backward
   QSlider* mpFrameSlider;             // slider is used to change the frame the movie is displaying
   QAction* mpDropFramesAction;        // button to determine show if frames can be dropped or not
   AnimationCycleButton* mpCycle;
   QLabel* mpTimestampLabel;

   AnimationController* mpController;       // current animation controller to play attached movies

   AnimationState mPrevAnimationState; // stores the previous animation state to be used after the slider is released
   bool mHideTimestamp;
};

#define ANIMATIONTOOLBARADAPTEREXTENSION_CLASSES \
   TOOLBARADAPTEREXTENSION_CLASSES

#define ANIMATIONTOOLBARADAPTER_METHODS(impClass) \
   TOOLBARADAPTER_METHODS(impClass) \
   void setAnimationController(AnimationController* pController) \
   { \
      return impClass::setAnimationController(pController); \
   } \
   AnimationController* getAnimationController() const \
   { \
      return impClass::getAnimationController(); \
   } \
   void setHideTimestamp(bool hideTimestamp) \
   { \
      return impClass::setHideTimestamp(hideTimestamp); \
   } \
   bool getHideTimestamp() const \
   { \
      return impClass::getHideTimestamp(); \
   }

#endif