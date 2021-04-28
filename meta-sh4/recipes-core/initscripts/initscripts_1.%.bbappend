FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append_sh4 = " \
	${@bb.utils.contains_any("BOX_BRAND", "cuberevo hs", "file://cuberevo_initscripts.patch", "", d)} \
	${@bb.utils.contains("MACHINE", "ufs912", "file://ufs912_initscripts.patch", "", d)} \
	${@bb.utils.contains_any("MACHINE", "atevio7500 arivalink200 sagemcom88 fortis_hdbox pace7241 vitamin_hd5000 tf7700", "file://sh4_initscripts.patch", "", d)} \
	${@bb.utils.contains_any("BOX_BRAND", "ipbox atemio", "file://sh4_initscripts.patch", "", d)} \
	"

PACKAGE_ARCH = "${MACHINE_ARCH}"
