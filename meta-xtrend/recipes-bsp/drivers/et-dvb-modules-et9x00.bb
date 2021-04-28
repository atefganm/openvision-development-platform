SRCDATE = "20180412"

RDEPENDS_${PN} += "et-fpupdate-${MACHINE}"

SRC_URI = "http://downloads.mutant-digital.net/xtrend/${MACHINE}/${MACHINE}-drivers-${KV}-${SRCDATE}.zip"

require et-dvb-modules.inc

SRC_URI[md5sum] = "b243d684b140869015db425a0be5dffc"
SRC_URI[sha256sum] = "42d3f87a3deef402efc88869dda6124960a61781ffaaa8a57d1b51c6cbd8bdf6"

COMPATIBLE_MACHINE = "^(et9x00)$"
