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

#ifndef __GST_H264_DEC_H__
#define __GST_H264_DEC_H__


#include <gst/gst.h>
#include <gst/video/video.h>
#include <gst/video/gstvideodecoder.h>

G_BEGIN_DECLS

#define GST_TYPE_H264_DEC \
  (gst_h264_dec_get_type())
#define GST_H264_DEC(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_H264_DEC,GstH264Dec))
#define GST_H264_DEC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_H264_DEC,GstH264DecClass))
#define GST_IS_H264_DEC(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_H264_DEC))
#define GST_IS_H264_DEC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_H264_DEC))

typedef struct _GstH264Dec GstH264Dec;
typedef struct _GstH264DecClass GstH264DecClass;

struct _GstH264Dec {
  GstVideoDecoder parent;
};

struct _GstH264DecClass {
  GstVideoDecoderClass parent_class;
};

GType gst_h264_dec_get_type(void);

G_END_DECLS

#endif /* __GST_H264_DEC_H__ */
