SUMMARY = "Forever CFE addon"
SECTION = "base"
PRIORITY = "required"
LICENSE = "proprietary"

require conf/license/license-gplv2.inc
inherit deploy

S = "${WORKDIR}"

SRC_URI = "file://bootscreen.gz;unpack=0"

ALLOW_EMPTY_${PN} = "1"

do_deploy() {
	mkdir -p ${DEPLOY_DIR_IMAGE}
	install -m 0644 bootscreen.gz ${DEPLOY_DIR_IMAGE}/
}

addtask deploy before do_build after do_install
