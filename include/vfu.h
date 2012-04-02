#ifndef VFU_H
#define VFU_H

#include "vfu_platform.h"
#include "vfu_defines.h"

/*
Copyright (c) 2012, "Altami LTD"
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of the "Altami LTD" nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL "Altami LTD" BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef __cplusplus
extern "C" {
#endif

VFUAPI vfuError vfuInitilizeSDK();
VFUAPI vfuError vfuDeInitilizeSDK();
VFUAPI vfuError setDeviceUpdatedCB(vfuUpdateDevices cb, void * userData);

VFUAPI vfuError vfuGetCameras(  unsigned int* pNumCameras, int ** cameras );
VFUAPI vfuError vfuGetDeviceInfo( int deviceID, vfuCameraInfo * cameraInfo );
VFUAPI vfuError vfuFinalizeDevice( int deviceID );

VFUAPI vfuError vfuConnect( int deviceID );
VFUAPI vfuError vfuDisconnect( int deviceID );

VFUAPI vfuError vfuStartCapture( int deviceID );
VFUAPI vfuError vfuStopCapture( int deviceID );
VFUAPI vfuError vfuSetFrameArrivedCB( int deviceID, vfuCBFrameArrived cb, void * userData = 0 );
VFUAPI vfuError vfuBufferLock( int deviceID );
VFUAPI vfuError vfuBufferUnlock( int deviceID );
VFUAPI vfuError vfuSetFrameDroppedCB( int deviceID, vfuCBFrameDropped cb, void * userData = 0 );

VFUAPI vfuError vfuGetVideoFormats( int deviceID, int ** modes, unsigned int * formatsNum );
VFUAPI vfuError vfuSetVideoMode( int deviceID, int modeID );
VFUAPI vfuError vfuGetCurrentVideoMode(int deviceID, int * modeID );
VFUAPI vfuError vfuGetModeInfo( int deviceID, int modeID, vfuResolution * resolution );

VFUAPI vfuError vfuGetAutoBrightnessControl( int deviceID, vfuAutoBrightnessControl * prop );
VFUAPI vfuError vfuSetAutoBrightnessControl( int deviceID, vfuAutoBrightnessControl prop );
VFUAPI vfuError vfuGetAutoBrightnessControlSupported( int deviceID, vfuTarget aec, vfuTarget agc, bool * supported );

VFUAPI vfuError vfuGetAutoBrightnessEnable( int deviceID, bool * prop );
VFUAPI vfuError vfuSetAutoBrightnessEnable( int deviceID, bool prop );

VFUAPI vfuError vfuGetAutoBrightnessRoi( int deviceID, vfuAutoBrightnessRoi * prop );
VFUAPI vfuError vfuSetAutoBrightnessRoi( int deviceID, vfuAutoBrightnessRoi prop );

VFUAPI vfuError vfuGetAutoBrightnessSpeedFactor( int deviceID, vfuAutoBrightnessSpeedFactor * prop );
VFUAPI vfuError vfuSetAutoBrightnessSpeedFactor( int deviceID, vfuAutoBrightnessSpeedFactor prop );

VFUAPI vfuError vfuGetAutoBrightnessTarget( int deviceID, vfuAutoBrightnessTarget * prop );
VFUAPI vfuError vfuSetAutoBrightnessTarget( int deviceID, vfuAutoBrightnessTarget prop);

VFUAPI vfuError vfuGetFlip( int deviceID, vfuFlip * prop );
VFUAPI vfuError vfuSetFlip( int deviceID, vfuFlip prop );

VFUAPI vfuError vfuGetGain( int deviceID, vfuGain * prop );
VFUAPI vfuError vfuSetGain( int deviceID, vfuGain prop );

VFUAPI vfuError vfuGetIntegrationTime( int deviceID, vfuIntegrationTime * prop );
VFUAPI vfuError vfuSetIntegrationTime( int deviceID, vfuIntegrationTime prop );

VFUAPI vfuError vfuGetWhiteBalance( int deviceID, vfuWhiteBalance * prop );
VFUAPI vfuError vfuSetWhiteBalance( int deviceID, vfuWhiteBalance prop );
VFUAPI vfuError vfuCalculateWhiteBalance( int deviceID, vfuWhiteBalance * prop );

VFUAPI vfuError vfuGetWhiteBalanceEnable( int deviceID, vfuWhiteBalanceEnabled * prop );
VFUAPI vfuError vfuSetWhiteBalanceEnable( int deviceID, vfuWhiteBalanceEnabled prop );

VFUAPI vfuError vfuGetPixelClock( int deviceID, vfuPixelClock * prop );
VFUAPI vfuError vfuSetPixelClock( int deviceID, vfuPixelClock prop );

VFUAPI vfuError vfuGetImageRoiExt( int deviceID, vfuImageRoi * prop );
VFUAPI vfuError vfuSetImageRoiExt( int deviceID, vfuImageRoi prop);
VFUAPI vfuError vfuCheckImageRoi( int deviceID, vfuImageRoi prop, bool * supported );

#ifdef __cplusplus
};
#endif


#endif