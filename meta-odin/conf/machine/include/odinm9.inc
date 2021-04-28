require conf/machine/include/odin-oem.inc

KERNELVERSION = "3.6.0"

MTD_KERNEL = "mtd2"
MTD_ROOTFS = "mtd3"

IMAGEDIR = "odinm9"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	odin-dvb-modules-odinm9 \
	"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "odin-blindscan-utils-odinm9"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "odin-blindscan-utils-odinm9"

SOC_FAMILY = "bcm7413"

PREFERRED_VERSION_linux-odin = "${KERNELVERSION}"

MACHINE_FEATURES += "ci fanctrl textlcd RCA SCART YUV vfdsymbol"

RCNAME = "odinm9"
