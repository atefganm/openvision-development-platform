require linux-os.inc
LIC_FILES_CHKSUM = "file://COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

SRC_URI = "http://source.mynonpublic.com/edision/linux-edision-${PV}.tar.xz \
	file://defconfig \
	file://${OPENVISION_BASE}/meta-openvision/recipes-linux/kernel-patches/kernel-add-support-for-gcc${VISIONGCCVERSION}.patch \
	file://0001-Support-TBS-USB-drivers-for-4.6-kernel.patch \
	file://0001-TBS-fixes-for-4.6-kernel.patch \
	file://0001-STV-Add-PLS-support.patch \
	file://0001-STV-Add-SNR-Signal-report-parameters.patch \
	file://blindscan2.patch \
	file://0001-stv090x-optimized-TS-sync-control.patch \
	file://0002-log2-give-up-on-gcc-constant-optimizations.patch \
	file://0003-cp1emu-do-not-use-bools-for-arithmetic.patch \
	"

COMPATIBLE_MACHINE = "^(osnino|osninoplus|osninopro)$"

SRC_URI[md5sum] = "10eb489d6d34213451ae808f55f449da"
SRC_URI[sha256sum] = "21a2db8e25d8eab13674cc45f8b102d7fa126b950648a02590daef4ff4c00f4c"

FILES_${KERNEL_PACKAGE_NAME}-image = "${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE}*"

pkg_postinst_${KERNEL_PACKAGE_NAME}-image () {
	if [ -z "$D" ]
	then
		MTD_DEVICE=$(grep 'kernel' /proc/mtd | cut -f1 -d':')
		flash_eraseall /dev/${MTD_DEVICE}
		nandwrite -p /dev/${MTD_DEVICE} /${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE}-${KERNEL_VERSION}
		rm -f /${KERNEL_IMAGEDEST}/${KERNEL_IMAGETYPE}-${KERNEL_VERSION}
	fi
}
