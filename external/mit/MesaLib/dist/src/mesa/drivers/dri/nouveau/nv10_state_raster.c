/*
 * Copyright (C) 2009 Francisco Jerez.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#include "nouveau_driver.h"
#include "nouveau_context.h"
#include "nouveau_gldefs.h"
#include "nouveau_util.h"
#include "nv10_3d.xml.h"
#include "nv10_driver.h"

void
nv10_emit_alpha_func(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_ALPHA_FUNC_ENABLE, 1);
	OUT_RINGb(chan, ctx->Color.AlphaEnabled);

	BEGIN_RING(chan, celsius, NV10_3D_ALPHA_FUNC_FUNC, 2);
	OUT_RING(chan, nvgl_comparison_op(ctx->Color.AlphaFunc));
	OUT_RING(chan, FLOAT_TO_UBYTE(ctx->Color.AlphaRef));
}

void
nv10_emit_blend_color(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_BLEND_COLOR, 1);
	OUT_RING(chan, FLOAT_TO_UBYTE(ctx->Color.BlendColor[3]) << 24 |
		 FLOAT_TO_UBYTE(ctx->Color.BlendColor[0]) << 16 |
		 FLOAT_TO_UBYTE(ctx->Color.BlendColor[1]) << 8 |
		 FLOAT_TO_UBYTE(ctx->Color.BlendColor[2]) << 0);
}

void
nv10_emit_blend_equation(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_BLEND_FUNC_ENABLE, 1);
	OUT_RINGb(chan, ctx->Color.BlendEnabled);

	BEGIN_RING(chan, celsius, NV10_3D_BLEND_EQUATION, 1);
	OUT_RING(chan, nvgl_blend_eqn(ctx->Color.Blend[0].EquationRGB));
}

void
nv10_emit_blend_func(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_BLEND_FUNC_SRC, 2);
	OUT_RING(chan, nvgl_blend_func(ctx->Color.Blend[0].SrcRGB));
	OUT_RING(chan, nvgl_blend_func(ctx->Color.Blend[0].DstRGB));
}

void
nv10_emit_color_mask(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_COLOR_MASK, 1);
	OUT_RING(chan, ((ctx->Color.ColorMask[0][3] ? 1 << 24 : 0) |
			(ctx->Color.ColorMask[0][0] ? 1 << 16 : 0) |
			(ctx->Color.ColorMask[0][1] ? 1 << 8 : 0) |
			(ctx->Color.ColorMask[0][2] ? 1 << 0 : 0)));
}

void
nv10_emit_depth(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_DEPTH_TEST_ENABLE, 1);
	OUT_RINGb(chan, ctx->Depth.Test);
	BEGIN_RING(chan, celsius, NV10_3D_DEPTH_WRITE_ENABLE, 1);
	OUT_RINGb(chan, ctx->Depth.Mask);
	BEGIN_RING(chan, celsius, NV10_3D_DEPTH_FUNC, 1);
	OUT_RING(chan, nvgl_comparison_op(ctx->Depth.Func));
}

void
nv10_emit_dither(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_DITHER_ENABLE, 1);
	OUT_RINGb(chan, ctx->Color.DitherFlag);
}

void
nv10_emit_logic_opcode(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	assert(!ctx->Color.ColorLogicOpEnabled
	       || context_chipset(ctx) >= 0x11);

	BEGIN_RING(chan, celsius, NV11_3D_COLOR_LOGIC_OP_ENABLE, 2);
	OUT_RINGb(chan, ctx->Color.ColorLogicOpEnabled);
	OUT_RING(chan, nvgl_logicop_func(ctx->Color.LogicOp));
}

void
nv10_emit_shade_model(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_SHADE_MODEL, 1);
	OUT_RING(chan, ctx->Light.ShadeModel == GL_SMOOTH ?
		 NV10_3D_SHADE_MODEL_SMOOTH : NV10_3D_SHADE_MODEL_FLAT);
}

void
nv10_emit_stencil_func(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_STENCIL_ENABLE, 1);
	OUT_RINGb(chan, ctx->Stencil.Enabled);

	BEGIN_RING(chan, celsius, NV10_3D_STENCIL_FUNC_FUNC, 3);
	OUT_RING(chan, nvgl_comparison_op(ctx->Stencil.Function[0]));
	OUT_RING(chan, ctx->Stencil.Ref[0]);
	OUT_RING(chan, ctx->Stencil.ValueMask[0]);
}

void
nv10_emit_stencil_mask(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_STENCIL_MASK, 1);
	OUT_RING(chan, ctx->Stencil.WriteMask[0]);
}

void
nv10_emit_stencil_op(struct gl_context *ctx, int emit)
{
	struct nouveau_channel *chan = context_chan(ctx);
	struct nouveau_grobj *celsius = context_eng3d(ctx);

	BEGIN_RING(chan, celsius, NV10_3D_STENCIL_OP_FAIL, 3);
	OUT_RING(chan, nvgl_stencil_op(ctx->Stencil.FailFunc[0]));
	OUT_RING(chan, nvgl_stencil_op(ctx->Stencil.ZFailFunc[0]));
	OUT_RING(chan, nvgl_stencil_op(ctx->Stencil.ZPassFunc[0]));
}
