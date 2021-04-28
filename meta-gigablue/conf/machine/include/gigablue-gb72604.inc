require conf/machine/include/gigablue-arm.inc

KERNELVERSION = "4.1.20"

DVBSKYPROVIDER = "kernel"

MACHINE_FEATURES += "colorlcd gigabluelcd gigabluelcd220 ci blindscan-dvbs blindscan-dvbc transcoding dvb-c mountboot bluetooth"

SOC_FAMILY = "bcm72604"

SRCDATE_BOLT = "20190926"

PREFERRED_VERSION_linux-gigablue = "${KERNELVERSION}"
PREFERRED_PROVIDER_virtual/kernel = "linux-gigablue"

IMAGE_CMD_tar_prepend = "\
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	mkdir -p ${IMGDEPLOYDIR}/${IMAGEDIR}; \
	cp -f ${DEPLOY_DIR_IMAGE}/${MACHINE}_boot.bin ${IMGDEPLOYDIR}/${IMAGEDIR}/boot.bin; \
	cp -f ${DEPLOY_DIR_IMAGE}/${MACHINE}_gpt.bin ${IMGDEPLOYDIR}/${IMAGEDIR}/gpt.bin; \
	cp -f ${DEPLOY_DIR_IMAGE}/${MACHINE}_rescue.bin ${IMGDEPLOYDIR}/${IMAGEDIR}/rescue.bin; \
	${@bb.utils.contains("MACHINE_FEATURES", "bolt", "cp -f ${DEPLOY_DIR_IMAGE}/${MACHINE}_bolt_${SRCDATE_BOLT}.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/bolt_${SRCDATE_BOLT}.bin;" , "", d)} \
	cp -f ${DEPLOY_DIR_IMAGE}/zImage ${IMGDEPLOYDIR}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo ${IMAGE_NAME} > ${IMGDEPLOYDIR}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${IMGDEPLOYDIR}/${IMAGEDIR}/donate.txt; \
	cd ${IMAGE_ROOTFS}; \
	tar -cvf ${IMGDEPLOYDIR}/rootfs.tar -C ${IMAGE_ROOTFS} .; \
	mv -f ${IMGDEPLOYDIR}/rootfs.tar ${IMGDEPLOYDIR}/${IMAGEDIR}/rootfs.tar; \
	bzip2 ${IMGDEPLOYDIR}/${IMAGEDIR}/rootfs.tar; \
	cd ${IMGDEPLOYDIR}; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.tar.bz2; \
	rm -Rf gigablue; \
	"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gigablue-platform-util-gb72604 \
	gigablue-ddbootup \
	gigablue-swapcreate \
	gstreamer1.0-plugin-dvbmediasink \
	"

EXTRA_IMAGEDEPENDS += "\
	gigablue-initrd-cfe-${MACHINE} \
	"

IMAGE_INSTALL_append = " \
	bluetoothsetup-gb72604 \
	"

STB_PLATFORM = "gb72604"
