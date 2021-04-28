FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://0003-meson-Add-valgrind-feature.patch \
	file://0005-revert-use-new-gst-adapter-get-buffer.patch \
	"

SRC_URI_remove += "file://0002-Remove-unused-valgrind-detection.patch"

EXTRA_OEMESON += "${GSTREAMER1_DEBUG}"

CFLAGS_append_sh4 = " -std=gnu99"
