FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += "file://0001-gstrtpmp4gpay-set-dafault-value-for-MPEG4-without-co.patch"

EXTRA_OEMESON += "${GSTREAMER1_DEBUG}"

CFLAGS_append_sh4 = " -std=gnu99"
