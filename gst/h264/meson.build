h264_sources = [
  'gsth264dec.c',
  'plugin.c',
]

gsth264 = library('gsth264',
  h264_sources,
  c_args : nvr_args,
  include_directories : [configinc],
  dependencies : [gstbase_dep, gstvideo_dep],
  install : true,
  install_dir : plugins_install_dir,
)
pkgconfig.generate(gsth264, install_dir : plugins_pkgconfig_install_dir)
plugins += [gsth264]
