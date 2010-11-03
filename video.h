/*
* Copyright (c) 2010 Ajith Hussain
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Ajith Hussain - initial contribution.
*
* Contributors:
*
* Description:
*
*/

#ifndef VIDEO_H
#define VIDEO_H

#include "ascii.h"

#define V_MEM_BASE	((unsigned char*)0x000B8000)
#define V_MAXX	80
#define V_MAXY	25
#define V_BPP	2

#define V_GRAY_ON_BLACK	0x07

#define vid_putch(chr,x,y) {V_MEM_BASE[y*V_MAXX*V_BPP + x*V_BPP] = chr;V_MEM_BASE[y*V_MAXX*V_BPP + x*V_BPP + 1] = V_GRAY_ON_BLACK;}
#define vid_getch(x,y)		 (V_MEM_BASE[y*V_MAXX*V_BPP + x*V_BPP])
#define vid_clear(x,y)		vid_putch(0,x,y)
#endif // VIDEO_H
