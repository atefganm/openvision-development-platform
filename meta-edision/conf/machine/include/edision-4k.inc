KERNELVERSION = "5.9"

SOC_FAMILY = "bcm72604"

BOX_BRAND = "edision"

# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

DEFAULTTUNE = "armv7vehf-neon-vfpv4"
KERNEL_IMAGETYPE = "zImage"

require conf/machine/include/arm/arch-armv8a.inc

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	edision-dvb-modules-${MACHINE} \
	edision-resizerootfs \
	kernel-module-extrawlan-qca6174 \
	firmware-qca6174 \
	wireless-regdb-static \
	kernel-module-rt2800usb \
	${@bb.utils.contains('MACHINE_FEATURES', 'swap', 'edision-swapcreate', '',d)} \
	enigma2-plugin-drivers-dvb-usb-opticombo \
	gstreamer1.0-plugin-dvbmediasink \
	edision-splash \
	"

DVBMEDIASINK_CONFIG = "--with-wma --with-pcm --with-dtsdownmix --with-eac3 --with-h265 --with-vb9"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "edision-blindscan-utils-${MACHINE}"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "edision-blindscan-utils-${MACHINE}"

PREFERRED_PROVIDER_virtual/kernel = "linux-edision"
PREFERRED_VERSION_linux-edision = "${KERNELVERSION}"

MTD_BOOTFS = "mmcblk1p1"
MTD_BLACK  = "mmcblk1"
MTD_KERNEL = "mmcblk1p2"
MTD_ROOTFS = "mmcblk1p3"
KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.tar.bz2"

KERNEL_CONSOLE = "ttyS0,115200n8"

MACHINE_FEATURES += "alsa switchoff hdmicec osdposition dvb-c blindscan-tbs blindscan-dvbs blindscan-dvbc satip mountboot videoenhancement mmc emmc swap HDMI"

require conf/machine/include/rootfs-emmc.inc

STB_PLATFORM = "edision4k"

RCNAME = "edision3"
