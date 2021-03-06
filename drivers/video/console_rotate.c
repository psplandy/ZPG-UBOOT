/*
 * Copyright (c) 2015 Google, Inc
 * (C) Copyright 2015
 * Bernecker & Rainer Industrieelektronik GmbH - http://www.br-automation.com
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <dm.h>
#include <video.h>
#include <video_console.h>
#include <video_font.h>		/* Get font data, width and height */

#if defined(CONFIG_TARGET_odroidgoa)
	#include <rockchip_display_cmds.h>
#endif

static int console_set_row_1(struct udevice *dev, uint row, int clr)
{
	struct video_priv *vid_priv = dev_get_uclass_priv(dev->parent);
#if defined(CONFIG_TARGET_odroidgoa)
	int pbytes = 3;
#else
	int pbytes = VNBYTES(vid_priv->bpix);
#endif
	void *line;
	int i, j;

	line = vid_priv->fb + vid_priv->line_length -
		(row + 1) * VIDEO_FONT_HEIGHT * pbytes;
	for (j = 0; j < vid_priv->ysize; j++) {
		switch (vid_priv->bpix) {
#ifdef CONFIG_VIDEO_BPP8
		case VIDEO_BPP8: {
			uint8_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++)
				*dst++ = clr;
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP16
		case VIDEO_BPP16: {
			uint16_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++)
				*dst++ = clr;
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP32
		case VIDEO_BPP32: {
#if defined(CONFIG_TARGET_odroidgoa)
			struct lcd_fb_bit *dst = line, *bg = lcd_getbg();
			struct video_fb_bit *c = (struct video_fb_bit *)&clr;

			if (!lcd_gettransp()) {
				for (i = 0; i < VIDEO_FONT_HEIGHT; i++, dst++) {
					if (bg == NULL) {
						dst->r = c->r;
						dst->g = c->g;
						dst->b = c->b;
					} else {
						dst->r = bg->r;
						dst->g = bg->g;
						dst->b = bg->b;
					}
				}
			}
			break;
#else
			uint32_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++)
				*dst++ = clr;
			break;
#endif
		}
#endif
		default:
			return -ENOSYS;
		}
		line += vid_priv->line_length;
	}

	return 0;
}

static int console_move_rows_1(struct udevice *dev, uint rowdst, uint rowsrc,
			       uint count)
{
	struct video_priv *vid_priv = dev_get_uclass_priv(dev->parent);
	void *dst;
	void *src;
#if defined(CONFIG_TARGET_odroidgoa)
	int pbytes = 3;
#else
	int pbytes = VNBYTES(vid_priv->bpix);
#endif
	int j;

	dst = vid_priv->fb + vid_priv->line_length -
		(rowdst + count) * VIDEO_FONT_HEIGHT * pbytes;
	src = vid_priv->fb + vid_priv->line_length -
		(rowsrc + count) * VIDEO_FONT_HEIGHT * pbytes;

	for (j = 0; j < vid_priv->ysize; j++) {
		memmove(dst, src, VIDEO_FONT_HEIGHT * pbytes * count);
		src += vid_priv->line_length;
		dst += vid_priv->line_length;
	}

	return 0;
}

