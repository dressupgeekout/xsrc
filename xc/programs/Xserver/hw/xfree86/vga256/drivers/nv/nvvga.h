/*
 * Copyright 1996-1997  David J. McKay
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * DAVID J. MCKAY BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* $XFree86: xc/programs/Xserver/hw/xfree86/vga256/drivers/nv/nvvga.h,v 1.1.2.3 1998/10/19 07:33:51 hohndel Exp $ */

#ifndef __NVVGA_H__
#define __NVVGA_H__

#define PALETTE_SIZE 256

#if 1
#define NV_PDAC_CURSOR_SIZE                   32
#define NV_PDAC_CURSOR_PLANE_SIZE         (NV_PDAC_CURSOR_SIZE*4)

/* This is the structure for the NV1. It is not a VGA based core */

typedef struct {
  unsigned char Nparam, Mparam, Oparam, Pparam;
  unsigned char NparamMPLL, MparamMPLL, OparamMPLL, PparamMPLL;
  unsigned char dacConfReg0;
  unsigned char dacConfReg1;
  unsigned char dacRgbPalCtrl;
  unsigned long confReg0;
  unsigned long green0; /* DPMS and sync polarity control */
  unsigned long memoryTrace;
  unsigned long startAddr; /* Where to start reading out from the buffer */
  /* All the following registers control the display */
  unsigned long prmConfig0;     /* Controls if text mode on or off */
  unsigned long horFrontPorch;  /* Front porch in pixels */
  unsigned long horSyncWidth;   /* Sync Width in pixels */
  unsigned long horBackPorch;   /* horizontal back porch in in pixels */
  unsigned long horDispWidth;   /* Horizontal display width in pixels */
  unsigned long verFrontPorch;  /* Vertical front porch in lines */
  unsigned long verSyncWidth;   /* Vertical sync width in lines */
  unsigned long verBackPorch;   /* Vertical back porch in lines */
  unsigned long verDispWidth;   /* Vertical display width in lines */
  /* Hardware cursor registers */
  unsigned char cursorCtrl;
  unsigned char xHi,xLo,yHi,yLo;
  unsigned char colour1[3]; /* RGB values for cursor planes */
  unsigned char colour2[3];
  unsigned char colour3[3];
  unsigned char plane0[NV_PDAC_CURSOR_PLANE_SIZE];
  unsigned char plane1[NV_PDAC_CURSOR_PLANE_SIZE];
  unsigned char palette[PALETTE_SIZE][3];
}NV1Registers;
#endif


/* This is for the NV3, AKA RIVA128. It does have a VGA core, so
 * fits into the SVGA server much easier than the NV1 does
 */
typedef struct {
  unsigned char offset,
                repaint0,
                repaint1,
                screenExtra,
                pixelFormat,
                horizExtra,
                fifoControl,
                fifo;

  unsigned long vpllCoeff,
                config0,
                coeffSelect,
                generalControl;
}NV3Registers;

/* This is for the NV4, AKA RIVATNT. It does have a VGA core, so
 * fits into the SVGA server much easier than the NV1 does
 */
typedef struct {
  unsigned char offset,
                repaint0,
                repaint1,
                screenExtra,
                pixelFormat,
                horizExtra,
                fifoControl,
                fifo;

  unsigned long vpllCoeff,
                config0,
                coeffSelect,
                generalControl;
}NV4Registers;

/*
 * Driver data structures.
 */
typedef struct {
  vgaHWRec std; /* good old IBM VGA */
  int vgaValid; /* is the above state valid?? */
  NVChipType type; /* What the union holds */
  union {
    NV1Registers nv1;
    NV3Registers nv3;
    NV4Registers nv4;
  }regs;
} vgaNVRec, *vgaNVPtr;


#endif
