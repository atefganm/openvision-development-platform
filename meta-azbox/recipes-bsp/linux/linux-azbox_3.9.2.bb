SUMMARY = "Linux kernel for ${MACHINE}"
SECTION = "kernel"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/linux-${KV}/COPYING;md5=d7810fab7487fb0aad327b76f1be7cd7"

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "^(azboxme|azboxminime)$"

SRCDATE = "14092013"

DEPENDS = "genromfs-native virtual/${TARGET_PREFIX}gcc"

inherit kernel machine_kernel_pr samba_change_dialect

PKG_${KERNEL_PACKAGE_NAME}-base = "${KERNEL_PACKAGE_NAME}-base"
PKG_${KERNEL_PACKAGE_NAME}-image = "${KERNEL_PACKAGE_NAME}-image"
RPROVIDES_${KERNEL_PACKAGE_NAME}-base = "${KERNEL_PACKAGE_NAME}-${KERNEL_VERSION}"
RPROVIDES_${KERNEL_PACKAGE_NAME}-image = "${KERNEL_PACKAGE_NAME}-image-${KERNEL_VERSION}"
ALLOW_EMPTY_kernel-dev = "1"

SRC_URI = "${KERNELORG_MIRROR}/linux/kernel/v3.x/linux-${KV}.tar.bz2;name=azbox-kernel \
	file://defconfig \
	file://${OPENVISION_BASE}/meta-openvision/recipes-linux/kernel-patches/kernel-add-support-for-gcc${VISIONGCCVERSION}.patch \
	file://genzbf.c \
	file://sigblock.h \
	file://zboot.h \
	file://emhwlib_registers_tango2.h \
	file://kernel-3.9.2.patch \
	file://add-dmx-source-timecode.patch \
	file://af9015-output-full-range-SNR.patch \
	file://af9033-output-full-range-SNR.patch \
	file://as102-adjust-signal-strength-report.patch \
	file://as102-scale-MER-to-full-range.patch \
	file://cinergy_s2_usb_r2.patch \
	file://cxd2820r-output-full-range-SNR.patch \
	file://dvb-usb-dib0700-disable-sleep.patch \
	file://dvb_usb_disable_rc_polling.patch \
	file://it913x-switch-off-PID-filter-by-default.patch \
	file://tda18271-advertise-supported-delsys.patch \
	file://fix-dvb-siano-sms-order.patch \
	file://mxl5007t-add-no_probe-and-no_reset-parameters.patch \
	file://nfs-max-rwsize-8k.patch \
	file://0001-rt2800usb-add-support-for-rt55xx.patch \
	file://0001-Revert-MIPS-Fix-potencial-corruption.patch \
	file://linux-3.9.7-gcc-4.9.3-build-error-fixed.patch \
	file://rtl8712-fix-warnings.patch \
	file://rtl8187se-fix-warnings.patch \
	file://kernel-azbox-miscbuildfixes.patch \
	file://kernel-azbox-fix-sata_tangox-platformdevice.patch \
	file://0002-cp1emu-do-not-use-bools-for-arithmetic.patch \
	file://0003-log2-give-up-on-gcc-constant-optimizations.patch \
	"

SRC_URI_append_azboxme = "http://source.mynonpublic.com/azbox/initramfs-${MACHINE}-oe-core-${KV}-${SRCDATE}.tar.bz2;name=azbox-initrd-${MACHINE}"
SRC_URI_append_azboxminime = "http://source.mynonpublic.com/azbox/initramfs-${MACHINE}-oe-core-${KV}-${SRCDATE}.tar.bz2;name=azbox-initrd-${MACHINE}"

SRC_URI[azbox-kernel.md5sum] = "661100fdf8a633f53991684b555373ba"
SRC_URI[azbox-kernel.sha256sum] = "dfcaa8bf10f87ad04fc46994c3b4646eae914a9eb89e76317fdbbd29f54f1076"
SRC_URI[azbox-initrd-azboxme.md5sum] = "59f73c9b9fe95183bd39e2a4010a2ac7"
SRC_URI[azbox-initrd-azboxme.sha256sum] = "b98be68bf2d607e57e1cbc48a4eb78c5759d24e0cf0c22e127263788e83665fd"
SRC_URI[azbox-initrd-azboxminime.md5sum] = "3b7508985058ac0a5d9d310f669cc5bc"
SRC_URI[azbox-initrd-azboxminime.sha256sum] = "b7979e03bd53f6c975079761c3399d5dd80e9db5addeae27726f09f87a86be72"

S = "${WORKDIR}/linux-${KV}"
B = "${WORKDIR}/build"

export OS = "Linux"
KERNEL_OBJECT_SUFFIX = "ko"
KERNEL_OUTPUT = "zbimage-linux-xload"
KERNEL_IMAGETYPE = "zbimage-linux-xload"
KERNEL_IMAGEDEST = "tmp"

FILES_${KERNEL_PACKAGE_NAME}-image = "/boot/zbimage-linux-xload"

CFLAGS_prepend = "-I${WORKDIR} "

EXTRA_OEMAKE += "CONFIG_INITRAMFS_SOURCE=${STAGING_KERNEL_DIR}/initramfs"

do_configure_prepend() {
	oe_machinstall -m 0644 ${WORKDIR}/defconfig ${S}/.config
	sed -i "s#:= usr/initramfs_default_node_list#:= \$(srctree)/usr/initramfs_default_node_list#" ${STAGING_KERNEL_DIR}/usr/Makefile
	sed -i "s#\$(srctree)/arch/mips/boot/#\$(obj)/#" ${STAGING_KERNEL_DIR}/arch/mips/boot/Makefile
        sed -i "s/ -static//" ${STAGING_KERNEL_DIR}/scripts/Makefile.host
}

kernel_do_compile_prepend() {
	gcc ${CFLAGS} ${WORKDIR}/genzbf.c -o ${WORKDIR}/genzbf
	install -d ${B}/arch/mips/boot/
	install -m 0755 ${WORKDIR}/genzbf ${B}/arch/mips/boot/
}

kernel_do_compile() {
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS MACHINE
	oe_runmake ${KERNEL_IMAGETYPE} CC="${KERNEL_CC}" LD="${KERNEL_LD}" AR="${AR}" OBJDUMP="${OBJDUMP}" NM="${NM}" CONFIG_INITRAMFS_SOURCE="${STAGING_KERNEL_DIR}/initramfs"
	oe_runmake modules CC="${KERNEL_CC}" LD="${KERNEL_LD}" AR="${AR}" OBJDUMP="${OBJDUMP}" CONFIG_INITRAMFS_SOURCE="${STAGING_KERNEL_DIR}/initramfs"
}

kernel_do_compile_append() {
    rm -rf ${B}/arch/${ARCH}/boot/genzbf
}

# This is part of kernel.bbclass but doesn't get executed when not copied here
do_sizecheck() {
        if [ ! -z "${KERNEL_IMAGE_MAXSIZE}" ]; then
                cd ${B}
                size=`ls -lL ${KERNEL_OUTPUT} | awk '{ print $5}'`
                if [ $size -ge ${KERNEL_IMAGE_MAXSIZE} ]; then
                        die "This kernel (size=$size > ${KERNEL_IMAGE_MAXSIZE}) is too big for your device. Please reduce the size of the kernel by making more of it modular."
                fi
        fi
}
do_sizecheck[dirs] = "${B}"

addtask sizecheck before do_install after do_strip
