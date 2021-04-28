require conf/machine/include/ceryon-oem.inc

KERNELVERSION = "4.10.12"

ROOTFS_FILE = "rootfs.tar.bz2"

SOC_FAMILY = "bcm7252s"

MTD_KERNEL = "mmcblk0p2"
MTD_ROOTFS = "mmcblk0p3"
MTD_BOOTFS = "mmcblk0p1"
MTD_BLACK  = "mmcblk0"

MACHINE_FEATURES += "colorlcd220 lcd220 ci dvb-c emmc mmc swap multitranscoding minitv mountboot swap"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	ceryon-lcd \
	"

IMAGE_CLASSES += "ceryonemmc_image_multiboot"

DISTRO_FEATURES_remove += "directfb gtk-directfb"

IMAGE_FSTYPES += "ceryonemmc"
IMAGE_ROOTFS_SIZE ?= "589824"

TARGET_ARCH = "arm"
DEFAULTTUNE = "cortexa15hf-neon-vfpv4"

PREFERRED_VERSION_linux-ceryon= "${KERNELVERSION}"
PREFERRED_VERSION_directfb = "1.7.7"

IMAGE_CMD_prepend = " \
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	"

IMAGE_CMD_ceryonemmc_append = " \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	${@bb.utils.contains("MACHINE_FEATURES", "lcd220", "cp -f ${DEPLOY_DIR_IMAGE}/lcdwarning220.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/lcdflashing.bmp;" , "", d)} \
	mv -f ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.emmc.img ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/disk.img; \
	cd ${IMAGE_ROOTFS}; \
	tar -cvf ${DEPLOY_DIR_IMAGE}/rootfs.tar -C ${IMAGE_ROOTFS} .; \
	mv -f ${DEPLOY_DIR_IMAGE}/rootfs.tar ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
	bzip2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
	cp -f ${DEPLOY_DIR_IMAGE}/zImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip ${IMAGE_NAME}_recovery_emmc.zip ${IMAGEDIR}/disk.img ${IMAGEDIR}/imageversion ${IMAGEDIR}/donate.txt; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/imageversion ${IMAGEDIR}/donate.txt ${IMAGEDIR}/${KERNEL_FILE} ${IMAGEDIR}/${ROOTFS_FILE}; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ext4; \
	rm -Rf ${IMAGEDIR}; \
	"

require conf/machine/include/tune-cortexa15.inc

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	ceryon-dvb-modules-${MACHINE} \
	kernel-module-mt7601u \
	firmware-mt7601u \
	"

STB_PLATFORM = "8100s"
