
/**************************************************************************

Copyright 1998-1999 Precision Insight, Inc., Cedar Park, Texas.
All Rights Reserved.

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sub license, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice (including the
next paragraph) shall be included in all copies or substantial portions
of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

**************************************************************************/
/* $XFree86: xc/programs/Xserver/GL/glxmodule.c,v 1.11 2001/06/15 21:22:38 dawes Exp $ */

/*
 * Authors:
 *   Kevin E. Martin <kevin@precisioninsight.com>
 *
 */

#include "xf86Module.h"
#include "colormap.h"
#include "micmap.h"

static MODULESETUPPROTO(glxSetup);

extern void GlxExtensionInit(INITARGS);
extern void GlxWrapInitVisuals(miInitVisualsProcPtr *);
extern void InitGlxWrapInitVisuals(void (*f)(miInitVisualsProcPtr *));

static const char *initdeps[] = { "DOUBLE-BUFFER", NULL };

ExtensionModule GLXExt =
{
    GlxExtensionInit,
    "GLX",
    NULL,
    NULL,
    initdeps
};

static const char *glcoreSymbols[] = {
    "__glCallLists_size",
    "__glColorTableParameterfv_size",
    "__glColorTableParameteriv_size",
    "__glConvolutionParameterfv_size",
    "__glConvolutionParameteriv_size",
    "__glDDXExtensionInfo",
    "__glDDXScreenInfo",
    "__glEvalComputeK",
    "__glFloorLog2",
    "__glFogfv_size",
    "__glFogiv_size",
    "__glGetBooleanv_size",
    "__glGetColorTableParameterfv_size",
    "__glGetColorTableParameteriv_size",
    "__glGetConvolutionParameterfv_size",
    "__glGetConvolutionParameteriv_size",
    "__glGetDoublev_size",
    "__glGetFloatv_size",
    "__glGetHistogramParameterfv_size",
    "__glGetHistogramParameteriv_size",
    "__glGetIntegerv_size",
    "__glGetLightfv_size",
    "__glGetLightiv_size",
    "__glGetMapdv_size",
    "__glGetMapfv_size",
    "__glGetMapiv_size",
    "__glGetMaterialfv_size",
    "__glGetMaterialiv_size",
    "__glGetMinmaxParameterfv_size",
    "__glGetMinmaxParameteriv_size",
    "__glGetPixelMapfv_size",
    "__glGetPixelMapuiv_size",
    "__glGetPixelMapusv_size",
    "__glGetTexEnvfv_size",
    "__glGetTexEnviv_size",
    "__glGetTexGendv_size",
    "__glGetTexGenfv_size",
    "__glGetTexGeniv_size",
    "__glGetTexImage_size",
    "__glGetTexLevelParameterfv_size",
    "__glGetTexLevelParameteriv_size",
    "__glGetTexParameterfv_size",
    "__glGetTexParameteriv_size",
    "__glLightModelfv_size",
    "__glLightModeliv_size",
    "__glLightfv_size",
    "__glLightiv_size",
    "__glMaterialfv_size",
    "__glMaterialiv_size",
    "__glReadPixels_size",
    "__glTexEnvfv_size",
    "__glTexEnviv_size",
    "__glTexGendv_size",
    "__glTexGenfv_size",
    "__glTexGeniv_size",
    "__glTexParameterfv_size",
    "__glTexParameteriv_size",
    "__glXActiveScreens",
    "__glXAssociateContext",
    "__glXBadContext",
    "__glXBadContextState",
    "__glXBadContextTag",
    "__glXBadCurrentWindow",
    "__glXBadDrawable",
    "__glXBadLargeRequest",
    "__glXBadPixmap",
    "__glXBadRenderRequest",
    "__glXBitmapReqSize",
    "__glXCacheDrawableSize",
    "__glXCallListsReqSize",
    "__glXClearErrorOccured",
    "__glXClientInfo",
    "__glXClientRes",
    "__glXClients",
    "__glXColorSubTableReqSize",
    "__glXColorTableParameterfvReqSize",
    "__glXColorTableParameterivReqSize",
    "__glXColorTableReqSize",
    "__glXContextRes",
    "__glXConvolutionFilter1DReqSize",
    "__glXConvolutionFilter2DReqSize",
    "__glXConvolutionParameterfvReqSize",
    "__glXConvolutionParameterivReqSize",
    "__glXCopyContext",
    "__glXCoreType",
    "__glXCreateContext",
    "__glXCreateGLXPixmap",
    "__glXDeassociateContext",
    "__glXDestroyContext",
    "__glXDestroyGLXPixmap",
    "__glXDispSwap_Accum",
    "__glXDispSwap_ActiveTextureARB",
    "__glXDispSwap_AlphaFunc",
    "__glXDispSwap_AreTexturesResident",
    "__glXDispSwap_AreTexturesResidentEXT",
    "__glXDispSwap_Begin",
    "__glXDispSwap_BindTexture",
    "__glXDispSwap_Bitmap",
    "__glXDispSwap_BlendColor",
    "__glXDispSwap_BlendEquation",
    "__glXDispSwap_BlendFunc",
    "__glXDispSwap_CallList",
    "__glXDispSwap_CallLists",
    "__glXDispSwap_Clear",
    "__glXDispSwap_ClearAccum",
    "__glXDispSwap_ClearColor",
    "__glXDispSwap_ClearDepth",
    "__glXDispSwap_ClearIndex",
    "__glXDispSwap_ClearStencil",
    "__glXDispSwap_ClipPlane",
    "__glXDispSwap_Color3bv",
    "__glXDispSwap_Color3dv",
    "__glXDispSwap_Color3fv",
    "__glXDispSwap_Color3iv",
    "__glXDispSwap_Color3sv",
    "__glXDispSwap_Color3ubv",
    "__glXDispSwap_Color3uiv",
    "__glXDispSwap_Color3usv",
    "__glXDispSwap_Color4bv",
    "__glXDispSwap_Color4dv",
    "__glXDispSwap_Color4fv",
    "__glXDispSwap_Color4iv",
    "__glXDispSwap_Color4sv",
    "__glXDispSwap_Color4ubv",
    "__glXDispSwap_Color4uiv",
    "__glXDispSwap_Color4usv",
    "__glXDispSwap_ColorMask",
    "__glXDispSwap_ColorMaterial",
    "__glXDispSwap_ColorSubTable",
    "__glXDispSwap_ColorTable",
    "__glXDispSwap_ColorTableParameterfv",
    "__glXDispSwap_ColorTableParameteriv",
    "__glXDispSwap_ConvolutionFilter1D",
    "__glXDispSwap_ConvolutionFilter2D",
    "__glXDispSwap_ConvolutionParameterf",
    "__glXDispSwap_ConvolutionParameterfv",
    "__glXDispSwap_ConvolutionParameteri",
    "__glXDispSwap_ConvolutionParameteriv",
    "__glXDispSwap_CopyColorSubTable",
    "__glXDispSwap_CopyColorTable",
    "__glXDispSwap_CopyConvolutionFilter1D",
    "__glXDispSwap_CopyConvolutionFilter2D",
    "__glXDispSwap_CopyPixels",
    "__glXDispSwap_CopyTexImage1D",
    "__glXDispSwap_CopyTexImage2D",
    "__glXDispSwap_CopyTexSubImage1D",
    "__glXDispSwap_CopyTexSubImage2D",
    "__glXDispSwap_CopyTexSubImage3D",
    "__glXDispSwap_CullFace",
    "__glXDispSwap_DeleteLists",
    "__glXDispSwap_DeleteTextures",
    "__glXDispSwap_DeleteTexturesEXT",
    "__glXDispSwap_DepthFunc",
    "__glXDispSwap_DepthMask",
    "__glXDispSwap_DepthRange",
    "__glXDispSwap_Disable",
    "__glXDispSwap_DrawArrays",
    "__glXDispSwap_DrawArraysEXT",
    "__glXDispSwap_DrawBuffer",
    "__glXDispSwap_DrawPixels",
    "__glXDispSwap_EdgeFlagv",
    "__glXDispSwap_Enable",
    "__glXDispSwap_End",
    "__glXDispSwap_EndList",
    "__glXDispSwap_EvalCoord1dv",
    "__glXDispSwap_EvalCoord1fv",
    "__glXDispSwap_EvalCoord2dv",
    "__glXDispSwap_EvalCoord2fv",
    "__glXDispSwap_EvalMesh1",
    "__glXDispSwap_EvalMesh2",
    "__glXDispSwap_EvalPoint1",
    "__glXDispSwap_EvalPoint2",
    "__glXDispSwap_FeedbackBuffer",
    "__glXDispSwap_Finish",
    "__glXDispSwap_Flush",
    "__glXDispSwap_Fogf",
    "__glXDispSwap_Fogfv",
    "__glXDispSwap_Fogi",
    "__glXDispSwap_Fogiv",
    "__glXDispSwap_FrontFace",
    "__glXDispSwap_Frustum",
    "__glXDispSwap_GenLists",
    "__glXDispSwap_GenTextures",
    "__glXDispSwap_GenTexturesEXT",
    "__glXDispSwap_GetBooleanv",
    "__glXDispSwap_GetClipPlane",
    "__glXDispSwap_GetColorTable",
    "__glXDispSwap_GetColorTableParameterfv",
    "__glXDispSwap_GetColorTableParameteriv",
    "__glXDispSwap_GetConvolutionFilter",
    "__glXDispSwap_GetConvolutionParameterfv",
    "__glXDispSwap_GetConvolutionParameteriv",
    "__glXDispSwap_GetDoublev",
    "__glXDispSwap_GetError",
    "__glXDispSwap_GetFloatv",
    "__glXDispSwap_GetHistogram",
    "__glXDispSwap_GetHistogramParameterfv",
    "__glXDispSwap_GetHistogramParameteriv",
    "__glXDispSwap_GetIntegerv",
    "__glXDispSwap_GetLightfv",
    "__glXDispSwap_GetLightiv",
    "__glXDispSwap_GetMapdv",
    "__glXDispSwap_GetMapfv",
    "__glXDispSwap_GetMapiv",
    "__glXDispSwap_GetMaterialfv",
    "__glXDispSwap_GetMaterialiv",
    "__glXDispSwap_GetMinmax",
    "__glXDispSwap_GetMinmaxParameterfv",
    "__glXDispSwap_GetMinmaxParameteriv",
    "__glXDispSwap_GetPixelMapfv",
    "__glXDispSwap_GetPixelMapuiv",
    "__glXDispSwap_GetPixelMapusv",
    "__glXDispSwap_GetPolygonStipple",
    "__glXDispSwap_GetSeparableFilter",
    "__glXDispSwap_GetString",
    "__glXDispSwap_GetTexEnvfv",
    "__glXDispSwap_GetTexEnviv",
    "__glXDispSwap_GetTexGendv",
    "__glXDispSwap_GetTexGenfv",
    "__glXDispSwap_GetTexGeniv",
    "__glXDispSwap_GetTexImage",
    "__glXDispSwap_GetTexLevelParameterfv",
    "__glXDispSwap_GetTexLevelParameteriv",
    "__glXDispSwap_GetTexParameterfv",
    "__glXDispSwap_GetTexParameteriv",
    "__glXDispSwap_Hint",
    "__glXDispSwap_Histogram",
    "__glXDispSwap_IndexMask",
    "__glXDispSwap_Indexdv",
    "__glXDispSwap_Indexfv",
    "__glXDispSwap_Indexiv",
    "__glXDispSwap_Indexsv",
    "__glXDispSwap_Indexubv",
    "__glXDispSwap_InitNames",
    "__glXDispSwap_IsEnabled",
    "__glXDispSwap_IsList",
    "__glXDispSwap_IsTexture",
    "__glXDispSwap_IsTextureEXT",
    "__glXDispSwap_LightModelf",
    "__glXDispSwap_LightModelfv",
    "__glXDispSwap_LightModeli",
    "__glXDispSwap_LightModeliv",
    "__glXDispSwap_Lightf",
    "__glXDispSwap_Lightfv",
    "__glXDispSwap_Lighti",
    "__glXDispSwap_Lightiv",
    "__glXDispSwap_LineStipple",
    "__glXDispSwap_LineWidth",
    "__glXDispSwap_ListBase",
    "__glXDispSwap_LoadIdentity",
    "__glXDispSwap_LoadMatrixd",
    "__glXDispSwap_LoadMatrixf",
    "__glXDispSwap_LoadName",
    "__glXDispSwap_LogicOp",
    "__glXDispSwap_Map1d",
    "__glXDispSwap_Map1f",
    "__glXDispSwap_Map2d",
    "__glXDispSwap_Map2f",
    "__glXDispSwap_MapGrid1d",
    "__glXDispSwap_MapGrid1f",
    "__glXDispSwap_MapGrid2d",
    "__glXDispSwap_MapGrid2f",
    "__glXDispSwap_Materialf",
    "__glXDispSwap_Materialfv",
    "__glXDispSwap_Materiali",
    "__glXDispSwap_Materialiv",
    "__glXDispSwap_MatrixMode",
    "__glXDispSwap_Minmax",
    "__glXDispSwap_MultMatrixd",
    "__glXDispSwap_MultMatrixf",
    "__glXDispSwap_MultiTexCoord1dvARB",
    "__glXDispSwap_MultiTexCoord1fvARB",
    "__glXDispSwap_MultiTexCoord1ivARB",
    "__glXDispSwap_MultiTexCoord1svARB",
    "__glXDispSwap_MultiTexCoord2dvARB",
    "__glXDispSwap_MultiTexCoord2fvARB",
    "__glXDispSwap_MultiTexCoord2ivARB",
    "__glXDispSwap_MultiTexCoord2svARB",
    "__glXDispSwap_MultiTexCoord3dvARB",
    "__glXDispSwap_MultiTexCoord3fvARB",
    "__glXDispSwap_MultiTexCoord3ivARB",
    "__glXDispSwap_MultiTexCoord3svARB",
    "__glXDispSwap_MultiTexCoord4dvARB",
    "__glXDispSwap_MultiTexCoord4fvARB",
    "__glXDispSwap_MultiTexCoord4ivARB",
    "__glXDispSwap_MultiTexCoord4svARB",
    "__glXDispSwap_NewList",
    "__glXDispSwap_Normal3bv",
    "__glXDispSwap_Normal3dv",
    "__glXDispSwap_Normal3fv",
    "__glXDispSwap_Normal3iv",
    "__glXDispSwap_Normal3sv",
    "__glXDispSwap_Ortho",
    "__glXDispSwap_PassThrough",
    "__glXDispSwap_PixelMapfv",
    "__glXDispSwap_PixelMapuiv",
    "__glXDispSwap_PixelMapusv",
    "__glXDispSwap_PixelStoref",
    "__glXDispSwap_PixelStorei",
    "__glXDispSwap_PixelTransferf",
    "__glXDispSwap_PixelTransferi",
    "__glXDispSwap_PixelZoom",
    "__glXDispSwap_PointSize",
    "__glXDispSwap_PolygonMode",
    "__glXDispSwap_PolygonOffset",
    "__glXDispSwap_PolygonStipple",
    "__glXDispSwap_PopAttrib",
    "__glXDispSwap_PopMatrix",
    "__glXDispSwap_PopName",
    "__glXDispSwap_PrioritizeTextures",
    "__glXDispSwap_PushAttrib",
    "__glXDispSwap_PushMatrix",
    "__glXDispSwap_PushName",
    "__glXDispSwap_RasterPos2dv",
    "__glXDispSwap_RasterPos2fv",
    "__glXDispSwap_RasterPos2iv",
    "__glXDispSwap_RasterPos2sv",
    "__glXDispSwap_RasterPos3dv",
    "__glXDispSwap_RasterPos3fv",
    "__glXDispSwap_RasterPos3iv",
    "__glXDispSwap_RasterPos3sv",
    "__glXDispSwap_RasterPos4dv",
    "__glXDispSwap_RasterPos4fv",
    "__glXDispSwap_RasterPos4iv",
    "__glXDispSwap_RasterPos4sv",
    "__glXDispSwap_ReadBuffer",
    "__glXDispSwap_ReadPixels",
    "__glXDispSwap_Rectdv",
    "__glXDispSwap_Rectfv",
    "__glXDispSwap_Rectiv",
    "__glXDispSwap_Rectsv",
    "__glXDispSwap_RenderMode",
    "__glXDispSwap_ResetHistogram",
    "__glXDispSwap_ResetMinmax",
    "__glXDispSwap_Rotated",
    "__glXDispSwap_Rotatef",
    "__glXDispSwap_Scaled",
    "__glXDispSwap_Scalef",
    "__glXDispSwap_Scissor",
    "__glXDispSwap_SelectBuffer",
    "__glXDispSwap_SeparableFilter2D",
    "__glXDispSwap_ShadeModel",
    "__glXDispSwap_StencilFunc",
    "__glXDispSwap_StencilMask",
    "__glXDispSwap_StencilOp",
    "__glXDispSwap_TexCoord1dv",
    "__glXDispSwap_TexCoord1fv",
    "__glXDispSwap_TexCoord1iv",
    "__glXDispSwap_TexCoord1sv",
    "__glXDispSwap_TexCoord2dv",
    "__glXDispSwap_TexCoord2fv",
    "__glXDispSwap_TexCoord2iv",
    "__glXDispSwap_TexCoord2sv",
    "__glXDispSwap_TexCoord3dv",
    "__glXDispSwap_TexCoord3fv",
    "__glXDispSwap_TexCoord3iv",
    "__glXDispSwap_TexCoord3sv",
    "__glXDispSwap_TexCoord4dv",
    "__glXDispSwap_TexCoord4fv",
    "__glXDispSwap_TexCoord4iv",
    "__glXDispSwap_TexCoord4sv",
    "__glXDispSwap_TexEnvf",
    "__glXDispSwap_TexEnvfv",
    "__glXDispSwap_TexEnvi",
    "__glXDispSwap_TexEnviv",
    "__glXDispSwap_TexGend",
    "__glXDispSwap_TexGendv",
    "__glXDispSwap_TexGenf",
    "__glXDispSwap_TexGenfv",
    "__glXDispSwap_TexGeni",
    "__glXDispSwap_TexGeniv",
    "__glXDispSwap_TexImage1D",
    "__glXDispSwap_TexImage2D",
    "__glXDispSwap_TexImage3D",
    "__glXDispSwap_TexParameterf",
    "__glXDispSwap_TexParameterfv",
    "__glXDispSwap_TexParameteri",
    "__glXDispSwap_TexParameteriv",
    "__glXDispSwap_TexSubImage1D",
    "__glXDispSwap_TexSubImage2D",
    "__glXDispSwap_TexSubImage3D",
    "__glXDispSwap_Translated",
    "__glXDispSwap_Translatef",
    "__glXDispSwap_Vertex2dv",
    "__glXDispSwap_Vertex2fv",
    "__glXDispSwap_Vertex2iv",
    "__glXDispSwap_Vertex2sv",
    "__glXDispSwap_Vertex3dv",
    "__glXDispSwap_Vertex3fv",
    "__glXDispSwap_Vertex3iv",
    "__glXDispSwap_Vertex3sv",
    "__glXDispSwap_Vertex4dv",
    "__glXDispSwap_Vertex4fv",
    "__glXDispSwap_Vertex4iv",
    "__glXDispSwap_Vertex4sv",
    "__glXDispSwap_Viewport",
    "__glXDisp_Accum",
    "__glXDisp_ActiveTextureARB",
    "__glXDisp_AlphaFunc",
    "__glXDisp_AreTexturesResident",
    "__glXDisp_AreTexturesResidentEXT",
    "__glXDisp_Begin",
    "__glXDisp_BindTexture",
    "__glXDisp_Bitmap",
    "__glXDisp_BlendColor",
    "__glXDisp_BlendEquation",
    "__glXDisp_BlendFunc",
    "__glXDisp_CallList",
    "__glXDisp_CallLists",
    "__glXDisp_Clear",
    "__glXDisp_ClearAccum",
    "__glXDisp_ClearColor",
    "__glXDisp_ClearDepth",
    "__glXDisp_ClearIndex",
    "__glXDisp_ClearStencil",
    "__glXDisp_ClipPlane",
    "__glXDisp_Color3bv",
    "__glXDisp_Color3dv",
    "__glXDisp_Color3fv",
    "__glXDisp_Color3iv",
    "__glXDisp_Color3sv",
    "__glXDisp_Color3ubv",
    "__glXDisp_Color3uiv",
    "__glXDisp_Color3usv",
    "__glXDisp_Color4bv",
    "__glXDisp_Color4dv",
    "__glXDisp_Color4fv",
    "__glXDisp_Color4iv",
    "__glXDisp_Color4sv",
    "__glXDisp_Color4ubv",
    "__glXDisp_Color4uiv",
    "__glXDisp_Color4usv",
    "__glXDisp_ColorMask",
    "__glXDisp_ColorMaterial",
    "__glXDisp_ColorSubTable",
    "__glXDisp_ColorTable",
    "__glXDisp_ColorTableParameterfv",
    "__glXDisp_ColorTableParameteriv",
    "__glXDisp_ConvolutionFilter1D",
    "__glXDisp_ConvolutionFilter2D",
    "__glXDisp_ConvolutionParameterf",
    "__glXDisp_ConvolutionParameterfv",
    "__glXDisp_ConvolutionParameteri",
    "__glXDisp_ConvolutionParameteriv",
    "__glXDisp_CopyColorSubTable",
    "__glXDisp_CopyColorTable",
    "__glXDisp_CopyConvolutionFilter1D",
    "__glXDisp_CopyConvolutionFilter2D",
    "__glXDisp_CopyPixels",
    "__glXDisp_CopyTexImage1D",
    "__glXDisp_CopyTexImage2D",
    "__glXDisp_CopyTexSubImage1D",
    "__glXDisp_CopyTexSubImage2D",
    "__glXDisp_CopyTexSubImage3D",
    "__glXDisp_CullFace",
    "__glXDisp_DeleteLists",
    "__glXDisp_DeleteTextures",
    "__glXDisp_DeleteTexturesEXT",
    "__glXDisp_DepthFunc",
    "__glXDisp_DepthMask",
    "__glXDisp_DepthRange",
    "__glXDisp_Disable",
    "__glXDisp_DrawArrays",
    "__glXDisp_DrawArraysEXT",
    "__glXDisp_DrawBuffer",
    "__glXDisp_DrawPixels",
    "__glXDisp_EdgeFlagv",
    "__glXDisp_Enable",
    "__glXDisp_End",
    "__glXDisp_EndList",
    "__glXDisp_EvalCoord1dv",
    "__glXDisp_EvalCoord1fv",
    "__glXDisp_EvalCoord2dv",
    "__glXDisp_EvalCoord2fv",
    "__glXDisp_EvalMesh1",
    "__glXDisp_EvalMesh2",
    "__glXDisp_EvalPoint1",
    "__glXDisp_EvalPoint2",
    "__glXDisp_FeedbackBuffer",
    "__glXDisp_Finish",
    "__glXDisp_Flush",
    "__glXDisp_Fogf",
    "__glXDisp_Fogfv",
    "__glXDisp_Fogi",
    "__glXDisp_Fogiv",
    "__glXDisp_FrontFace",
    "__glXDisp_Frustum",
    "__glXDisp_GenLists",
    "__glXDisp_GenTextures",
    "__glXDisp_GenTexturesEXT",
    "__glXDisp_GetBooleanv",
    "__glXDisp_GetClipPlane",
    "__glXDisp_GetColorTable",
    "__glXDisp_GetColorTableParameterfv",
    "__glXDisp_GetColorTableParameteriv",
    "__glXDisp_GetConvolutionFilter",
    "__glXDisp_GetConvolutionParameterfv",
    "__glXDisp_GetConvolutionParameteriv",
    "__glXDisp_GetDoublev",
    "__glXDisp_GetError",
    "__glXDisp_GetFloatv",
    "__glXDisp_GetHistogram",
    "__glXDisp_GetHistogramParameterfv",
    "__glXDisp_GetHistogramParameteriv",
    "__glXDisp_GetIntegerv",
    "__glXDisp_GetLightfv",
    "__glXDisp_GetLightiv",
    "__glXDisp_GetMapdv",
    "__glXDisp_GetMapfv",
    "__glXDisp_GetMapiv",
    "__glXDisp_GetMaterialfv",
    "__glXDisp_GetMaterialiv",
    "__glXDisp_GetMinmax",
    "__glXDisp_GetMinmaxParameterfv",
    "__glXDisp_GetMinmaxParameteriv",
    "__glXDisp_GetPixelMapfv",
    "__glXDisp_GetPixelMapuiv",
    "__glXDisp_GetPixelMapusv",
    "__glXDisp_GetPolygonStipple",
    "__glXDisp_GetSeparableFilter",
    "__glXDisp_GetString",
    "__glXDisp_GetTexEnvfv",
    "__glXDisp_GetTexEnviv",
    "__glXDisp_GetTexGendv",
    "__glXDisp_GetTexGenfv",
    "__glXDisp_GetTexGeniv",
    "__glXDisp_GetTexImage",
    "__glXDisp_GetTexLevelParameterfv",
    "__glXDisp_GetTexLevelParameteriv",
    "__glXDisp_GetTexParameterfv",
    "__glXDisp_GetTexParameteriv",
    "__glXDisp_Hint",
    "__glXDisp_Histogram",
    "__glXDisp_IndexMask",
    "__glXDisp_Indexdv",
    "__glXDisp_Indexfv",
    "__glXDisp_Indexiv",
    "__glXDisp_Indexsv",
    "__glXDisp_Indexubv",
    "__glXDisp_InitNames",
    "__glXDisp_IsEnabled",
    "__glXDisp_IsList",
    "__glXDisp_IsTexture",
    "__glXDisp_IsTextureEXT",
    "__glXDisp_LightModelf",
    "__glXDisp_LightModelfv",
    "__glXDisp_LightModeli",
    "__glXDisp_LightModeliv",
    "__glXDisp_Lightf",
    "__glXDisp_Lightfv",
    "__glXDisp_Lighti",
    "__glXDisp_Lightiv",
    "__glXDisp_LineStipple",
    "__glXDisp_LineWidth",
    "__glXDisp_ListBase",
    "__glXDisp_LoadIdentity",
    "__glXDisp_LoadMatrixd",
    "__glXDisp_LoadMatrixf",
    "__glXDisp_LoadName",
    "__glXDisp_LogicOp",
    "__glXDisp_Map1d",
    "__glXDisp_Map1f",
    "__glXDisp_Map2d",
    "__glXDisp_Map2f",
    "__glXDisp_MapGrid1d",
    "__glXDisp_MapGrid1f",
    "__glXDisp_MapGrid2d",
    "__glXDisp_MapGrid2f",
    "__glXDisp_Materialf",
    "__glXDisp_Materialfv",
    "__glXDisp_Materiali",
    "__glXDisp_Materialiv",
    "__glXDisp_MatrixMode",
    "__glXDisp_Minmax",
    "__glXDisp_MultMatrixd",
    "__glXDisp_MultMatrixf",
    "__glXDisp_MultiTexCoord1dvARB",
    "__glXDisp_MultiTexCoord1fvARB",
    "__glXDisp_MultiTexCoord1ivARB",
    "__glXDisp_MultiTexCoord1svARB",
    "__glXDisp_MultiTexCoord2dvARB",
    "__glXDisp_MultiTexCoord2fvARB",
    "__glXDisp_MultiTexCoord2ivARB",
    "__glXDisp_MultiTexCoord2svARB",
    "__glXDisp_MultiTexCoord3dvARB",
    "__glXDisp_MultiTexCoord3fvARB",
    "__glXDisp_MultiTexCoord3ivARB",
    "__glXDisp_MultiTexCoord3svARB",
    "__glXDisp_MultiTexCoord4dvARB",
    "__glXDisp_MultiTexCoord4fvARB",
    "__glXDisp_MultiTexCoord4ivARB",
    "__glXDisp_MultiTexCoord4svARB",
    "__glXDisp_NewList",
    "__glXDisp_Normal3bv",
    "__glXDisp_Normal3dv",
    "__glXDisp_Normal3fv",
    "__glXDisp_Normal3iv",
    "__glXDisp_Normal3sv",
    "__glXDisp_Ortho",
    "__glXDisp_PassThrough",
    "__glXDisp_PixelMapfv",
    "__glXDisp_PixelMapuiv",
    "__glXDisp_PixelMapusv",
    "__glXDisp_PixelStoref",
    "__glXDisp_PixelStorei",
    "__glXDisp_PixelTransferf",
    "__glXDisp_PixelTransferi",
    "__glXDisp_PixelZoom",
    "__glXDisp_PointSize",
    "__glXDisp_PolygonMode",
    "__glXDisp_PolygonOffset",
    "__glXDisp_PolygonStipple",
    "__glXDisp_PopAttrib",
    "__glXDisp_PopMatrix",
    "__glXDisp_PopName",
    "__glXDisp_PrioritizeTextures",
    "__glXDisp_PushAttrib",
    "__glXDisp_PushMatrix",
    "__glXDisp_PushName",
    "__glXDisp_RasterPos2dv",
    "__glXDisp_RasterPos2fv",
    "__glXDisp_RasterPos2iv",
    "__glXDisp_RasterPos2sv",
    "__glXDisp_RasterPos3dv",
    "__glXDisp_RasterPos3fv",
    "__glXDisp_RasterPos3iv",
    "__glXDisp_RasterPos3sv",
    "__glXDisp_RasterPos4dv",
    "__glXDisp_RasterPos4fv",
    "__glXDisp_RasterPos4iv",
    "__glXDisp_RasterPos4sv",
    "__glXDisp_ReadBuffer",
    "__glXDisp_ReadPixels",
    "__glXDisp_Rectdv",
    "__glXDisp_Rectfv",
    "__glXDisp_Rectiv",
    "__glXDisp_Rectsv",
    "__glXDisp_RenderMode",
    "__glXDisp_ResetHistogram",
    "__glXDisp_ResetMinmax",
    "__glXDisp_Rotated",
    "__glXDisp_Rotatef",
    "__glXDisp_Scaled",
    "__glXDisp_Scalef",
    "__glXDisp_Scissor",
    "__glXDisp_SelectBuffer",
    "__glXDisp_SeparableFilter2D",
    "__glXDisp_ShadeModel",
    "__glXDisp_StencilFunc",
    "__glXDisp_StencilMask",
    "__glXDisp_StencilOp",
    "__glXDisp_TexCoord1dv",
    "__glXDisp_TexCoord1fv",
    "__glXDisp_TexCoord1iv",
    "__glXDisp_TexCoord1sv",
    "__glXDisp_TexCoord2dv",
    "__glXDisp_TexCoord2fv",
    "__glXDisp_TexCoord2iv",
    "__glXDisp_TexCoord2sv",
    "__glXDisp_TexCoord3dv",
    "__glXDisp_TexCoord3fv",
    "__glXDisp_TexCoord3iv",
    "__glXDisp_TexCoord3sv",
    "__glXDisp_TexCoord4dv",
    "__glXDisp_TexCoord4fv",
    "__glXDisp_TexCoord4iv",
    "__glXDisp_TexCoord4sv",
    "__glXDisp_TexEnvf",
    "__glXDisp_TexEnvfv",
    "__glXDisp_TexEnvi",
    "__glXDisp_TexEnviv",
    "__glXDisp_TexGend",
    "__glXDisp_TexGendv",
    "__glXDisp_TexGenf",
    "__glXDisp_TexGenfv",
    "__glXDisp_TexGeni",
    "__glXDisp_TexGeniv",
    "__glXDisp_TexImage1D",
    "__glXDisp_TexImage2D",
    "__glXDisp_TexImage3D",
    "__glXDisp_TexParameterf",
    "__glXDisp_TexParameterfv",
    "__glXDisp_TexParameteri",
    "__glXDisp_TexParameteriv",
    "__glXDisp_TexSubImage1D",
    "__glXDisp_TexSubImage2D",
    "__glXDisp_TexSubImage3D",
    "__glXDisp_Translated",
    "__glXDisp_Translatef",
    "__glXDisp_Vertex2dv",
    "__glXDisp_Vertex2fv",
    "__glXDisp_Vertex2iv",
    "__glXDisp_Vertex2sv",
    "__glXDisp_Vertex3dv",
    "__glXDisp_Vertex3fv",
    "__glXDisp_Vertex3iv",
    "__glXDisp_Vertex3sv",
    "__glXDisp_Vertex4dv",
    "__glXDisp_Vertex4fv",
    "__glXDisp_Vertex4iv",
    "__glXDisp_Vertex4sv",
    "__glXDisp_Viewport",
    "__glXDrawArraysSize",
    "__glXDrawPixelsReqSize",
    "__glXDrawableRes",
    "__glXErrorOccured",
    "__glXFBInitDrawable",
    "__glXFBMemSwapBuffers",
    "__glXFindDrawablePrivate",
    "__glXFogfvReqSize",
    "__glXFogivReqSize",
    "__glXForceCurrent",
    "__glXFormatGLModes",
    "__glXFree",
    "__glXFreeBuffers",
    "__glXFreeContext",
    "__glXGetDrawablePrivate",
    "__glXGetVisualConfigs",
    "__glXImageSize",
    "__glXImpAtoi",
    "__glXImpCalloc",
    "__glXImpFatal",
    "__glXImpFclose",
    "__glXImpFopen",
    "__glXImpFprintf",
    "__glXImpFree",
    "__glXImpGetDrawablePrivate",
    "__glXImpGetenv",
    "__glXImpMalloc",
    "__glXImpRealloc",
    "__glXImpSprintf",
    "__glXImpWarning",
    "__glXInitFB",
    "__glXInitMem",
    "__glXInitPix",
    "__glXIsDirect",
    "__glXLastContext",
    "__glXLightModelfvReqSize",
    "__glXLightModelivReqSize",
    "__glXLightfvReqSize",
    "__glXLightivReqSize",
    "__glXLookupContextByTag",
    "__glXMakeCurrent",
    "__glXMalloc",
    "__glXMap1dReqSize",
    "__glXMap1fReqSize",
    "__glXMap2dReqSize",
    "__glXMap2fReqSize",
    "__glXMaterialfvReqSize",
    "__glXMaterialivReqSize",
    "__glXNoSuchRenderOpcode",
    "__glXNoSuchSingleOpcode",
    "__glXNop",
    "__glXPixInitDrawable",
    "__glXPixelMapfvReqSize",
    "__glXPixelMapuivReqSize",
    "__glXPixelMapusvReqSize",
    "__glXPixmapRes",
    "__glXPrioritizeTexturesReqSize",
    "__glXQueryContextInfoEXT",
    "__glXQueryExtensionsString",
    "__glXQueryServerString",
    "__glXQueryVersion",
    "__glXRealloc",
    "__glXRender",
    "__glXRenderLarge",
    "__glXRenderSizeTable",
    "__glXRenderSizeTable_EXT",
    "__glXRenderTable",
    "__glXRenderTable_EXT",
    "__glXReply",
    "__glXResetLargeCommandStatus",
    "__glXResizeBuffers",
    "__glXResizeDrawableBuffers",
    "__glXScreenInit",
    "__glXScreenReset",
    "__glXSeparableFilter2DReqSize",
    "__glXSingleTable",
    "__glXSwapBuffers",
    "__glXSwapClientInfo",
    "__glXSwapCopyContext",
    "__glXSwapCreateContext",
    "__glXSwapCreateGLXPixmap",
    "__glXSwapDestroyContext",
    "__glXSwapDestroyGLXPixmap",
    "__glXSwapGetVisualConfigs",
    "__glXSwapIsDirect",
    "__glXSwapIsDirectReply",
    "__glXSwapMakeCurrent",
    "__glXSwapMakeCurrentReply",
    "__glXSwapQueryContextInfoEXTReply",
    "__glXSwapQueryExtensionsString",
    "__glXSwapQueryServerString",
    "__glXSwapQueryVersion",
    "__glXSwapQueryVersionReply",
    "__glXSwapRender",
    "__glXSwapRenderLarge",
    "__glXSwapRenderTable",
    "__glXSwapRenderTable_EXT",
    "__glXSwapSingleTable",
    "__glXSwapSwapBuffers",
    "__glXSwapUseXFont",
    "__glXSwapVendorPrivTable_EXT",
    "__glXSwapVendorPrivate",
    "__glXSwapVendorPrivateWithReply",
    "__glXSwapWaitGL",
    "__glXSwapWaitX",
    "__glXTexEnvfvReqSize",
    "__glXTexEnvivReqSize",
    "__glXTexGendvReqSize",
    "__glXTexGenfvReqSize",
    "__glXTexGenivReqSize",
    "__glXTexImage1DReqSize",
    "__glXTexImage2DReqSize",
    "__glXTexImage3DReqSize",
    "__glXTexParameterfvReqSize",
    "__glXTexParameterivReqSize",
    "__glXTexSubImage1DReqSize",
    "__glXTexSubImage2DReqSize",
    "__glXTexSubImage3DReqSize",
    "__glXTypeSize",
    "__glXUnrefDrawablePrivate",
    "__glXUnsupportedPrivateRequest",
    "__glXUseXFont",
    "__glXVendorPrivTable_EXT",
    "__glXVendorPrivate",
    "__glXVendorPrivateWithReply",
    "__glXWaitGL",
    "__glXWaitX",
    "__glXcombine_strings",
    "glAccum",
    "glActiveTextureARB",
    "glAlphaFunc",
    "glAreTexturesResident",
    "glAreTexturesResidentEXT",
    "glBegin",
    "glBindTexture",
    "glBitmap",
    "glBlendColor",
    "glBlendEquation",
    "glBlendFunc",
    "glCallList",
    "glCallLists",
    "glClear",
    "glClearAccum",
    "glClearColor",
    "glClearDepth",
    "glClearIndex",
    "glClearStencil",
    "glClipPlane",
    "glColor3bv",
    "glColor3dv",
    "glColor3fv",
    "glColor3iv",
    "glColor3sv",
    "glColor3ubv",
    "glColor3uiv",
    "glColor3usv",
    "glColor4bv",
    "glColor4dv",
    "glColor4fv",
    "glColor4iv",
    "glColor4sv",
    "glColor4ubv",
    "glColor4uiv",
    "glColor4usv",
    "glColorMask",
    "glColorMaterial",
    "glColorPointer",
    "glColorSubTable",
    "glColorTable",
    "glColorTableParameterfv",
    "glColorTableParameteriv",
    "glConvolutionFilter1D",
    "glConvolutionFilter2D",
    "glConvolutionParameterf",
    "glConvolutionParameterfv",
    "glConvolutionParameteri",
    "glConvolutionParameteriv",
    "glCopyColorSubTable",
    "glCopyColorTable",
    "glCopyConvolutionFilter1D",
    "glCopyConvolutionFilter2D",
    "glCopyPixels",
    "glCopyTexImage1D",
    "glCopyTexImage2D",
    "glCopyTexSubImage1D",
    "glCopyTexSubImage2D",
    "glCopyTexSubImage3D",
    "glCullFace",
    "glDeleteLists",
    "glDeleteTextures",
    "glDeleteTexturesEXT",
    "glDepthFunc",
    "glDepthMask",
    "glDepthRange",
    "glDisable",
    "glDisableClientState",
    "glDrawArrays",
    "glDrawBuffer",
    "glDrawPixels",
    "glEdgeFlagPointer",
    "glEdgeFlagv",
    "glEnable",
    "glEnableClientState",
    "glEnd",
    "glEndList",
    "glEvalCoord1dv",
    "glEvalCoord1fv",
    "glEvalCoord2dv",
    "glEvalCoord2fv",
    "glEvalMesh1",
    "glEvalMesh2",
    "glEvalPoint1",
    "glEvalPoint2",
    "glFeedbackBuffer",
    "glFinish",
    "glFlush",
    "glFogf",
    "glFogfv",
    "glFogi",
    "glFogiv",
    "glFrontFace",
    "glFrustum",
    "glGenLists",
    "glGenTextures",
    "glGenTexturesEXT",
    "glGetBooleanv",
    "glGetClipPlane",
    "glGetColorTable",
    "glGetColorTableParameterfv",
    "glGetColorTableParameteriv",
    "glGetConvolutionFilter",
    "glGetConvolutionParameterfv",
    "glGetConvolutionParameteriv",
    "glGetDoublev",
    "glGetError",
    "glGetFloatv",
    "glGetHistogram",
    "glGetHistogramParameterfv",
    "glGetHistogramParameteriv",
    "glGetIntegerv",
    "glGetLightfv",
    "glGetLightiv",
    "glGetMapdv",
    "glGetMapfv",
    "glGetMapiv",
    "glGetMaterialfv",
    "glGetMaterialiv",
    "glGetMinmax",
    "glGetMinmaxParameterfv",
    "glGetMinmaxParameteriv",
    "glGetPixelMapfv",
    "glGetPixelMapuiv",
    "glGetPixelMapusv",
    "glGetPolygonStipple",
    "glGetSeparableFilter",
    "glGetString",
    "glGetTexEnvfv",
    "glGetTexEnviv",
    "glGetTexGendv",
    "glGetTexGenfv",
    "glGetTexGeniv",
    "glGetTexImage",
    "glGetTexLevelParameterfv",
    "glGetTexLevelParameteriv",
    "glGetTexParameterfv",
    "glGetTexParameteriv",
    "glHint",
    "glHistogram",
    "glIndexMask",
    "glIndexPointer",
    "glIndexdv",
    "glIndexfv",
    "glIndexiv",
    "glIndexsv",
    "glIndexubv",
    "glInitNames",
    "glIsEnabled",
    "glIsList",
    "glIsTexture",
    "glIsTextureEXT",
    "glLightModelf",
    "glLightModelfv",
    "glLightModeli",
    "glLightModeliv",
    "glLightf",
    "glLightfv",
    "glLighti",
    "glLightiv",
    "glLineStipple",
    "glLineWidth",
    "glListBase",
    "glLoadIdentity",
    "glLoadMatrixd",
    "glLoadMatrixf",
    "glLoadName",
    "glLogicOp",
    "glMap1d",
    "glMap1f",
    "glMap2d",
    "glMap2f",
    "glMapGrid1d",
    "glMapGrid1f",
    "glMapGrid2d",
    "glMapGrid2f",
    "glMaterialf",
    "glMaterialfv",
    "glMateriali",
    "glMaterialiv",
    "glMatrixMode",
    "glMinmax",
    "glMultMatrixd",
    "glMultMatrixf",
    "glMultiTexCoord1dvARB",
    "glMultiTexCoord1fvARB",
    "glMultiTexCoord1ivARB",
    "glMultiTexCoord1svARB",
    "glMultiTexCoord2dvARB",
    "glMultiTexCoord2fvARB",
    "glMultiTexCoord2ivARB",
    "glMultiTexCoord2svARB",
    "glMultiTexCoord3dvARB",
    "glMultiTexCoord3fvARB",
    "glMultiTexCoord3ivARB",
    "glMultiTexCoord3svARB",
    "glMultiTexCoord4dvARB",
    "glMultiTexCoord4fvARB",
    "glMultiTexCoord4ivARB",
    "glMultiTexCoord4svARB",
    "glNewList",
    "glNormal3bv",
    "glNormal3dv",
    "glNormal3fv",
    "glNormal3iv",
    "glNormal3sv",
    "glNormalPointer",
    "glOrtho",
    "glPassThrough",
    "glPixelMapfv",
    "glPixelMapuiv",
    "glPixelMapusv",
    "glPixelStoref",
    "glPixelStorei",
    "glPixelTransferf",
    "glPixelTransferi",
    "glPixelZoom",
    "glPointSize",
    "glPolygonMode",
    "glPolygonOffset",
    "glPolygonStipple",
    "glPopAttrib",
    "glPopMatrix",
    "glPopName",
    "glPrioritizeTextures",
    "glPushAttrib",
    "glPushMatrix",
    "glPushName",
    "glRasterPos2dv",
    "glRasterPos2fv",
    "glRasterPos2iv",
    "glRasterPos2sv",
    "glRasterPos3dv",
    "glRasterPos3fv",
    "glRasterPos3iv",
    "glRasterPos3sv",
    "glRasterPos4dv",
    "glRasterPos4fv",
    "glRasterPos4iv",
    "glRasterPos4sv",
    "glReadBuffer",
    "glReadPixels",
    "glRectdv",
    "glRectfv",
    "glRectiv",
    "glRectsv",
    "glRenderMode",
    "glResetHistogram",
    "glResetMinmax",
    "glRotated",
    "glRotatef",
    "glScaled",
    "glScalef",
    "glScissor",
    "glSelectBuffer",
    "glSeparableFilter2D",
    "glShadeModel",
    "glStencilFunc",
    "glStencilMask",
    "glStencilOp",
    "glTexCoord1dv",
    "glTexCoord1fv",
    "glTexCoord1iv",
    "glTexCoord1sv",
    "glTexCoord2dv",
    "glTexCoord2fv",
    "glTexCoord2iv",
    "glTexCoord2sv",
    "glTexCoord3dv",
    "glTexCoord3fv",
    "glTexCoord3iv",
    "glTexCoord3sv",
    "glTexCoord4dv",
    "glTexCoord4fv",
    "glTexCoord4iv",
    "glTexCoord4sv",
    "glTexCoordPointer",
    "glTexEnvf",
    "glTexEnvfv",
    "glTexEnvi",
    "glTexEnviv",
    "glTexGend",
    "glTexGendv",
    "glTexGenf",
    "glTexGenfv",
    "glTexGeni",
    "glTexGeniv",
    "glTexImage1D",
    "glTexImage2D",
    "glTexImage3D",
    "glTexParameterf",
    "glTexParameterfv",
    "glTexParameteri",
    "glTexParameteriv",
    "glTexSubImage1D",
    "glTexSubImage2D",
    "glTexSubImage3D",
    "glTranslated",
    "glTranslatef",
    "glVertex2dv",
    "glVertex2fv",
    "glVertex2iv",
    "glVertex2sv",
    "glVertex3dv",
    "glVertex3fv",
    "glVertex3iv",
    "glVertex3sv",
    "glVertex4dv",
    "glVertex4fv",
    "glVertex4iv",
    "glVertex4sv",
    "glVertexPointer",
    "glViewport",
    "glxSwapQueryExtensionsStringReply",
    "glxSwapQueryServerStringReply",
    NULL
};

