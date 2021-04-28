MODULE = "Satscan"
DESCRIPTION = "Blind scan on DVB-S"
RDEPENDS_${PN} = "virtual/blindscan-dvbs"
RDEPENDS_${PN} += "${@bb.utils.contains("PYTHONEXACTVERSION", "python3", "", "python-subprocess", d)}"

inherit gitpkgv

PV = "1.3+git${SRCPV}"
PKGV = "${PV}"

require conf/license/license-gplv2.inc
require openplugins-distutils.inc
