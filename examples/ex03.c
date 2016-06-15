/*******************************************************************************
 Create a 320x240 surface
*******************************************************************************/

 #include "aa.h"


 V aaMain                              (V)
 {
 _size sz1;
 _surfaceunit surface;
 Q ms;
 _inputengine ie;
 _fontunit font;

 aaFontCreate(&font.handle,"arial",0,-20,1,0,0,0,1,0);
 aaFontStatus(font.handle,&font.status);
 aaSizeSet(&sz1,320,240);
 aaSurfaceCreate(&surface.handle,&sz1);
 aaSurfaceCenter(surface.handle,0);
 aaSurfaceShow(surface.handle,YES);
 aaSurfaceIconSetUsingResource(surface.handle,1000,F32);
 aaSurfaceTitleSet(surface.handle,"my prog");
 aaSurfaceClear(surface.handle,&col_gray[25]);
 aaSurfaceCaption(surface.handle,0,font.handle,"my prog, press <esc>");
 aaSurfaceUpdateAreaAdd(surface.handle,0,YES);
 aaSurfaceStatus(surface.handle,&surface.status);
 ms=aaMsRunning();
 while(aaYield(1234.23)==YES) // extremely precise cpu control, we run main loop at 1234.23 hz
  {
  if((aa_msrunning-ms)>=25)
   {
   ms=aa_msrunning;
   aaInputEngine(&ie);
   if(ie.is_ok==YES&&ie.event_byt[aa_IE_KeyDown]&&ie.curr->vkey==VK_ESCAPE) {  break;  }
   }
  }
 aaSurfaceDestroy(surface.handle);
 aaFontDestroy(font.handle);
 }



