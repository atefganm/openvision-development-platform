require conf/machine/include/dags-arm.inc

KERNELVERSION = "4.1.20"

SOC_FAMILY = "bcm72604"

STB_PLATFORM = "dags72604"

MACHINE_FEATURES += "emmc mmc dvb-c blindscan-dvbs swap"

DVBMEDIASINK_CONFIG = "--with-dags --with-pcm --with-eac3 --with-amr --with-wmv --with-h265 --with-vb9"

MTD_KERNEL = "mmcblk0p1"
MTD_ROOTFS = "mmcblk0p4"
SPLASH1_BMP = "splash1_power.bmp"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	dags-dvb-modules-dags72604 \
	"
