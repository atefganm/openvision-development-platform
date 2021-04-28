require gigablue-blindscan-utils.inc

SRCDATE = "20151013"

SRC_URI[md5sum] = "c51ad24b8fcd74671bf9790707485c7b"
SRC_URI[sha256sum] = "5d77489dd0c588bb962a588e2b919cf018d5d7e732ff8a1e08db1d4a16236252"

SRC_URI = "http://source.mynonpublic.com/gigablue/blindscan/gigablue-blindscan-utils-${SRCDATE}.tgz"

COMPATIBLE_MACHINE = "^(gbultraueh|gbx2|gbx3h|gbquad|gbquadplus|gb800solo|gb800seplus|gb800ueplus|gbultrase|gbultraue|gbx1|gbx3)$"
