require conf/machine/include/tripledot-oem.inc

MTD_ROOTFS = "mtd8"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	tripledot-dvb-modules-vg5000 \
	"

PREFERRED_PROVIDER_virtual/kernel = "linux-tripledot-vg5000"
PREFERRED_VERSION_linux-tripledot-vg5000 = "${KERNELVERSION}"

SOC_FAMILY = "bcm7362"

MKUBIFS_ARGS = "-m 2048 -e 126976 -c 4096"
UBINIZE_ARGS = "-m 2048 -p 128KiB -s 2048"

MACHINE_FEATURES += "ci 7segment textlcd AV_JACK"

STB_PLATFORM = "vg5000"