static int console_putc_xy_1(struct udevice *dev, uint x_frac, uint y, char ch)
{
	struct vidconsole_priv *vc_priv = dev_get_uclass_priv(dev);
	struct udevice *vid = dev->parent;
	struct video_priv *vid_priv = dev_get_uclass_priv(vid);
#if defined(CONFIG_TARGET_odroidgoa)
	int pbytes = 3;
#else
	int pbytes = VNBYTES(vid_priv->bpix);
#endif
	int i, col;
	int mask = 0x80;
	void *line;
	uchar *pfont = video_fontdata + ch * VIDEO_FONT_HEIGHT;

	line = vid_priv->fb + (VID_TO_PIXEL(x_frac) + 1) *
			vid_priv->line_length - (y + 1) * pbytes;
	if (x_frac + VID_TO_POS(vc_priv->x_charsize) > vc_priv->xsize_frac)
		return -EAGAIN;

	for (col = 0; col < VIDEO_FONT_HEIGHT; col++) {
		switch (vid_priv->bpix) {
#ifdef CONFIG_VIDEO_BPP8
		case VIDEO_BPP8: {
			uint8_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++) {
				*dst-- = (pfont[i] & mask) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
			}
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP16
		case VIDEO_BPP16: {
			uint16_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++) {
				*dst-- = (pfont[i] & mask) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
			}
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP32
		case VIDEO_BPP32: {
#if defined(CONFIG_TARGET_odroidgoa)
			struct lcd_fb_bit *dst = line, *lfg, *lbg;
			struct video_fb_bit *fg, *bg;
			bool transp = lcd_gettransp();

			fg = (struct video_fb_bit *)&vid_priv->colour_fg;
			bg = (struct video_fb_bit *)&vid_priv->colour_bg;

			lfg = lcd_getfg();
			lbg = lcd_getbg();
			for (i = 0; i < VIDEO_FONT_HEIGHT; i++, dst--) {
				if (pfont[i] & mask) {
					if (lfg == NULL) {
						dst->r = fg->r;
						dst->g = fg->g;
						dst->b = fg->b;
					} else {
						dst->r = lfg->r;
						dst->g = lfg->g;
						dst->b = lfg->b;
					}
				} else {
					if (!transp) {
						if (lbg == NULL) {
							dst->r = bg->r;
							dst->g = bg->g;
							dst->b = bg->b;
						} else {
							dst->r = lbg->r;
							dst->g = lbg->g;
							dst->b = lbg->b;
						}
					}
				}
			}
			break;
#else
			uint32_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++) {
				*dst-- = (pfont[i] & mask) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
			}
			break;
#endif
		}
#endif
		default:
			return -ENOSYS;
		}
		line += vid_priv->line_length;
		mask >>= 1;
	}

	return VID_TO_POS(VIDEO_FONT_WIDTH);
}


static int console_set_row_2(struct udevice *dev, uint row, int clr)
{
	struct video_priv *vid_priv = dev_get_uclass_priv(dev->parent);
	void *line;
	int pixels = VIDEO_FONT_HEIGHT * vid_priv->xsize;
	int i;

	line = vid_priv->fb + vid_priv->ysize * vid_priv->line_length -
		(row + 1) * VIDEO_FONT_HEIGHT * vid_priv->line_length;
	switch (vid_priv->bpix) {
#ifdef CONFIG_VIDEO_BPP8
	case VIDEO_BPP8: {
		uint8_t *dst = line;

		for (i = 0; i < pixels; i++)
			*dst++ = clr;
		break;
	}
#endif
#ifdef CONFIG_VIDEO_BPP16
	case VIDEO_BPP16: {
		uint16_t *dst = line;

		for (i = 0; i < pixels; i++)
			*dst++ = clr;
		break;
	}
#endif
#ifdef CONFIG_VIDEO_BPP32
	case VIDEO_BPP32: {
#if defined(CONFIG_TARGET_odroidgoa)
		struct lcd_fb_bit *dst = line, *bg = lcd_getbg();
		struct video_fb_bit *c = (struct video_fb_bit *)&clr;

		if (!lcd_gettransp()) {
			for (i = 0; i < pixels; i++, dst++) {
				if (bg == NULL) {
					dst->r = c->r;
					dst->g = c->g;
					dst->b = c->b;
				} else {
					dst->r = bg->r;
					dst->g = bg->g;
					dst->b = bg->b;
				}
			}
		}
		break;
#else
		uint32_t *dst = line;

		for (i = 0; i < pixels; i++)
			*dst++ = clr;
		break;
#endif
	}
#endif
	default:
		return -ENOSYS;
	}

	return 0;
}

