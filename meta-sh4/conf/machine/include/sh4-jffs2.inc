IMAGE_FSTYPES = "jffs2"

JFFS2_ERASEBLOCK = "0x20000"
JFFS2_ENDIANNESS = "${@oe.utils.conditional('SITEINFO_ENDIANNESS', 'le', '--little-endian', '--big-endian', d)}"
EXTRA_IMAGECMD_jffs2 = "--pad ${JFFS2_ENDIANNESS} --eraseblock=${JFFS2_ERASEBLOCK} --no-cleanmarkers"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
	mtd-utils-jffs2 \
	"

IMAGE_CMD_jffs2_prepend = "\
	rm -rf ${IMAGE_ROOTFS}/tmp/*; \
	"
