MACHINE_FEATURES += "smallflash"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	forever-logo-cfe \
	"

do_image_jffs2[depends] += "fup-native:do_populate_sysroot"

IMAGE_CMD_jffs2_append = " \
	; \
	while [ ! -s ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.jffs2 ]; do sleep 1; done ; \
	cp -f ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.jffs2 ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.jffs2; \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	while [ ! -s ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.jffs2 ]; do sleep 1; done ; \
	mv -f ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.jffs2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
	cp -f ${DEPLOY_DIR_IMAGE}/uImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ird; \
	cd ${DEPLOY_DIR_IMAGE}; \
	if [ -e ${DEPLOY_DIR_IMAGE}/bootscreen.gz ]; then \
		fup -c ${IMAGEDIR}/e2-R${RESELLERID}.ird -1 ${IMAGEDIR}/${ROOTFS_FILE} -6 ${IMAGEDIR}/${KERNEL_FILE} -9 bootscreen.gz; \
	else \
		fup -c ${IMAGEDIR}/e2-R${RESELLERID}.ird -1 ${IMAGEDIR}/${ROOTFS_FILE} -6 ${IMAGEDIR}/${KERNEL_FILE}; \
	fi; \
	fup -r ${IMAGEDIR}/e2-R${RESELLERID}.ird ${RESELLERID}; \
	fup -n ${IMAGEDIR}/e2-R${RESELLERID}.ird 100200; \
	fup -i ${IMAGEDIR}/e2-R${RESELLERID}.ird > ${IMAGEDIR}/e2-R${RESELLERID}-info.txt; \
	echo ${IMAGE_NAME} > ${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${IMAGEDIR}/donate.txt; \
	zip ${IMAGE_NAME}_ird.zip ${IMAGEDIR}/e2-R${RESELLERID}.ird ${IMAGEDIR}/e2-R${RESELLERID}-info.txt ${IMAGEDIR}/imageversion ${IMAGEDIR}/donate.txt; \
	rm -f ${IMAGEDIR}/*.ird; \
	rm -f ${IMAGEDIR}/*.txt; \
	echo "https://forum.openvision.tech/app.php/donate" > ${IMAGEDIR}/donate.txt; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.jffs2; \
	rm -rf ${IMAGEDIR}; \
	"

# There's this magic limit in ird names that we can't use our complete name so I used e2-R${RESELLERID} to make it work.
# As we're using zip files with our complete name so we could ignore the ird name.
