FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "\
	file://mount.sh \
	file://localextra.rules \
	"
