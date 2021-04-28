IMAGE_FSTYPES = "ubifs"

IMAGE_TYPES = "ubifs"

do_image_ubifs[depends] += "fup-native:do_populate_sysroot"

IMAGE_CMD_ubifs_prepend = " \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	echo \[ubi-rootfs\] > ubinize-${IMAGE_NAME}.cfg; \
	echo mode=ubi >> ubinize-${IMAGE_NAME}.cfg; \
	echo image=${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubifs >> ubinize-${IMAGE_NAME}.cfg; \
	echo vol_id=0 >> ubinize-${IMAGE_NAME}.cfg; \
	echo vol_type=dynamic >> ubinize-${IMAGE_NAME}.cfg; \
	echo vol_name=${UBI_VOLNAME} >> ubinize-${IMAGE_NAME}.cfg; \
	echo vol_flags=autoresize >> ubinize-${IMAGE_NAME}.cfg; \
	echo vol_alignment=1 >> ubinize-${IMAGE_NAME}.cfg; \
	echo vol_size=${UBINIZE_DATAVOLSIZE} >> ubinize-${IMAGE_NAME}.cfg; \
	mkfs.ubifs -r ${IMAGE_ROOTFS} -o ${IMGDEPLOYDIR}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubifs ${MKUBIFS_ARGS}; \
	ubinize -o ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${UBINIZE_ARGS} ubinize-${IMAGE_NAME}.cfg; \
	mv -f ubinize-${IMAGE_NAME}.cfg ${IMGDEPLOYDIR}/ubinize-${IMAGE_NAME}.cfg; \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	mv -f ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}${IMAGE_NAME_SUFFIX}.ubi ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
	cp -f ${DEPLOY_DIR_IMAGE}/uImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.zip; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ird; \
	cd ${DEPLOY_DIR_IMAGE}; \
	if [ -e bootscreen.gz ]; then \
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
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubi; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.ubifs; \
	rm -rf ${IMAGEDIR}; \
	"

# There's this magic limit in ird names that we can't use our complete name so I used e2-R${RESELLERID} to make it work.
# As we're using zip files with our complete name so we could ignore the ird name.
