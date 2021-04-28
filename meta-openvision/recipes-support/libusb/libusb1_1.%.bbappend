# Just a comment line to avoid PAK archive (application/x-pak)
PACKAGECONFIG_class-target ??= ""

EXTRA_OECONF = "--libdir=${base_libdir} --disable-udev"