static int console_move_rows_2(struct udevice *dev, uint rowdst, uint rowsrc,
			       uint count)
{
	struct video_priv *vid_priv = dev_get_uclass_priv(dev->parent);
	void *dst;
	void *src;
	void *end;

	end = vid_priv->fb + vid_priv->ysize * vid_priv->line_length;
	dst = end - (rowdst + count) * VIDEO_FONT_HEIGHT *
		vid_priv->line_length;
	src = end - (rowsrc + count) * VIDEO_FONT_HEIGHT *
		vid_priv->line_length;
	memmove(dst, src, VIDEO_FONT_HEIGHT * vid_priv->line_length * count);

	return 0;
}

static int console_putc_xy_2(struct udevice *dev, uint x_frac, uint y, char ch)
{
	struct vidconsole_priv *vc_priv = dev_get_uclass_priv(dev);
	struct udevice *vid = dev->parent;
	struct video_priv *vid_priv = dev_get_uclass_priv(vid);
	int i, row;
	void *line;

	if (x_frac + VID_TO_POS(vc_priv->x_charsize) > vc_priv->xsize_frac)
		return -EAGAIN;

#if defined(CONFIG_TARGET_odroidgoa)
	line = vid_priv->fb + (vid_priv->ysize - y - 1) *
			vid_priv->line_length +
			(vid_priv->xsize - VID_TO_PIXEL(x_frac) -
			VIDEO_FONT_WIDTH - 1) * 3;
#else
	line = vid_priv->fb + (vid_priv->ysize - y - 1) *
			vid_priv->line_length +
			(vid_priv->xsize - VID_TO_PIXEL(x_frac) -
			VIDEO_FONT_WIDTH - 1) * VNBYTES(vid_priv->bpix);
#endif

	for (row = 0; row < VIDEO_FONT_HEIGHT; row++) {
		uchar bits = video_fontdata[ch * VIDEO_FONT_HEIGHT + row];

		switch (vid_priv->bpix) {
#ifdef CONFIG_VIDEO_BPP8
		case VIDEO_BPP8: {
			uint8_t *dst = line;

			for (i = 0; i < VIDEO_FONT_WIDTH; i++) {
				*dst-- = (bits & 0x80) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
				bits <<= 1;
			}
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP16
		case VIDEO_BPP16: {
			uint16_t *dst = line;

			for (i = 0; i < VIDEO_FONT_WIDTH; i++) {
				*dst-- = (bits & 0x80) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
				bits <<= 1;
			}
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP32
		case VIDEO_BPP32: {
#if defined(CONFIG_TARGET_odroidgoa)
			struct lcd_fb_bit *dst = line, *lfg, *lbg;
			struct video_fb_bit *fg, *bg;
			bool transp = lcd_gettransp();

			fg = (struct video_fb_bit *)&vid_priv->colour_fg;
			bg = (struct video_fb_bit *)&vid_priv->colour_bg;

			lfg = lcd_getfg();
			lbg = lcd_getbg();
			for (i = 0; i < VIDEO_FONT_WIDTH; i++, dst--) {
				if (bits & 0x80) {
					if (lfg == NULL) {
						dst->r = fg->r;
						dst->g = fg->g;
						dst->b = fg->b;
					} else {
						dst->r = lfg->r;
						dst->g = lfg->g;
						dst->b = lfg->b;
					}
				} else {
					if (!transp) {
						if (lbg == NULL) {
							dst->r = bg->r;
							dst->g = bg->g;
							dst->b = bg->b;
						} else {
							dst->r = lbg->r;
							dst->g = lbg->g;
							dst->b = lbg->b;
						}
					}
				}
				bits <<= 1;
			}
			break;
#else
			uint32_t *dst = line;

			for (i = 0; i < VIDEO_FONT_WIDTH; i++) {
				*dst-- = (bits & 0x80) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
				bits <<= 1;
			}
			break;
#endif
		}
#endif
		default:
			return -ENOSYS;
		}
		line -= vid_priv->line_length;
	}

	return VID_TO_POS(VIDEO_FONT_WIDTH);
}

static int console_set_row_3(struct udevice *dev, uint row, int clr)
{
	struct video_priv *vid_priv = dev_get_uclass_priv(dev->parent);
#if defined(CONFIG_TARGET_odroidgoa)
	int pbytes = 3;
#else
	int pbytes = VNBYTES(vid_priv->bpix);
#endif
	void *line;
	int i, j;

	line = vid_priv->fb + row * VIDEO_FONT_HEIGHT * pbytes;
	for (j = 0; j < vid_priv->ysize; j++) {
		switch (vid_priv->bpix) {
#ifdef CONFIG_VIDEO_BPP8
		case VIDEO_BPP8: {
			uint8_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++)
				*dst++ = clr;
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP16
		case VIDEO_BPP16: {
			uint16_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++)
				*dst++ = clr;
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP32
		case VIDEO_BPP32: {
#if defined(CONFIG_TARGET_odroidgoa)
			struct lcd_fb_bit *dst = line, *bg = lcd_getbg();
			struct video_fb_bit *c = (struct video_fb_bit *)&clr;

			if (!lcd_gettransp()) {
				for (i = 0; i < VIDEO_FONT_HEIGHT; i++, dst++) {
					if (bg == NULL) {
						dst->r = c->r;
						dst->g = c->g;
						dst->b = c->b;
					} else {
						dst->r = bg->r;
						dst->g = bg->g;
						dst->b = bg->b;
					}
				}
			}
			break;
#else
			uint32_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++)
				*dst++ = clr;
			break;
#endif
		}
#endif
		default:
			return -ENOSYS;
		}
		line += vid_priv->line_length;
	}

	return 0;
}

static int console_move_rows_3(struct udevice *dev, uint rowdst, uint rowsrc,
			       uint count)
{
	struct video_priv *vid_priv = dev_get_uclass_priv(dev->parent);
	void *dst;
	void *src;
#if defined(CONFIG_TARGET_odroidgoa)
	int pbytes = 3;
#else
	int pbytes = VNBYTES(vid_priv->bpix);
#endif
	int j;

	dst = vid_priv->fb + rowdst * VIDEO_FONT_HEIGHT * pbytes;
	src = vid_priv->fb + rowsrc * VIDEO_FONT_HEIGHT * pbytes;

	for (j = 0; j < vid_priv->ysize; j++) {
		memmove(dst, src, VIDEO_FONT_HEIGHT * pbytes * count);
		src += vid_priv->line_length;
		dst += vid_priv->line_length;
	}

	return 0;
}

static int console_putc_xy_3(struct udevice *dev, uint x_frac, uint y, char ch)
{
	struct vidconsole_priv *vc_priv = dev_get_uclass_priv(dev);
	struct udevice *vid = dev->parent;
	struct video_priv *vid_priv = dev_get_uclass_priv(vid);
#if defined(CONFIG_TARGET_odroidgoa)
	int pbytes = 3;
#else
	int pbytes = VNBYTES(vid_priv->bpix);
#endif
	int i, col;
	int mask = 0x80;
	void *line = vid_priv->fb +
		(vid_priv->ysize - VID_TO_PIXEL(x_frac) - 1) *
		vid_priv->line_length + y * pbytes;
	uchar *pfont = video_fontdata + ch * VIDEO_FONT_HEIGHT;

	if (x_frac + VID_TO_POS(vc_priv->x_charsize) > vc_priv->xsize_frac)
		return -EAGAIN;

	for (col = 0; col < VIDEO_FONT_HEIGHT; col++) {
		switch (vid_priv->bpix) {
#ifdef CONFIG_VIDEO_BPP8
		case VIDEO_BPP8: {
			uint8_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++) {
				*dst++ = (pfont[i] & mask) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
			}
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP16
		case VIDEO_BPP16: {
			uint16_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++) {
				*dst++ = (pfont[i] & mask) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
			}
			break;
		}
#endif
#ifdef CONFIG_VIDEO_BPP32
		case VIDEO_BPP32: {
#if defined(CONFIG_TARGET_odroidgoa)
			struct lcd_fb_bit *dst = line, *lfg, *lbg;
			struct video_fb_bit *fg, *bg;
			bool transp = lcd_gettransp();

			fg = (struct video_fb_bit *)&vid_priv->colour_fg;
			bg = (struct video_fb_bit *)&vid_priv->colour_bg;

			lfg = lcd_getfg();
			lbg = lcd_getbg();
			for (i = 0; i < VIDEO_FONT_HEIGHT; i++, dst++) {
				if (pfont[i] & mask) {
					if (lfg == NULL) {
						dst->r = fg->r;
						dst->g = fg->g;
						dst->b = fg->b;
					} else {
						dst->r = lfg->r;
						dst->g = lfg->g;
						dst->b = lfg->b;
					}
				} else {
					if (!transp) {
						if (lbg == NULL) {
							dst->r = bg->r;
							dst->g = bg->g;
							dst->b = bg->b;
						} else {
							dst->r = lbg->r;
							dst->g = lbg->g;
							dst->b = lbg->b;
						}
					}
				}
			}
			break;
#else
			uint32_t *dst = line;

			for (i = 0; i < VIDEO_FONT_HEIGHT; i++) {
				*dst++ = (pfont[i] & mask) ? vid_priv->colour_fg
					: vid_priv->colour_bg;
			}
			break;
#endif
		}
#endif
		default:
			return -ENOSYS;
		}
		line -= vid_priv->line_length;
		mask >>= 1;
	}

	return VID_TO_POS(VIDEO_FONT_WIDTH);
}


