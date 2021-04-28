require conf/machine/include/oem-sh4.inc

BOX_BRAND = "hs"

PREFERRED_PROVIDER_virtual/kernel = "linux-sh4-hs"

ROOTFS_FILE = "root.img"
KERNEL_FILE = "uImage"

AUDIOELF = "audio_7111.elf"
VIDEOELF = "video_7111.elf"

SOC_FAMILY = "sti7111"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	flash-tools \
	fortis-eeprom \
	fp-control \
	kernel-module-zram \
	stlinux24-sh4-stmfb-firmware-stx7111 \
	stlinux24-sh4-stx7111-fdma-firmware \
	"

MACHINE_FEATURES += "hdmicec ci resellerid"

RCNAME ?= "hs9510"