static XF86ModuleVersionInfo VersRec =
{
        "glx",
        MODULEVENDORSTRING,
        MODINFOSTRING1,
        MODINFOSTRING2,
        XF86_VERSION_CURRENT,
        1, 0, 0,
        ABI_CLASS_EXTENSION,
        ABI_EXTENSION_VERSION,
        MOD_CLASS_NONE,
        {0,0,0,0}
};

XF86ModuleData glxModuleData = { &VersRec, glxSetup, NULL };

static pointer
glxSetup(pointer module, pointer opts, int *errmaj, int *errmin)
{
    static Bool setupDone = FALSE;
    pointer GLcore  = NULL;
#ifdef GLX_USE_SGI_SI
    char GLcoreName[] = "GL";
#else
    char GLcoreName[] = "GLcore";
#endif

    if (!setupDone) {
    	setupDone = TRUE;

    	GLcore = LoadSubModule(module, GLcoreName, NULL, NULL, NULL, NULL, 
			   errmaj, errmin);
    	if (!GLcore) {
	    if (errmaj) *errmaj = LDR_NOSUBENT;
    	} else {
	    LoaderReqSymLists(glcoreSymbols, NULL);
    	    LoadExtension(&GLXExt, FALSE);
    	    /* Wrap the init visuals routine in micmap.c */
    	    GlxWrapInitVisuals(&miInitVisualsProc);
    	    /* Make sure this gets wrapped each time InitVisualWrap is called */
    	    miHookInitVisuals(NULL, GlxWrapInitVisuals);
	}
    } else {
	if (errmaj) *errmaj = LDR_ONCEONLY;
    }
    /* Need a non-NULL return value to indicate success */
    return GLcore;
}
