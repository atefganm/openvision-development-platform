IMAGE_FSTYPES = "ubi"

MKUBIFS_ARGS = "-m 2048 -e 129024 -c 768 -x zlib -U"
UBINIZE_ARGS = "-m 2048 -p 128KiB -s 512 -x 1"

EXTRA_IMAGECMD_COMPAT = " --eraseblock=0x20000 -n -l "

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	mtd-utils-ubifs \
	"

IMAGE_CMD_ubifs_prepend = " \
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	"
