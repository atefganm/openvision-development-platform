SUMMARY = "SH4 driver modules"
DESCRIPTION = "SH4 driver modules"
SECTION = "base"
PRIORITY = "required"
LICENSE = " GPLv2"
require conf/license/license-gplv2.inc

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "^(adb_box|adb_2850|arivalink200|atemio520|atemio530|atevio7500|cuberevo|cuberevo_250hd|cuberevo_2000hd|cuberevo_3000hd|cuberevo_mini|cuberevo_mini2|cuberevo_9500hd|pace7241|vip1_v1|vip1_v2|vip2|fortis_hdbox|hl101|hs7110|hs7119|hs7420|hs7429|hs7810a|hs7819|ipbox55|ipbox99|ipbox9900|sagemcom88|octagon1008|spark|spark7162|tf7700|ufc960|ufs910|ufs912|ufs913|ufs922|vitamin_hd5000|qboxhd|qboxhd_mini|forever_2424hd|forever_3434hd|forever_9898hd|forever_nanosmart|opt9600)$"

KV = "${KERNELVERSION}.71-stm24-0217"
SRCREV = "${AUTOREV}"

inherit module machine_kernel_pr gitpkgv

PACKAGES = "${PN} ${PN}-dev"

PV = "${KV}+git${SRCPV}-${MACHINE}"
PKGV = "git${GITPKGV}"

PTI_NP_PATH ?= "/data/pti_np"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI = "\
	git://github.com/OpenVisionE2/sh4-driver.git;protocol=git \
	file://modules.conf \
	file://modules-conf.conf \
	" 

FILES_${PN} = "${sysconfdir}/init.d ${sysconfdir}/rcS.d ${sysconfdir}/modules-load.d ${sysconfdir}/modprobe.d ${base_bindir} ${sysconfdir}"

FILES = ""

S = "${WORKDIR}/git"

EXTRA_OEMAKE = "-e MAKEFLAGS="

CLEANBROKEN = "1"

do_configure_prepend () {
    # if a custom pti source is present, add it to the sources
    if [ -e ${PTI_NP_PATH}/Makefile ]; then
        echo "Found custom pti sources.."
        cp -fr ${PTI_NP_PATH} ${S}
    fi
    if [ -L include/multicom ]; then
        rm -rf include/multicom
    fi
    if [ -L multicom ]; then
        rm -rf multicom 
    fi
    ln -sf ${S}/multicom/include ${S}/include/multicom
    export KERNEL_LOCATION="${STAGING_KERNEL_DIR}"
    cp -fR ${S}/multicom ${STAGING_KERNEL_DIR}/multicom
}

do_compile() {
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
    oe_runmake KERNEL_PATH=${STAGING_KERNEL_DIR}   \
        KERNEL_SRC=${STAGING_KERNEL_DIR}    \
        KERNEL_VERSION=${KERNEL_VERSION}    \
        -C ${STAGING_KERNEL_DIR}   \
	O=${STAGING_KERNEL_BUILDDIR} \
        ${@d.getVar('MACHINE',1).upper()}=1 \
        M=${S} V=1 \
        ARCH=sh \
        DRIVER_TOPDIR="${S}" \
        KERNEL_LOCATION="${STAGING_KERNEL_DIR}" \
        CONFIG_KERNEL_BUILD="${STAGING_KERNEL_BUILDDIR}" \
        CONFIG_KERNEL_PATH="${STAGING_KERNEL_DIR}" \
        CONFIG_MODULES_PATH="${D}" \
        CCFLAGSY="-I${STAGING_DIR_HOST}${incdir}" \
        modules 
}

do_install() {
    unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
    oe_runmake KERNEL_PATH=${STAGING_KERNEL_DIR}   \
        KERNEL_SRC=${STAGING_KERNEL_DIR}    \
        KERNEL_VERSION=${KERNEL_VERSION}    \
        -C ${STAGING_KERNEL_DIR}   \
	O=${STAGING_KERNEL_BUILDDIR} \
        ${@d.getVar('MACHINE',1).upper()}=1 \
        M=${S} V=1 \
        ARCH=sh \
        DRIVER_TOPDIR="${S}" \
        KERNEL_LOCATION="${STAGING_KERNEL_DIR}" \
        CONFIG_KERNEL_BUILD="${STAGING_KERNEL_BUILDDIR}" \
        CONFIG_KERNEL_PATH="${STAGING_KERNEL_DIR}" \
        CONFIG_MODULES_PATH="${D}" \
        CCFLAGSY="-I${STAGING_DIR_HOST}${incdir}" \
        INSTALL_MOD_PATH=${D} modules_install

    # install header files
    install -d ${D}${includedir}/
    install -m 644 multicom/include/mme.h ${D}${includedir}
    install -m 644 include/player2/JPEG_VideoTransformerTypes.h ${D}${includedir}
    install -m 644 include/player2/JPEGDECHW_VideoTransformerTypes.h ${D}${includedir}
    install -m 644 include/player2/PNGDecode_interface.h ${D}${includedir}
    install -m 644 include/player2/RLEDecode_interface.h ${D}${includedir}
    install -m 644 frontcontroller/aotom_spark/aotom_main.h ${D}${includedir}
    install -m 644 player2/components/include/stddefs.h ${D}${includedir}

    #install modutils config
    install -d ${D}${sysconfdir}/modules-load.d
    install -m 644 ${WORKDIR}/modules.conf ${D}${sysconfdir}/modules-load.d/_${MACHINE}.conf
    echo "e2_proc" > ${D}${sysconfdir}/modules-load.d/zeprocfs.conf
    install -d ${D}${sysconfdir}/modprobe.d
    install -m 644 ${WORKDIR}/modules-conf.conf ${D}${sysconfdir}/modprobe.d/_${MACHINE}.conf
    install -d ${D}${sysconfdir}/init.d
    install -d ${D}${sysconfdir}/rcS.d
    install -m 0755 ${S}/ddbootup ${D}${sysconfdir}/init.d
    ln -sf ../init.d/ddbootup ${D}${sysconfdir}/rcS.d/S01ddbootup
    install -d ${D}${base_bindir}
    install -m 755 ${S}/vdstandby ${D}${base_bindir}
    install -d ${D}${sysconfdir}
    install -m 644 ${S}/vdstandby.cfg ${D}${sysconfdir}
    install -m 0755 ${S}/sh4booster ${D}${sysconfdir}/init.d
    ln -sf ../init.d/sh4booster ${D}${sysconfdir}/rcS.d/S05sh4booster

    # if no pti_np sources are available and a custom pti.ko is present, overwrite the SH4 one
    if [ ! -e ${PTI_NP_PATH}/Makefile ]; then
        if [ -e ${PTI_NP_PATH}/pti.ko ]; then
            echo "Found custom pti binary.." 
            install -m 644 ${PTI_NP_PATH}/pti.ko ${D}${nonarch_base_libdir}/modules/${KERNEL_VERSION}/extra/pti/pti.ko
        fi
    fi
	
    find ${D} -name stmcore-display-sti7106.ko | xargs -r rm # we don't have a 7106 chip
}

PACKAGESPLITFUNCS_append = " handle_driver_rename "

python handle_driver_rename () {
    d.setVar("RPROVIDES_sh4-dvb-modules", "sh4-dvb-modules")
    d.setVar("RREPLACES_sh4-dvb-modules", "sh4-dvb-modules")
    d.setVar("RCONFLICTS_sh4-dvb-modules", "sh4-dvb-modules")
}

FILES_${PN}-dev += "${includedir}"
