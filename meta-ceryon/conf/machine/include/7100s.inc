require conf/machine/include/ceryon-mipsel.inc

KERNELVERSION = "4.0.1"

SOC_FAMILY = "bcm7362"

PREFERRED_VERSION_linux-ceryon = "${KERNELVERSION}"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	ceryon-dvb-modules-7100s \
	ceryon-lcd \
	"

MACHINE_FEATURES += "colorlcd220 lcd220 ci RCA"

STB_PLATFORM = "7100s"
