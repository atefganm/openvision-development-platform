require conf/machine/include/odin-oem.inc

KERNELVERSION = "3.18.24"

MTD_KERNEL = "mtd1"
MTD_ROOTFS = "mtd2"

IMAGEDIR = "e3hd"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	odin-dvb-modules-e3hd \
	"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "odin-blindscan-utils-e3hd"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "odin-blindscan-utils-e3hd"

SOC_FAMILY = "bcm7358"

PREFERRED_VERSION_linux-odin = "${KERNELVERSION}"

MACHINE_FEATURES += "videoenhancement blindscan-tbs dvb-c RCA"

RCTYPE = "504"
RCNAME = "e3hd"
