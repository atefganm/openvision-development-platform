require conf/machine/include/broadmedia-oem.inc

SOC_FAMILY = "bcm7241"

MACHINE_FEATURES += "dvb-c ci blindscan-dvbc"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

STB_PLATFORM = "g300"

RCTYPE = "503"
