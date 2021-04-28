require conf/machine/include/entwopia-oem.inc

KERNELVERSION = "3.14.2"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	entwopia-dvb-modules-ew7358 \
	"

SOC_FAMILY = "bcm7358"

MACHINE_FEATURES += "7segment textlcd RCA YUV"

PREFERRED_VERSION_linux-entwopia = "${KERNELVERSION}"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

STB_PLATFORM = "ew7358"
