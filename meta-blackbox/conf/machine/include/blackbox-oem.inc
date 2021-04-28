# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

KERNELVERSION = "3.14.21"

BOX_BRAND = "blackbox"

PREFERRED_PROVIDER_virtual/kernel = "linux-blackbox"
PREFERRED_VERSION_linux-blackbox = "${KERNELVERSION}"

MACHINE_FEATURES += "textlcd ci dvb-c blindscan-dvbc blindscan-dvbs blindscan-tbs alsa hdmicec switchoff HDMI SCART RCA"

# Broken bootloader can only flash around 100 MB
FLASHSIZE = "96"

SOC_FAMILY = "bcm7413"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	blackbox-dvb-modules-blackbox7405 \
	gstreamer1.0-plugin-dvbmediasink \
	"

MTD_ROOTFS = "mtd6"
MTD_KERNEL = "mtd7"
KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

DVBPROVIDER = "kernel"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

GLIBC_EXTRA_OECONF = "--with-tls --with-__thread"

PREFERRED_PROVIDER_virtual/blindscan-dvbs = "blackbox-blindscan-utils"
PREFERRED_PROVIDER_virtual/blindscan-dvbc = "blackbox-blindscan-utils"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

IMAGE_FSTYPES ?= "ubi"

IMAGE_CMD_ubifs_prepend = "\
	rm -rf ${IMAGE_ROOTFS}/boot/*; \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	"

UBINIZE_ARGS = "-m 2048 -p 128KiB"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	mv -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
	gzip -f -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt; \
	echo "rename this file to 'force' to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
	rm -Rf ${IMAGEDIR}; \
	"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/tune-mips32.inc
require conf/machine/include/soc-family.inc

BLINDSCAN_BINARY = "blackbox_blindscan"
