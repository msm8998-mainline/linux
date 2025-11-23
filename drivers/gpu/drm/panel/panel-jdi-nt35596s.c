// SPDX-License-Identifier: GPL-2.0-only
/* Copyright (c) 2025 Giovanni Ricca <giovanniricca@proton.me>
 * Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
 * Copyright (c) 2025, The Linux Foundation. All rights reserved.
 */

#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>

#include <video/mipi_display.h>

#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct jdi_nt35596s {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct gpio_desc *reset_gpio;
};

static inline
struct jdi_nt35596s *to_jdi_nt35596s(struct drm_panel *panel)
{
	return container_of(panel, struct jdi_nt35596s, panel);
}

static void jdi_nt35596s_reset(struct jdi_nt35596s *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(5000, 6000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(10000, 11000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(10000, 11000);
}

static int jdi_nt35596s_on(struct jdi_nt35596s *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x75, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x76, 0x2a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x77, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x78, 0x2f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x79, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7a, 0x3a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7b, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7c, 0x44);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7d, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7e, 0x4d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7f, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x80, 0x56);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x81, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x82, 0x5d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x83, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x84, 0x66);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x85, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x86, 0x6e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x87, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x88, 0x88);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x89, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8a, 0xa1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8b, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8c, 0xc9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8d, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8e, 0xec);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8f, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x90, 0x25);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x91, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x92, 0x53);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x93, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x94, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x95, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x96, 0x86);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x97, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x98, 0xbf);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x99, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9a, 0xe5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9b, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9c, 0x16);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9d, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9e, 0x34);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9f, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa0, 0x5b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_READ_PPS_START, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa3, 0x68);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa4, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa5, 0x75);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa6, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa7, 0x85);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_READ_PPS_CONTINUE,
				     0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xaa, 0x97);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xab, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xac, 0xac);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xad, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xae, 0xc3);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xaf, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0xce);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb1, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb2, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb3, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb4, 0x2a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb5, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb6, 0x2f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb7, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb8, 0x3a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb9, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xba, 0x44);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0x4d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbe, 0x56);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbf, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0, 0x5d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc1, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x66);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc4, 0x6e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0x88);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc8, 0xa1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc9, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xca, 0xc9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcc, 0xec);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcd, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xce, 0x25);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcf, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd0, 0x53);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd1, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd3, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd4, 0x86);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd5, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd6, 0xbf);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd7, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd8, 0xe5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd9, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xda, 0x16);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdb, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdc, 0x34);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdd, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xde, 0x5b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdf, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe0, 0x68);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe1, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe2, 0x75);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe3, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe4, 0x85);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe5, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe6, 0x97);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe7, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe8, 0xac);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe9, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xea, 0xc3);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xeb, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xec, 0xce);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xed, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xee, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xef, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0, 0xb1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf1, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf2, 0xbe);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf3, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf4, 0xd5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf5, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf6, 0xe9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf7, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf8, 0xfb);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf9, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfa, 0x0b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x21);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x01, 0x1a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x02, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x03, 0x27);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x04, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x05, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x06, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x07, 0x5d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x08, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x09, 0x7e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0a, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0b, 0xb2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0c, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0d, 0xda);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0e, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x0f, 0x1b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x10, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x11, 0x4d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x12, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x13, 0x4f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x14, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x15, 0x81);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x16, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x17, 0xb9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x18, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x19, 0xdf);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1a, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1b, 0x11);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1c, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1d, 0x2f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1e, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1f, 0x56);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x20, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x21, 0x62);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x22, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x23, 0x6f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x24, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x25, 0x7e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_GAMMA_CURVE, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x27, 0x90);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x28, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x29, 0xa4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x2a, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x2b, 0xbb);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_LUT, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x2f, 0xca);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_PARTIAL_ROWS, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_PARTIAL_COLUMNS,
				     0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x32, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x33, 0xb1);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x34, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x35, 0xbe);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_ADDRESS_MODE, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x37, 0xd5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x38, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x39, 0xe9);
	mipi_dsi_dcs_set_pixel_format_multi(&dsi_ctx, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x3b, 0xfb);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_3D_CONTROL, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x3f, 0x0b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_VSYNC_TIMING, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x41, 0x1a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x42, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x43, 0x27);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x44, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_GET_SCANLINE, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x46, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x47, 0x5d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x48, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x49, 0x7e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x4a, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x4b, 0xb2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x4c, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x4d, 0xda);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x4e, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x4f, 0x1b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x50, 0x02);
	mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x004d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x52, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x4f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x54, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_POWER_SAVE, 0x81);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x56, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x58, 0xb9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x59, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5a, 0xdf);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5b, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5c, 0x11);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5d, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_CABC_MIN_BRIGHTNESS,
				     0x2f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5f, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x60, 0x56);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x61, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x62, 0x62);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x63, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x64, 0x6f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x65, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x66, 0x7e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x67, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x68, 0x90);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x69, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6a, 0xa4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6b, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6c, 0xbb);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6d, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6e, 0xca);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x70, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x71, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x72, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x73, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x74, 0x38);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x75, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x76, 0x68);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x77, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x78, 0x90);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x79, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7a, 0xae);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7b, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7c, 0xc7);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7d, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7e, 0xdf);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x7f, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x80, 0xf0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x81, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x82, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x83, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x84, 0x3a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x85, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x86, 0x63);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x87, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x88, 0xa2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x89, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8a, 0xcd);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8b, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8c, 0x12);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8d, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8e, 0x45);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8f, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x90, 0x47);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x91, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x92, 0x7a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x93, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x94, 0xb4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x95, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x96, 0xda);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x97, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x98, 0x0e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x99, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9a, 0x2c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9b, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9c, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9d, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9e, 0x61);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9f, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa0, 0x6f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_READ_PPS_START, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa3, 0x7f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa4, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa5, 0x93);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa6, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xa7, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_READ_PPS_CONTINUE,
				     0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xaa, 0xba);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xab, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xac, 0xc9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xad, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xae, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xaf, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb1, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb2, 0x38);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb3, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb4, 0x68);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb5, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb6, 0x90);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb7, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb8, 0xae);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb9, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xba, 0xc7);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbb, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbc, 0xdf);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbd, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbe, 0xf0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbf, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc1, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x3a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc4, 0x63);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6, 0xa2);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc7, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc8, 0xcd);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc9, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xca, 0x12);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcb, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcc, 0x45);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcd, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xce, 0x47);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcf, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd0, 0x7a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd1, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2, 0xb4);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd3, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd4, 0xda);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd5, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd6, 0x0e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd7, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd8, 0x2c);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd9, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xda, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdb, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdc, 0x61);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdd, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xde, 0x6f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdf, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe0, 0x7f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe1, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe2, 0x93);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe3, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe4, 0xa5);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe5, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe6, 0xba);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe7, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe8, 0xc9);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe9, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xea, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x26);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x03, 0x18);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0xe0);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x24, 0xca);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x23);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x01, 0x84);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x05, 0x2d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x06, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x27);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1e, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x24);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9d, 0x34);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x1f, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0x10);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VHBLANK);
	mipi_dsi_dcs_set_display_brightness_multi(&dsi_ctx, 0x00ff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x24);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_POWER_SAVE, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb0, 0x00);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 80);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);

	return dsi_ctx.accum_err;
}

