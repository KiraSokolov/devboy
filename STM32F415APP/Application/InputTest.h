//******************************************************************************
//  @file InputTest.h
//  @author Nicolai Shlapunov
//
//  @details Application: Input Test Application Class, header
//
//  @copyright Copyright (c) 2017, Devtronic & Nicolai Shlapunov
//             All rights reserved.
//
//  @section SUPPORT
//
//   Devtronic invests time and resources providing this open source code,
//   please support Devtronic and open-source hardware/software by
//   donations and/or purchasing products from Devtronic.
//
//******************************************************************************

#ifndef InputTest_h
#define InputTest_h

// *****************************************************************************
// ***   Includes   ************************************************************
// *****************************************************************************
#include "DevCfg.h"
#include "AppTask.h"
#include "DisplayDrv.h"
#include "InputDrv.h"
#include "SoundDrv.h"
#include "UiEngine.h"

// *****************************************************************************
// ***   Local const variables   ***********************************************
// *****************************************************************************

// *****************************************************************************
// ***   Defines   *************************************************************
// *****************************************************************************
#define BG_Z (100)

// *****************************************************************************
// ***   Application Class   ***************************************************
// *****************************************************************************
class InputTest : public AppTask
{
  public:
    // *************************************************************************
    // ***   Get Instance   ****************************************************
    // *************************************************************************
    static InputTest& GetInstance(void);

    // *************************************************************************
    // ***   Application Loop   ************************************************
    // *************************************************************************
    virtual Result Loop();

  private:
    // Display driver instance
    DisplayDrv& display_drv = DisplayDrv::GetInstance();
    // Input driver instance
    InputDrv& input_drv = InputDrv::GetInstance();
    // Sound driver instance
    SoundDrv& sound_drv = SoundDrv::GetInstance();

    // *************************************************************************
    // ***   ProcessUserInput   ************************************************
    // *************************************************************************
    static char* GetMenuStr(void* ptr, char* buf, uint32_t n, uint32_t add_param);

    // *************************************************************************
    // ***   Private constructor   *********************************************
    // *************************************************************************
    InputTest() : AppTask(APPLICATION_TASK_STACK_SIZE, APPLICATION_TASK_PRIORITY,
                          "InputTest") {};
};

#endif
