DESCRIPTION = "STM Coprocessor firmware"
LICENSE = "CLOSED"
SECTION = "base"
inherit allarch

COMPATIBLE_MACHINE = "^(adb_box|adb_2850|arivalink200|atemio520|atemio530|atevio7500|cuberevo|cuberevo_250hd|cuberevo_2000hd|cuberevo_3000hd|cuberevo_mini|cuberevo_mini2|cuberevo_9500hd|pace7241|vip1_v1|vip1_v2|vip2|fortis_hdbox|hl101|hs7110|hs7119|hs7420|hs7429|hs7810a|hs7819|ipbox55|ipbox99|ipbox9900|sagemcom88|octagon1008|spark|spark7162|tf7700|ufc960|ufs910|ufs912|ufs913|ufs922|vitamin_hd5000|qboxhd|qboxhd_mini|forever_2424hd|forever_3434hd|forever_9898hd|forever_nanosmart|opt9600)$"

# fix architecture mismatch QA error
INSANE_SKIP_${PN} = "arch"

SRC_URI = "file://${AUDIOELF} \
	file://${VIDEOELF} \
	${@bb.utils.contains("BOX_BRAND", "forever", "file://companion_h205_video_Bx.bin", "", d)} \
	"

# For audio_7109.elf just use audio_7100.elf

FILES_${PN} += "/boot"

do_install () {
	# Remove stuff from old packages if present
	if [ -e ${sysconfdir}/init.d/stslave.sh ] ; then
		rm -f ${sysconfdir}/init.d/stslave.sh
	fi
	if [ -e ${sysconfdir}/rcS.d/S03stslave ] ; then
		rm -f ${sysconfdir}/rcS.d/S03stslave
	fi
	install -d ${D}/boot
	if [ "${BOX_BRAND}" = "forever" ]; then
		install -m 644 ${WORKDIR}/${AUDIOELF}  ${D}/boot/
		install -m 644 ${WORKDIR}/${VIDEOELF}  ${D}/boot/
		install -m 644 ${WORKDIR}/${VIDEOELF2}  ${D}/boot/
	else
		install -m 644 ${WORKDIR}/${AUDIOELF}  ${D}/boot/audio.elf
		install -m 644 ${WORKDIR}/${VIDEOELF}  ${D}/boot/video.elf
	fi
}
