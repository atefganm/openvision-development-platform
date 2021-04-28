# enable/disable your preferred mediaservice
# servicemp3epl = mixed solution gst/exteplayer3
# servicesh4 = pure libeplayer3 (ffmpeg without gst)
PREFERRED_PROVIDER_virtual/enigma2-mediaservice = "enigma2-plugin-systemplugins-servicesh4"

# add libeplayer MACHINE_FEATURES if mediaservice is servicesh4
# delete libeplayer MACHINE_FEATURES if mediaservice is servicemp3epl
MACHINE_FEATURES += "libeplayer"

# add this MACHINE_EXTRA_PRECOMMENDS if mediaservice is servicesh4
# delete this MACHINE_EXTRA_PRECOMMENDS if mediaservice is servicemp3epl
MACHINE_EXTRA_RRECOMMENDS += "\
	enigma2-plugin-systemplugins-servicesh4 \
	"