static int console_probe_2(struct udevice *dev)
{
	struct vidconsole_priv *vc_priv = dev_get_uclass_priv(dev);
	struct udevice *vid_dev = dev->parent;
	struct video_priv *vid_priv = dev_get_uclass_priv(vid_dev);

	vc_priv->x_charsize = VIDEO_FONT_WIDTH;
	vc_priv->y_charsize = VIDEO_FONT_HEIGHT;
	vc_priv->cols = vid_priv->xsize / VIDEO_FONT_WIDTH;
	vc_priv->rows = vid_priv->ysize / VIDEO_FONT_HEIGHT;

	return 0;
}

static int console_probe_1_3(struct udevice *dev)
{
	struct vidconsole_priv *vc_priv = dev_get_uclass_priv(dev);
	struct udevice *vid_dev = dev->parent;
	struct video_priv *vid_priv = dev_get_uclass_priv(vid_dev);

	vc_priv->x_charsize = VIDEO_FONT_WIDTH;
	vc_priv->y_charsize = VIDEO_FONT_HEIGHT;
	vc_priv->cols = vid_priv->ysize / VIDEO_FONT_WIDTH;
	vc_priv->rows = vid_priv->xsize / VIDEO_FONT_HEIGHT;
	vc_priv->xsize_frac = VID_TO_POS(vid_priv->ysize);

	return 0;
}

