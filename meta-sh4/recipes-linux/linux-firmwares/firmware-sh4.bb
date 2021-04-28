SUMMARY = "Firmware files for sh4"
LICENSE = "CLOSED"

PACKAGE_ARCH = "${MACHINE_ARCH}"

COMPATIBLE_MACHINE = "^(adb_box|adb_2850|arivalink200|atevio7500|cuberevo|cuberevo_250hd|cuberevo_2000hd|cuberevo_3000hd|cuberevo_mini|cuberevo_mini2|cuberevo_9500hd|pace7241|vip1_v1|vip1_v2|vip2|hl101|sagemcom88|octagon1008|tf7700|ufc960|ufs910|ufs913|ufs922|vitamin_hd5000|qboxhd|qboxhd_mini|forever_2424hd|forever_3434hd|forever_9898hd|forever_nanosmart|opt9600)$"

SRC_URI = "https://raw.githubusercontent.com/OpenVisionE2/linux-firmwares/master/sh4-firmwares.zip"

SRC_URI[md5sum] = "61b4877cf8170832d82ec876cf6b0a56"
SRC_URI[sha256sum] = "869b07c99b77a54449ed766bdcd6ea219d1860129fe801f2d92d5d515bff69f1"

S = "${WORKDIR}"

PACKAGES = "${PN}"
FILES_${PN} += "${nonarch_base_libdir}/firmware"

do_install() {
	install -d ${D}${nonarch_base_libdir}/firmware
	if [ "${MACHINE}" = "adb_box" -o "${MACHINE}" = "adb_2850" ]; then
		install -m 0644 dvb-fe-avl2108.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 dvb-fe-avl6222.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 as102_data1_st.hex ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 as102_data2_st.hex ${D}${nonarch_base_libdir}/firmware/
	elif [ "${MACHINE}" = "tf7700" ]; then
		install -m 0644 dvb-fe-cx24116.fw ${D}${nonarch_base_libdir}/firmware/
	elif [ "${MACHINE}" = "ufs910" ]; then
		install -m 0644 dvb-fe-cx21143.fw ${D}${nonarch_base_libdir}/firmware/dvb-fe-cx24116.fw
	elif [ "${MACHINE}" = "pace7241" -o "${MACHINE}" = "sagemcom88" -o "${MACHINE}" = "ufs913" -o "${MACHINE}" = "vitamin_hd5000" ]; then
		install -m 0644 dvb-fe-avl6222.fw ${D}${nonarch_base_libdir}/firmware/
	elif [ "${MACHINE}" = "ufs922" ]; then
		install -m 0644 dvb-fe-avl2108.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 dvb-fe-avl6222.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 dvb-fe-cx21143.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 dvb-fe-stv6306.fw ${D}${nonarch_base_libdir}/firmware/
	elif [ "${MACHINE}" = "hl101" -o "${MACHINE}" = "vip1_v1" -o "${MACHINE}" = "opt9600" ]; then
		install -m 0644 dvb-fe-avl2108.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 dvb-fe-avl6222.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 dvb-fe-cx21143.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 dvb-fe-stv6306.fw ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 dvb-fe-cx24116.fw ${D}${nonarch_base_libdir}/firmware/
	else
		install -m 0644 ${DVB1FIRMWARE} ${D}${nonarch_base_libdir}/firmware/
		install -m 0644 ${DVB2FIRMWARE} ${D}${nonarch_base_libdir}/firmware/
	fi
}
