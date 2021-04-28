# Make sure it starts before udev

INITSCRIPT_PARAMS = "${@bb.utils.contains("MACHINE_FEATURES", "sh4stb", "start 05 S .", "start 03 S .", d)}"
