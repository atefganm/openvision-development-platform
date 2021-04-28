require conf/license/license-gplv2.inc


SRC_URI = " \
    file://ceryon-shutdown.sh "

INITSCRIPT_NAME = "ceryon-shutdown"
INITSCRIPT_PARAMS = "start 31 0 ."

inherit pkgconfig update-rc.d

do_install() {
    install -d ${D}${sysconfdir}/init.d/
    install -m 0755 ${WORKDIR}/ceryon-shutdown.sh ${D}${sysconfdir}/init.d/ceryon-shutdown
}

COMPATIBLE_MACHINE = "^(9910lx|e4hd|e4hdhybrid|odin2hybrid|odinplus|sf208|sf228|singleboxlcd|twinboxlcd|mbmicro|9911lx|e4hdcombo|sf238|twinboxlcdci5|9920lx|mbmicrov2)$"
