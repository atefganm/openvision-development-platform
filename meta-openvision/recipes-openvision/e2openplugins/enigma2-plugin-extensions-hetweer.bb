MODULE = "HetWeer"
DESCRIPTION = "HetWeer plugin"

require conf/license/license-gplv2.inc
require openplugins-replace-vision.inc
require openplugins-distutils.inc

PLUGINPATH = "${libdir}/enigma2/python/Plugins/Extensions/${MODULE}"
do_install() {
        install -d ${D}${PLUGINPATH}/Images
        cp -r ${S}/plugin/* ${D}${PLUGINPATH}
        chmod a+rX ${D}${PLUGINPATH}
}

FILES_${PN} = "${PLUGINPATH}"
