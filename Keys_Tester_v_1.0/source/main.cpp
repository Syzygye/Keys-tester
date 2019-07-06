
#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
  char keysNames[32][32] = {
      "KEY_A", "KEY_B", "KEY_X", "KEY_Y",
      "KEY_LSTICK", "KEY_RSTICK", "KEY_L", "KEY_R",
      "KEY_ZL", "KEY_ZR", "KEY_PLUS", "KEY_MINUS",
      "KEY_DLEFT", "KEY_DUP", "KEY_DRIGHT", "KEY_DDOWN",
      "KEY_LSTICK_LEFT", "KEY_LSTICK_UP", "KEY_LSTICK_RIGHT", "KEY_LSTICK_DOWN",
      "KEY_RSTICK_LEFT", "KEY_RSTICK_UP", "KEY_RSTICK_RIGHT", "KEY_RSTICK_DOWN",
      "KEY_SL", "KEY_SR", "KEY_TOUCH", "",
      "", "", "", ""
  };

    gfxInitDefault();

    //Initialize console.
    consoleInit(NULL);



    printf("\x1b[15;28HTouch the screen to exit.");
    printf("\x1b[45;70HBY SYZYGY_E");


    while(appletMainLoop())
    {
        //Scan all the inputs. This should be done once for each frame
        hidScanInput();

        //hidKeysDown returns information about which buttons have been just pressed (and they weren't in the previous frame)
        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
        u64 kHeld = hidKeysHeld(CONTROLLER_P1_AUTO);
        u64 kUp = hidKeysUp(CONTROLLER_P1_AUTO);

// A B X Y
        if (kHeld & KEY_A){printf("\x1b[10;70HA");}
        if (kUp & KEY_A){printf("\x1b[10;70H ");}

        if (kHeld & KEY_B){printf("\x1b[15;65HB");}
        if (kUp & KEY_B){printf("\x1b[15;65H ");}

        if (kHeld & KEY_Y){printf("\x1b[10;60HY");}
        if (kUp & KEY_Y){printf("\x1b[10;60H ");}

        if (kHeld & KEY_X){printf("\x1b[5;65HX");}
        if (kUp & KEY_X){printf("\x1b[5;65H ");}

//D PAD
        if (kHeld & KEY_DUP){printf("\x1b[25;10HUP");}
        if (kUp & KEY_DUP){printf("\x1b[25;10H  ");}

        if (kHeld & KEY_DDOWN){printf("\x1b[35;10HDOWN");}
        if (kUp & KEY_DDOWN){printf("\x1b[35;10H    ");}

        if (kHeld & KEY_DLEFT){printf("\x1b[30;1HLEFT");}
        if (kUp & KEY_DLEFT){printf("\x1b[30;1H    ");}

        if (kHeld & KEY_DRIGHT){printf("\x1b[30;15HRIGHT");}
        if (kUp & KEY_DRIGHT){printf("\x1b[30;15H     ");}

//RIGHT JOYSTICK
        if (kHeld & KEY_RSTICK_UP){printf("\x1b[25;65HUP");}
        if (kUp & KEY_RSTICK_UP){printf("\x1b[25;65H  ");}

        if (kHeld & KEY_RSTICK_DOWN){printf("\x1b[35;65HDOWN");}
        if (kUp & KEY_RSTICK_DOWN){printf("\x1b[35;65H    ");}

        if (kHeld & KEY_RSTICK_LEFT){printf("\x1b[30;55HLEFT");}
        if (kUp & KEY_RSTICK_LEFT){printf("\x1b[30;55H    ");}

        if (kHeld & KEY_RSTICK_RIGHT){printf("\x1b[30;75HRIGHT");}
        if (kUp & KEY_RSTICK_RIGHT){printf("\x1b[30;75H     ");}

//LEFT JOYSTICK
        if (kHeld & KEY_LSTICK_UP){printf("\x1b[5;10HUP");}
        if (kUp & KEY_LSTICK_UP){printf("\x1b[5;10H  ");}

        if (kHeld & KEY_LSTICK_DOWN){printf("\x1b[15;10HDOWN");}
        if (kUp & KEY_LSTICK_DOWN){printf("\x1b[15;10H    ");}

        if (kHeld & KEY_LSTICK_LEFT){printf("\x1b[10;1HLEFT");}
        if (kUp & KEY_LSTICK_LEFT){printf("\x1b[10;1H    ");}

        if (kHeld & KEY_LSTICK_RIGHT){printf("\x1b[10;15HRIGHT");}
        if (kUp & KEY_LSTICK_RIGHT){printf("\x1b[10;15H     ");}

//PLUS & MINUS
        if (kHeld & KEY_PLUS){printf("\x1b[5;55H+");}
        if (kUp & KEY_PLUS){printf("\x1b[5;55H ");}

        if (kHeld & KEY_MINUS){printf("\x1b[5;25H-");}
        if (kUp & KEY_MINUS){printf("\x1b[5;25H ");}

        if (kHeld & KEY_R){printf("\x1b[5;75HR");}
        if (kUp & KEY_R){printf("\x1b[5;75H ");}

//L-R Z
        if (kHeld & KEY_ZR){printf("\x1b[1;75HZR");}
        if (kUp & KEY_ZR){printf("\x1b[1;75H  ");}

        if (kHeld & KEY_L){printf("\x1b[5;5HL");}
        if (kUp & KEY_L){printf("\x1b[5;5H ");}

        if (kHeld & KEY_ZL){printf("\x1b[1;5HZL");}
        if (kUp & KEY_ZL){printf("\x1b[1;5H  ");}

        if (kDown & KEY_TOUCH) break; // return to hbmenu

        gfxFlushBuffers();
        gfxSwapBuffers();
        gfxWaitForVsync();
    }

    gfxExit();
    return 0;
}