static int jdi_nt35596s_off(struct jdi_nt35596s *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	ctx->dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	mipi_dsi_dcs_set_display_off_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 20);
	mipi_dsi_dcs_enter_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);

	return dsi_ctx.accum_err;
}

static int jdi_nt35596s_prepare(struct drm_panel *panel)
{
	struct jdi_nt35596s *ctx = to_jdi_nt35596s(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	jdi_nt35596s_reset(ctx);

	ret = jdi_nt35596s_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		return ret;
	}

	return 0;
}

static int jdi_nt35596s_unprepare(struct drm_panel *panel)
{
	struct jdi_nt35596s *ctx = to_jdi_nt35596s(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = jdi_nt35596s_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);

	return 0;
}

static const struct drm_display_mode jdi_nt35596s_mode = {
	.clock = (1080 + 12 + 4 + 64) * (2040 + 4 + 1 + 23) * 60 / 1000,
	.hdisplay = 1080,
	.hsync_start = 1080 + 12,
	.hsync_end = 1080 + 12 + 4,
	.htotal = 1080 + 12 + 4 + 64,
	.vdisplay = 2040,
	.vsync_start = 2040 + 4,
	.vsync_end = 2040 + 4 + 1,
	.vtotal = 2040 + 4 + 1 + 23,
	.width_mm = 68,
	.height_mm = 128,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int jdi_nt35596s_get_modes(struct drm_panel *panel,
					    struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &jdi_nt35596s_mode);
}

static const struct drm_panel_funcs jdi_nt35596s_panel_funcs = {
	.prepare = jdi_nt35596s_prepare,
	.unprepare = jdi_nt35596s_unprepare,
	.get_modes = jdi_nt35596s_get_modes,
};

static int jdi_nt35596s_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct jdi_nt35596s *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct jdi_nt35596s, panel,
				   &jdi_nt35596s_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_MODE_VIDEO | MIPI_DSI_MODE_NO_EOT_PACKET |
			  MIPI_DSI_CLOCK_NON_CONTINUOUS;

	ctx->panel.prepare_prev_first = true;

	ret = drm_panel_of_backlight(&ctx->panel);
	if (ret)
		return dev_err_probe(dev, ret, "Failed to get backlight\n");

	drm_panel_add(&ctx->panel);

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void jdi_nt35596s_remove(struct mipi_dsi_device *dsi)
{
	struct jdi_nt35596s *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id jdi_nt35596s_of_match[] = {
	{ .compatible = "jdi,fhd-nt35596s" },
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, jdi_nt35596s_of_match);

static struct mipi_dsi_driver jdi_nt35596s_driver = {
	.probe = jdi_nt35596s_probe,
	.remove = jdi_nt35596s_remove,
	.driver = {
		.name = "panel-jdi-nt35596s",
		.of_match_table = jdi_nt35596s_of_match,
	},
};
module_mipi_dsi_driver(jdi_nt35596s_driver);

MODULE_AUTHOR("Giovanni Ricca <giovanniricca@proton.me>");
MODULE_DESCRIPTION("DRM driver for jdi nt35596s mipi video panel");
MODULE_LICENSE("GPL");
