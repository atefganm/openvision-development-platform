require conf/machine/include/odin-oem.inc

KERNELVERSION = "3.18.24"

IMAGEDIR = "en2"

MTD_KERNEL = "mtd3"
MTD_ROOTFS = "mtd4"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	odin-dvb-modules-odinm7 \
	"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "odin-blindscan-utils-odinm7"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "odin-blindscan-utils-odinm7"

SOC_FAMILY = "bcm7358"

PREFERRED_VERSION_linux-odin = "${KERNELVERSION}"

MACHINE_FEATURES += "videoenhancement blindscan-tbs 7segment textlcd dvb-c SCART RCA"

RCTYPE = "505"
RCNAME = "odinm7"
