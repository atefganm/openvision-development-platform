DESCRIPTION = "gstreamer dvbmediasink plugin"
SECTION = "multimedia"
PRIORITY = "optional"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://COPYING;md5=7fbc338309ac38fefcd64b04bb903e34"

# Most machine recipes still (r)depend on gst-plugin-dvbmediasink
RPROVIDES_${PN} = "gst-plugin-dvbmediasink"
RREPLACES_${PN} = "gst-plugin-dvbmediasink"
RCONFLICTS_${PN} = "gst-plugin-dvbmediasink"

PROVIDES += "virtual/gstreamer1.0-mediasink"
RPROVIDES_${PN} += "virtual/gstreamer1.0-dvbmediasink"

DEPENDS = "glib-2.0-native gstreamer1.0 gstreamer1.0-plugins-base libdca"

SRC_URI = "${@bb.utils.contains("MACHINE_FEATURES", "azbox", "git://github.com/OpenVisionE2/gstreamer1.0-plugin-azbox-dvbmediasink.git", "git://github.com/OpenVisionE2/gstreamer1.0-plugin-multibox-dvbmediasink.git", d)}"

S = "${WORKDIR}/git"

inherit gitpkgv

PV = "1.0+git${SRCPV}"
PKGV = "1.0+git${GITPKGV}"

inherit autotools pkgconfig

FILES_${PN} = "${libdir}/gstreamer-1.0/*.so*"
FILES_${PN}-dev += "${libdir}/gstreamer-1.0/*.la"
FILES_${PN}-staticdev += "${libdir}/gstreamer-1.0/*.a"
FILES_${PN}-dbg += "${libdir}/gstreamer-1.0/.debug"

PACKAGE_ARCH = "${MACHINE_ARCH}"

EXTRA_OECONF = "${DVBMEDIASINK_CONFIG} --with-gstversion=1.0 --with-boxtype=${MACHINE} --with-boxbrand=${BOX_BRAND} --with-stbplatform=${STB_PLATFORM}"
