SRCDATE = "20180412"

RDEPENDS_${PN} += "et-fpupdate-${MACHINE}"

SRC_URI = "http://downloads.mutant-digital.net/xtrend/${MACHINE}/${MACHINE}-drivers-${KV}-${SRCDATE}.zip"

require et-dvb-modules.inc

SRC_URI[md5sum] = "2ff542f55d8d2f80f6610538b7bb1465"
SRC_URI[sha256sum] = "9f323285449cc14ccd54863b85df41161d5e1afbe552ba37e41cc68aca5a38fd"

COMPATIBLE_MACHINE = "^(et6x00)$"
