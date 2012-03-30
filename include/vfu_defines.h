#ifndef VFU_DEFINES
#define VFU_DEFINES

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

typedef enum _vfu_error
{
	VFU_ERR_OK = 0,
	VFU_ERR_UNKNOWN,
	VFU_ERR_SDK_ALREADY_INITIALIZED,
	VFU_ERR_UNSUPPORTED,
	VFU_ERR_DISPOSED,
	VFU_ERR_DOTNETFX_NOT_INSTALLED,
} vfuError;

typedef enum _vfu_brightness_target
{
    VFU_TARGET_SOFTWARE = 0,
	VFU_TARGET_HARDWARE,
	VFU_TARGET_OFF,
	VFU_TARGET_IGNORE,
} vfuTarget;

typedef enum _vfu_flip_mode
{
	VFU_FLIP_HORIZONTAL = 0,
	VFU_FLIP_VERTICAL,
	VFU_FLIP_BOTH,
	VFU_FLIP_NONE,
	VFU_FLIP_INVALID
} vfuFlipMode;

typedef enum _vfu_gain_channel
{
	VFU_GAIN_GLOBAL = 0,
	VFU_GAIN_RED,
	VFU_GAIN_GREEN,
	VFU_GAIN_BLUE,
	VFU_GAIN_GREENRED,
	VFU_GAIN_GREENBLUE,
	VFU_GAIN_INVALID
} vfuGainChannel;

typedef enum _vfu_skip
{
	VFU_SKIP_NONE = 0,
	VFU_SKIP_2X = 1,
	VFU_SKIP_4X = 2,
	VFU_SKIP_8X = 3,
	VFU_SKIP_16X = 4,
	VFU_SKIP_32X = 5,
} vfuSkip;

typedef enum _vfu_subsampling
{
	VFU_SUBSAMPLING_NONE = 0,
	VFU_SUBSAMPLING_SUMMING = 1,
	VFU_SUBSAMPLING_BINNING = 2
} vfuSubsampling;

typedef enum _vfu_property_type
{
	VFU_PROPERTY_UNKNOWN = 0,
} vfuPropertyType;

typedef struct _vfu_camera_info
{
	const char * cameraID;
	const char * cameraName;
} vfuCameraInfo;

typedef struct _vfu_resolution
{
	unsigned int x;
	unsigned int y;
	unsigned int width;
	unsigned int height;
	char * name;
} vfuResolution;

typedef struct _vfu_property_info
{

} vfuPropertyInfo;


typedef struct _auto_brightness_control
{
	vfuTarget aecTarget;
	vfuTarget agcTarget;
	bool supported;
} vfuAutoBrightnessControl;

typedef struct _auto_brightness_enable
{
	bool enabled;
	bool supported;
} vfuAutoBrightnessEnable;

typedef struct _auto_brightness_speedfactor
{
	double speedFactor;
	double minValue;
	double maxValue;
	double defaultValue;
	bool supported;
} vfuAutoBrightnessSpeedFactor;

typedef struct _auto_brightness_target
{
	double target;
    double minValue;
    double maxValue;
	double defaultValue;
	bool supported;
} vfuAutoBrightnessTarget;

typedef struct _integration_time
{
	double usec;
	int minValue;
	int maxValue;
	int regValue;
	int defaultValue;
	bool supported;
} vfuIntegrationTime;

typedef struct _vfu_roi
{

	unsigned int x;
	unsigned int maxX;
	unsigned int minX;
	unsigned int defaultX;

	unsigned int y;
	unsigned int maxY;
	unsigned int minY;
	unsigned int defaultY;

	unsigned int width;
	unsigned int maxWidth;
	unsigned int minWidth;
	unsigned int defaultWidth;

	unsigned int height;
	unsigned int maxHeight;
	unsigned int minHeight;
	unsigned int defaultHeight;

} vfuRoi;

typedef struct _auto_brightness_roi
{
	vfuRoi roi;
	bool supported;	
} vfuAutoBrightnessRoi;

typedef struct _flip_mode
{
	vfuFlipMode flipMode;
	bool supported;
} vfuFlip;

typedef struct _gain_channel
{
	double factor;
	double minValue;
	double maxValue;
	double defaultValue;
	vfuGainChannel channel;
	bool supported;
} vfuGain;

typedef struct _white_balance
{
	double red;
	double redMinValue;
	double redMaxValue;
	double redDefaultValue;
	double green;
	double greenMinValue;
	double greenMaxValue;
	double greenDefaultValue;
	double blue;
	double blueMinValue;
	double blueMaxValue;
	double blueDefaultValue;
	bool supported;
} vfuWhiteBalance;

typedef struct _auto_whitebalance
{
	bool enabled;
	bool supported;
} vfuWhiteBalanceEnabled;

typedef struct _pixel_clock
{
	double pixelClock;
	double maxValue;
	double minValue;
	double defaultValue;
	bool autoEnabled;
	bool supported;
} vfuPixelClock;


typedef struct _image_roi
{
	vfuRoi roi;
	vfuSubsampling subsampling;
	vfuSkip xSkip;
	vfuSkip ySkip;
	bool supported;
} vfuImageRoi;

typedef void (*vfuCBFrameArrived)( int deviceID, void * data, int datasize,int width, int height, void *pUserData );
typedef void (*vfuCBFrameDropped)( int deviceID, void *pUserData );
typedef void (*vfuUpdateDevices)( void *pUserData );

#endif
