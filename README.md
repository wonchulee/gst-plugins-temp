# Gst-plugins-temp

Gst-plugins-temp repository is to develop GStreamer plugins required for NVR
projects.

## Getting Started

### Prerequisites
It requires 0.54 or newer version of Meson to build.

Install meson

`pip3 install --user meson`

Setup indent tool

`apt install indent`

Then you need to set to make it possible to run gst-indent script in your
environment. You can refer to the script in gstreamer repo.

`cp gstreamer/tools/gst-indent ~/.local/bin`

### build

Configure

`meson build`

Build

`ninja -C build`

Install

`ninja -C build install`
