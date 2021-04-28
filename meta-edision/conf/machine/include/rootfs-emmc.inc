IMAGE_CLASSES += "edision4k-emmcimg"
IMAGE_FSTYPES ?= "emmcimg tar.bz2"
IMAGE_OVERHEAD_FACTOR = "1.0"

IMAGE_CMD_emmcimg_append = " \
	mkdir -p ${IMGDEPLOYDIR}/${IMAGEDIR}; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.emmc ${IMGDEPLOYDIR}/${IMAGEDIR}/emmc.img; \
	cp -f ${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGETYPE}-${MACHINE}.bin ${IMGDEPLOYDIR}/${IMAGEDIR}/${KERNEL_FILE}; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.tar.bz2 ${IMGDEPLOYDIR}/${IMAGEDIR}/${ROOTFS_FILE}; \
	cp -f ${DEPLOY_DIR_IMAGE}/splash.bin ${IMGDEPLOYDIR}/${IMAGEDIR}; \
	echo "${IMAGE_NAME}" > ${IMGDEPLOYDIR}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${IMGDEPLOYDIR}/${IMAGEDIR}/donate.txt; \
	echo "rename this file to 'force' to force an update without confirmation" > ${IMGDEPLOYDIR}/${IMAGEDIR}/noforce; \
	echo "***** ATTENTION *****" >${IMGDEPLOYDIR}/${IMAGEDIR}/recovery_${MACHINE}_READ.ME; \
	echo "The RECOVERY is only required for new installation of the ${MACHINE}" >>${IMGDEPLOYDIR}/${IMAGEDIR}/recovery_${MACHINE}_READ.ME; \
	echo "The ${IMAGE_NAME}_recovery_emmc.zip deletes all images including the multiboot images" >>${IMGDEPLOYDIR}/${IMAGEDIR}/recovery_${MACHINE}_READ.ME; \
	rm -f ${IMGDEPLOYDIR}/*.zip; \
	cd ${IMGDEPLOYDIR}; \
	zip -j ${IMAGE_NAME}_recovery_emmc.zip ${IMAGEDIR}/emmc.img ${IMAGEDIR}/imageversion ${IMAGEDIR}/donate.txt ${IMAGEDIR}/recovery_${MACHINE}_READ.ME ${IMAGEDIR}/noforce ${IMAGEDIR}/splash.bin ; \
	zip -j ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/imageversion ${IMAGEDIR}/donate.txt ${IMAGEDIR}/${KERNEL_FILE} ${IMAGEDIR}/${ROOTFS_FILE}; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ext4; \
	rm -rf ${IMAGEDIR}; \
	"

IMAGE_CMD_prepend = "\
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	"
