require conf/machine/include/broadmedia-oem.inc

SOC_FAMILY = "bcm73625"

MACHINE_FEATURES += "ci 7segment"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	broadmedia-dvb-modules-g100 \
	"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3 --with-h265 --with-vb6 --with-vb8 --with-spark"

STB_PLATFORM = "g100"

RCTYPE = "501"
RCNAME = "sf3038"
