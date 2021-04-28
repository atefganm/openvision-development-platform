require conf/machine/include/tripledot-oem.inc

MTD_ROOTFS = "mtd0"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	tripledot-dvb-modules-yh7362 \
	tripledot-cfe \
	"

PREFERRED_PROVIDER_virtual/kernel = "linux-tripledot-yh7362"
PREFERRED_VERSION_linux-tripledot-yh7362 = "${KERNELVERSION}"

SOC_FAMILY = "bcm7362"

MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096"
UBINIZE_ARGS = "-m 2048 -p 128KiB -s 2048"

STB_PLATFORM = "yh7362"
