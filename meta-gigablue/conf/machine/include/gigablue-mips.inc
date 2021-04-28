require conf/machine/include/gigablue-oem.inc

MTD_KERNEL = "mtd2"
MTD_ROOTFS = "mtd0"
ROOTFS_FILE = "rootfs.bin"

TARGET_ARCH = "mipsel"
DEFAULTTUNE = "mips32el"
KERNEL_IMAGETYPE = "vmlinux"

PREFERRED_PROVIDER_virtual/blindscan-dvbc = "gigablue-blindscan-utils-mips"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "gigablue-blindscan-utils-mips"

IMAGE_CMD_ubifs_prepend = "\
	rm -rf ${IMAGE_ROOTFS}/boot/*; \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	"

IMAGE_CMD_ubi_append = " \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	${@bb.utils.contains("MACHINE_FEATURES", "gigabluelcd220", "cp -f ${DEPLOY_DIR_IMAGE}/lcdwarning220.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/lcdwarning.bin;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "gigabluelcd220", "cp -f ${DEPLOY_DIR_IMAGE}/lcdwaitkey220.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/lcdwaitkey.bin;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "gigabluelcd400", "cp -f ${DEPLOY_DIR_IMAGE}/lcdwarning400.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/lcdwarning.bin;" , "", d)} \
	${@bb.utils.contains("MACHINE_FEATURES", "gigabluelcd400", "cp -f ${DEPLOY_DIR_IMAGE}/lcdwaitkey400.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/lcdwaitkey.bin;" , "", d)} \
	cp -f ${DEPLOY_DIR_IMAGE}/warning.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/warning.bin; \
	mv -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
	gzip -f -c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt; \
	echo "rename this file to 'force' to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip -r ${IMAGE_NAME}_usb.zip gigablue/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
	rm -rf ${DEPLOY_DIR_IMAGE}/gigablue; \
	"

IMAGE_CMD_jffs2_prepend = "\
	rm -rf ${IMAGE_ROOTFS}/boot/*; \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	"

IMAGE_CMD_jffs2_append = " ; \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	mv -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.jffs2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
	gzip -f -c ${DEPLOY_DIR_IMAGE}/vmlinux-${MACHINE}.bin > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo "rename this file to 'force' to force an update without confirmation" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/noforce; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip -r ${IMAGE_NAME}_usb.zip gigablue/*; \
	zip ${IMAGE_NAME}_usb.zip burn.bat; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.jffs2; \
	rm -rf ${DEPLOY_DIR_IMAGE}/gigablue; \
	"

require conf/machine/include/tune-mips32.inc