struct vidconsole_ops console_ops_1 = {
	.putc_xy	= console_putc_xy_1,
	.move_rows	= console_move_rows_1,
	.set_row	= console_set_row_1,
};

struct vidconsole_ops console_ops_2 = {
	.putc_xy	= console_putc_xy_2,
	.move_rows	= console_move_rows_2,
	.set_row	= console_set_row_2,
};

struct vidconsole_ops console_ops_3 = {
	.putc_xy	= console_putc_xy_3,
	.move_rows	= console_move_rows_3,
	.set_row	= console_set_row_3,
};

U_BOOT_DRIVER(vidconsole_1) = {
	.name	= "vidconsole1",
	.id	= UCLASS_VIDEO_CONSOLE,
	.ops	= &console_ops_1,
	.probe	= console_probe_1_3,
};

U_BOOT_DRIVER(vidconsole_2) = {
	.name	= "vidconsole2",
	.id	= UCLASS_VIDEO_CONSOLE,
	.ops	= &console_ops_2,
	.probe	= console_probe_2,
};

U_BOOT_DRIVER(vidconsole_3) = {
	.name	= "vidconsole3",
	.id	= UCLASS_VIDEO_CONSOLE,
	.ops	= &console_ops_3,
	.probe	= console_probe_1_3,
};
