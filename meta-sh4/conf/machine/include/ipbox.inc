require conf/machine/include/oem-sh4.inc
require conf/machine/include/normal-sh4-image.inc
require conf/machine/include/sh4-jffs2.inc

BOX_BRAND = "ipbox"

PREFERRED_PROVIDER_virtual/kernel = "linux-sh4-cuberevo"

ROOTFS_FILE = "root.img"
KERNEL_FILE = "uImage"

IMAGE_FSTYPES = "tar.gz"

AUDIOELF = "audio_7100.elf"
VIDEOELF = "video_7109.elf"

SOC_FAMILY = "sti7109"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	ipbox-eeprom \
	kernel-module-zram \
	stlinux24-sh4-stx7109-fdma-firmware \
	stlirc \
	"

MACHINE_FEATURES += "ci smallflash SCART"

CAN_USE_ENIGMA2_IN_FLASH = "0"

RCNAME = "cuberevo_uni"
