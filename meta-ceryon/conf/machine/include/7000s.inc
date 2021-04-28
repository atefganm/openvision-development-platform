require conf/machine/include/ceryon-mipsel.inc

KERNELVERSION = "4.0.1"

SOC_FAMILY = "bcm7362"

PREFERRED_VERSION_linux-ceryon = "${KERNELVERSION}"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	ceryon-dvb-modules-7000s \
	"

MACHINE_FEATURES += "AV_JACK vfdsymbol"

STB_PLATFORM = "7000s"

RCNAME ?= "e4hd"
