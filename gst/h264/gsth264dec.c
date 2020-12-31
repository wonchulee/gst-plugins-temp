/* GStreamer
 * Copyright (C) <2020>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

/* TODO: Fix license */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gsth264dec.h"

GST_DEBUG_CATEGORY (h264dec_debug);
#define GST_CAT_DEFAULT (h264dec_debug)

#define gst_h264_dec_parent_class parent_class
G_DEFINE_TYPE (GstH264Dec, gst_h264_dec, GST_TYPE_VIDEO_DECODER);

/* FIXME: refine caps of padtemplate */
static GstStaticPadTemplate src_factory = GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("video/x-raw")
    );
static GstStaticPadTemplate sink_factory = GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("video/x-h264")
    );

static void gst_h264_dec_set_property (GObject * object, guint prop_id,
    const GValue * value, GParamSpec * pspec);
static void gst_h264_dec_get_property (GObject * object, guint prop_id,
    GValue * value, GParamSpec * pspec);
static void gst_h264_dec_finalize (GObject * object);
static gboolean gst_h264_dec_start (GstVideoDecoder * decoder);
static gboolean gst_h264_dec_stop (GstVideoDecoder * decoder);
static gboolean gst_h264_dec_flush (GstVideoDecoder * decoder);
static GstFlowReturn gst_h264_dec_finish (GstVideoDecoder * decoder);
static GstFlowReturn gst_h264_dec_handle_frame (GstVideoDecoder * decoder,
    GstVideoCodecFrame * frame);
static gboolean gst_h264_dec_set_format (GstVideoDecoder * video_dec,
    GstVideoCodecState * state);

static void
gst_h264_dec_class_init (GstH264DecClass * klass)
{
  GObjectClass *gobject_class;
  GstElementClass *element_class;
  GstVideoDecoderClass *decoder_class;

  gobject_class = G_OBJECT_CLASS (klass);
  element_class = GST_ELEMENT_CLASS (klass);
  decoder_class = GST_VIDEO_DECODER_CLASS (klass);

  gst_element_class_set_static_metadata (element_class,
      "h264 decoder", "Codec/Decoder/Video",
      "h264 decoder as a part of transcoder", "Sidan Kim<sidan@atins.io>");

  gobject_class->set_property = gst_h264_dec_set_property;
  gobject_class->get_property = gst_h264_dec_get_property;
  gobject_class->finalize = gst_h264_dec_finalize;

  decoder_class->set_format = GST_DEBUG_FUNCPTR (gst_h264_dec_set_format);
  decoder_class->handle_frame = GST_DEBUG_FUNCPTR (gst_h264_dec_handle_frame);
  decoder_class->start = GST_DEBUG_FUNCPTR (gst_h264_dec_start);
  decoder_class->stop = GST_DEBUG_FUNCPTR (gst_h264_dec_stop);
  decoder_class->flush = GST_DEBUG_FUNCPTR (gst_h264_dec_flush);
  decoder_class->finish = GST_DEBUG_FUNCPTR (gst_h264_dec_finish);

  gst_element_class_add_static_pad_template (element_class, &sink_factory);
  gst_element_class_add_static_pad_template (element_class, &src_factory);
}

static void
gst_h264_dec_init (GstH264Dec * dec)
{
  /* Constructor */
}

static void
gst_h264_dec_finalize (GObject * object)
{
  /* Destructor */
  G_OBJECT_CLASS (parent_class)->finalize (object);
}

static void
gst_h264_dec_set_property (GObject * object,
    guint prop_id, const GValue * value, GParamSpec * pspec)
{
  switch (prop_id) {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static void
gst_h264_dec_get_property (GObject * object,
    guint prop_id, GValue * value, GParamSpec * pspec)
{
  switch (prop_id) {
    default:
      G_OBJECT_WARN_INVALID_PROPERTY_ID (object, prop_id, pspec);
      break;
  }
}

static gboolean
gst_h264_dec_set_format (GstVideoDecoder * decoder, GstVideoCodecState * state)
{
  /* set_format informs us which format of data will come, extract caps from
   * GstVideoCodecState */
  return TRUE;
}

static GstFlowReturn
gst_h264_dec_handle_frame (GstVideoDecoder * decoder,
    GstVideoCodecFrame * frame)
{
  /* process video frame here */
  return GST_FLOW_OK;
}

static gboolean
gst_h264_dec_start (GstVideoDecoder * decoder)
{
  /* This is optional, do things at the very beginning before process the first
   * frame */
  return TRUE;
}

static gboolean
gst_h264_dec_stop (GstVideoDecoder * decoder)
{
  /* this is optional, do things after process the last frame */
  return TRUE;
}

static gboolean
gst_h264_dec_flush (GstVideoDecoder * decoder)
{
  /* This is optional, release all the remaining data within the decoder without
   * pushing it downstream */
  return TRUE;
}

static gboolean
gst_h264_dec_finish (GstVideoDecoder * decoder)
{
  /* This is optional, For EOS, request to process all the remaining data within
   * the decoder */
  return GST_FLOW_OK;
}
