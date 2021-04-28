require conf/machine/include/gigablue-arm.inc

KERNELVERSION = "4.1.20"

MACHINE_FEATURES += "bolt colorlcd gigabluelcd ci blindscan-dvbs blindscan-dvbc transcoding dvb-c mountboot bluetooth quadpip"

SOC_FAMILY = "bcm7252s"

SRCDATE_BOLT = "20181120"

PREFERRED_VERSION_linux-gigablue = "${KERNELVERSION}"
PREFERRED_PROVIDER_virtual/kernel = "linux-gigablue"

IMAGE_CMD_tar_prepend = "\
	rm -Rf ${IMAGE_ROOTFS}/tmp/*; \
	mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
	cp -f ${DEPLOY_DIR_IMAGE}/${MACHINE}_boot.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/boot.bin; \
	cp -f ${DEPLOY_DIR_IMAGE}/${MACHINE}_gpt.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/gpt.bin; \
	cp -f ${DEPLOY_DIR_IMAGE}/${MACHINE}_rescue.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rescue.bin; \
	${@bb.utils.contains("MACHINE_FEATURES", "bolt", "cp -f ${DEPLOY_DIR_IMAGE}/${MACHINE}_bolt_${SRCDATE_BOLT}.bin ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/bolt_${SRCDATE_BOLT}.bin;" , "", d)} \
	cp -f ${DEPLOY_DIR_IMAGE}/zImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
	echo ${IMAGE_NAME} > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/imageversion; \
	echo "https://forum.openvision.tech/app.php/donate" > ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/donate.txt; \
	cd ${IMAGE_ROOTFS}; \
	tar -cvf ${DEPLOY_DIR_IMAGE}/rootfs.tar -C ${IMAGE_ROOTFS} .; \
	mv -f ${DEPLOY_DIR_IMAGE}/rootfs.tar ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
	bzip2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/rootfs.tar; \
	cd ${DEPLOY_DIR_IMAGE}; \
	zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
	rm -f ${DEPLOY_DIR_IMAGE}/*.tar.bz2; \
	rm -Rf gigablue; \
	"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	gigablue-platform-util-gb7252 \
	gigablue-ddbootup \
	gigablue-swapcreate \
	gstreamer1.0-plugin-dvbmediasink \
	"

EXTRA_IMAGEDEPENDS += "\
	gigablue-initrd-cfe-${MACHINE} \
	"

IMAGE_INSTALL_append = " \
	bluetoothsetup-gb7252 \
	"

STB_PLATFORM = "gb7252"

EXTRA_OECONF_append_pn-transtreamproxy = " --enable-ext-pid"
