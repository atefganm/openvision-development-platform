require conf/machine/include/oem-sh4.inc
require conf/machine/include/normal-sh4-image.inc
require conf/machine/include/sh4-jffs2.inc

BOX_BRAND = "fulan"

MTD_KERNEL = "mtd5"
MTD_ROOTFS = "mtd6"

PREFERRED_PROVIDER_virtual/kernel = "linux-sh4-${MACHINE}"

ROOTFS_FILE = "e2jffs2.img"
KERNEL_FILE = "uImage"

IMAGE_FSTYPES += "tar.gz"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	enigma2-plugin-extensions-${MACHINE}vfd \
	flash-tools \
	fp-control \
	kernel-module-zram \
	mount-sh4 \
	stlirc \
	"

MACHINE_FEATURES += "hdmicec ci directfb sh4booster SCART RCA"

DISTRO_FEATURES_append = " gtk-directfb"

CAN_USE_ENIGMA2_IN_FLASH = "1"

RCTYPE = "10"

IMAGE_CLASSES += "usb_image-sh4"

INITRAMFS_FSTYPES =  "ext2.gz sh4updt"
