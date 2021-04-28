# We know about rtc
MACHINE_FEATURES_BACKFILL_CONSIDERED += "rtc"

KERNELVERSION = "3.14.2"

BOX_BRAND = "tripledot"

MTD_KERNEL = "mtd2"

KERNEL_FILE = "kernel.bin"
ROOTFS_FILE = "rootfs.bin"

DVBPROVIDER = "kernel"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gstreamer1.0-plugin-dvbmediasink \
	"

DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dts --with-eac3"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"

KERNEL_IMAGETYPE = "vmlinux"
KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"
KERNEL_CONSOLE = "ttyS0,115200n8"

IMAGE_FSTYPES ?= "ubi"

IMAGE_CMD_ubifs_prepend = "\
	rm -rf ${IMAGE_ROOTFS}/boot/*; \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp -f ${DEPLOY_DIR_IMAGE}/cfe.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp -f ${DEPLOY_DIR_IMAGE}/splash.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp -f ${DEPLOY_DIR_IMAGE}/imageversion.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp -f ${DEPLOY_DIR_IMAGE}/kernel.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp -f ${DEPLOY_DIR_IMAGE}/rootfs.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "extrasplash", "cp -f ${DEPLOY_DIR_IMAGE}/finished.bmp ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/;" , "", d)} \
	mv -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
	gzip -9c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt; \
	${@bb.utils.contains('MACHINE', 'yh7362', \
	'echo "dont change this file" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/force;' , \
	'echo "rename this file to force to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce;', d)} \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
	rm -Rf ${IMAGEDIR}; \
	"

MACHINE_FEATURES += "alsa hdmicec switchoff blindscan-tbs videoenhancement HDMI"

# Broken bootloader can only flash around 100 MB
FLASHSIZE = "96"

BOOTLOGO_FILENAME = "splash.bin"

require conf/machine/include/tune-mips32.inc
require conf/machine/include/soc-family.inc
